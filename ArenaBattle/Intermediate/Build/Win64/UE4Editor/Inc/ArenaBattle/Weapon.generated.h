// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_Weapon_generated_h
#error "Weapon.generated.h already included, missing '#pragma once' in Weapon.h"
#endif
#define ARENABATTLE_Weapon_generated_h

#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDamage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetDamage(); \
		P_NATIVE_END; \
	}


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDamage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetDamage(); \
		P_NATIVE_END; \
	}


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWeapon(); \
	friend ARENABATTLE_API class UClass* Z_Construct_UClass_AWeapon(); \
public: \
	DECLARE_CLASS(AWeapon, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AWeapon) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAWeapon(); \
	friend ARENABATTLE_API class UClass* Z_Construct_UClass_AWeapon(); \
public: \
	DECLARE_CLASS(AWeapon, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AWeapon) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWeapon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeapon(AWeapon&&); \
	NO_API AWeapon(const AWeapon&); \
public:


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeapon(AWeapon&&); \
	NO_API AWeapon(const AWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWeapon)


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BaseDamage() { return STRUCT_OFFSET(AWeapon, BaseDamage); }


#define ArenaBattle_Source_ArenaBattle_Weapon_h_9_PROLOG
#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_RPC_WRAPPERS \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_INCLASS \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ArenaBattle_Source_ArenaBattle_Weapon_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_INCLASS_NO_PURE_DECLS \
	ArenaBattle_Source_ArenaBattle_Weapon_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ArenaBattle_Source_ArenaBattle_Weapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
