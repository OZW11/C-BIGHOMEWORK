#pragma once
///////collis类要能与Physics_System、Gameobject发生交互
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
	/// 只完成了ptr_collision_picture的指向工作
	///  collision_picture的内容要在每个子类中实现
	/// </summary>
	collision(GameObject* Duixiang, string tagc, Physics_System* PHY_);
	
	GameObject* duixiang; 
	

	bool active;                 //激活碰撞体
	string collision_tag;         //碰撞体标签

	int On_attack_collision();         //受到攻击

	bool On_obstacle_collision_B();  //后方障碍
	bool On_obstacle_collision_F();  //前方障碍
	bool On_obstacle_collision_D();  //下方障碍，没有障碍则rig_gravity
	bool On_obstacle_collision_U();

	zuobiao collision_picture1;      // 用一个矩形模拟碰撞体 左上角相对位置
	zuobiao collision_picture2;       //// 用一个矩形模拟碰撞体 右下角相对位置 
private:
	Physics_System* PHY;
};


