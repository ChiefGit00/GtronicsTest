// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GamitronicsTest : ModuleRules
{
	public GamitronicsTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PrivateIncludePaths.AddRange (new string[] { "GamitronicsTest", "GamitronicsTest/Gameplay", "GamitronicsTest/Actors" });
		PrivateIncludePaths.AddRange(new string[] { "Runtime/UMG/Public/UMG.h", "Runtime/UMG/Public/UMGStyle.h", "Runtime/UMG/Public/Blueprint/UserWidget.h", "Runtime/UMG/Public/Slate/SObjectWidget.h", "Runtime/UMG/Public/IUMGModule.h" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
