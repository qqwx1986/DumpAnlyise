// Copyright Epic Games, Inc. All Rights Reserved.

#include "DumpAnlyiseApp.h"
#include "Windows/WindowsHWrapper.h"
#include "HAL/PlatformProcess.h"


/**
 * WinMain, called when the application is started
 */
int WINAPI WinMain(_In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow)
{
	RunDumpAnlyise(GetCommandLineW());
	RequestEngineExit(TEXT("normal"));
	return 0;
}
