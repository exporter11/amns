#include "misc.h"

void cmisc::bunnyhop(cbase_player* p_local, CUserCmd* p_cmd) {
	if (p_local->m_lifeState != 0)
		return;
	
	if (p_cmd->buttons & IN_JUMP && !(p_local->m_fFlags & FL_ONGROUND))
			p_cmd->buttons &= ~IN_JUMP;
}