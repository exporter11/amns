#pragma once
#include <Windows.h>
#include "math.h"

#define FL_ONGROUND  (1 << 0)
#define FL_DUCKING  (1 << 1)
#define FL_ANIMDUCKING  (1 << 2)
#define FL_WATERJUMP  (1 << 3)
#define FL_ONTRAIN  (1 << 4)
#define FL_INRAIN  (1 << 5)
#define FL_FROZEN  (1 << 6)
#define FL_ATCONTROLS  (1 << 7)
#define FL_CLIENT  (1 << 8)
#define FL_FAKECLIENT  (1 << 9)
#define FL_INWATER  (1 << 10)
#define FL_FLY  (1 << 11)
#define FL_SWIM  (1 << 12)
#define FL_CONVEYOR  (1 << 13)
#define FL_NPC  (1 << 14)
#define FL_GODMODE  (1 << 15)
#define FL_NOTARGET  (1 << 16)
#define FL_AIMTARGET  (1 << 17)
#define FL_PARTIALGROUND  (1 << 18)
#define FL_STATICPROP  (1 << 19)
#define FL_GRAPHED  (1 << 20)
#define FL_GRENADE  (1 << 21)
#define FL_STEPMOVEMENT  (1 << 22)
#define FL_DONTTOUCH  (1 << 23),
#define FL_BASEVELOCITY  (1 << 24),
#define FL_WORLDBRUSH  (1 << 25)
#define FL_OBJECT  (1 << 26)
#define FL_KILLME  (1 << 27)
#define FL_ONFIRE  (1 << 28)
#define FL_DISSOLVING  (1 << 29)
#define FL_TRANSRAGDOLL  (1 << 30)
#define FL_UNBLOCKABLE_BY_PLAYER  (1 << 31)


class cbase_player
{
public:
	char pad_0000[60]; //0x0000
	float time; //0x003C
	char pad_0040[84]; //0x0040
	Vector m_vecVelocity; //0x0094
	Vector m_vecOrigin; //0x00A0
	char pad_00AC[72]; //0x00AC
	int m_iTeamNum; //0x00F4
	int m_iPendingTeamNum; //0x00F8
	char pad_00FC[4]; //0x00FC
	int m_iHealth; //0x0100
	int m_fFlags; //0x0104
	Vector m_vecViewOffset; //0x0108
	char pad_0114[24]; //0x0114
	QAngle m_angRotation; //0x012C
	char pad_0138[288]; //0x0138
	int m_nModelIndex; //0x0258
	char pad_025C[3]; //0x025C
	__int8 m_lifeState; //0x025F
	char pad_0260[11612]; //0x0260
	float m_flDuckAmount; //0x2FBC
	float m_flDuckSpeed; //0x2FC0
	char pad_2FC4[72]; //0x2FC4
	int in_thing; //0x300C
	char pad_3010[888]; //0x3010
	int m_iObserverMode; //0x3388
	char pad_338C[16]; //0x338C
	int* m_hObserverTarget; //0x339C
	char pad_33A0[548]; //0x33A0
	char m_szLastPlaceName[18]; //0x35C4
	char pad_35D6[6818]; //0x35D6
};

class i_entity_list
{
public:
	virtual void* get_client_net(int entnum) = 0;
	virtual void* get_client_net_from_handle(void* hEnt) = 0;
	virtual void* get_client_unknown_from_handle(void* hEnt) = 0;
	virtual cbase_player* get_client_entity(int entnum) = 0;
};

