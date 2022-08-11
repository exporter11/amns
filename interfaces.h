#pragma once
#include "sdk.h"

typedef void*(__cdecl* fnCreateInterface)(const char*, int*);

void* get_interface(const char* dll_name, const char* interfacename) {
	fnCreateInterface getinfc = (fnCreateInterface)GetProcAddress(GetModuleHandle(dll_name), "CreateInterface");
	int rtn = 0;
	return getinfc(interfacename, &rtn);
}

namespace interfaces {
	i_engine_client* p_engine = 0;
	chl_client* p_chl_client = 0;
	i_client_mode** p_clientmode = 0;
	i_entity_list* p_entitylist = 0;

	void setup() {
		p_engine = (i_engine_client*)get_interface("engine.dll", "VEngineClient014");
		p_chl_client = (chl_client*)get_interface("client.dll", "VClient018");
		p_entitylist = (i_entity_list*)get_interface("client.dll", "VClientEntityList003");
		//clmode sshit
		auto basevmt = *(void***)p_chl_client;
		p_clientmode = *(i_client_mode***)((DWORD)basevmt[10] + 5);
		//end


	}

	
};
