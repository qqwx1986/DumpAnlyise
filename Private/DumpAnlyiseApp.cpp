// Copyright Epic Games, Inc. All Rights Reserved.

#include "DumpAnlyiseApp.h"

#include "CrashDebugHelper.h"
#include "CrashDebugHelperModule.h"
#include "DumpAnlyiseDefines.h"
#include "Misc/CommandLine.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/App.h"
#include "Modules/ModuleManager.h"
#include "HAL/PlatformProcess.h"

#include "Async/TaskGraphInterfaces.h"

#if CRASH_REPORT_WITH_MTBF
#include "EditorAnalyticsSession.h"
#include "EditorSessionSummarySender.h"
#endif
TCHAR GInternalProjectName[64] = TEXT("");
const TCHAR *GForeignEngineDir = nullptr;
int RunDumpAnlyise(const TCHAR* CommandLine)
{
	FCommandLine::Set(CommandLine);
	FCrashDebugHelperModule& CrashHelperModule = FModuleManager::LoadModuleChecked<FCrashDebugHelperModule>( FName( "CrashDebugHelper" ) );
	ICrashDebugHelper* Helper = CrashHelperModule.Get();
	if(Helper)
	{
		FString MiniDump;
		if (!FParse::Value(FCommandLine::Get(), TEXT("MiniDump="), MiniDump))
		{
			return -1;
		}
		Helper->CreateMinidumpDiagnosticReport(MiniDump);

		printf("exception %ls\n",*		Helper->CrashInfo.Exception.ExceptionString);
		TArray<FString> CallStack = Helper->CrashInfo.Exception.CallStackString;
		for(int i=0;i<CallStack.Num();i++)
		{
			printf("CallStack[%d]  %ls\n",i,*CallStack[i]);
		}
	}
	FModuleManager::Get().UnloadModulesAtShutdown();
	return 0;
}
