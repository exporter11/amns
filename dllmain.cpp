#include <Windows.h>
#include <iostream>
#include "hook.h"

DWORD WINAPI setup(HMODULE hModule) {
    FILE* f;
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);

    setup_hooks();
    while (!GetAsyncKeyState(VK_END) & 1);
    delete_hooks();

    if (f)
        fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        HANDLE h_thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)setup, hModule, 0, 0);
        if (h_thread)
            CloseHandle(h_thread);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

