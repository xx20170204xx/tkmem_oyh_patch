#include "stdafx.h"

#define DEBUG_LOG ("winnn.dll.txt")

HINSTANCE hLibMine;
HINSTANCE hLib;
FARPROC p[210];

/*
 * ◆関数名
 *   デバック出力用関数
 * ◆引数
 *   strFilename    ファイル名
 *   _format        書式指定文字列
 */
int dprintf( const char* strFilename, const char* _format , ... )
{
    // return 0;
    const int buf_size=256+1;
    char buf[buf_size];
    FILE* l_fp = NULL;
    
    memset(buf, 0, sizeof(buf));
    va_list ap;
    va_start( ap, _format );
    vsprintf_s(buf, sizeof(buf), _format, ap );
    va_end( ap );
    
    fopen_s( &l_fp, strFilename, "a+" );
    if( l_fp != NULL )
    {
        fprintf(l_fp, "%s", buf);
        fclose(l_fp);
    }else{
        return -1;
    }
    
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        hLibMine = hinstDLL;

        /* winmm.dll のパスを組み立てる */
        char strSysPath[MAX_PATH];
        char strDllPath[MAX_PATH];
        GetSystemDirectoryA(strSysPath, sizeof(strSysPath));
        sprintf_s(strDllPath, sizeof(strDllPath), "%s\\%s", strSysPath, "winmm.dll");
        dprintf( DEBUG_LOG, "DllPath:%s\n", strDllPath );
        
        /* dllをロードする */
        hLib = LoadLibraryA(strDllPath);
        if(!hLib){
            return FALSE;
        }

        p[0] = GetProcAddress(hLib, MAKEINTRESOURCEA(2));
        p[1] = GetProcAddress(hLib, (LPCSTR)"CloseDriver");
        p[2] = GetProcAddress(hLib, (LPCSTR)"DefDriverProc");
        p[3] = GetProcAddress(hLib, (LPCSTR)"DriverCallback");
        p[4] = GetProcAddress(hLib, (LPCSTR)"DrvGetModuleHandle");
        p[5] = GetProcAddress(hLib, (LPCSTR)"GetDriverModuleHandle");
        p[6] = GetProcAddress(hLib, (LPCSTR)"MigrateAllDrivers");
        p[7] = GetProcAddress(hLib, (LPCSTR)"MigrateSoundEvents");
        p[8] = GetProcAddress(hLib, (LPCSTR)"NotifyCallbackData");
        p[9] = GetProcAddress(hLib, (LPCSTR)"OpenDriver");
        p[10] = GetProcAddress(hLib, (LPCSTR)"PlaySound");
        p[11] = GetProcAddress(hLib, (LPCSTR)"PlaySoundA");
        p[12] = GetProcAddress(hLib, (LPCSTR)"PlaySoundW");
        p[13] = GetProcAddress(hLib, (LPCSTR)"SendDriverMessage");
        p[14] = GetProcAddress(hLib, (LPCSTR)"WOW32DriverCallback");
        p[15] = GetProcAddress(hLib, (LPCSTR)"WOW32ResolveMultiMediaHandle");
        p[16] = GetProcAddress(hLib, (LPCSTR)"WOWAppExit");
        p[17] = GetProcAddress(hLib, (LPCSTR)"WinmmLogoff");
        p[18] = GetProcAddress(hLib, (LPCSTR)"WinmmLogon");
        p[19] = GetProcAddress(hLib, (LPCSTR)"aux32Message");
        p[20] = GetProcAddress(hLib, (LPCSTR)"auxGetDevCapsA");
        p[21] = GetProcAddress(hLib, (LPCSTR)"auxGetDevCapsW");
        p[22] = GetProcAddress(hLib, (LPCSTR)"auxGetNumDevs");
        p[23] = GetProcAddress(hLib, (LPCSTR)"auxGetVolume");
        p[24] = GetProcAddress(hLib, (LPCSTR)"auxOutMessage");
        p[25] = GetProcAddress(hLib, (LPCSTR)"auxSetVolume");
        p[26] = GetProcAddress(hLib, (LPCSTR)"gfxAddGfx");
        p[27] = GetProcAddress(hLib, (LPCSTR)"gfxBatchChange");
        p[28] = GetProcAddress(hLib, (LPCSTR)"gfxCreateGfxFactoriesList");
        p[29] = GetProcAddress(hLib, (LPCSTR)"gfxCreateZoneFactoriesList");
        p[30] = GetProcAddress(hLib, (LPCSTR)"gfxDestroyDeviceInterfaceList");
        p[31] = GetProcAddress(hLib, (LPCSTR)"gfxEnumerateGfxs");
        p[32] = GetProcAddress(hLib, (LPCSTR)"_gfxLogoff@0");
        p[33] = GetProcAddress(hLib, (LPCSTR)"_gfxLogon@4");
        p[34] = GetProcAddress(hLib, (LPCSTR)"gfxModifyGfx");
        p[35] = GetProcAddress(hLib, (LPCSTR)"gfxOpenGfx");
        p[36] = GetProcAddress(hLib, (LPCSTR)"gfxRemoveGfx");
        p[37] = GetProcAddress(hLib, (LPCSTR)"joy32Message");
        p[38] = GetProcAddress(hLib, (LPCSTR)"joyConfigChanged");
        p[39] = GetProcAddress(hLib, (LPCSTR)"joyGetDevCapsA");
        p[40] = GetProcAddress(hLib, (LPCSTR)"joyGetDevCapsW");
        p[41] = GetProcAddress(hLib, (LPCSTR)"joyGetNumDevs");
        p[42] = GetProcAddress(hLib, (LPCSTR)"joyGetPos");
        p[43] = GetProcAddress(hLib, (LPCSTR)"joyGetPosEx");
        p[44] = GetProcAddress(hLib, (LPCSTR)"joyGetThreshold");
        p[45] = GetProcAddress(hLib, (LPCSTR)"joyReleaseCapture");
        p[46] = GetProcAddress(hLib, (LPCSTR)"joySetCapture");
        p[47] = GetProcAddress(hLib, (LPCSTR)"joySetThreshold");
        p[48] = GetProcAddress(hLib, (LPCSTR)"mci32Message");
        p[49] = GetProcAddress(hLib, (LPCSTR)"mciDriverNotify");
        p[50] = GetProcAddress(hLib, (LPCSTR)"mciDriverYield");
        p[51] = GetProcAddress(hLib, (LPCSTR)"mciExecute");
        p[52] = GetProcAddress(hLib, (LPCSTR)"mciFreeCommandResource");
        p[53] = GetProcAddress(hLib, (LPCSTR)"mciGetCreatorTask");
        p[54] = GetProcAddress(hLib, (LPCSTR)"mciGetDeviceIDA");
        p[55] = GetProcAddress(hLib, (LPCSTR)"mciGetDeviceIDFromElementIDA");
        p[56] = GetProcAddress(hLib, (LPCSTR)"mciGetDeviceIDFromElementIDW");
        p[57] = GetProcAddress(hLib, (LPCSTR)"mciGetDeviceIDW");
        p[58] = GetProcAddress(hLib, (LPCSTR)"mciGetDriverData");
        p[59] = GetProcAddress(hLib, (LPCSTR)"mciGetErrorStringA");
        p[60] = GetProcAddress(hLib, (LPCSTR)"mciGetErrorStringW");
        p[61] = GetProcAddress(hLib, (LPCSTR)"mciGetYieldProc");
        p[62] = GetProcAddress(hLib, (LPCSTR)"mciLoadCommandResource");
        p[63] = GetProcAddress(hLib, (LPCSTR)"mciSendCommandA");
        p[64] = GetProcAddress(hLib, (LPCSTR)"mciSendCommandW");
        p[65] = GetProcAddress(hLib, (LPCSTR)"mciSendStringA");
        p[66] = GetProcAddress(hLib, (LPCSTR)"mciSendStringW");
        p[67] = GetProcAddress(hLib, (LPCSTR)"mciSetDriverData");
        p[68] = GetProcAddress(hLib, (LPCSTR)"mciSetYieldProc");
        p[69] = GetProcAddress(hLib, (LPCSTR)"mid32Message");
        p[70] = GetProcAddress(hLib, (LPCSTR)"midiConnect");
        p[71] = GetProcAddress(hLib, (LPCSTR)"midiDisconnect");
        p[72] = GetProcAddress(hLib, (LPCSTR)"midiInAddBuffer");
        p[73] = GetProcAddress(hLib, (LPCSTR)"midiInClose");
        p[74] = GetProcAddress(hLib, (LPCSTR)"midiInGetDevCapsA");
        p[75] = GetProcAddress(hLib, (LPCSTR)"midiInGetDevCapsW");
        p[76] = GetProcAddress(hLib, (LPCSTR)"midiInGetErrorTextA");
        p[77] = GetProcAddress(hLib, (LPCSTR)"midiInGetErrorTextW");
        p[78] = GetProcAddress(hLib, (LPCSTR)"midiInGetID");
        p[79] = GetProcAddress(hLib, (LPCSTR)"midiInGetNumDevs");
        p[80] = GetProcAddress(hLib, (LPCSTR)"midiInMessage");
        p[81] = GetProcAddress(hLib, (LPCSTR)"midiInOpen");
        p[82] = GetProcAddress(hLib, (LPCSTR)"midiInPrepareHeader");
        p[83] = GetProcAddress(hLib, (LPCSTR)"midiInReset");
        p[84] = GetProcAddress(hLib, (LPCSTR)"midiInStart");
        p[85] = GetProcAddress(hLib, (LPCSTR)"midiInStop");
        p[86] = GetProcAddress(hLib, (LPCSTR)"midiInUnprepareHeader");
        p[87] = GetProcAddress(hLib, (LPCSTR)"midiOutCacheDrumPatches");
        p[88] = GetProcAddress(hLib, (LPCSTR)"midiOutCachePatches");
        p[89] = GetProcAddress(hLib, (LPCSTR)"midiOutClose");
        p[90] = GetProcAddress(hLib, (LPCSTR)"midiOutGetDevCapsA");
        p[91] = GetProcAddress(hLib, (LPCSTR)"midiOutGetDevCapsW");
        p[92] = GetProcAddress(hLib, (LPCSTR)"midiOutGetErrorTextA");
        p[93] = GetProcAddress(hLib, (LPCSTR)"midiOutGetErrorTextW");
        p[94] = GetProcAddress(hLib, (LPCSTR)"midiOutGetID");
        p[95] = GetProcAddress(hLib, (LPCSTR)"midiOutGetNumDevs");
        p[96] = GetProcAddress(hLib, (LPCSTR)"midiOutGetVolume");
        p[97] = GetProcAddress(hLib, (LPCSTR)"midiOutLongMsg");
        p[98] = GetProcAddress(hLib, (LPCSTR)"midiOutMessage");
        p[99] = GetProcAddress(hLib, (LPCSTR)"midiOutOpen");
        p[100] = GetProcAddress(hLib, (LPCSTR)"midiOutPrepareHeader");
        p[101] = GetProcAddress(hLib, (LPCSTR)"midiOutReset");
        p[102] = GetProcAddress(hLib, (LPCSTR)"midiOutSetVolume");
        p[103] = GetProcAddress(hLib, (LPCSTR)"midiOutShortMsg");
        p[104] = GetProcAddress(hLib, (LPCSTR)"midiOutUnprepareHeader");
        p[105] = GetProcAddress(hLib, (LPCSTR)"midiStreamClose");
        p[106] = GetProcAddress(hLib, (LPCSTR)"midiStreamOpen");
        p[107] = GetProcAddress(hLib, (LPCSTR)"midiStreamOut");
        p[108] = GetProcAddress(hLib, (LPCSTR)"midiStreamPause");
        p[109] = GetProcAddress(hLib, (LPCSTR)"midiStreamPosition");
        p[110] = GetProcAddress(hLib, (LPCSTR)"midiStreamProperty");
        p[111] = GetProcAddress(hLib, (LPCSTR)"midiStreamRestart");
        p[112] = GetProcAddress(hLib, (LPCSTR)"midiStreamStop");
        p[113] = GetProcAddress(hLib, (LPCSTR)"mixerClose");
        p[114] = GetProcAddress(hLib, (LPCSTR)"mixerGetControlDetailsA");
        p[115] = GetProcAddress(hLib, (LPCSTR)"mixerGetControlDetailsW");
        p[116] = GetProcAddress(hLib, (LPCSTR)"mixerGetDevCapsA");
        p[117] = GetProcAddress(hLib, (LPCSTR)"mixerGetDevCapsW");
        p[118] = GetProcAddress(hLib, (LPCSTR)"mixerGetID");
        p[119] = GetProcAddress(hLib, (LPCSTR)"mixerGetLineControlsA");
        p[120] = GetProcAddress(hLib, (LPCSTR)"mixerGetLineControlsW");
        p[121] = GetProcAddress(hLib, (LPCSTR)"mixerGetLineInfoA");
        p[122] = GetProcAddress(hLib, (LPCSTR)"mixerGetLineInfoW");
        p[123] = GetProcAddress(hLib, (LPCSTR)"mixerGetNumDevs");
        p[124] = GetProcAddress(hLib, (LPCSTR)"mixerMessage");
        p[125] = GetProcAddress(hLib, (LPCSTR)"mixerOpen");
        p[126] = GetProcAddress(hLib, (LPCSTR)"mixerSetControlDetails");
        p[127] = GetProcAddress(hLib, (LPCSTR)"mmDrvInstall");
        p[128] = GetProcAddress(hLib, (LPCSTR)"mmGetCurrentTask");
        p[129] = GetProcAddress(hLib, (LPCSTR)"mmTaskBlock");
        p[130] = GetProcAddress(hLib, (LPCSTR)"mmTaskCreate");
        p[131] = GetProcAddress(hLib, (LPCSTR)"mmTaskSignal");
        p[132] = GetProcAddress(hLib, (LPCSTR)"mmTaskYield");
        p[133] = GetProcAddress(hLib, (LPCSTR)"mmioAdvance");
        p[134] = GetProcAddress(hLib, (LPCSTR)"mmioAscend");
        p[135] = GetProcAddress(hLib, (LPCSTR)"mmioClose");
        p[136] = GetProcAddress(hLib, (LPCSTR)"mmioCreateChunk");
        p[137] = GetProcAddress(hLib, (LPCSTR)"mmioDescend");
        p[138] = GetProcAddress(hLib, (LPCSTR)"mmioFlush");
        p[139] = GetProcAddress(hLib, (LPCSTR)"mmioGetInfo");
        p[140] = GetProcAddress(hLib, (LPCSTR)"mmioInstallIOProcA");
        p[141] = GetProcAddress(hLib, (LPCSTR)"mmioInstallIOProcW");
        p[142] = GetProcAddress(hLib, (LPCSTR)"mmioOpenA");
        p[143] = GetProcAddress(hLib, (LPCSTR)"mmioOpenW");
        p[144] = GetProcAddress(hLib, (LPCSTR)"mmioRead");
        p[145] = GetProcAddress(hLib, (LPCSTR)"mmioRenameA");
        p[146] = GetProcAddress(hLib, (LPCSTR)"mmioRenameW");
        p[147] = GetProcAddress(hLib, (LPCSTR)"mmioSeek");
        p[148] = GetProcAddress(hLib, (LPCSTR)"mmioSendMessage");
        p[149] = GetProcAddress(hLib, (LPCSTR)"mmioSetBuffer");
        p[150] = GetProcAddress(hLib, (LPCSTR)"mmioSetInfo");
        p[151] = GetProcAddress(hLib, (LPCSTR)"mmioStringToFOURCCA");
        p[152] = GetProcAddress(hLib, (LPCSTR)"mmioStringToFOURCCW");
        p[153] = GetProcAddress(hLib, (LPCSTR)"mmioWrite");
        p[154] = GetProcAddress(hLib, (LPCSTR)"mmsystemGetVersion");
        p[155] = GetProcAddress(hLib, (LPCSTR)"mod32Message");
        p[156] = GetProcAddress(hLib, (LPCSTR)"mxd32Message");
        p[157] = GetProcAddress(hLib, (LPCSTR)"sndPlaySoundA");
        p[158] = GetProcAddress(hLib, (LPCSTR)"sndPlaySoundW");
        p[159] = GetProcAddress(hLib, (LPCSTR)"tid32Message");
        p[160] = GetProcAddress(hLib, (LPCSTR)"timeBeginPeriod");
        p[161] = GetProcAddress(hLib, (LPCSTR)"timeEndPeriod");
        p[162] = GetProcAddress(hLib, (LPCSTR)"timeGetDevCaps");
        p[163] = GetProcAddress(hLib, (LPCSTR)"timeGetSystemTime");
        p[164] = GetProcAddress(hLib, (LPCSTR)"timeGetTime");
        p[165] = GetProcAddress(hLib, (LPCSTR)"timeKillEvent");
        p[166] = GetProcAddress(hLib, (LPCSTR)"timeSetEvent");
        p[167] = GetProcAddress(hLib, (LPCSTR)"waveInAddBuffer");
        p[168] = GetProcAddress(hLib, (LPCSTR)"waveInClose");
        p[169] = GetProcAddress(hLib, (LPCSTR)"waveInGetDevCapsA");
        p[170] = GetProcAddress(hLib, (LPCSTR)"waveInGetDevCapsW");
        p[171] = GetProcAddress(hLib, (LPCSTR)"waveInGetErrorTextA");
        p[172] = GetProcAddress(hLib, (LPCSTR)"waveInGetErrorTextW");
        p[173] = GetProcAddress(hLib, (LPCSTR)"waveInGetID");
        p[174] = GetProcAddress(hLib, (LPCSTR)"waveInGetNumDevs");
        p[175] = GetProcAddress(hLib, (LPCSTR)"waveInGetPosition");
        p[176] = GetProcAddress(hLib, (LPCSTR)"waveInMessage");
        p[177] = GetProcAddress(hLib, (LPCSTR)"waveInOpen");
        p[178] = GetProcAddress(hLib, (LPCSTR)"waveInPrepareHeader");
        p[179] = GetProcAddress(hLib, (LPCSTR)"waveInReset");
        p[180] = GetProcAddress(hLib, (LPCSTR)"waveInStart");
        p[181] = GetProcAddress(hLib, (LPCSTR)"waveInStop");
        p[182] = GetProcAddress(hLib, (LPCSTR)"waveInUnprepareHeader");
        p[183] = GetProcAddress(hLib, (LPCSTR)"waveOutBreakLoop");
        p[184] = GetProcAddress(hLib, (LPCSTR)"waveOutClose");
        p[185] = GetProcAddress(hLib, (LPCSTR)"waveOutGetDevCapsA");
        p[186] = GetProcAddress(hLib, (LPCSTR)"waveOutGetDevCapsW");
        p[187] = GetProcAddress(hLib, (LPCSTR)"waveOutGetErrorTextA");
        p[188] = GetProcAddress(hLib, (LPCSTR)"waveOutGetErrorTextW");
        p[189] = GetProcAddress(hLib, (LPCSTR)"waveOutGetID");
        p[190] = GetProcAddress(hLib, (LPCSTR)"waveOutGetNumDevs");
        p[191] = GetProcAddress(hLib, (LPCSTR)"waveOutGetPitch");
        p[192] = GetProcAddress(hLib, (LPCSTR)"waveOutGetPlaybackRate");
        p[193] = GetProcAddress(hLib, (LPCSTR)"waveOutGetPosition");
        p[194] = GetProcAddress(hLib, (LPCSTR)"waveOutGetVolume");
        p[195] = GetProcAddress(hLib, (LPCSTR)"waveOutMessage");
        p[196] = GetProcAddress(hLib, (LPCSTR)"waveOutOpen");
        p[197] = GetProcAddress(hLib, (LPCSTR)"waveOutPause");
        p[198] = GetProcAddress(hLib, (LPCSTR)"waveOutPrepareHeader");
        p[199] = GetProcAddress(hLib, (LPCSTR)"waveOutReset");
        p[200] = GetProcAddress(hLib, (LPCSTR)"waveOutRestart");
        p[201] = GetProcAddress(hLib, (LPCSTR)"waveOutSetPitch");
        p[202] = GetProcAddress(hLib, (LPCSTR)"waveOutSetPlaybackRate");
        p[203] = GetProcAddress(hLib, (LPCSTR)"waveOutSetVolume");
        p[204] = GetProcAddress(hLib, (LPCSTR)"waveOutUnprepareHeader");
        p[205] = GetProcAddress(hLib, (LPCSTR)"waveOutWrite");
        p[206] = GetProcAddress(hLib, (LPCSTR)"wid32Message");
        p[207] = GetProcAddress(hLib, (LPCSTR)"winmmDbgOut");
        p[208] = GetProcAddress(hLib, (LPCSTR)"winmmSetDebugLevel");
        p[209] = GetProcAddress(hLib, (LPCSTR)"wod32Message");
    }
    else if (fdwReason == DLL_PROCESS_DETACH)
    {
        FreeLibrary(hLib);
        return TRUE;
    }

    return TRUE;
}

