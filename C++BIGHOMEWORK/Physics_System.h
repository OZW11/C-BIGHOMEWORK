#pragma once
#include"player.h"


/// <summary>
/// 物理对象存储在PLAYER上
/// 此类的主要功能为调用所有物理对象中  script  的controller
/// 这些函数会将物理信息输出到map上   
/// </summary>
class Physics_System
{
public:
	Physics_System(player* p1, bool** Pmap, int**Amap);
	
	Physics_System(player* p1, bool** Pmap);

	void Player_NPC_script_Do();

	void SET();
	 
	bool phy_map[1000][400];                    /// map是一个int[1000][400]的表，如值为0则无碰撞体 为1有obstacle_collision， 为2有attack_collision  3为有player attack

	int phy_mapA[1000][400];                    

private:
	player* m_PLAYER;
	const int box_length=32;

	bool static_obstacle_map[1000][400];       //存储静态ob物理体

	int static_attack_map[1000][400];



};

