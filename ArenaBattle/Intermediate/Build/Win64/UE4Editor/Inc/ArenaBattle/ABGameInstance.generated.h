// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABGameInstance_generated_h
#error "ABGameInstance.generated.h already included, missing '#pragma once' in ABGameInstance.h"
#endif
#define ARENABATTLE_ABGameInstance_generated_h

#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCheckUObjectAlive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CheckUObjectAlive(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRequestTokenComplete) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RequestTokenComplete(Z_Param_Token); \
		P_NATIVE_END; \
	}


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCheckUObjectAlive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CheckUObjectAlive(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRequestTokenComplete) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Token); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RequestTokenComplete(Z_Param_Token); \
		P_NATIVE_END; \
	}


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABGameInstance(); \
	friend ARENABATTLE_API class UClass* Z_Construct_UClass_UABGameInstance(); \
public: \
	DECLARE_CLASS(UABGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABGameInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUABGameInstance(); \
	friend ARENABATTLE_API class UClass* Z_Construct_UClass_UABGameInstance(); \
public: \
	DECLARE_CLASS(UABGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABGameInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABGameInstance(UABGameInstance&&); \
	NO_API UABGameInstance(const UABGameInstance&); \
public:


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABGameInstance(UABGameInstance&&); \
	NO_API UABGameInstance(const UABGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABGameInstance)


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_PRIVATE_PROPERTY_OFFSET
#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_21_PROLOG
#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_RPC_WRAPPERS \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_INCLASS \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_INCLASS_NO_PURE_DECLS \
	ArenaBattle_Source_ArenaBattle_ABGameInstance_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ArenaBattle_Source_ArenaBattle_ABGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
