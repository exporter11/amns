#include "i_engine_client.h"
void i_engine_client::get_screen_size(int& w, int& h) {
	typedef void(__thiscall* func)(void*, int&, int&);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 5;
	ofunc = (func)*funcadd;

	ofunc(this, w, h);
}
bool i_engine_client::get_player_info(int ent_num, player_info_t* pinfo) {
	typedef bool(__thiscall* func)(void*, int, player_info_t*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 5;
	ofunc = (func)*funcadd;

	return ofunc(this, ent_num, pinfo);
}
int i_engine_client::get_local_player() {
	typedef int(__thiscall* func)(void*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 12;
	ofunc = (func)*funcadd;

	return ofunc(this);
}
void i_engine_client::get_viewangles(QAngle& va) {
	typedef void(__thiscall* func)(void*, QAngle&);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 18;
	ofunc = (func)*funcadd;

	ofunc(this, va);
}
void i_engine_client::set_viewangles(QAngle& va) {
	typedef void(__thiscall* func)(void*, QAngle&);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 19;
	ofunc = (func)*funcadd;

	ofunc(this, va);
}
bool i_engine_client::is_in_game() {
	typedef bool(__thiscall* func)(void*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 26;
	ofunc = (func)*funcadd;

	return ofunc(this);
}
bool i_engine_client::is_connected() {
	typedef bool(__thiscall* func)(void*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 27;
	ofunc = (func)*funcadd;

	return ofunc(this);
}
const char* i_engine_client::get_level_name() {
	typedef const char* (__thiscall* func)(void*);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 53;
	ofunc = (func)*funcadd;

	return ofunc(this);
}