// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameInstance.h"
#include "WebConnection.h"
#include "ArenaBattle.h"

UABGameInstance::UABGameInstance()
{
	// UE_LOG(CategoryName, Verbosity, FormatString)
	// �α� ī�װ� ����, Log / Warning / Error(���α׷� ���� ����) / ..., TEXT() : printf�� ����
	
	//UE_LOG(LogClass, Warning, TEXT("Game Instance Constructor Call!"));
	AB_LOG(Warning, TEXT("Constructor Start!"));
	
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
}