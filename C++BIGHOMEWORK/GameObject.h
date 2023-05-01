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
/// GameObject����ֻ�����˶�̬�Ķ��󣬾�̬�����ڲ����ӵ��������дһ�������
/// ����������������˸��壬��ײ�壬����������������������Ҫִ�ж���������
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
	
	int weight;                                //��  �������г�ʼ��
	int hight;                                  //��   �������г�ʼ��
	string tag;
	int health;
	script* contoller;
	//�����������Ǻ��������ģ�����û��ʹ���������position
	float position_x;
	float position_y;

	int power = 0;                                  //12Ϊ���
	
	animation** ANIMATION;                                //��ÿ������д�������з������ѿռ�
    rigbody*  RIGBODY;
	collision* COLLISION;                                //��ÿ������д�������з������ѿռ�
	animator* ANIMATOR;                                 //��ÿ����������д�������з������ѿռ�
	 Physics_System* PHY_SYS;          
	 

protected:
	int wudi;                                          //��ֵΪ1-16ʱ�޵У�16ʱ�Զ���0�����˺�ת��1ͬʱ��player_state����Ϊ-6
	GameObject* To_Find_Player;

	

};

/////////////////////NPC��/////////////////////////

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

/////////////////script��////////////////////
//NPC�ű�����Ҫ������ 
//����animator��ִ�ж���
// ��Щʱ�ű�����Ĺ���
// ����collis��������˲�ִ��������Ϊ
//��ͬ�Ľű����Լ���˽��4���ܣ�boss�ű�Ҫ��׷�٣�С�������ϰ���Ҫ�����ٶȣ�box������collis�µ�set�������趩��ײ
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
	static float boundance ;               //����ϵ��
	
};

class zhanwuzha_script :public script
{
public:
	zhanwuzha_script(GameObject* Duixiang_, int speed_ = 10, int a_speed_ = 4, int jump_speed_ = 27, int search_range_ = 270, int dash_v_ = 20, int jump_posi=43,int dash_posi=23);//posi�ǿ����԰�ǧ��֮����
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
	void random_jump();                     //ÿ�ε������������ǧ��֮i�Ļ���������
	void random_dash();                 //ÿ�ε������������ǧ��֮i�Ļ���dash����
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



