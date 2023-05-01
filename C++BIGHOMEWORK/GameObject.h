#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include"animation.h"
#include"animator.h"
#include"collision.h"
#include"rigbody.h"
#include"zuobiao.h" 
using namespace std;

class rigbody;
class script;
/// <summary>
/// GameObject类中只包含了动态的对象，静态对象在不可视的情况下重写一个类更好
/// 此类析构函数完成了刚体，碰撞体，动画控制器的析构，子类要执行动画的析构
/// </summary>
class GameObject
{
	friend class animator;
	friend class  Box_script;
	friend class  zhanwuzha_script;
	friend class  fruit_script;
	friend class  Boss_script;

public:
	GameObject(float x, float y, string tagname);
	virtual ~GameObject();
	
	int weight;                                //宽  在子类中初始化
	int hight;                                  //高   在子类中初始化
	string tag;
	int health;
	script* contoller;
	//由于坐标类是后面才引入的，所以没有使用它来表达position
	float position_x;
	float position_y;

	int power = 0;                                  //12为最大
	
	animation** ANIMATION;                                //将每个动画写到子类中方便管理堆空间
    rigbody*  RIGBODY;
	collision* COLLISION;                                //将每个刚体写到子类中方便管理堆空间
	animator* ANIMATOR;                                 //将每个动画管理写到子类中方便管理堆空间
	 Physics_System* PHY_SYS;          
	 

protected:
	int wudi;                                          //当值为1-16时无敌，16时自动归0，受伤后转至1同时将player_state设置为-6
	GameObject* To_Find_Player;

	

};

/////////////////////NPC类/////////////////////////

class Box:public GameObject
{
	friend class Box_script;
public:
	Box(float B_x, float B_y, string tagname, GameObject* ToFindPlayer, Physics_System* PHY_);
	~Box();

private:
	
};

class zhanwuzha :public GameObject
{
	friend class zhanwuzha_script;
public:
	zhanwuzha(float B_x, float B_y, string tagname, GameObject* ToFindPlayer, Physics_System* PHY_);

	~zhanwuzha();

private:

};

class fruit :public GameObject
{
public:
	fruit(int x_,int y_,string tag_, GameObject* ToFindPlayer, Physics_System* PHY_);
	~fruit();
};

/////////////////script类////////////////////
//NPC脚本的主要功能有 
//调用animator来执行动画
// 这些时脚本父类的功能
// 调用collis来检查受伤并执行受伤行为
//不同的脚本有自己的私有4功能，boss脚本要能追踪，小怪碰到障碍物要反向速度，box类会调用collis下的set函数来设订碰撞
class script
{
public:
	script(GameObject* Duixiang_);
	GameObject* Duixiang;
	int ani_num;
	virtual void Collision_Happen()=0;
	virtual void Show_NPC_Happen() = 0;
	virtual void Do_script()=0;
	int activt_or_not=1;
	
};

class Box_script:public script
{
public:
	Box_script(GameObject* Duixiang_);
	 void Collision_Happen() ;
	void Show_NPC_Happen() ;
	void Do_script();
private:
	static float boundance ;               //弹性系数
	
};

class zhanwuzha_script :public script
{
public:
	zhanwuzha_script(GameObject* Duixiang_, int speed_ = 10, int a_speed_ = 4, int jump_speed_ = 27, int search_range_ = 270, int dash_v_ = 20, int jump_posi=43,int dash_posi=23);//posi是可能性按千分之计算
	void Collision_Happen();
	void Show_NPC_Happen();
	void Do_script();
	int distance_to_player;
	int jump_posi;
	int dash_posi;
private:
	int speed ;      
	 int a_speed ;
	  int jifeix;
	int jifeiy;
	 int jump_speed ;
	int search_range ;
	int dash_v ;
	void auto_attack();
	void random_jump();                     //每次调用这个函数有千分之i的机会跳起来
	void random_dash();                 //每次调用这个函数有千分之i的机会dash起来
};	

class fruit_script :public script
{
public:
	fruit_script(GameObject* Duixiang_);
	void Collision_Happen();
	void Show_NPC_Happen();
	void Do_script();
private:
	const static int sleep_time = 50;
};



