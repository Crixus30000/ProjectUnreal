// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Hack_n_Slash_Project : ModuleRules
{
	public Hack_n_Slash_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GameplayTasks", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
