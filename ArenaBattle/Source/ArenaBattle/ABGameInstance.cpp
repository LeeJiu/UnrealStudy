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
	// �α� ī�װ� ����, Log / Warning / Error(���α׷� ���� ����) / ..., TEXT() : printf�� ����

	//UE_LOG(LogClass, Warning, TEXT("Game Instance Constructor Call!"));
	AB_LOG(Warning, TEXT("Constructor Start!"));

	// ABGameInstance �� �����Ǹ� �ڵ����� ���� �����ȴ�.
	// ����� ������ ���� ���� ������Ʈ ������ �ѹ��� ������ �� ����.
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
		AB_LOG(Warning, TEXT("�𸮾� ������Ʈ�� ���Դϴ�."));
		return;
	}

	if (!WebConnectionTest->IsValidLowLevel())
	{
		AB_LOG(Warning, TEXT("�𸮾� ������Ʈ�� ��ȿ���� �ʽ��ϴ�."));
		return;
	}

	AB_LOG(Warning, TEXT("�𸮾� ������Ʈ�� ���� ����ֽ��ϴ�. : %s"), *WebConnectionTest->Host);
}

void UABGameInstance::Search()
{
	UClass* ClassInfo1 = WebConnection->GetClass();
	UClass* ClassInfo2 = UWebConnection::StaticClass();

	if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2."));
	}

	// TFieldIterator : UClass �� ��ϵ� �Ӽ��� �Լ����� �˻��� �� �ִ�.
	// UProperty �� ����ϸ� �Ӽ� ���� �˻� ����,
	// ��Ÿ�ӿ��� Ư�� �ν��Ͻ��� �Ҵ�� �Ӽ� ���� ������ �� �ִ�.
	// TFieldIterator<UProperty> = ���� ���
	for (TFieldIterator<UProperty> Iter(ClassInfo1); Iter; ++Iter)
	{
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *Iter->GetName(), *Iter->GetClass()->GetName());
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *Iter->GetName());

		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnection));
		}
	}

	// NativeFunctionLookupTable �� ���� � �Լ��� �ִ��� �� �� �ִ�.
	// TFieldIterator<UFunction> = �Լ� ���
	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)	// ���� ��� for loop
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
	GetDefaultSubobjects(DefaultSubobjects);		//ABGameInstance �� DefaultSubobjects �� �����´�.
	for (const auto& Entry : DefaultSubobjects)
	{
		AB_LOG(Warning, TEXT("DefaultSubobject : %s"), *Entry->GetClass()->GetName());
		AB_LOG(Warning, TEXT("Outer of DefaultSubobject : %s"), *Entry->GetOuter()->GetClass()->GetName());
	}

	// ����ڰ� ���� ����������Ѵ�.
	// �پ��� Ÿ���� ������Ʈ�� ������ �� �ִ�.
	WebConnectionNew = NewObject<UWebConnection>(this);
	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnectionNew->GetOuter()->GetClass()->GetName());

	UWorld* CurrentWorld = GetWorld();
	// FActorRange : ���忡 �ִ� ��� ���͸� �˻��Ѵ�.
	for (const auto& Entry : FActorRange(CurrentWorld))
	{
		AB_LOG(Warning, TEXT("Actor : %s"), *Entry->GetName());
		TArray<UObject*> Components;
		Entry->GetDefaultSubobjects(Components);		// ���� �� ������Ʈ�� ��� DefaultSubobject �� ���� �Ǿ��ִ�.
		for (const auto& CEntry : Components)
		{
			AB_LOG(Warning, TEXT(" -- Component : %s"), *CEntry->GetName());
		}
	}


	// ===== ���� �߿� ���ϴ� Ÿ�Ը� �����ؼ� �˻� =====

	// TActorIterator : ����ƽ �޽� ����
	for (TActorIterator<AStaticMeshActor> Iter(CurrentWorld); Iter; ++Iter)
	{
		AB_LOG(Warning, TEXT("StaticMeshActor : %s"), *Iter->GetName());
	}

	WebConnection->Host = TEXT("localhost");
	WebConnectionNew->Host = TEXT("127.0.0.1");

	// TObjectIterator : �𸮾� ������Ʈ
	// ������Ʈ�� 3�� ã�´�.
	// �ϳ��� ABGameInstance �� CDO
	// �ϳ��� �ν��Ͻ� �ʱ�ȭ �� ������ WebConnection
	// �ϳ��� ��Ÿ�� �߿� ������ WebConnectionNew
	for (TObjectIterator<UWebConnection> Iter; Iter; ++Iter)
	{
		UWebConnection* Conn = *Iter;
		AB_LOG(Warning, TEXT("WebConnection Object Host : %s"), *Conn->Host);
	}
}

void UABGameInstance::BindDelegate()
{
	// Delegate ============================================================================================

	// �Լ��� ���ε��Ѵ�.
	//WebConnection->TokenCompleteDelegate.BindUObject(this, &UABGameInstance::RequestTokenComplete);
	WebConnection->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete);

	WebConnection->RequestToken(TEXT("destiny"));
}

