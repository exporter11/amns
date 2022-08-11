#include "entity.h"

bool i_client_renderable::SetupBones(matrix3_4* pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime) {
	typedef bool(__thiscall* func)(void*, matrix3_4*, int, int, float);
	func ofunc = 0;
	DWORD* funcadd = (DWORD*)*(DWORD*)this + 13;
	ofunc = (func)*funcadd;

	return ofunc(this, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
}