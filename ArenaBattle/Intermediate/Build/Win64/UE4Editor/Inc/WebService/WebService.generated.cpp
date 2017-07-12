// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "WebService.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1WebService() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject();

	WEBSERVICE_API class UFunction* Z_Construct_UFunction_UWebConnection_RequestToken();
	WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection_NoRegister();
	WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection();
	WEBSERVICE_API class UPackage* Z_Construct_UPackage__Script_WebService();
	void UWebConnection::StaticRegisterNativesUWebConnection()
	{
		UClass* Class = UWebConnection::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "RequestToken", (Native)&UWebConnection::execRequestToken },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 1);
	}
	UFunction* Z_Construct_UFunction_UWebConnection_RequestToken()
	{
		UObject* Outer=Z_Construct_UClass_UWebConnection();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RequestToken"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWebConnection_NoRegister()
	{
		return UWebConnection::StaticClass();
	}
	UClass* Z_Construct_UClass_UWebConnection()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_WebService();
			OuterClass = UWebConnection::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100080;

				OuterClass->LinkChild(Z_Construct_UFunction_UWebConnection_RequestToken());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_URI = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("URI"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(URI, UWebConnection), 0x0010000000000000);
				UProperty* NewProp_Host = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Host"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Host, UWebConnection), 0x0010000000000000);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWebConnection_RequestToken(), "RequestToken"); // 4207259791
				static TCppClassTypeInfo<TCppClassTypeTraits<UWebConnection> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("WebConnection.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
				MetaData->SetValue(NewProp_URI, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
				MetaData->SetValue(NewProp_Host, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWebConnection, 3851824600);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWebConnection(Z_Construct_UClass_UWebConnection, &UWebConnection::StaticClass, TEXT("/Script/WebService"), TEXT("UWebConnection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWebConnection);
	UPackage* Z_Construct_UPackage__Script_WebService()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/WebService")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x1B39A916;
			Guid.B = 0x50954B33;
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
