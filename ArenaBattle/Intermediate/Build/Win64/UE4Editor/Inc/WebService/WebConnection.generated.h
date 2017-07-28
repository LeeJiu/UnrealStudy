// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WEBSERVICE_WebConnection_generated_h
#error "WebConnection.generated.h already included, missing '#pragma once' in WebConnection.h"
#endif
#define WEBSERVICE_WebConnection_generated_h

#define ArenaBattle_Source_WebService_Classes_WebConnection_h_11_DELEGATE \
struct _Script_WebService_eventTokenCompleteSignature_Parms \
{ \
	FString Token; \
}; \
static inline void FTokenCompleteSignature_DelegateWrapper(const FMulticastScriptDelegate& TokenCompleteSignature, const FString& Token) \
{ \
	_Script_WebService_eventTokenCompleteSignature_Parms Parms; \
	Parms.Token=Token; \
	TokenCompleteSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRequestToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RequestToken(Z_Param_UserID); \
		P_NATIVE_END; \
	}


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRequestToken) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_UserID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RequestToken(Z_Param_UserID); \
		P_NATIVE_END; \
	}


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebConnection(); \
	friend WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection(); \
public: \
	DECLARE_CLASS(UWebConnection, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebService"), NO_API) \
	DECLARE_SERIALIZER(UWebConnection) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUWebConnection(); \
	friend WEBSERVICE_API class UClass* Z_Construct_UClass_UWebConnection(); \
public: \
	DECLARE_CLASS(UWebConnection, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/WebService"), NO_API) \
	DECLARE_SERIALIZER(UWebConnection) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebConnection(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebConnection) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebConnection); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebConnection); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebConnection(UWebConnection&&); \
	NO_API UWebConnection(const UWebConnection&); \
public:


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebConnection(UWebConnection&&); \
	NO_API UWebConnection(const UWebConnection&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebConnection); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebConnection); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWebConnection)


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_PRIVATE_PROPERTY_OFFSET
#define ArenaBattle_Source_WebService_Classes_WebConnection_h_16_PROLOG
#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_RPC_WRAPPERS \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_INCLASS \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ArenaBattle_Source_WebService_Classes_WebConnection_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_INCLASS_NO_PURE_DECLS \
	ArenaBattle_Source_WebService_Classes_WebConnection_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ArenaBattle_Source_WebService_Classes_WebConnection_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
