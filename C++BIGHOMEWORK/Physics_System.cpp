#include "Physics_System.h"

Physics_System::Physics_System(player* p1,bool** Pmap,int** Amap)
{

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			static_obstacle_map[i % 1000][j % 400]= Pmap[i % 1000][j % 400];
		}
	}
	
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			static_attack_map[i % 1000][j % 400] = Amap[i % 1000][j % 400];
		}
	}



	this->m_PLAYER = p1;
}

Physics_System::Physics_System(player* p1, bool** Pmap)
{

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			static_obstacle_map[i % 1000][j % 400] = Pmap[i % 1000][j % 400];
		}
	}


	this->m_PLAYER = p1;
}

void Physics_System::Player_NPC_script_Do()                           //NPC对象在脚本中调用volocity_do函数
{
	this->m_PLAYER->P_script();

	this->m_PLAYER->RIGBODY->volocity_DO();

	for (vector<GameObject*>::iterator ptr = this->m_PLAYER->GameObject_list.begin(); ptr < this->m_PLAYER->GameObject_list.end(); ptr++)
	{
		(*ptr)->contoller->Do_script();
	}
}

void Physics_System::SET()
{

	/////////场景1的静态obstacle/////////取余是因为防止对象卡出地图导致的写入bug
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			this->phy_map[i % 1000][j % 400] = this->static_obstacle_map[i % 1000][j % 400];
		}
	}

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			phy_mapA[i % 1000][j % 400] = this->static_attack_map[i%1000][j%400];
		}
	}

	for (int i = (int)this->m_PLAYER->position_x + this->m_PLAYER->COLLISION->collision_picture1.x; i < (int)this->m_PLAYER->position_x + this->m_PLAYER->COLLISION->collision_picture2.x; i++)
	{
		for (int j = this->m_PLAYER->position_y + this->m_PLAYER->COLLISION->collision_picture1.y; j < this->m_PLAYER->position_y + this->m_PLAYER->COLLISION->collision_picture2.y; j++)
		{

			if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入
			this->phy_map[i % 1000][j % 400] = 1;
		}

	}

	for (vector<GameObject*>::iterator ptr = this->m_PLAYER->GameObject_list.begin(); ptr < this->m_PLAYER->GameObject_list.end(); ptr++)
	{
		if ((*ptr)->tag == "obstacle"&&(*ptr)->COLLISION->active==1)
		{
			for (int i = (int)(*ptr)->position_x + (*ptr)->COLLISION->collision_picture1.x; i < (int)(*ptr)->position_x + (*ptr)->COLLISION->collision_picture2.x; i++)
			{
				for (int j = (*ptr)->position_y + (*ptr)->COLLISION->collision_picture1.y; j < (*ptr)->position_y + (*ptr)->COLLISION->collision_picture2.y; j++)
				{

					if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入
					this->phy_map[i % 1000][j % 400] = 1;
				}

			}
		}
		else if ((*ptr)->tag == "attack" && (*ptr)->COLLISION->active == 1 && (*ptr)->health>0)
		{
			for (int i = (int)(*ptr)->position_x + (*ptr)->COLLISION->collision_picture1.x-5; i < (int)(*ptr)->position_x + (*ptr)->COLLISION->collision_picture2.x+5; i++)
			{
				for (int j = (*ptr)->position_y + (*ptr)->COLLISION->collision_picture1.y; j < (*ptr)->position_y + (*ptr)->COLLISION->collision_picture2.y+2; j++)
				{
					if (i > 0 && i < 1000 && j>0 && (j +2)< 400)                                //保护程序不溢出写入
						this->phy_mapA[i%1000][j % 400] = 2;
				}

			}
		}
		

	}
}