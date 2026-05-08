// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActionCombatCharacter.h"

#ifdef ACTIONCOMBAT_ActionCombatCharacter_generated_h
#error "ActionCombatCharacter.generated.h already included, missing '#pragma once' in ActionCombatCharacter.h"
#endif
#define ACTIONCOMBAT_ActionCombatCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AActionCombatCharacter ***************************************************
#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


struct Z_Construct_UClass_AActionCombatCharacter_Statics;
ACTIONCOMBAT_API UClass* Z_Construct_UClass_AActionCombatCharacter_NoRegister();

#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAActionCombatCharacter(); \
	friend struct ::Z_Construct_UClass_AActionCombatCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ACTIONCOMBAT_API UClass* ::Z_Construct_UClass_AActionCombatCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AActionCombatCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ActionCombat"), Z_Construct_UClass_AActionCombatCharacter_NoRegister) \
	DECLARE_SERIALIZER(AActionCombatCharacter)


#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AActionCombatCharacter(AActionCombatCharacter&&) = delete; \
	AActionCombatCharacter(const AActionCombatCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AActionCombatCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AActionCombatCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AActionCombatCharacter) \
	NO_API virtual ~AActionCombatCharacter();


#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_21_PROLOG
#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AActionCombatCharacter;

// ********** End Class AActionCombatCharacter *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
