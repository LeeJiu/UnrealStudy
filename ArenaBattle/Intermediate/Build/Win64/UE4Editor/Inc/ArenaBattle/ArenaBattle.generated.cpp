// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ArenaBattle.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1ArenaBattle() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UGameInstance();
	WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection_NoRegister();

	ARENABATTLE_API class UClass* Z_Construct_UClass_UABGameInstance_NoRegister();
	ARENABATTLE_API class UClass* Z_Construct_UClass_UABGameInstance();
	ARENABATTLE_API class UPackage* Z_Construct_UPackage__Script_ArenaBattle();
	void UABGameInstance::StaticRegisterNativesUABGameInstance()
	{
	}
	UClass* Z_Construct_UClass_UABGameInstance_NoRegister()
	{
		return UABGameInstance::StaticClass();
	}
	UClass* Z_Construct_UClass_UABGameInstance()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UGameInstance();
			Z_Construct_UPackage__Script_ArenaBattle();
			OuterClass = UABGameInstance::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100088;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_WebConnection = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("WebConnection"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WebConnection, UABGameInstance), 0x0010000000000000, Z_Construct_UClass_UWebConnection_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<UABGameInstance> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ABGameInstance.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ABGameInstance.h"));
				MetaData->SetValue(NewProp_WebConnection, TEXT("ModuleRelativePath"), TEXT("ABGameInstance.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UABGameInstance, 1797125136);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UABGameInstance(Z_Construct_UClass_UABGameInstance, &UABGameInstance::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("UABGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABGameInstance);
	UPackage* Z_Construct_UPackage__Script_ArenaBattle()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/ArenaBattle")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x87B04DF6;
			Guid.B = 0x85524F5C;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
