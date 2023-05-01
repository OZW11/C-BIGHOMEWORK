#pragma once
#include"player.h"


/// <summary>
/// �������洢��PLAYER��
/// �������Ҫ����Ϊ�����������������  script  ��controller
/// ��Щ�����Ὣ������Ϣ�����map��   
/// </summary>
class Physics_System
{
public:
	Physics_System(player* p1, bool** Pmap, int**Amap);
	
	Physics_System(player* p1, bool** Pmap);

	void Player_NPC_script_Do();

	void SET();
	 
	bool phy_map[1000][400];                    /// map��һ��int[1000][400]�ı���ֵΪ0������ײ�� Ϊ1��obstacle_collision�� Ϊ2��attack_collision  3Ϊ��player attack

	int phy_mapA[1000][400];                    

private:
	player* m_PLAYER;
	const int box_length=32;

	bool static_obstacle_map[1000][400];       //�洢��̬ob������

	int static_attack_map[1000][400];



};

