#include "chl_client.h"

void chl_client::activate_mouse() {
	typedef void(__thiscall* func)(void*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 16;
	ofunc = (func)*funcadd;

	ofunc(this);
}
void chl_client::deactivate_mouse() {
	typedef void(__thiscall* func)(void*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 17;
	ofunc = (func)*funcadd;

	ofunc(this);
}