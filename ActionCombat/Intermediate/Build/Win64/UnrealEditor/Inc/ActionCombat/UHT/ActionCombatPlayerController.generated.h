// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActionCombatPlayerController.h"

#ifdef ACTIONCOMBAT_ActionCombatPlayerController_generated_h
#error "ActionCombatPlayerController.generated.h already included, missing '#pragma once' in ActionCombatPlayerController.h"
#endif
#define ACTIONCOMBAT_ActionCombatPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AActionCombatPlayerController ********************************************
struct Z_Construct_UClass_AActionCombatPlayerController_Statics;
ACTIONCOMBAT_API UClass* Z_Construct_UClass_AActionCombatPlayerController_NoRegister();

#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAActionCombatPlayerController(); \
	friend struct ::Z_Construct_UClass_AActionCombatPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ACTIONCOMBAT_API UClass* ::Z_Construct_UClass_AActionCombatPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AActionCombatPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ActionCombat"), Z_Construct_UClass_AActionCombatPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AActionCombatPlayerController)


#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AActionCombatPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AActionCombatPlayerController(AActionCombatPlayerController&&) = delete; \
	AActionCombatPlayerController(const AActionCombatPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AActionCombatPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AActionCombatPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AActionCombatPlayerController) \
	NO_API virtual ~AActionCombatPlayerController();


#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h_16_PROLOG
#define FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AActionCombatPlayerController;

// ********** End Class AActionCombatPlayerController **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
