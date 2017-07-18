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
	ENGINE_API class UClass* Z_Construct_UClass_APawn();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FStringAssetReference();
	ENGINE_API class UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();

	ARENABATTLE_API class UClass* Z_Construct_UClass_UABGameInstance_NoRegister();
	ARENABATTLE_API class UClass* Z_Construct_UClass_UABGameInstance();
	ARENABATTLE_API class UClass* Z_Construct_UClass_AABPawn_NoRegister();
	ARENABATTLE_API class UClass* Z_Construct_UClass_AABPawn();
	ARENABATTLE_API class UFunction* Z_Construct_UFunction_AWeapon_GetDamage();
	ARENABATTLE_API class UClass* Z_Construct_UClass_AWeapon_NoRegister();
	ARENABATTLE_API class UClass* Z_Construct_UClass_AWeapon();
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
				UProperty* NewProp_WebConnectionNew = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("WebConnectionNew"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WebConnectionNew, UABGameInstance), 0x0010000000000000, Z_Construct_UClass_UWebConnection_NoRegister());
				UProperty* NewProp_WebConnection = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("WebConnection"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WebConnection, UABGameInstance), 0x0010000000000000, Z_Construct_UClass_UWebConnection_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<UABGameInstance> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ABGameInstance.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ABGameInstance.h"));
				MetaData->SetValue(NewProp_WebConnectionNew, TEXT("ModuleRelativePath"), TEXT("ABGameInstance.h"));
				MetaData->SetValue(NewProp_WebConnection, TEXT("ModuleRelativePath"), TEXT("ABGameInstance.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UABGameInstance, 2346761646);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UABGameInstance(Z_Construct_UClass_UABGameInstance, &UABGameInstance::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("UABGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABGameInstance);
	void AABPawn::StaticRegisterNativesAABPawn()
	{
	}
	UClass* Z_Construct_UClass_AABPawn_NoRegister()
	{
		return AABPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_AABPawn()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage__Script_ArenaBattle();
			OuterClass = AABPawn::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900084;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_CharacterAssets = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CharacterAssets"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(CharacterAssets, AABPawn), 0x0040000000004000);
				UProperty* NewProp_CharacterAssets_Inner = new(EC_InternalUseOnlyConstructor, NewProp_CharacterAssets, TEXT("CharacterAssets"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000004000, Z_Construct_UScriptStruct_FStringAssetReference());
				UProperty* NewProp_CurrentHP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentHP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(CurrentHP, AABPawn), 0x0010000000000805);
				UProperty* NewProp_MaxHP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MaxHP"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MaxHP, AABPawn), 0x0010000000014005);
				UProperty* NewProp_Camera = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Camera"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Camera, AABPawn), 0x00100000000a001d, Z_Construct_UClass_UCameraComponent_NoRegister());
				UProperty* NewProp_SpringArm = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SpringArm"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(SpringArm, AABPawn), 0x00100000000a001d, Z_Construct_UClass_USpringArmComponent_NoRegister());
				UProperty* NewProp_Arrow = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Arrow"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Arrow, AABPawn), 0x00100000000a001d, Z_Construct_UClass_UArrowComponent_NoRegister());
				UProperty* NewProp_Mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Mesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Mesh, AABPawn), 0x00100000000a001d, Z_Construct_UClass_USkeletalMeshComponent_NoRegister());
				UProperty* NewProp_Body = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Body"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Body, AABPawn), 0x00100000000a001d, Z_Construct_UClass_UCapsuleComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AABPawn> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("ini \xd30c\xc77c\xc744 \xc77d\xc5b4\xc624\xae30 \xc704\xd574 / \xac8c\xc784 \xb85c\xc9c1 = DefaultGame / \xc5d4\xc9c4 = DefaultEngine"));
				MetaData->SetValue(NewProp_CharacterAssets, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_CharacterAssets, TEXT("ToolTip"), TEXT("FStringAssetReference : \xc5d0\xc14b \xc815\xbcf4 / \xc18c\xd504\xd2b8 \xb808\xd37c\xb7f0\xc2f1"));
				MetaData->SetValue(NewProp_CurrentHP, TEXT("Category"), TEXT("Stat"));
				MetaData->SetValue(NewProp_CurrentHP, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_CurrentHP, TEXT("ToolTip"), TEXT("\xc778\xc2a4\xd134\xc2a4\xb9c8\xb2e4 \xb2e4\xb978 \xac12\xc744 \xac00\xc9c8 \xc218 \xc788\xb2e4."));
				MetaData->SetValue(NewProp_MaxHP, TEXT("Category"), TEXT("Stat"));
				MetaData->SetValue(NewProp_MaxHP, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_MaxHP, TEXT("ToolTip"), TEXT("\xd3f0\xb4e4\xc774 \xacf5\xd1b5\xc801\xc778 \xac12\xc744 \xac00\xc9c4\xb2e4."));
				MetaData->SetValue(NewProp_Camera, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_Camera, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Camera, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_Camera, TEXT("ToolTip"), TEXT("\xd3f0\xc5d0 \xbe59\xc758\xd55c \xd50c\xb808\xc774\xc5b4\xc758 \xd654\xba74\xc744 \xb80c\xb354\xb9c1\xd560 \xce74\xba54\xb77c \xcef4\xd3ec\xb10c\xd2b8"));
				MetaData->SetValue(NewProp_SpringArm, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_SpringArm, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_SpringArm, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_SpringArm, TEXT("ToolTip"), TEXT("\xce74\xba54\xb77c \xad6c\xb3c4\xb97c \xc27d\xac8c \xc138\xd305\xd560 \xc218 \xc788\xac8c \xc81c\xacf5\xd558\xb294 \xcef4\xd3ec\xb10c\xd2b8"));
				MetaData->SetValue(NewProp_Arrow, TEXT("Category"), TEXT("Helper"));
				MetaData->SetValue(NewProp_Arrow, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Arrow, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_Arrow, TEXT("ToolTip"), TEXT("\xc2dc\xc120 \xbc29\xd5a5\xc744 \xac00\xb9ac\xd0a4\xb294 \xcef4\xd3ec\xb10c\xd2b8"));
				MetaData->SetValue(NewProp_Mesh, TEXT("Category"), TEXT("Visual"));
				MetaData->SetValue(NewProp_Mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Mesh, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_Mesh, TEXT("ToolTip"), TEXT("\xc778\xac04\xd615 \xd3f0\xc758 \xc678\xd615\xc744 \xb2f4\xb2f9\xd558\xb294 \xcef4\xd3ec\xb10c\xd2b8"));
				MetaData->SetValue(NewProp_Body, TEXT("Category"), TEXT("Collision"));
				MetaData->SetValue(NewProp_Body, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Body, TEXT("ModuleRelativePath"), TEXT("ABPawn.h"));
				MetaData->SetValue(NewProp_Body, TEXT("ToolTip"), TEXT("\xc778\xac04\xd615 \xd3f0\xc758 \xcda9\xb3cc\xacfc \xc774\xb3d9\xc744 \xad00\xb9ac\xd558\xb294 \xb8e8\xd2b8 \xcef4\xd3ec\xb10c\xd2b8"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AABPawn, 3656361945);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AABPawn(Z_Construct_UClass_AABPawn, &AABPawn::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AABPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABPawn);
	void AWeapon::StaticRegisterNativesAWeapon()
	{
		UClass* Class = AWeapon::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetDamage", (Native)&AWeapon::execGetDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 1);
	}
	UFunction* Z_Construct_UFunction_AWeapon_GetDamage()
	{
		struct Weapon_eventGetDamage_Parms
		{
			float ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_AWeapon();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(Weapon_eventGetDamage_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, Weapon_eventGetDamage_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Weapon|Stat"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Weapon.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\xbe14\xb8e8 \xd504\xb9b0\xd2b8\xc5d0\xc11c \xc77d\xae30/\xc4f0\xae30 \xac00\xb2a5 / \xc778\xc2a4\xd134\xc2a4\xb9c8\xb2e4 \xb2e4\xb974\xac8c \xd3b8\xc9d1 \xac00\xb2a5 / \xce74\xd14c\xace0\xb9ac \xc124\xc815\nUPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = \"Stat\")\nfloat BaseDamage;"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AWeapon_NoRegister()
	{
		return AWeapon::StaticClass();
	}
	UClass* Z_Construct_UClass_AWeapon()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_ArenaBattle();
			OuterClass = AWeapon::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AWeapon_GetDamage());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_BaseDamage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BaseDamage, AWeapon), 0x0040000000010005);
				UProperty* NewProp_Weapon = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Weapon"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Weapon, AWeapon), 0x00100000000a001d, Z_Construct_UClass_USkeletalMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AWeapon_GetDamage(), "GetDamage"); // 3912758340
				static TCppClassTypeInfo<TCppClassTypeTraits<AWeapon> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Weapon.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Weapon.h"));
				MetaData->SetValue(NewProp_BaseDamage, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_BaseDamage, TEXT("Category"), TEXT("Stat"));
				MetaData->SetValue(NewProp_BaseDamage, TEXT("ModuleRelativePath"), TEXT("Weapon.h"));
				MetaData->SetValue(NewProp_BaseDamage, TEXT("ToolTip"), TEXT("AllowPrivateAccess : private \xba64\xbc84 \xbcc0\xc218\xb3c4 \xbe14\xb8e8\xd504\xb9b0\xd2b8 \xc2a4\xd06c\xb9bd\xd2b8\xc5d0\xc11c \xc0ac\xc6a9 \xac00\xb2a5"));
				MetaData->SetValue(NewProp_Weapon, TEXT("Category"), TEXT("Weapon"));
				MetaData->SetValue(NewProp_Weapon, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Weapon, TEXT("ModuleRelativePath"), TEXT("Weapon.h"));
				MetaData->SetValue(NewProp_Weapon, TEXT("ToolTip"), TEXT("\xbe14\xb8e8 \xd504\xb9b0\xd2b8\xc5d0\xc11c \xc77d\xae30\xb9cc \xac00\xb2a5\n\xba54\xc2dc\xb97c \xc800\xc7a5 / \xba54\xc2dc\xb97c \xbcc0\xacbd \xac00\xb2a5\xd558\xac8c \xd558\xba74 \xd06c\xb798\xc2dc \xbc1c\xc0dd"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWeapon, 2981020584);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWeapon(Z_Construct_UClass_AWeapon, &AWeapon::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AWeapon"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWeapon);
	UPackage* Z_Construct_UPackage__Script_ArenaBattle()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/ArenaBattle")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x905145E7;
			Guid.B = 0xF40A08C2;
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
