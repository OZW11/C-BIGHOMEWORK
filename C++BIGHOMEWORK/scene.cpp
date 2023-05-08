#include "scene.h"


scene::scene(char sky_name[])
{

	loadimage(&this->skybox, sky_name);
	char blood_backc[] = { "animation\\player\\UI\\health_back.png" };
	char blood_back_blackc[] = { "animation\\player\\UI\\health_back_black.png" };
	this->blood_back = new animation(1, blood_backc, blood_back_blackc,300,111);
	char heartc[] = { "animation\\player\\UI\\heart.png" };
	char heart_blackc[] = { "animation\\player\\UI\\heart_black.png" };
	this->heart = new animation(1, heartc, heart_blackc, 52, 52);
	char powerc[] = { "animation\\player\\UI\\power_tiao.png" };
	char power_blackc[] = { "animation\\player\\UI\\power_tiao_black.png" };
	this->power_tiao = new animation(1, powerc, power_blackc, 52, 52);

}
int scene::die_time = 0;

scene::~scene()
{
	if (blood_back != NULL)
	{
		delete blood_back;
		blood_back = NULL;
	}
	if (heart != NULL)
	{
		delete heart;
		heart = NULL;
	}
	if (power_tiao != NULL)
	{
		delete power_tiao;
		power_tiao = NULL;
	}
	
}
extern player* P1;
void scene::UPDATE_show_scene()
{
	BeginBatchDraw();

	putimage(0,0,&this->skybox);
	//动画测试器 //
	//this->PLAYER->get_animation().TakeHit->Play_animation(10,10, 160,111,this->PLAYER->foo);
	//if (this->PLAYER->foo < 0)this->PLAYER->foo = 0;
	////////////////////////////////////////////


	for (vector<GameObject*>::iterator ptr = this->PLAYER->GameObject_list.begin(); ptr < this->PLAYER->GameObject_list.end(); ptr++)
	{
		if((*ptr)->contoller->activt_or_not==1)
		(*ptr)->contoller->Show_NPC_Happen();
	}

	this->PLAYER->MyAnimator->show_player();
	{//UI贴图
		static int chixujihuo = 0;       //无用的变量，只是用来使用animation（其实是动画类的一种重载）
		this->blood_back->Play_animation(0, -10, 300, 111, chixujihuo);
		chixujihuo = 0;
		if(this->PLAYER->health>=1)
		this->heart->Play_animation(99, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 2)
			this->heart->Play_animation(99+45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 3)
			this->heart->Play_animation(99 + 45 + 45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 4)
			this->heart->Play_animation(99 + 45 + 45 + 45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 5)
			this->heart->Play_animation(99 + 45 + 45 + 45+45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 6)
			this->heart->Play_animation(99 + 45 + 45 + 45+45+45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 7)
			this->heart->Play_animation(99 + 45 + 45 + 45 + 45 + 45+45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		if (this->PLAYER->health >= 8)
			this->heart->Play_animation(99 + 45 + 45 + 45 + 45 + 45+45+45, 34, 300, 111, chixujihuo);
		chixujihuo = 0;
		putimage(37, 28 +52- (52 * this->PLAYER->power / 12), 52, 0 + 52 * this->PLAYER->power / 12, &this->power_tiao->GetImage_black(), 0, 52 - (52 * this->PLAYER->power / 12),SRCAND);
		putimage(37, 28 +52- (52 * this->PLAYER->power / 12), 52, 0 + 52 * this->PLAYER->power / 12, &this->power_tiao->GetImage(), 0, 52 - (52 * this->PLAYER->power / 12), SRCPAINT);

	}
	
	EndBatchDraw();
	static int karou_con = 0;                                                      //解决无限卡肉时间带来的卡顿问题

	for (vector<GameObject*>::iterator i = PLAYER->GameObject_list.begin();i< PLAYER->GameObject_list.end(); i++)
	{
		if ((*i)->COLLISION->On_attack_collision())
		{
			
			if (karou_con < 1)
			{
				P1->RIGBODY->volocity_x += ((this->PLAYER->RIGBODY->direction == 1 ? -1 : 1) * 16);
			}
			if (karou_con < 2)
			{
				this->camera_shake(4,1);
				Sleep(6);
				this->camera_shake(4,1);
				Sleep(6);
				this->camera_shake(2,2);
				Sleep(6);                                             //卡肉时间和震动
				karou_con++;
			}

		}
	}
	
	if( PLAYER->dazhaotime > 0)                                                  //大招
	{
		PLAYER->dazhaotime++;
		this->camera_shake(10,0);
		if (PLAYER->dazhaotime == 30)
		{
			PLAYER->dazhaotime = 0;
		}
	}
	if (karou_con >= 2)
	{
		karou_con = 0;
	}
	if (PLAYER->player_state >=92)                                                    //角色在冲刺
	{
		this->camera_shake(3,0);
	}
	
	
	Sleep(1000/this->zhenglv);
	if (PLAYER->health <= 0)
	{
		die_time++;
		if (die_time >= 100)
		{
			IMAGE DIE;
			loadimage(&DIE, "de.png",1000,400);
			putimage(0, 0, &DIE);
			settextcolor(RGB(150,10,10));
			outtextxy(0,0,"按任意键退出");
			system("pause");
			exit(0);
		}
	}

}

void scene::camera_shake(int shake_range, int shake_rangey)
{
	static float foo_OOOO = 1;
	IMAGE afoo;
	getimage(&afoo, 0, 0, 1000, 400);
	putimage(foo_OOOO * shake_range, foo_OOOO * shake_rangey * foo_OOOO, &afoo);
	if (foo_OOOO > 0)
	{
		foo_OOOO += 0.4;
		if (foo_OOOO >= 2)
			foo_OOOO = -1;
	}
	else
	{
		foo_OOOO -= 0.1;
		if (foo_OOOO <= -2)
			foo_OOOO = 1;
	}
}
