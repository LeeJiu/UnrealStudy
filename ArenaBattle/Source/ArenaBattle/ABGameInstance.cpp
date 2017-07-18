// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameInstance.h"
#include "WebConnection.h"
#include "ArenaBattle.h"
#include "Public/EngineUtils.h"
#include "Public/UObject/UObjectIterator.h"
#include "Engine/StaticMeshActor.h"

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

	//============================================================================================
	
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