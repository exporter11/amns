#include "aimbot.h"

bool caimbot::do_aimbot(cbase_player* p_local, i_entity_list* p_entitylist, CUserCmd* p_cmd) {
	if (!GetAsyncKeyState(VK_MENU))
		return false;

	cbase_player* p_target = nullptr;
	float minfov = 99999;
	for (int i = 1; i <= 64; i++) {

		cbase_player* p_entity = p_entitylist->get_client_entity(i);

		if (!p_entity || p_entity->m_lifeState != 0 || p_entity->m_iTeamNum == p_local->m_iTeamNum || p_entity == p_local)
			continue;

		
		QAngle angle_to_enemy;
		angle_to_enemy.angle_from_vector((p_entity->m_vecOrigin + p_entity->m_vecViewOffset) - (p_local->m_vecOrigin + p_local->m_vecViewOffset));
		angle_to_enemy =  angle_to_enemy - p_cmd->viewangles;
		angle_to_enemy.clamp();
		angle_to_enemy.abs(true);

		float fov = angle_to_enemy.fov();

		if (fov < minfov)
		{
			minfov = fov;
			p_target = p_entity;
		}
	}

	if (!p_target)
		return false;


	i_client_unknown* icunk = p_entitylist->get_client_unknown_from_handle(p_target->m_hObserverTarget);

	std::cout << icunk << '\n';

	QAngle angle_to_enemy;
	angle_to_enemy.angle_from_vector((p_target->m_vecOrigin + p_target->m_vecViewOffset) - (p_local->m_vecOrigin + p_local->m_vecViewOffset));

	p_cmd->viewangles = angle_to_enemy;
	p_cmd->buttons |= IN_ATTACK;

	return true;
}