#pragma once
#include"scene.h"
#include"Physics_System.h"
#include"animation.h"
#include<fstream>
extern  player* P1;
void Store(int);
class guanqia
{
public:
	static scene* My_Game_scene;

	static Physics_System* PHY;

	void NEW_BOX(int x, int y)
	{
		Box* foo;
		foo = new Box(x, y, "obstacle", P1, PHY);
		P1->GameObject_list.push_back(foo);

		return;
	}

	void NEW_zhanwuzha(int x, int y)
	{
		zhanwuzha* foo;
		foo = new zhanwuzha(x, y, "obstacle", P1, PHY);
		P1->GameObject_list.push_back(foo);
		return;
	}

	void NEW_fruit(int x_, int y_, string type = "power_fruit")
	{
		fruit* foo;
		foo = new fruit(x_, y_, type, P1, PHY);
		P1->GameObject_list.push_back(foo);
		return;
	}

	void NEW_Boss(int x, int y)
	{
		Boss* foo;
		foo = new Boss(x, y, P1, PHY);
		P1->GameObject_list.push_back(foo);
		return;
	}

	void connect_sce_player()
	{
		My_Game_scene->PLAYER = P1;
	}

	void connect_phy_player()
	{
		P1->PHY_SYS = PHY;
	}
	
	guanqia(char sky_name[], bool** static_Obstacle)
	{
		My_Game_scene = new scene(sky_name);
		PHY = new Physics_System(P1, static_Obstacle);
		this->connect_sce_player();
		this->connect_phy_player();
		P1->conect_PHYSYS();
		Store(4);
	}

	~guanqia()
	{
		for (vector<GameObject*>::iterator i_ = P1->GameObject_list.begin(); i_ < P1->GameObject_list.end(); i_++)
		{
			delete (*i_);
		}
		P1->GameObject_list.clear();
		this->ani_scene.clear();
		delete PHY;
		delete My_Game_scene;
	}

	vector<animation> ani_scene;

	void add_ani(int _ani_num, char _ani[], char _ani_black[], int ani_weight, int ani_hight)
	{
		animation* foo_ani = new animation(_ani_num, _ani, _ani_black, ani_weight, ani_hight);
		ani_scene.push_back(*foo_ani);
		if (foo_ani != NULL)
			delete foo_ani;
	}

};
static char Vc[] = { "animation\\UI\\V.png" };                  //初始化动画V
static char V_blackc[] = { "animation\\UI\\V_black.png" };     //初始化动画V
static char talk_blockc[] = { "animation\\UI\\talk_block.png" };                  //初始化动画V
static char talk_block_blackc[] = { "animation\\UI\\talk_block_black.png" };     //初始化动画V

void RandomMap(guanqia* guan1)
{
	srand((unsigned int)time(NULL));

	for (int j = 1; j < 6; j++)
	{
		for (int i_ = 1; i_ < 28; i_++)
		{
			if (rand() % 5 == 1)
			{
				guan1->NEW_BOX(32 * i_, 32 * j);
			}
		}
	}
}

extern guanqia* guan1;
void Store()
{
	ofstream O;
	O.open("DATA", ios::binary | ios::out);
	O << P1->health << " " << P1->position_x << " " << P1->position_y<<" ";
	for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
	{
		O << (*i)->health << " " << (*i)->position_x << " " << (*i)->position_y<<" ";
	}
	outtextxy(0, 0, "存档成功");
	system("pause");
}
void Store(int)
{
	ofstream O;
	O.open("DATA", ios::binary | ios::out);
	O << P1->health << " " << P1->position_x << " " << P1->position_y << " ";
	for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
	{
		O << (*i)->health << " " << (*i)->position_x << " " << (*i)->position_y << " ";
	}
	outtextxy(500, 0, "存档成功");

}

void Read()
{
	ifstream I;
	I.open("DATA", ios::in | ios::binary);
	if (!I.is_open())
	{
		outtextxy(0,0,"未找到该档案，打开失败！！");
		system("pause");
		return;
	}
	I >> P1->health >>P1 ->position_x >> P1->position_y;
	for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
	{
		I >>(*i)->health  >> (*i)->position_x >>(*i)->position_y ;
	}
}