void UABGameInstance::SerializationAndPackaging()
{
	// Serialization =======================================================================================

	// ���ο� WebConnection �� ����
	WebConnectionNew2 = NewObject<UWebConnection>(this);
	WebConnectionNew2->Host = TEXT("127.0.0.7");
	WebConnectionNew2->URI = TEXT("/");

	FString FullPath = FString::Printf(TEXT("%s %s"), *FPaths::GameSavedDir(), TEXT("WebConnection.txt"));

	// FArchive : ����, �޸� ���� �����͸� �����ϴ� ��� ��ü�� �� Ŭ������ ��ӹ޾� ����
	// �𸮾󿡼��� << �� ����.
	FArchive* ArWriter = IFileManager::Get().CreateFileWriter(*FullPath);
	if (ArWriter)
	{
		// ��� �������� ������ ���� / Serialization �̶�� ���� ����.
		//*ArWriter << WebConnectionNew2->Host;
		//*ArWriter << WebConnectionNew2->URI;

		// �ν��Ͻ��� �����Ѵ�.
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
		// ������ �����ε����� ������ �����͸� �����´�.
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

	// 1 �ܰ�
	AB_LOG(Warning, TEXT("*** 1 �ܰ� ***"));
	FHouse* NewHouseAddress = new FHouse();
	AB_LOG(Warning, TEXT("���� ���� �������ϴ�. �� �� ũ�� : %d"), NewHouseAddress->Size);
	if (NewHouseAddress)
	{
		delete NewHouseAddress;
		AB_LOG(Warning, TEXT("���� ���� ���� ö���߽��ϴ�. �� ũ�� : %d"), NewHouseAddress->Size);
		NewHouseAddress = nullptr;
	}


	// 2 �ܰ� / Unique Pointer
	AB_LOG(Warning, TEXT("*** 2 �ܰ� ***"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 100;
	AB_LOG(Warning, TEXT("���� �ٽ� �������ϴ�. �� ũ�� : %d"), NewHouseAddress->Size);
	{
		// ����ũ ������ : �ٸ� �����Ϳ� ���� x
		TUniquePtr<FHouse> MyHouseDeed = TUniquePtr<FHouse>(NewHouseAddress);
		if (MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("�� ���� �� �ܵ� ���� �����Դϴ�. �� �� ũ�� : %d"), MyHouseDeed->Size);
		}

		//TUniquePtr<FHouse> FriendHouseDeed = MyHouseDeed; // ���� : ������ �� ���� ������

		// �ּ� ������ �״�� / ����Ű�� �����͸� ����
		// ǥ�� C++������ Move Semantic
		TUniquePtr<FHouse> FriendHouseDeed = MoveTemp(MyHouseDeed);
		if (!MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("ģ������ ���� �Ⱦҽ��ϴ�. ģ�� �� ũ�� : %d"), FriendHouseDeed->Size);
		}
	}
	AB_LOG(Warning, TEXT("�������� ������� ���� �ڵ����� ö�ŵǾ����ϴ�. �� ũ�� : %d"), NewHouseAddress->Size);


	// 3 �ܰ� / Shared Pointer
	AB_LOG(Warning, TEXT("*** 3 �ܰ� ***"));
	NewHouseAddress = new FHouse;
	NewHouseAddress->Size = 150.0f;
	AB_LOG(Warning, TEXT("���� �� �ٽ� �������ϴ�. �� ũ�� : %d"), NewHouseAddress->Size);
	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);	// ������� ���� ���� ���
		if(MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("���� ���� ������ ���� �Ǿ����ϴ�. �� �� ũ�� : %d"), MyHouseDeed->Size);
			if (MyHouseDeed.IsUnique())
			{
				AB_LOG(Warning, TEXT("����� ȥ�� �����ϰ� �ֽ��ϴ�. �� �� ũ�� : %d"), MyHouseDeed->Size);
			}
		}

		TSharedPtr<FHouse> FriendsHouseDeed = MyHouseDeed;
		if (!FriendsHouseDeed.IsUnique())
		{
			AB_LOG(Warning, TEXT("ģ���� ���� ���������� �Ǿ����ϴ�. ģ�� �� ũ�� : %d"), FriendsHouseDeed->Size);
		}

		MyHouseDeed.Reset();	// ���� �� �������� ������
		if (FriendsHouseDeed.IsUnique())
		{
			AB_LOG(Warning, TEXT("���� ģ���� ���� �����ϰ� �ֽ��ϴ�. ģ�� �� ũ�� : %d"), FriendsHouseDeed->Size);
		}

		AB_LOG(Warning, TEXT("���� ���� �״�� �ֽ��ϴ�. �� ũ�� : %d"), NewHouseAddress->Size);
	}

	AB_LOG(Warning, TEXT("���� �ڵ� ö�ŵǾ����ϴ�. �� ũ�� : %d"), NewHouseAddress->Size);

	
	// 4 �ܰ� / Shared Pointer �� ��ȯ ���� ����
	AB_LOG(Warning, TEXT("*** 4 �ܰ� ***"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 200.0f;
	AB_LOG(Warning, TEXT("���� �ѹ� �� �ٽ� �������ϴ�. ù��° �� ũ�� : %d"), NewHouseAddress->Size);

	FHouse* NewHouseAddress2 = new FHouse();
	NewHouseAddress2->Size = 250.0f;
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �������ϴ�. �ι�° �� ũ�� : %d"), NewHouseAddress2->Size);

	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);
		AB_LOG(Warning, TEXT("�� ���� ���� �����մϴ�. �� �� ũ�� : %d"), MyHouseDeed->Size);
		TSharedPtr<FHouse> FriendsHouseDeed = MakeShareable(NewHouseAddress2);
		AB_LOG(Warning, TEXT("ģ�� ���� ģ���� �����մϴ�. ģ�� �� ũ�� : %d"), FriendsHouseDeed->Size);

		// ��ȯ ����
		MyHouseDeed->OthersDeed = FriendsHouseDeed;
		AB_LOG(Warning, TEXT("ģ�� ���� ���� �����ϰ� ������ �� ���� �����մϴ�. ģ�� �� ũ�� : %d"), 
			MyHouseDeed->OthersDeed->Size);
		FriendsHouseDeed->OthersDeed = MyHouseDeed;
		AB_LOG(Warning, TEXT("ģ���� �� ���� ���� �����ϰ� ������ �ڱ� ���� �����մϴ�. �� �� ũ�� : %d"), 
			FriendsHouseDeed->OthersDeed->Size);
	}

	AB_LOG(Warning, TEXT("�������� ������� ���� ���� ���� �ڵ� ö�ŵ��� �ʽ��ϴ�. ù��° �� ũ�� : %d"), 
		NewHouseAddress->Size);
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �ڵ� ö�ŵ��� �ʽ��ϴ�. �ι�° �� ũ�� : %d"), 
		NewHouseAddress2->Size);

	NewHouseAddress->OthersDeed.Reset();
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �������� ö���߽��ϴ�. ���ּҰ� �����־ �����Դϴ�. �ι�° �� ũ�� : %d"),
		NewHouseAddress2->Size);
	AB_LOG(Warning, TEXT("�������� ���� ���� ���� �ڵ� ö�ŵ˴ϴ�. ù��° �� ũ�� : %d"),
		NewHouseAddress->Size);


	// 5 �ܰ� / Weak Pointer
	AB_LOG(Warning, TEXT("*** 5 �ܰ� ***"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 300.0f;
	AB_LOG(Warning, TEXT("���� ���������� ���� �����ϴ�. ù��° �� ũ�� : %d"), NewHouseAddress->Size);

	NewHouseAddress2 = new FHouse();
	NewHouseAddress2->Size = 350.0f;
	AB_LOG(Warning, TEXT("ģ���� ���� �ٽ� �������ϴ�. �ι�° �� ũ�� : %d"), NewHouseAddress2->Size);

	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);
		AB_LOG(Warning, TEXT("�� ���� ���� �����մϴ�. �� �� ũ�� : %d"), MyHouseDeed->Size);
		TSharedPtr<FHouse> FriendsHouseDeed = MakeShareable(NewHouseAddress2);
		AB_LOG(Warning, TEXT("ģ�� ���� ģ���� �����մϴ�. ģ�� �� ũ�� : %d"), FriendsHouseDeed->Size);

		MyHouseDeed->OthersDeed = FriendsHouseDeed;
		AB_LOG(Warning, TEXT("ģ�� ���� ���� �����ϰ� ������ �� ���� �����մϴ�. ģ�� �� ũ�� : %d"), 
			MyHouseDeed->OthersDeed->Size);
		
		FriendsHouseDeed->AccessHouse = MyHouseDeed;
		AB_LOG(Warning, TEXT("ģ���� �� �� ������ �����մϴ�. �� �� ũ�� : %d"), 
			FriendsHouseDeed->AccessHouse.Pin()->Size);
	}

	AB_LOG(Warning, TEXT("���� ���� ���� �ڵ� ö�ŵ˴ϴ�. ù��° �� ũ�� : %d"), NewHouseAddress->Size);
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �ڵ� ö�ŵ˴ϴ�. �ι�° �� ũ�� : %d"), NewHouseAddress2->Size);

	
	// 6 �ܰ�
	AB_LOG(Warning, TEXT("*** 6 �ܰ� ***"));
	WebConnectionTest = NewObject<UWebConnection>();
	WebConnectionTest->Host = TEXT("127.0.0.1");
	//WebConnectionTest->AddToRoot();				// �޸𸮿� ������Ű�� ������
	WebConnectionTest->ConditionalBeginDestroy();
	//GetWorld()->ForceGarbageCollection(true);		// �ٷ� �ڿ�ȸ�� ���
	GetWorld()->GetTimerManager().SetTimer(
		ObjectCheckTimer, this, &UABGameInstance::CheckUObjectAlive, 1.0f, true);
}
