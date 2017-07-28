// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameInstance.h"
#include "WebConnection.h"
#include "ArenaBattle.h"
#include "Public/EngineUtils.h"
#include "Public/UObject/UObjectIterator.h"
#include "Engine/StaticMeshActor.h"
#include "Paths.h"
#include "FileManager.h"
#include "Package.h"
#include "PackageName.h"
#include "TimerManager.h"

UABGameInstance::UABGameInstance()
{
	// UE_LOG(CategoryName, Verbosity, FormatString)
	// 로그 카테고리 지정, Log / Warning / Error(프로그램 정지 가능) / ..., TEXT() : printf와 유사

	//UE_LOG(LogClass, Warning, TEXT("Game Instance Constructor Call!"));
	AB_LOG(Warning, TEXT("Constructor Start!"));

	// ABGameInstance 가 생성되면 자동으로 따라 생성된다.
	// 변경될 여지가 거의 없는 오브젝트 묶음을 한번에 생성할 때 유용.
	WebConnection = CreateDefaultSubobject<UWebConnection>(TEXT("MyWebConnection"));

	//UE_LOG(LogClass, Warning, TEXT("Game Instance Constructor End!"))
	AB_LOG(Warning, TEXT("Constructor End!"));
}

void UABGameInstance::Init()
{
	Super::Init();
	//UE_LOG(LogClass, Warning, TEXT("Game Instance Init!"));
	AB_LOG_CALLONLY(Warning);	

	Search();

	BindDelegate();
	
	SerializationAndPackaging();

	SmartPointer();

}

void UABGameInstance::RequestTokenComplete(const FString & Token)
{
	AB_LOG(Warning, TEXT("Token : %s"), *Token);
}

void UABGameInstance::CheckUObjectAlive()
{
	if (!WebConnectionTest)
	{
		AB_LOG(Warning, TEXT("언리얼 오브젝트가 널입니다."));
		return;
	}

	if (!WebConnectionTest->IsValidLowLevel())
	{
		AB_LOG(Warning, TEXT("언리얼 오브젝트가 유효하지 않습니다."));
		return;
	}

	AB_LOG(Warning, TEXT("언리얼 오브젝트가 아직 살아있습니다. : %s"), *WebConnectionTest->Host);
}

void UABGameInstance::Search()
{
	UClass* ClassInfo1 = WebConnection->GetClass();
	UClass* ClassInfo2 = UWebConnection::StaticClass();

	if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2."));
	}

	// TFieldIterator : UClass 에 등록된 속성과 함수들을 검색할 수 있다.
	// UProperty 를 사용하면 속성 값만 검색 가능,
	// 런타임에서 특정 인스턴스에 할당된 속성 값을 가져올 수 있다.
	// TFieldIterator<UProperty> = 변수 목록
	for (TFieldIterator<UProperty> Iter(ClassInfo1); Iter; ++Iter)
	{
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *Iter->GetName(), *Iter->GetClass()->GetName());
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *Iter->GetName());

		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnection));
		}
	}

	// NativeFunctionLookupTable 를 통해 어떤 함수가 있는지 알 수 있다.
	// TFieldIterator<UFunction> = 함수 목록
	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)	// 범위 기반 for loop
	{
		AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());
		UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);

		if (Func1->ParmsSize == 0)
		{
			WebConnection->ProcessEvent(Func1, NULL);
		}
	}

	// ============================================================================================

	TArray<UObject*> DefaultSubobjects;
	GetDefaultSubobjects(DefaultSubobjects);		//ABGameInstance 의 DefaultSubobjects 를 가져온다.
	for (const auto& Entry : DefaultSubobjects)
	{
		AB_LOG(Warning, TEXT("DefaultSubobject : %s"), *Entry->GetClass()->GetName());
		AB_LOG(Warning, TEXT("Outer of DefaultSubobject : %s"), *Entry->GetOuter()->GetClass()->GetName());
	}

	// 사용자가 직접 생성해줘야한다.
	// 다양한 타입의 오브젝트를 생성할 수 있다.
	WebConnectionNew = NewObject<UWebConnection>(this);
	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnectionNew->GetOuter()->GetClass()->GetName());

	UWorld* CurrentWorld = GetWorld();
	// FActorRange : 월드에 있는 모든 액터를 검색한다.
	for (const auto& Entry : FActorRange(CurrentWorld))
	{
		AB_LOG(Warning, TEXT("Actor : %s"), *Entry->GetName());
		TArray<UObject*> Components;
		Entry->GetDefaultSubobjects(Components);		// 액터 내 컴포넌트는 모두 DefaultSubobject 로 설정 되어있다.
		for (const auto& CEntry : Components)
		{
			AB_LOG(Warning, TEXT(" -- Component : %s"), *CEntry->GetName());
		}
	}


	// ===== 액터 중에 원하는 타입만 선별해서 검색 =====

	// TActorIterator : 스태틱 메시 액터
	for (TActorIterator<AStaticMeshActor> Iter(CurrentWorld); Iter; ++Iter)
	{
		AB_LOG(Warning, TEXT("StaticMeshActor : %s"), *Iter->GetName());
	}

	WebConnection->Host = TEXT("localhost");
	WebConnectionNew->Host = TEXT("127.0.0.1");

	// TObjectIterator : 언리얼 오브젝트
	// 오브젝트를 3개 찾는다.
	// 하나는 ABGameInstance 의 CDO
	// 하나는 인스턴스 초기화 때 생성된 WebConnection
	// 하나는 런타임 중에 생성한 WebConnectionNew
	for (TObjectIterator<UWebConnection> Iter; Iter; ++Iter)
	{
		UWebConnection* Conn = *Iter;
		AB_LOG(Warning, TEXT("WebConnection Object Host : %s"), *Conn->Host);
	}
}

