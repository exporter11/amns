#include "hook.h"
#include "interfaces.h"
#include "misc.h"
#include "aimbot.h"


using namespace interfaces;

void hook(void* p_class, DWORD functionreplacer, int method, void** p_ogfunc) {
	DWORD vtable = *(DWORD*)p_class;
	DWORD* p_vtablefunc = (DWORD*)(vtable + method * 0x4);

	//there is a chance that virtual function will get called right after replacing the address so we edit the original here before we replace it 
	if (p_ogfunc)
		*p_ogfunc = (void*)*p_vtablefunc;

	DWORD op = 0;
	VirtualProtect((void*)p_vtablefunc, sizeof(void*), PAGE_EXECUTE_READWRITE, &op);
	*p_vtablefunc = functionreplacer;
	VirtualProtect((void*)p_vtablefunc, sizeof(void*), op, &op);	  
}


typedef bool(__thiscall* fncreate_move)(void*, float, CUserCmd*);
fncreate_move ogcreate_move = 0;


bool __fastcall hkcreate_move(void* ecx, void*, float frametime, CUserCmd* p_cmd) {

	if (!p_cmd || !p_cmd->command_number)
		return true;

	if (p_engine->is_connected() && p_engine->is_in_game()) {
		cbase_player* p_local = p_entitylist->get_client_entity(p_engine->get_local_player());

		cmisc misc;
		misc.bunnyhop(p_local, p_cmd);

		caimbot aimbot;
		aimbot.do_aimbot(p_local, p_entitylist, p_cmd);

	}

	return false;
}

void setup_hooks() {
	interfaces::setup();

	hook(*(void***)interfaces::p_clientmode, (DWORD)&hkcreate_move, 24,  (void**)&ogcreate_move);
	ogcreate_move = ogcreate_move;
}
void delete_hooks() {

	hook(*(void***)interfaces::p_clientmode, (DWORD)ogcreate_move, 24, nullptr);
};