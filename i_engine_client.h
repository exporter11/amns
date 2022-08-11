#pragma once
#include <Windows.h>
#include "math.h"
typedef struct player_info_s
{
	__int64			version;
	__int64			xuid;
	char			name[32];
	int				userID;
	char			guid[33];
	int			friendsID;
	char			friendsName[32];
	bool			fakeplayer;
	bool			ishltv;
	int			customFiles[4];
	unsigned char	filesDownloaded;
} player_info_t;


class i_engine_client {
public:
	void get_screen_size(int& w, int& h);
	bool get_player_info(int ent_num, player_info_t* pinfo);
	int get_local_player();
	void get_viewangles(QAngle& va);
	void set_viewangles(QAngle& va);
	bool is_in_game();
	bool is_connected();
	const char* get_level_name();
};