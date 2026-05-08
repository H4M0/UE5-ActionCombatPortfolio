// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionCombatGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeActionCombatGameMode() {}

// ********** Begin Cross Module References ********************************************************
ACTIONCOMBAT_API UClass* Z_Construct_UClass_AActionCombatGameMode();
ACTIONCOMBAT_API UClass* Z_Construct_UClass_AActionCombatGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_ActionCombat();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AActionCombatGameMode ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AActionCombatGameMode;
UClass* AActionCombatGameMode::GetPrivateStaticClass()
{
	using TClass = AActionCombatGameMode;
	if (!Z_Registration_Info_UClass_AActionCombatGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ActionCombatGameMode"),
			Z_Registration_Info_UClass_AActionCombatGameMode.InnerSingleton,
			StaticRegisterNativesAActionCombatGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AActionCombatGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AActionCombatGameMode_NoRegister()
{
	return AActionCombatGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AActionCombatGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ActionCombatGameMode.h" },
		{ "ModuleRelativePath", "ActionCombatGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AActionCombatGameMode constinit property declarations ********************
// ********** End Class AActionCombatGameMode constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActionCombatGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AActionCombatGameMode_Statics
UObject* (*const Z_Construct_UClass_AActionCombatGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ActionCombat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActionCombatGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AActionCombatGameMode_Statics::ClassParams = {
	&AActionCombatGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AActionCombatGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AActionCombatGameMode_Statics::Class_MetaDataParams)
};
void AActionCombatGameMode::StaticRegisterNativesAActionCombatGameMode()
{
}
UClass* Z_Construct_UClass_AActionCombatGameMode()
{
	if (!Z_Registration_Info_UClass_AActionCombatGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActionCombatGameMode.OuterSingleton, Z_Construct_UClass_AActionCombatGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AActionCombatGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AActionCombatGameMode);
AActionCombatGameMode::~AActionCombatGameMode() {}
// ********** End Class AActionCombatGameMode ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatGameMode_h__Script_ActionCombat_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActionCombatGameMode, AActionCombatGameMode::StaticClass, TEXT("AActionCombatGameMode"), &Z_Registration_Info_UClass_AActionCombatGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActionCombatGameMode), 3269276129U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatGameMode_h__Script_ActionCombat_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatGameMode_h__Script_ActionCombat_2653564508{
	TEXT("/Script/ActionCombat"),
	Z_CompiledInDeferFile_FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatGameMode_h__Script_ActionCombat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Desktop_Project_UE5_ActionCombatPortfolio_ActionCombat_Source_ActionCombat_ActionCombatGameMode_h__Script_ActionCombat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