extern "C"
{
    __declspec( naked ) void WINAPI PROXY_NONAME0() {
        __asm { jmp p[0 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_CloseDriver() {
        __asm { jmp p[1 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_DefDriverProc() {
        __asm { jmp p[2 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_DriverCallback() {
        __asm { jmp p[3 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_DrvGetModuleHandle() {
        __asm { jmp p[4 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_GetDriverModuleHandle() {
        __asm { jmp p[5 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_MigrateAllDrivers() {
        __asm { jmp p[6 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_MigrateSoundEvents() {
        __asm { jmp p[7 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_NotifyCallbackData() {
        __asm { jmp p[8 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_OpenDriver() {
        __asm { jmp p[9 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_PlaySound() {
        __asm { jmp p[10 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_PlaySoundA() {
        __asm { jmp p[11 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_PlaySoundW() {
        __asm { jmp p[12 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_SendDriverMessage() {
        __asm { jmp p[13 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_WOW32DriverCallback() {
        __asm { jmp p[14 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_WOW32ResolveMultiMediaHandle() {
        __asm { jmp p[15 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_WOWAppExit() {
        __asm { jmp p[16 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_WinmmLogoff() {
        __asm { jmp p[17 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_WinmmLogon() {
        __asm { jmp p[18 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_aux32Message() {
        __asm { jmp p[19 * 4] }
    }
//  __declspec( naked ) void WINAPI PROXY_auxGetDevCapsA() {
//      __asm { jmp p[20 * 4] }
//  }
    __declspec( dllexport ) MMRESULT WINAPI PROXY_auxGetDevCapsA( UINT_PTR uDeviceID, LPAUXCAPSA lpCaps, UINT cbCaps ) {
        dprintf( DEBUG_LOG, "auxGetDevCapsA\n" );

        if( uDeviceID == AUX_MAPPER ){
            dprintf( DEBUG_LOG, "  uDeviceID : AUX_MAPPER\n" );
        }else{
            dprintf( DEBUG_LOG, "  uDeviceID : 0x%08x\n", uDeviceID );
        }

        dprintf( DEBUG_LOG, "  lpCaps : 0x%08x\n", lpCaps );
        dprintf( DEBUG_LOG, "  cbCaps : %d\n", cbCaps );


        MMRESULT lRet = auxGetDevCapsA(uDeviceID, lpCaps, cbCaps);

        dprintf( DEBUG_LOG, "(Return) %d\n", lRet );
        if( lRet == MMSYSERR_NOERROR )
        {
            // 戻り値が正常終了の場合、そのまま抜ける
            return lRet;
        }
        
        lRet = MMSYSERR_NOERROR;
        dprintf( DEBUG_LOG, "(Return-fixed) %d\n", lRet );
        if( lpCaps != NULL )
        {
            lpCaps->wTechnology = AUXCAPS_CDAUDIO;
            lpCaps->dwSupport = AUXCAPS_VOLUME;
            dprintf( DEBUG_LOG, "(Return-fixed) lpCaps->wTechnology：AUXCAPS_CDAUDIO\n" );
            dprintf( DEBUG_LOG, "(Return-fixed) lpCaps->dwSupport：AUXCAPS_VOLUME\n" );
        }

        return lRet ;
    }
    __declspec( naked ) void WINAPI PROXY_auxGetDevCapsW() {
        __asm { jmp p[21 * 4] }
    }
//  __declspec( naked ) void WINAPI PROXY_auxGetNumDevs() {
//      __asm { jmp p[22 * 4] }
//  }
    __declspec( dllexport ) UINT WINAPI PROXY_auxGetNumDevs() {
        dprintf( DEBUG_LOG, "auxGetNumDevs\n" );
        UINT lRet = auxGetNumDevs();

        dprintf( DEBUG_LOG, "(Return) %d\n", lRet );
        if( lRet != 0 )
        {
            // デバイスが存在する場合、そのまま抜ける
            return lRet;
        }

        lRet = 1;
        dprintf( DEBUG_LOG, "(Return-fixed) %d\n", lRet );

        return lRet;
    }
//  __declspec( naked ) void WINAPI PROXY_auxGetVolume() {
//      __asm { jmp p[23 * 4] }
//  }
    __declspec( dllexport ) MMRESULT WINAPI PROXY_auxGetVolume(UINT uDeviceID, LPDWORD pdwVolume) {
        dprintf( DEBUG_LOG, "auxGetVolume\n" );
        dprintf( DEBUG_LOG, "  uDeviceID:0x%08x\n", uDeviceID );

        MMRESULT lRet = auxGetVolume( uDeviceID, pdwVolume );
        dprintf( DEBUG_LOG, "(Return)0x%08x\n", lRet);
        dprintf( DEBUG_LOG, "(Return)pdwVolume=[0x%08x]\n", pdwVolume);
        if( pdwVolume != NULL ){
            dprintf( DEBUG_LOG, "(Return)*pdwVolume=[%d]\n", *pdwVolume);
        }

        if( lRet == MMSYSERR_NOERROR )
        {
            // 戻り値が正常終了の場合、そのまま抜ける
            return lRet;
        }

        lRet = MMSYSERR_NOERROR;
        dprintf( DEBUG_LOG, "(Return-fixed) %d\n", lRet );
        if( pdwVolume != NULL ){
            *pdwVolume = 0xFFFF;
            dprintf( DEBUG_LOG, "(Return-fixed)*pdwVolume=[%d]\n", *pdwVolume);
        }
        return lRet;
    }

    __declspec( naked ) void WINAPI PROXY_auxOutMessage() {
        __asm { jmp p[24 * 4] }
    }
//  __declspec( naked ) void WINAPI PROXY_auxSetVolume() {
//      __asm { jmp p[25 * 4] }
//  }
    __declspec( dllexport ) MMRESULT WINAPI PROXY_auxSetVolume(UINT uDeviceID, DWORD dwVolume) {
        dprintf( DEBUG_LOG, "auxSetVolume\n" );
        dprintf( DEBUG_LOG, "  uDeviceID:0x%08x\n", uDeviceID );
        dprintf( DEBUG_LOG, "  dwVolume:%d\n", dwVolume );

        MMRESULT lRet = auxSetVolume(uDeviceID, dwVolume);
        dprintf( DEBUG_LOG, "(Return)0x%08x\n", lRet);

        return lRet;
    }
    __declspec( naked ) void WINAPI PROXY_gfxAddGfx() {
        __asm { jmp p[26 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxBatchChange() {
        __asm { jmp p[27 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxCreateGfxFactoriesList() {
        __asm { jmp p[28 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxCreateZoneFactoriesList() {
        __asm { jmp p[29 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxDestroyDeviceInterfaceList() {
        __asm { jmp p[30 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxEnumerateGfxs() {
        __asm { jmp p[31 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY__gfxLogoff() {
        __asm { jmp p[32 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY__gfxLogon() {
        __asm { jmp p[33 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxModifyGfx() {
        __asm { jmp p[34 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxOpenGfx() {
        __asm { jmp p[35 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_gfxRemoveGfx() {
        __asm { jmp p[36 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joy32Message() {
        __asm { jmp p[37 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyConfigChanged() {
        __asm { jmp p[38 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyGetDevCapsA() {
        __asm { jmp p[39 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyGetDevCapsW() {
        __asm { jmp p[40 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyGetNumDevs() {
        __asm { jmp p[41 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyGetPos() {
        __asm { jmp p[42 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyGetPosEx() {
        __asm { jmp p[43 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyGetThreshold() {
        __asm { jmp p[44 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joyReleaseCapture() {
        __asm { jmp p[45 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joySetCapture() {
        __asm { jmp p[46 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_joySetThreshold() {
        __asm { jmp p[47 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mci32Message() {
        __asm { jmp p[48 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciDriverNotify() {
        __asm { jmp p[49 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciDriverYield() {
        __asm { jmp p[50 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciExecute() {
        __asm { jmp p[51 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciFreeCommandResource() {
        __asm { jmp p[52 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetCreatorTask() {
        __asm { jmp p[53 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetDeviceIDA() {
        __asm { jmp p[54 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetDeviceIDFromElementIDA() {
        __asm { jmp p[55 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetDeviceIDFromElementIDW() {
        __asm { jmp p[56 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetDeviceIDW() {
        __asm { jmp p[57 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetDriverData() {
        __asm { jmp p[58 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetErrorStringA() {
        __asm { jmp p[59 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetErrorStringW() {
        __asm { jmp p[60 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciGetYieldProc() {
        __asm { jmp p[61 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciLoadCommandResource() {
        __asm { jmp p[62 * 4] }
    }
#if defined(__COMMENT__)
    __declspec( naked ) void WINAPI PROXY_mciSendCommandA() {
        __asm { jmp p[63 * 4] }
    }
#else
    //__declspec( dllexport ) MCIERROR WINAPI PROXY_mciSendCommandA( MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2 );
    __declspec( dllexport ) MCIERROR WINAPI PROXY_mciSendCommandA( MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2 )
    {
        MCIERROR lMciError = 0;
        LPMCI_OPEN_PARMSA   lpOpenParam = NULL;
        LPMCI_SET_PARMS     lpSetParam = NULL;
        LPMCI_PLAY_PARMS    lpPlayParam = NULL;
        LPMCI_GENERIC_PARMS lpGenParam = NULL;
        LPMCI_STATUS_PARMS  lpStatusPara = NULL;

        OutputDebugString(_T("mciSendCommandA"));

        dprintf( DEBUG_LOG, "mciSendCommandA\n" );
        dprintf( DEBUG_LOG, "    mciId=0x%08x\n", mciId  );
        dprintf( DEBUG_LOG, "    uMsg=0x%08x\n", uMsg );

        if( uMsg == MCI_OPEN )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpOpenParam = (LPMCI_OPEN_PARMSA)dwParam2;

            dprintf( DEBUG_LOG, "    dwFlag=0x%08x\n", dwFlag );
            dprintf( DEBUG_LOG, "      dwCallback=0x%08x\n", lpOpenParam->dwCallback );
            dprintf( DEBUG_LOG, "      wDeviceID=0x%08x\n", (DWORD)lpOpenParam->wDeviceID );
//              fprintf( l_fp, "      lpstrDeviceType=%s\n", lpOpenParam->lpstrDeviceType );
            dprintf( DEBUG_LOG, "      lpstrElementName=%s\n", lpOpenParam->lpstrElementName );
            dprintf( DEBUG_LOG, "      lpstrAlias=%s\n", lpOpenParam->lpstrAlias );
        }
        if( uMsg == MCI_CLOSE )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpGenParam = (LPMCI_GENERIC_PARMS)dwParam2;

            dprintf( DEBUG_LOG,  "    dwFlag=0x%08x\n", dwFlag );
            dprintf( DEBUG_LOG,  "      dwCallback=0x%08x\n", lpGenParam->dwCallback );
        }
        if( uMsg == MCI_SET )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpSetParam = (LPMCI_SET_PARMS)dwParam2;
            dprintf( DEBUG_LOG,  "    dwFlag=0x%08x\n", dwFlag );
            dprintf( DEBUG_LOG,  "      dwAudio=0x%08x\n", lpSetParam->dwAudio );
            dprintf( DEBUG_LOG,  "      dwCallback=0x%08x\n", lpSetParam->dwCallback );
            dprintf( DEBUG_LOG,  "      dwTimeFormat=0x%08x\n", lpSetParam->dwTimeFormat );
        }
        if( uMsg == MCI_PLAY )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpPlayParam = (LPMCI_PLAY_PARMS)dwParam2;
            dprintf( DEBUG_LOG,  "    dwFlag=0x%08x\n", dwFlag );
            dprintf( DEBUG_LOG,  "      dwCallback=0x%08x\n", lpPlayParam->dwCallback );
            dprintf( DEBUG_LOG,  "      dwFrom=0x%08x\n", lpPlayParam->dwFrom );
            dprintf( DEBUG_LOG,  "      dwTo=0x%08x\n", lpPlayParam->dwTo );
        }
        if( uMsg == MCI_STOP )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpGenParam = (LPMCI_GENERIC_PARMS)dwParam2;

            dprintf( DEBUG_LOG,  "    dwFlag=0x%08x\n", dwFlag );
            dprintf( DEBUG_LOG,  "      dwCallback=0x%08x\n", lpGenParam->dwCallback );
        }
        if( uMsg == MCI_STATUS )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpStatusPara = (LPMCI_STATUS_PARMS)dwParam2;

            dprintf( DEBUG_LOG, "    dwFlag=0x%08x\n", dwFlag );
            dprintf( DEBUG_LOG, "      dwCallback=0x%08x\n", lpStatusPara->dwCallback );
            dprintf( DEBUG_LOG, "      dwItem=0x%08x\n", lpStatusPara->dwItem );
            dprintf( DEBUG_LOG, "      dwReturn=0x%08x\n", lpStatusPara->dwReturn );
            dprintf( DEBUG_LOG, "      dwTrack=0x%08x\n", lpStatusPara->dwTrack );
        }

        lMciError = mciSendCommandA(mciId, uMsg, dwParam1, dwParam2 );

        if( lMciError != 0 )
        {
            char lpBuf[256];
            mciGetErrorStringA(lMciError, (LPSTR)lpBuf, sizeof(lpBuf) );
            dprintf( DEBUG_LOG, "[0x%08x]%s\n", lMciError, lpBuf);
        }else{
            dprintf( DEBUG_LOG, "[0x%08x]\n", 0);
        }

        /* MCI_SET かつ 異常が返った場合 */
        if( uMsg == MCI_SET && lMciError != 0 )
        {
            DWORD dwFlag = 0x00000402;
            /* dwFlag が設定する値と同じ場合、エラー終了する */
            if( dwParam1 == dwFlag )
            {
                return lMciError;
            }
            /* パラメータを修正して再度実行 */
            dwParam1 = dwFlag;
            dprintf( DEBUG_LOG,  "fix dwFlag=0x%08x\n", dwParam1 );
            lMciError = PROXY_mciSendCommandA(mciId, uMsg, dwParam1, dwParam2 );
        }
        if( uMsg == MCI_OPEN )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpOpenParam = (LPMCI_OPEN_PARMSA)dwParam2;
            dprintf( DEBUG_LOG, "(Return)wDeviceID=0x%08x\n", (DWORD)lpOpenParam->wDeviceID );
        }
        if( uMsg == MCI_STATUS )
        {
            DWORD dwFlag = (DWORD)dwParam1;
            lpStatusPara = (LPMCI_STATUS_PARMS)dwParam2;

            dprintf( DEBUG_LOG, "(Return)dwCallback=0x%08x\n", lpStatusPara->dwCallback );
            dprintf( DEBUG_LOG, "(Return)dwItem=0x%08x\n", lpStatusPara->dwItem );
            dprintf( DEBUG_LOG, "(Return)dwReturn=0x%08x\n", lpStatusPara->dwReturn );
            dprintf( DEBUG_LOG, "(Return)dwTrack=0x%08x\n", lpStatusPara->dwTrack );
        }

        return lMciError;
    }
#endif
    __declspec( naked ) void WINAPI PROXY_mciSendCommandW() {
        __asm { jmp p[64 * 4] }
    }
#if defined(__COMMENT__)
    __declspec( naked ) void WINAPI PROXY_mciSendStringA() {
        __asm { jmp p[65 * 4] }
    }
#else
    __declspec( dllexport ) MCIERROR WINAPI PROXY_mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLen, HWND hWnd )
    {
        MCIERROR lMciError = 0;
        dprintf( DEBUG_LOG, "mciSendStringA\n" );
        dprintf( DEBUG_LOG, "  Command=[%s]\n", lpstrCommand );
        dprintf( DEBUG_LOG, "  hWnd=[0x%08x]\n", hWnd );
        lMciError = mciSendStringA(lpstrCommand, lpstrReturnString, uReturnLen, hWnd );
        if( lMciError != 0 )
        {
            char lpBuf[256];
            mciGetErrorStringA(lMciError, (LPSTR)lpBuf, sizeof(lpBuf) );
            dprintf( DEBUG_LOG, "[0x%08x]%s\n", lMciError, lpBuf);
        }else{
            dprintf( DEBUG_LOG, "[0x%08x]\n", 0);
        }

        return lMciError;
    }
#endif

    __declspec( naked ) void WINAPI PROXY_mciSendStringW() {
        __asm { jmp p[66 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciSetDriverData() {
        __asm { jmp p[67 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mciSetYieldProc() {
        __asm { jmp p[68 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mid32Message() {
        __asm { jmp p[69 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiConnect() {
        __asm { jmp p[70 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiDisconnect() {
        __asm { jmp p[71 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInAddBuffer() {
        __asm { jmp p[72 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInClose() {
        __asm { jmp p[73 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInGetDevCapsA() {
        __asm { jmp p[74 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInGetDevCapsW() {
        __asm { jmp p[75 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInGetErrorTextA() {
        __asm { jmp p[76 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInGetErrorTextW() {
        __asm { jmp p[77 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInGetID() {
        __asm { jmp p[78 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInGetNumDevs() {
        __asm { jmp p[79 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInMessage() {
        __asm { jmp p[80 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInOpen() {
        __asm { jmp p[81 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInPrepareHeader() {
        __asm { jmp p[82 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInReset() {
        __asm { jmp p[83 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInStart() {
        __asm { jmp p[84 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInStop() {
        __asm { jmp p[85 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiInUnprepareHeader() {
        __asm { jmp p[86 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutCacheDrumPatches() {
        __asm { jmp p[87 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutCachePatches() {
        __asm { jmp p[88 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutClose() {
        __asm { jmp p[89 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetDevCapsA() {
        __asm { jmp p[90 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetDevCapsW() {
        __asm { jmp p[91 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetErrorTextA() {
        __asm { jmp p[92 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetErrorTextW() {
        __asm { jmp p[93 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetID() {
        __asm { jmp p[94 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetNumDevs() {
        __asm { jmp p[95 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutGetVolume() {
        __asm { jmp p[96 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutLongMsg() {
        __asm { jmp p[97 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutMessage() {
        __asm { jmp p[98 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutOpen() {
        __asm { jmp p[99 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutPrepareHeader() {
        __asm { jmp p[100 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutReset() {
        __asm { jmp p[101 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutSetVolume() {
        __asm { jmp p[102 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutShortMsg() {
        __asm { jmp p[103 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiOutUnprepareHeader() {
        __asm { jmp p[104 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamClose() {
        __asm { jmp p[105 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamOpen() {
        __asm { jmp p[106 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamOut() {
        __asm { jmp p[107 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamPause() {
        __asm { jmp p[108 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamPosition() {
        __asm { jmp p[109 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamProperty() {
        __asm { jmp p[110 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamRestart() {
        __asm { jmp p[111 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_midiStreamStop() {
        __asm { jmp p[112 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerClose() {
        __asm { jmp p[113 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetControlDetailsA() {
        __asm { jmp p[114 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetControlDetailsW() {
        __asm { jmp p[115 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetDevCapsA() {
        __asm { jmp p[116 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetDevCapsW() {
        __asm { jmp p[117 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetID() {
        __asm { jmp p[118 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetLineControlsA() {
        __asm { jmp p[119 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetLineControlsW() {
        __asm { jmp p[120 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetLineInfoA() {
        __asm { jmp p[121 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetLineInfoW() {
        __asm { jmp p[122 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerGetNumDevs() {
        __asm { jmp p[123 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerMessage() {
        __asm { jmp p[124 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerOpen() {
        __asm { jmp p[125 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mixerSetControlDetails() {
        __asm { jmp p[126 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmDrvInstall() {
        __asm { jmp p[127 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmGetCurrentTask() {
        __asm { jmp p[128 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmTaskBlock() {
        __asm { jmp p[129 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmTaskCreate() {
        __asm { jmp p[130 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmTaskSignal() {
        __asm { jmp p[131 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmTaskYield() {
        __asm { jmp p[132 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioAdvance() {
        __asm { jmp p[133 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioAscend() {
        __asm { jmp p[134 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioClose() {
        __asm { jmp p[135 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioCreateChunk() {
        __asm { jmp p[136 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioDescend() {
        __asm { jmp p[137 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioFlush() {
        __asm { jmp p[138 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioGetInfo() {
        __asm { jmp p[139 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioInstallIOProcA() {
        __asm { jmp p[140 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioInstallIOProcW() {
        __asm { jmp p[141 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioOpenA() {
        __asm { jmp p[142 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioOpenW() {
        __asm { jmp p[143 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioRead() {
        __asm { jmp p[144 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioRenameA() {
        __asm { jmp p[145 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioRenameW() {
        __asm { jmp p[146 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioSeek() {
        __asm { jmp p[147 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioSendMessage() {
        __asm { jmp p[148 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioSetBuffer() {
        __asm { jmp p[149 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioSetInfo() {
        __asm { jmp p[150 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioStringToFOURCCA() {
        __asm { jmp p[151 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioStringToFOURCCW() {
        __asm { jmp p[152 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmioWrite() {
        __asm { jmp p[153 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mmsystemGetVersion() {
        __asm { jmp p[154 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mod32Message() {
        __asm { jmp p[155 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_mxd32Message() {
        __asm { jmp p[156 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_sndPlaySoundA() {
        __asm { jmp p[157 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_sndPlaySoundW() {
        __asm { jmp p[158 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_tid32Message() {
        __asm { jmp p[159 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeBeginPeriod() {
        __asm { jmp p[160 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeEndPeriod() {
        __asm { jmp p[161 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeGetDevCaps() {
        __asm { jmp p[162 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeGetSystemTime() {
        __asm { jmp p[163 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeGetTime() {
        __asm { jmp p[164 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeKillEvent() {
        __asm { jmp p[165 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_timeSetEvent() {
        __asm { jmp p[166 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInAddBuffer() {
        __asm { jmp p[167 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInClose() {
        __asm { jmp p[168 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetDevCapsA() {
        __asm { jmp p[169 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetDevCapsW() {
        __asm { jmp p[170 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetErrorTextA() {
        __asm { jmp p[171 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetErrorTextW() {
        __asm { jmp p[172 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetID() {
        __asm { jmp p[173 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetNumDevs() {
        __asm { jmp p[174 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInGetPosition() {
        __asm { jmp p[175 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInMessage() {
        __asm { jmp p[176 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInOpen() {
        __asm { jmp p[177 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInPrepareHeader() {
        __asm { jmp p[178 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInReset() {
        __asm { jmp p[179 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInStart() {
        __asm { jmp p[180 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInStop() {
        __asm { jmp p[181 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveInUnprepareHeader() {
        __asm { jmp p[182 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutBreakLoop() {
        __asm { jmp p[183 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutClose() {
        __asm { jmp p[184 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetDevCapsA() {
        __asm { jmp p[185 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetDevCapsW() {
        __asm { jmp p[186 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetErrorTextA() {
        __asm { jmp p[187 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetErrorTextW() {
        __asm { jmp p[188 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetID() {
        __asm { jmp p[189 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetNumDevs() {
        __asm { jmp p[190 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetPitch() {
        __asm { jmp p[191 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetPlaybackRate() {
        __asm { jmp p[192 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetPosition() {
        __asm { jmp p[193 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutGetVolume() {
        __asm { jmp p[194 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutMessage() {
        __asm { jmp p[195 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutOpen() {
        __asm { jmp p[196 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutPause() {
        __asm { jmp p[197 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutPrepareHeader() {
        __asm { jmp p[198 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutReset() {
        __asm { jmp p[199 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutRestart() {
        __asm { jmp p[200 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutSetPitch() {
        __asm { jmp p[201 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutSetPlaybackRate() {
        __asm { jmp p[202 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutSetVolume() {
        __asm { jmp p[203 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutUnprepareHeader() {
        __asm { jmp p[204 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_waveOutWrite() {
        __asm { jmp p[205 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_wid32Message() {
        __asm { jmp p[206 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_winmmDbgOut() {
        __asm { jmp p[207 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_winmmSetDebugLevel() {
        __asm { jmp p[208 * 4] }
    }
    __declspec( naked ) void WINAPI PROXY_wod32Message() {
        __asm { jmp p[209 * 4] }
    }
}
