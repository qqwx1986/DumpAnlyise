// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DumpAnlyise : ModuleRules
{
	public DumpAnlyise(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.AddRange
		(
			new string[] 
			{ 
				"Runtime/Launch/Public",
				"Programs/DumpAnlyise/Private",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] 
			{
				"Core",
				"CoreUObject",
				"CrashReportCore",
			}
		);

		PublicDependencyModuleNames.Add("CrashDebugHelper");

		PrivateIncludePaths.Add("Runtime/Launch/Private");		// For LaunchEngineLoop.cpp include
	}
}
