#pragma once
///////collis��Ҫ����Physics_System��Gameobject��������
#include<vector>
#include<string>
#include"zuobiao.h"
using namespace std;




class GameObject;
class Physics_System;
class zuobiao;
class collision
{
public:
	/// <summary>
	/// ֻ�����ptr_collision_picture��ָ����
	///  collision_picture������Ҫ��ÿ��������ʵ��
	/// </summary>
	collision(GameObject* Duixiang, string tagc, Physics_System* PHY_);
	
	GameObject* duixiang; 
	

	bool active;                 //������ײ��
	string collision_tag;         //��ײ���ǩ

	int On_attack_collision();         //�ܵ�����

	bool On_obstacle_collision_B();  //���ϰ�
	bool On_obstacle_collision_F();  //ǰ���ϰ�
	bool On_obstacle_collision_D();  //�·��ϰ���û���ϰ���rig_gravity
	bool On_obstacle_collision_U();

	zuobiao collision_picture1;      // ��һ������ģ����ײ�� ���Ͻ����λ��
	zuobiao collision_picture2;       //// ��һ������ģ����ײ�� ���½����λ�� 
private:
	Physics_System* PHY;
};


