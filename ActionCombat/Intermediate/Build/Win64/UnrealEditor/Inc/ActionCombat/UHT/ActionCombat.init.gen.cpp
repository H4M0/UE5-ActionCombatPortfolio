// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActionCombat_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	ACTIONCOMBAT_API UFunction* Z_Construct_UDelegateFunction_ActionCombat_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ActionCombat;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ActionCombat()
	{
		if (!Z_Registration_Info_UPackage__Script_ActionCombat.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_ActionCombat_OnEnemyDied__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ActionCombat",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x9EEE9023,
			0xBC3D29A9,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ActionCombat.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ActionCombat.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ActionCombat(Z_Construct_UPackage__Script_ActionCombat, TEXT("/Script/ActionCombat"), Z_Registration_Info_UPackage__Script_ActionCombat, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x9EEE9023, 0xBC3D29A9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
