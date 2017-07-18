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

	//============================================================================================
	
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