void UABGameInstance::BindDelegate()
{
	// Delegate ============================================================================================

	// 함수를 바인딩한다.
	//WebConnection->TokenCompleteDelegate.BindUObject(this, &UABGameInstance::RequestTokenComplete);
	WebConnection->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete);

	WebConnection->RequestToken(TEXT("destiny"));
}

void UABGameInstance::SerializationAndPackaging()
{
	// Serialization =======================================================================================

	// 새로운 WebConnection 을 생성
	WebConnectionNew2 = NewObject<UWebConnection>(this);
	WebConnectionNew2->Host = TEXT("127.0.0.7");
	WebConnectionNew2->URI = TEXT("/");

	FString FullPath = FString::Printf(TEXT("%s %s"), *FPaths::GameSavedDir(), TEXT("WebConnection.txt"));

	// FArchive : 파일, 메모리 등의 데이터를 전송하는 모든 매체는 이 클래스를 상속받아 구현
	// 언리얼에서는 << 만 쓴다.
	FArchive* ArWriter = IFileManager::Get().CreateFileWriter(*FullPath);
	if (ArWriter)
	{
		// 멤버 변수들을 일일히 전달 / Serialization 이라고 보기 힘듦.
		//*ArWriter << WebConnectionNew2->Host;
		//*ArWriter << WebConnectionNew2->URI;

		// 인스턴스를 전달한다.
		*ArWriter << *WebConnectionNew2;

		ArWriter->Close();
		delete ArWriter;
		ArWriter = NULL;
	}

	TSharedPtr<FArchive> FileReader = MakeShareable(IFileManager::Get().CreateFileReader(*FullPath));
	if (FileReader.IsValid())
	{
		//FString Host;
		//FString URI;
		//*FileReader.Get() << Host;
		//*FileReader.Get() << URI;

		UWebConnection* WebConnectionFromFile = NewObject<UWebConnection>(this);
		// 연산자 오버로딩으로 지정한 데이터를 가져온다.
		*FileReader.Get() << *WebConnectionFromFile;

		FileReader->Close();
		//AB_LOG(Warning, TEXT("WebConnection : Host %s, URI %s"), *Host, *URI);
		AB_LOG(Warning, TEXT("WebConnection From File : Host %s, URI %s"),
			*WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
	}


	// ======= Serialization - Packaging =======

	FString PackageName = TEXT("/Temp/SavedWebConnection");
	UPackage* NewPackage = CreatePackage(nullptr, *PackageName);
	WebConnectionNew3 = NewObject<UWebConnection>(NewPackage);
	FString PackageFileName =
		FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	WebConnectionNew3->Host = TEXT("127.0.0.7");
	WebConnectionNew3->URI = TEXT("/");

	if (UPackage::SavePackage(NewPackage, WebConnectionNew3, RF_Standalone, *PackageFileName))
	{
		UPackage* SavedPackage = ::LoadPackage(NULL, *PackageFileName, LOAD_None);
		TArray<UObject*> ObjectsInPackage;
		GetObjectsWithOuter(SavedPackage, ObjectsInPackage, false);
		for (const auto& EachObject : ObjectsInPackage)
		{
			UWebConnection* WebConnectionFromFile = Cast<UWebConnection>(EachObject);
			if (WebConnectionFromFile)
			{
				AB_LOG(Warning, TEXT("WebConnection From File : Host %s, URI %s"),
					*WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
			}
		}
	}
}

void UABGameInstance::SmartPointer()
{
	// SmartPointer ===================================================================

	// 1 단계
	AB_LOG(Warning, TEXT("*** 1 단계 ***"));
	FHouse* NewHouseAddress = new FHouse();
	AB_LOG(Warning, TEXT("집을 새로 지었습니다. 내 집 크기 : %d"), NewHouseAddress->Size);
	if (NewHouseAddress)
	{
		delete NewHouseAddress;
		AB_LOG(Warning, TEXT("내가 직접 집을 철거했습니다. 집 크기 : %d"), NewHouseAddress->Size);
		NewHouseAddress = nullptr;
	}


	// 2 단계 / Unique Pointer
	AB_LOG(Warning, TEXT("*** 2 단계 ***"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 100;
	AB_LOG(Warning, TEXT("집을 다시 지었습니다. 집 크기 : %d"), NewHouseAddress->Size);
	{
		// 유니크 포인터 : 다른 포인터와 공유 x
		TUniquePtr<FHouse> MyHouseDeed = TUniquePtr<FHouse>(NewHouseAddress);
		if (MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("이 집은 제 단독 소유 주택입니다. 내 집 크기 : %d"), MyHouseDeed->Size);
		}

		//TUniquePtr<FHouse> FriendHouseDeed = MyHouseDeed; // 에러 : 공유할 수 없기 때문에

		// 주소 공간은 그대로 / 가리키는 포인터를 변경
		// 표준 C++에서의 Move Semantic
		TUniquePtr<FHouse> FriendHouseDeed = MoveTemp(MyHouseDeed);
		if (!MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("친구에게 집을 팔았습니다. 친구 집 크기 : %d"), FriendHouseDeed->Size);
		}
	}
	AB_LOG(Warning, TEXT("집문서가 사라져서 집은 자동으로 철거되었습니다. 집 크기 : %d"), NewHouseAddress->Size);


	// 3 단계 / Shared Pointer
	AB_LOG(Warning, TEXT("*** 3 단계 ***"));
	NewHouseAddress = new FHouse;
	NewHouseAddress->Size = 150.0f;
	AB_LOG(Warning, TEXT("집을 또 다시 지었습니다. 집 크기 : %d"), NewHouseAddress->Size);
	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);	// 만들어진 집을 차후 등록
		if(MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("공동 소유 가능한 집이 되었습니다. 내 집 크기 : %d"), MyHouseDeed->Size);
			if (MyHouseDeed.IsUnique())
			{
				AB_LOG(Warning, TEXT("현재는 혼자 소유하고 있습니다. 내 집 크기 : %d"), MyHouseDeed->Size);
			}
		}

		TSharedPtr<FHouse> FriendsHouseDeed = MyHouseDeed;
		if (!FriendsHouseDeed.IsUnique())
		{
			AB_LOG(Warning, TEXT("친구와 집을 나눠가지게 되었습니다. 친구 집 크기 : %d"), FriendsHouseDeed->Size);
		}

		MyHouseDeed.Reset();	// 내가 집 소유권을 포기함
		if (FriendsHouseDeed.IsUnique())
		{
			AB_LOG(Warning, TEXT("이제 친구만 집을 소유하고 있습니다. 친구 집 크기 : %d"), FriendsHouseDeed->Size);
		}

		AB_LOG(Warning, TEXT("집은 아직 그대로 있습니다. 집 크기 : %d"), NewHouseAddress->Size);
	}

	AB_LOG(Warning, TEXT("집은 자동 철거되었습니다. 집 크기 : %d"), NewHouseAddress->Size);

	
	// 4 단계 / Shared Pointer 의 순환 참조 문제
	AB_LOG(Warning, TEXT("*** 4 단계 ***"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 200.0f;
	AB_LOG(Warning, TEXT("집을 한번 더 다시 지었습니다. 첫번째 집 크기 : %d"), NewHouseAddress->Size);

	FHouse* NewHouseAddress2 = new FHouse();
	NewHouseAddress2->Size = 250.0f;
	AB_LOG(Warning, TEXT("친구도 집을 직접 지엇습니다. 두번째 집 크기 : %d"), NewHouseAddress2->Size);

	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);
		AB_LOG(Warning, TEXT("내 집은 내가 소유합니다. 내 집 크기 : %d"), MyHouseDeed->Size);
		TSharedPtr<FHouse> FriendsHouseDeed = MakeShareable(NewHouseAddress2);
		AB_LOG(Warning, TEXT("친구 집은 친구가 소유합니다. 친구 집 크기 : %d"), FriendsHouseDeed->Size);

		// 순환 참조
		MyHouseDeed->OthersDeed = FriendsHouseDeed;
		AB_LOG(Warning, TEXT("친구 집을 공동 소유하고 문서를 내 집에 보관합니다. 친구 집 크기 : %d"), 
			MyHouseDeed->OthersDeed->Size);
		FriendsHouseDeed->OthersDeed = MyHouseDeed;
		AB_LOG(Warning, TEXT("친구도 내 집을 공동 소유하고 문서를 자기 집에 보관합니다. 내 집 크기 : %d"), 
			FriendsHouseDeed->OthersDeed->Size);
	}

	AB_LOG(Warning, TEXT("집문서가 사라져도 내가 지은 집이 자동 철거되지 않습니다. 첫번째 집 크기 : %d"), 
		NewHouseAddress->Size);
	AB_LOG(Warning, TEXT("친구가 지은 집도 자동 철거되지 않습니다. 두번째 집 크기 : %d"), 
		NewHouseAddress2->Size);

	NewHouseAddress->OthersDeed.Reset();
	AB_LOG(Warning, TEXT("친구가 지은 집을 수동으로 철거했습니다. 집주소가 남아있어서 다행입니다. 두번째 집 크기 : %d"),
		NewHouseAddress2->Size);
	AB_LOG(Warning, TEXT("이제서야 내가 지은 집도 자동 철거됩니다. 첫번째 집 크기 : %d"),
		NewHouseAddress->Size);


	// 5 단계 / Weak Pointer
	AB_LOG(Warning, TEXT("*** 5 단계 ***"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 300.0f;
	AB_LOG(Warning, TEXT("이제 마지막으로 집을 짓습니다. 첫번째 집 크기 : %d"), NewHouseAddress->Size);

	NewHouseAddress2 = new FHouse();
	NewHouseAddress2->Size = 350.0f;
	AB_LOG(Warning, TEXT("친구도 집을 다시 지었습니다. 두번째 집 크기 : %d"), NewHouseAddress2->Size);

	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);
		AB_LOG(Warning, TEXT("내 집은 내가 소유합니다. 내 집 크기 : %d"), MyHouseDeed->Size);
		TSharedPtr<FHouse> FriendsHouseDeed = MakeShareable(NewHouseAddress2);
		AB_LOG(Warning, TEXT("친구 집은 친구가 소유합니다. 친구 집 크기 : %d"), FriendsHouseDeed->Size);

		MyHouseDeed->OthersDeed = FriendsHouseDeed;
		AB_LOG(Warning, TEXT("친구 집을 공동 소유하고 문서를 내 집에 보관합니다. 친구 집 크기 : %d"), 
			MyHouseDeed->OthersDeed->Size);
		
		FriendsHouseDeed->AccessHouse = MyHouseDeed;
		AB_LOG(Warning, TEXT("친구가 내 집 정보를 열람합니다. 내 집 크기 : %d"), 
			FriendsHouseDeed->AccessHouse.Pin()->Size);
	}

	AB_LOG(Warning, TEXT("내가 지은 집은 자동 철거됩니다. 첫번째 집 크기 : %d"), NewHouseAddress->Size);
	AB_LOG(Warning, TEXT("친구가 지은 집도 자동 철거됩니다. 두번째 집 크기 : %d"), NewHouseAddress2->Size);

	
	// 6 단계
	AB_LOG(Warning, TEXT("*** 6 단계 ***"));
	WebConnectionTest = NewObject<UWebConnection>();
	WebConnectionTest->Host = TEXT("127.0.0.1");
	//WebConnectionTest->AddToRoot();				// 메모리에 유지시키고 싶을때
	WebConnectionTest->ConditionalBeginDestroy();
	//GetWorld()->ForceGarbageCollection(true);		// 바로 자원회수 명령
	GetWorld()->GetTimerManager().SetTimer(
		ObjectCheckTimer, this, &UABGameInstance::CheckUObjectAlive, 1.0f, true);
}
