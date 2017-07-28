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

	WEBSERVICE_API class UFunction* Z_Construct_UDelegateFunction_WebService_TokenCompleteSignature__DelegateSignature();
	WEBSERVICE_API class UFunction* Z_Construct_UFunction_UWebConnection_RequestToken();
	WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection_NoRegister();
	WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection();
	WEBSERVICE_API class UPackage* Z_Construct_UPackage__Script_WebService();
	UFunction* Z_Construct_UDelegateFunction_WebService_TokenCompleteSignature__DelegateSignature()
	{
		struct _Script_WebService_eventTokenCompleteSignature_Parms
		{
			FString Token;
		};
		UObject* Outer=Z_Construct_UPackage__Script_WebService();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("TokenCompleteSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), NULL, 0x00130000, 65535, sizeof(_Script_WebService_eventTokenCompleteSignature_Parms));
			UProperty* NewProp_Token = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Token"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Token, _Script_WebService_eventTokenCompleteSignature_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("DECLARE_DELEGATE_OneParam(FTokenCompleteSignature, const FString&);"));
			MetaData->SetValue(NewProp_Token, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
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
		struct WebConnection_eventRequestToken_Parms
		{
			FString UserID;
		};
		UObject* Outer=Z_Construct_UClass_UWebConnection();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RequestToken"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535, sizeof(WebConnection_eventRequestToken_Parms));
			UProperty* NewProp_UserID = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("UserID"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(UserID, WebConnection_eventRequestToken_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
			MetaData->SetValue(NewProp_UserID, TEXT("NativeConst"), TEXT(""));
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
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_UWebConnection_RequestToken());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_TokenCompleteDelegate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TokenCompleteDelegate"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(TokenCompleteDelegate, UWebConnection), 0x0010000010080000, Z_Construct_UDelegateFunction_WebService_TokenCompleteSignature__DelegateSignature());
				UProperty* NewProp_URI = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("URI"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(URI, UWebConnection), 0x0010000000000000);
				UProperty* NewProp_Host = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Host"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Host, UWebConnection), 0x0010000000000000);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWebConnection_RequestToken(), "RequestToken"); // 802113267
				static TCppClassTypeInfo<TCppClassTypeTraits<UWebConnection> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("WebConnection.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
				MetaData->SetValue(NewProp_TokenCompleteDelegate, TEXT("Category"), TEXT("WebService"));
				MetaData->SetValue(NewProp_TokenCompleteDelegate, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
				MetaData->SetValue(NewProp_URI, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
				MetaData->SetValue(NewProp_Host, TEXT("ModuleRelativePath"), TEXT("Classes/WebConnection.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWebConnection, 67021696);
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
			Guid.A = 0xFD02C10B;
			Guid.B = 0xFA269120;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

			Z_Construct_UDelegateFunction_WebService_TokenCompleteSignature__DelegateSignature();
		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
