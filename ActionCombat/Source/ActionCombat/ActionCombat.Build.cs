// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ActionCombat : ModuleRules
{
	public ActionCombat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ActionCombat",
			"ActionCombat/Variant_Platforming",
			"ActionCombat/Variant_Platforming/Animation",
			"ActionCombat/Variant_Combat",
			"ActionCombat/Variant_Combat/AI",
			"ActionCombat/Variant_Combat/Animation",
			"ActionCombat/Variant_Combat/Gameplay",
			"ActionCombat/Variant_Combat/Interfaces",
			"ActionCombat/Variant_Combat/UI",
			"ActionCombat/Variant_SideScrolling",
			"ActionCombat/Variant_SideScrolling/AI",
			"ActionCombat/Variant_SideScrolling/Gameplay",
			"ActionCombat/Variant_SideScrolling/Interfaces",
			"ActionCombat/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
