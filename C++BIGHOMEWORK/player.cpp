#include "player.h"
#include"rigbody.h"
#include<stdio.h>
#include"Physics_System.h"
#include <Mmsystem.h> 
#pragma comment(lib, "Winmm.lib") 

player::player(float x, float y) :GameObject(x, y, "player")
{
	this->weight = 160;
	this->hight=111;
	this->health = 8;
	this->player_state = 0;
	this->RIGBODY = new rigbody(this);
	this->MyAnimator = new player_animator(this);
	 wudi = 0;
	OnMove = 0;
	this->tag = "player";
	attack_sleep = 0;
	zuobiao foo(16,51);
	this->attack2_collision[0]=foo;
	foo.set_zuobiao(155, 99);
	this->attack2_collision[1]=foo;
	foo.set_zuobiao(54, 63);
	this->attack1_collision[0]=foo;
	foo.set_zuobiao(151,100);
	this->attack1_collision[1]=foo;
	foo.set_zuobiao(25,5 );
	this->attack3_collision[0] = foo;
	foo.set_zuobiao(153,100 );
	this->attack3_collision[1] = foo;
	this->COLLISION = new collision(this, "obstacle", this->PHY_SYS);
	zuobiao foo1(75, 62);
	COLLISION->collision_picture1 = foo1;
	foo1.set_zuobiao(92, 102);
	COLLISION->collision_picture2 = foo1;
	backgrondmusic_xunhanqi = 0;
	
	power = 0;
}

//加载动画
player_ani::player_ani()
{
	///////////////攻击图形1///////////////////

	char Attack1[] = { "animation\\player\\attack1\\Attack1.png" };
	char Attack1_black[] = { "animation\\player\\attack1\\Attack1_black.png" };
	attack1 = new animation(4, Attack1, Attack1_black, 160, 111);
	////////////////////////////////////////

	 ///////////////攻击图形2//////////////////////////////////
	char Attack2[] = { "animation\\player\\attack2\\Attack2.png" };
	char Attack2_black[] = { "animation\\player\\attack2\\Attack2_black.png" };
	attack2 = new animation(4, Attack2, Attack2_black, 160, 111);

	////////////////////////////////////////
		 ///////////////攻击图形3//////////////////
	char Attack3[] = { "animation\\player\\attack3\\Attack3.png" };
	char Attack3_black[] = { "animation\\player\\attack3\\Attack3_black.png" };
	attack3 = new animation(4, Attack3, Attack3_black, 160, 111);

	////////////////////////////////////////
	//                death               //
	char deathc[] = { "animation\\player\\death\\Death.png" };
	char death_blackc[] = { "animation\\player\\death\\Death_black.png" };
	death = new animation(6, deathc, death_blackc, 160, 111);

	////////////////////////////////////////
	//                Fall              //
	char Fallc[] = { "animation\\player\\Fall\\Fall.png" };
	char Fall_blackc[] = { "animation\\player\\Fall\\Fall_black.png" };
	Fall = new animation(2, Fallc, Fall_blackc, 160, 111);

	////////////////////////////////////////
	//                Idle             //
	char Idlec[] = { "animation\\player\\Idle\\Idle.png" };
	char Idle_blackc[] = { "animation\\player\\Idle\\Idle_black.png" };
	Idle = new animation(8, Idlec, Idle_blackc, 160, 111);

	////////////////////////////////////////
	//                Jump               //
	char Jumpc[] = { "animation\\player\\Jump\\Jump.png" };
	char Jump_blackc[] = { "animation\\player\\Jump\\Jump_black.png" };
	Jump = new animation(2, Jumpc, Jump_blackc, 160, 111);

	////////////////////////////////////////
	//                Run               //
	char Runc[] = { "animation\\player\\Run\\Run.png" };
	char Run_blackc[] = { "animation\\player\\Run\\Run_black.png" };
	Run = new animation(8, Runc, Run_blackc, 160, 111);



////////////////////////////////////////
//                TakeHit             //
char TakeHitc[] = { "animation\\player\\TakeHit\\TakeHit.png" };
char TakeHit_blackc[] = { "animation\\player\\TakeHit\\TakeHit_black.png" };
TakeHit = new animation(6, TakeHitc, TakeHit_blackc, 160, 111);
////////////////////////////////////////
//                Dash             //
char Dashc[] = { "animation\\player\\Dash\\Dash.png" };
char Dash_blackc[] = { "animation\\player\\Dash\\Dash_black.png" };
Dash = new animation(3, Dashc, Dash_blackc, 160, 111);


///////////////攻击图形1R///////////////////

char Attack1R[] = { "animation\\player\\attack1\\Attack1R.png" };
char Attack1_blackR[] = { "animation\\player\\attack1\\Attack1_blackR.png" };
attack1R = new animation(4, Attack1R, Attack1_blackR, 160, 111);
////////////////////////////////////////

 ///////////////攻击图形2R//////////////////////////////////
char Attack2R[] = { "animation\\player\\attack2\\Attack2R.png" };
char Attack2_blackR[] = { "animation\\player\\attack2\\Attack2_blackR.png" };
attack2R = new animation(4, Attack2R, Attack2_blackR, 160, 111);

////////////////////////////////////////
	 ///////////////攻击图形3R//////////////////
char Attack3R[] = { "animation\\player\\attack3\\Attack3R.png" };
char Attack3_blackR[] = { "animation\\player\\attack3\\Attack3_blackR.png" };
attack3R = new animation(4, Attack3R, Attack3_blackR, 160, 111);

////////////////////////////////////////
//                death     R          //
char deathcR[] = { "animation\\player\\death\\DeathR.png" };
char death_blackcR[] = { "animation\\player\\death\\Death_blackR.png" };
deathR = new animation(6, deathcR, death_blackcR, 160, 111);

////////////////////////////////////////
//                Fall   R           //
char FallcR[] = { "animation\\player\\Fall\\FallR.png" };
char Fall_blackcR[] = { "animation\\player\\Fall\\Fall_blackR.png" };
FallR = new animation(2, FallcR, Fall_blackcR, 160, 111);

////////////////////////////////////////
//                Idle             //
char IdlecR[] = { "animation\\player\\Idle\\IdleR.png" };
char Idle_blackcR[] = { "animation\\player\\Idle\\Idle_blackR.png" };
IdleR = new animation(8, IdlecR, Idle_blackcR, 160, 111);

////////////////////////////////////////
//                Jump   R            //
char JumpcR[] = { "animation\\player\\Jump\\JumpR.png" };
char Jump_blackcR[] = { "animation\\player\\Jump\\Jump_blackR.png" };
JumpR = new animation(2, JumpcR, Jump_blackcR, 160, 111);

////////////////////////////////////////
//                Run   R            //
char RuncR[] = { "animation\\player\\Run\\RunR.png" };
char Run_blackcR[] = { "animation\\player\\Run\\Run_blackR.png" };
RunR = new animation(8, RuncR, Run_blackcR, 160, 111);



////////////////////////////////////////
//                TakeHit    R          //
char TakeHitcR[] = { "animation\\player\\TakeHit\\TakeHitR.png" };
char TakeHit_blackcR[] = { "animation\\player\\TakeHit\\TakeHit_blackR.png" };
TakeHitR = new animation(6, TakeHitcR, TakeHit_blackcR, 160, 111);

////////////////////////////////////////
//                Dash R            //
char DashcR[] = { "animation\\player\\Dash\\DashR.png" };
char Dash_blackcR[] = { "animation\\player\\Dash\\Dash_blackR.png" };
DashR = new animation(3, DashcR, Dash_blackcR, 160, 111);

}

player_ani::~player_ani()
{
	//delete TakeHit;//死动画
	//delete attack1;//死动画
	//delete attack2;//死动画
	//delete attack3;//死动画
	//delete Dash;//死动画
	//delete death;//死动画
	//delete Fall;//活动画
	//delete Idle;//活动画
	//delete Jump;//活动画
	//delete Run;//活动画
	//delete TakeHitR;//死动画
	//delete attack1R;//死动画
	//delete attack2R;//死动画
	//delete attack3R;//死动画
	//delete deathR;//死动画
	//delete DashR;//死动画
	//delete FallR;//活动画
	//delete IdleR;//活动画
	//delete JumpR;//活动画
	//delete RunR;//活动画

}


/// <取得总动画>
/// 
/// </summary>
/// <returns></returns>
player_ani player::get_animation()
{
	return this->Player_Animation;
}

//角色的控制脚本                 //为了维持视觉效果与攻击一致，将attack的物理实现与图像实现一起放在animator里
void player::P_script()
{
	//碰撞更新函数
	
	//power = 9999;                           //有备而来(*/ω＼*)
	
	
	if (wudi==0&&this->COLLISION->On_attack_collision()>0 && this->COLLISION->On_attack_collision() < 10)
	{
		this->TAKE_HIT();
	}

	if (this->player_state >= 0&& this->player_state<90)
	{
		if (GetAsyncKeyState('K') && (this->player_state == 0 || this->player_state == 4 || this->player_state == 5) && (Dash_sleep == 0))
		{
			this->RIGBODY->Gravity = 0;
			no_gravity = -5;
			mciSendString("close audio\\main.wav", 0, 0, 0);
			mciSendString("close audio\\buttom.wav", 0, 0, 0);
			mciSendString("close audio\\player\\dash.wav", 0, 0, 0);
			mciSendString("open audio\\player\\dash.wav", 0, 0, 0);
			mciSendString("play audio\\player\\dash.wav", 0, 0, 0);

			Dash_sleep++;
			wudi = 12;
			this->player_state = 95;
			if (GetAsyncKeyState('W') && GetAsyncKeyState('D'))
			{
				this->RIGBODY->volocity_y = dash_v * -0.15;
				this->RIGBODY->volocity_x = dash_v * 0.8;
			}
			else if (GetAsyncKeyState('W') && GetAsyncKeyState('A'))
			{
				this->RIGBODY->volocity_y = dash_v * -0.15;
				this->RIGBODY->volocity_x = -dash_v * 0.8;
			}
			else if (GetAsyncKeyState('W'))
			{
				this->RIGBODY->volocity_y = dash_v * -0.18;
				this->RIGBODY->volocity_x = 0;
			}
			else if (GetAsyncKeyState('S') && GetAsyncKeyState('D'))
			{
				this->RIGBODY->volocity_y = dash_v * 0.2;
				this->RIGBODY->volocity_x = dash_v * 0.8;
			}
			else if (GetAsyncKeyState('S') && GetAsyncKeyState('A'))
			{
				this->RIGBODY->volocity_y = dash_v * 0.2;
				this->RIGBODY->volocity_x = -dash_v * 0.8;
			}
			else if (GetAsyncKeyState('S'))
			{
				this->RIGBODY->volocity_y = dash_v * 0.4;
				this->RIGBODY->volocity_x = 0;
			}
			else
			{
				this->RIGBODY->volocity_x = (this->RIGBODY->direction == 1 ? 1 : -1) * dash_v;
				this->RIGBODY->volocity_y = 0;
			}
		}
	     if (GetAsyncKeyState('J')&&attack_sleep==0&&(this->player_state==0|| this->player_state == 4|| this->player_state == 5))
	     {
		//attack函数
			 mciSendString("close audio\\main.wav", 0, 0, 0);
			 mciSendString("close audio\\buttom.wav", 0, 0, 0);
			 mciSendString("close audio\\player\\dash.wav", 0, 0, 0);
			 mciSendString("close audio\\player\\kill.wav", 0, 0, 0);
			 mciSendString("open audio\\player\\kill.wav", 0, 0, 0);
			 mciSendString("play audio\\player\\kill.wav", 0, 0, 0);
     	 attack_sleep++;
		switch (this->player_state)
		{
		case 0:
			this->player_state = 1;
			break;
		case 4:
			this->player_state = 2;
			break;
		case 5:
			this->player_state = 3;

			break;

			OnMove = 0;
		}
	     }
	     if (GetAsyncKeyState('D'))
		 {
			if (this->RIGBODY->volocity_x < this->max_vx)
			{
				this->RIGBODY->volocity_x += this->vx;
			}
			{
			OnMove = 1;
			this->RIGBODY->direction = 1;
			}
		 }
		 else if (GetAsyncKeyState('A'))
		 {
			if (this->RIGBODY->volocity_x > -this->max_vx)
			{
				this->RIGBODY->volocity_x += -this->vx;
			}
			{
				OnMove = 1;
				this->RIGBODY->direction = 0;
			}
		 }
		 else
		 {
			OnMove = 0;
		 }
		 if (GetAsyncKeyState(VK_SPACE))
		 {
			 if (this->COLLISION->On_obstacle_collision_D())
			 {
				 this->RIGBODY->volocity_y = this->vJump;
			 }
			 OnMove = 0;
		 }

		 if ((GetAsyncKeyState('I')))
		 {
			 if (power >= 12)
			 {
				 power = 0;
				 this->Dazhao();
			 }
		 }


	}
	else
	{
		this->player_state++;
		
		OnMove = 0;
	}
	if (this->player_state == 103)
	{
		this->player_state =0;
	}
	if (attack_sleep != 0)
	{
		attack_sleep++;	
	}
	if (attack_sleep >= 7)
	{
		attack_sleep = 0;
	}
	if (this->wudi > 0)
	{
		wudi++;
		if (wudi == 17)
		{
			wudi = 0;
		}
	}
	if (Dash_sleep > 0)
	{
		Dash_sleep++;
		if (Dash_sleep >= 18)
		{
			Dash_sleep = 0;
		}
	}
	if (this->RIGBODY->volocity_x > 16 || this->RIGBODY->volocity_x < -16)
	{
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
		this->RIGBODY->liner_Drag();
	}

	if ((this->COLLISION->On_obstacle_collision_D()) && this->RIGBODY->volocity_y > 0)//判断条件为collision脚是否着地
	{
		this->RIGBODY->volocity_y = 0;
	}
	

	////////////////背景音频控制/////////////////
	backgrondmusic_xunhanqi++;
	if (backgrondmusic_xunhanqi >= 4880)
	{
		backgrondmusic_xunhanqi = 0;
		mciSendString("stop audio\\backgrond.mp3", 0, 0, 0);
		mciSendString("stop audio\\player\\dazhao.mp3", 0, 0, 0);
		mciSendString("stop audio\\player\\POWER.wav", 0, 0, 0);
		mciSendString("close audio\\backgrond.mp3", 0, 0, 0);
		mciSendString("close audio\\player\\dazhao.mp3", 0, 0, 0);
		mciSendString("close audio\\player\\POWER.wav", 0, 0, 0);
		mciSendString("close audio\\backgrond.mp3", 0, 0, 0);
		mciSendString("play audio\\backgrond.mp3", 0, 0, 0);
	}
	if (no_gravity < 0)
	{
		no_gravity++;
	}
	else 
	{
		this->RIGBODY->Gravity = 3;
	}
}

//扣血放过在碰撞时script完成
void player::TAKE_HIT()
{
	this->RIGBODY->volocity_x = -12 * ( (this->RIGBODY->direction == 1 ?1: -1));
	this->RIGBODY->volocity_y = -15;
	health--;
	this->wudi = 1;
	this->player_state = -6;
}

void player::conect_PHYSYS()
{
	this->COLLISION = new collision(this, "obstacle", this->PHY_SYS);
	/////////////////////////////////////////////////////
	////////////// set collision picture ////////////////
	zuobiao foo(68, 58);
	this->COLLISION->collision_picture1 = foo;
	zuobiao foo1(91, 104);
	this->COLLISION->collision_picture2 = foo1;

	//////////////////////////////////////////////////
}

void player::Dazhao()
{
	dazhaotime = 1;
	mciSendString("stop audio\\backgrond.mp3", 0, 0, 0);
	mciSendString("stop audio\\player\\dazhao.mp3", 0, 0, 0);
	mciSendString("stop audio\\player\\POWER.wav", 0, 0, 0);
	mciSendString("close audio\\backgrond.mp3", 0, 0, 0);
	mciSendString("close audio\\player\\dazhao.mp3", 0, 0, 0);
	mciSendString("close audio\\player\\POWER.wav", 0, 0, 0);
	

	Sleep(500);

	this->attack_sleep = 1;
	this->backgrondmusic_xunhanqi = 3500 ;
	mciSendString("open audio\\POWER.wav", 0, 0, 0);
	mciSendString("play audio\\POWER.wav", 0, 0, 0);
	
	wudi = 1;
	IMAGE dazhao_;
	IMAGE dazhao_w;
	IMAGE dazhao_b;
	IMAGE dao[15];
	if (this->RIGBODY->direction)
	{
		loadimage(&dazhao_, "animation\\player\\death\\Death_black.png");
		loadimage(&dazhao_w, "animation\\UI\\white.png");
		loadimage(&dazhao_b, "animation\\UI\\black.png");
		BeginBatchDraw();

		putimage(0, 0, &dazhao_w);
		for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
		{
			(*i)->contoller->Show_NPC_Happen();
		}
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_, this->weight * 0, 0, SRCAND);
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_b, this->weight * 0, 0, SRCPAINT);
		EndBatchDraw();
		Sleep(800);
		Sleep(1000);
		BeginBatchDraw();
		putimage(0, 0, &dazhao_w);
		for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
		{
			(*i)->contoller->Show_NPC_Happen();
		}
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_, this->weight, 0, SRCAND);
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_b, this->weight, 0, SRCPAINT);
		EndBatchDraw();
		Sleep(800);
		BeginBatchDraw();
		putimage(0, 0, &dazhao_w);
		for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
		{
			(*i)->contoller->Show_NPC_Happen();
		}
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_, this->weight * 2, 0, SRCAND);
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_b, this->weight * 2, 0, SRCPAINT);
		EndBatchDraw();
		
	Sleep(1200);
	mciSendString("open audio\\player\\dazhao.mp3", 0, 0, 0);                           ////////////////////////////////////////////////////
	mciSendString("play audio\\player\\dazhao.mp3", 0, 0, 0);                            ///////////////////////////////////
	Sleep(800);
	}
	else
	{
		loadimage(&dazhao_, "animation\\player\\death\\Death_blackR.png");
		loadimage(&dazhao_w, "animation\\UI\\white.png");
		loadimage(&dazhao_b, "animation\\UI\\black.png");
		BeginBatchDraw();

		putimage(0, 0, &dazhao_w);
		
		for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
		{
			(*i)->contoller->Show_NPC_Happen();
		}
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_, this->weight * 5, 0, SRCAND);
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_b, this->weight * 5, 0, SRCPAINT);
		EndBatchDraw();
		Sleep(800);
		Sleep(1000);
		BeginBatchDraw();
		putimage(0, 0, &dazhao_w);
		for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
		{
			(*i)->contoller->Show_NPC_Happen();
		}
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_, this->weight * 4, 0, SRCAND);
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_b, this->weight * 4, 0, SRCPAINT);
		EndBatchDraw();
		Sleep(800);
		BeginBatchDraw();
		putimage(0, 0, &dazhao_w);

		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_, this->weight * 3, 0, SRCAND);
		putimage(this->position_x, this->position_y, this->weight, this->hight, &dazhao_b, this->weight * 3, 0, SRCPAINT);

		for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
		{
			(*i)->contoller->Show_NPC_Happen();
		}
		EndBatchDraw();
		
		Sleep(1200);
		mciSendString("open audio\\player\\dazhao.mp3", 0, 0, 0);                           ////////////////////////////////////////////////////
		mciSendString("play audio\\player\\dazhao.mp3", 0, 0, 0);                            ///////////////////////////////////
		Sleep(800);
	}
	char foo_aa[256];
	for (int i = 0; i <11; i++)
	{
		sprintf_s(foo_aa, "animation\\UI\\white%d.png",i+1);
		loadimage(&(dao[i]), foo_aa);
	}
	for (int i = 0; i <250; i++)
	{
		int k = -1250+rand() % 1500;
		int j =  -280+rand() % 180;
		putimage(k, j, &(dao[rand() % 12]), SRCAND);
		putimage(k, j, &dazhao_b, SRCPAINT);
		
		if(i%8==0)
		this->Player_Animation.attack1->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);

		if (i % 12== 0)
			this->Player_Animation.attack1R->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);
		this->Player_Animation.attack1->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);

		if (i %7== 0)
			this->Player_Animation.attack2->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);
		this->Player_Animation.attack1R->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);

		if (i % 6 == 0)
			this->Player_Animation.attack2R->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);

		if (i % 11== 0)
			this->Player_Animation.attack3->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);
		this->Player_Animation.attack2->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);

		if (i % 9== 0)
			this->Player_Animation.attack3R->Play_animation(rand() % 940, rand() % 400, this->weight, this->hight);

		if (i < 20)
			Sleep(55);
		else if (i < 70)
			Sleep(27);
		else
			Sleep(7);
	}
	for (vector<GameObject*>::iterator i = this->GameObject_list.begin(); i < this->GameObject_list.end(); i++)
	{
		(*i)->contoller->Collision_Happen();
		(*i)->contoller->Collision_Happen();
		(*i)->contoller->Collision_Happen();
		(*i)->contoller->Collision_Happen();
		(*i)->contoller->Collision_Happen();
	
	}
	
	Dash_sleep++;

	this->RIGBODY->volocity_x = (this->RIGBODY->direction == 1 ? 1 : -1) * dash_v*1.5;
}

player_animator::player_animator(player* duixiangA)
{

	this->zhen_duixiang = duixiangA;
	Fall_jishu = 0;
	Idle_jishu = 0;
	 Jump_jishu = 0;
	Run_jishu=0;
	 attack1_jishu=0;
	attack2_jishu=0;
	attack3_jishu=0;
	TakeHit_jishu=0;
	death_jishu=0;
	Dash_jishu = 0;
}

//用于呈现player的图形
void player_animator::show_player()
{
//注意图片展示的优先级   死亡>冲刺>受伤>攻击>跳>下落>跑>等待

	if ( this->zhen_duixiang->health<= 0 && this->zhen_duixiang->RIGBODY->direction == 1)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().death->GetImage_black(), (this->zhen_duixiang->player_weight * this->death_jishu), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().death->GetImage(), (this->zhen_duixiang->player_weight * this->death_jishu), 0, SRCPAINT);

		this->zhen_duixiang->COLLISION->active = 0;
		
		if (this->death_jishu < this->zhen_duixiang->get_animation().death->num - 1)
		{
			this->death_jishu++;
		}
		this->zhen_duixiang->player_state = -100;
		return;
	}
	else if (this->zhen_duixiang->health <= 0 && this->zhen_duixiang->RIGBODY->direction == 0)
	{
		this->zhen_duixiang->COLLISION->active = 0;
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().deathR->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().death->num-1-this->death_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().deathR->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().death->num - 1 - this->death_jishu)), 0, SRCPAINT);


		if (this->death_jishu <this->zhen_duixiang->get_animation().death->num-1)
		{
			this->death_jishu++;
		}
		this->zhen_duixiang->player_state = -100;
		return;
	}

    if(this->zhen_duixiang->player_state>=50&& this->zhen_duixiang->RIGBODY->direction==1)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Dash->GetImage_black(), (this->zhen_duixiang->player_weight * this->Dash_jishu), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Dash->GetImage(), (this->zhen_duixiang->player_weight * this->Dash_jishu), 0, SRCPAINT);

		this->Dash_jishu++;
		if (this->Dash_jishu >= this->zhen_duixiang->get_animation().Dash->num&& this->zhen_duixiang->player_state>100)
		{
			
			this->Dash_jishu = 0;
			this->zhen_duixiang->player_state = 0;
		}
		else
		{
			this->zhen_duixiang->player_state++;
			if (this->Dash_jishu >= this->zhen_duixiang->get_animation().Dash->num)
			{
				this->Dash_jishu =0;
			}
		}
		return;
	}
	else if (this->zhen_duixiang->player_state >=50 && this->zhen_duixiang->RIGBODY->direction == 0)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().DashR->GetImage_black(), (this->zhen_duixiang->player_weight *(this->zhen_duixiang->get_animation().Dash->num -1-this->Dash_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().DashR->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().Dash->num - 1 - this->Dash_jishu)), 0, SRCPAINT);

		this->Dash_jishu++;
		if (this->Dash_jishu >= this->zhen_duixiang->get_animation().Dash->num&& this->zhen_duixiang->player_state > 100)
		{
			this->Dash_jishu = 0;
			this->zhen_duixiang->player_state = 0;
		}
		else
		{
			this->zhen_duixiang->player_state++;
			if (this->Dash_jishu >= this->zhen_duixiang->get_animation().Dash->num)
			{
				this->Dash_jishu = 0;
			}
		}
		return;
	}

	if ((this->zhen_duixiang->player_state < 0||this->TakeHit_jishu!=0 )&& this->zhen_duixiang->RIGBODY->direction == 1)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().TakeHit->GetImage_black(), (this->zhen_duixiang->player_weight * this->TakeHit_jishu), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().TakeHit->GetImage(), (this->zhen_duixiang->player_weight * this->TakeHit_jishu), 0, SRCPAINT);

		this->TakeHit_jishu++;
		if (this->TakeHit_jishu >= this->zhen_duixiang->get_animation().TakeHit->num)
		{
			this->TakeHit_jishu = 0;
		}
		return;
	}
	else if ((this->zhen_duixiang->player_state < 0 || this->TakeHit_jishu != 0 )&& this->zhen_duixiang->RIGBODY->direction == 0)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().TakeHitR->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().TakeHit->num - 1 - this->TakeHit_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().TakeHitR->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().TakeHit->num - 1 - this->TakeHit_jishu)), 0, SRCPAINT);

		this->TakeHit_jishu++;
		if (this->TakeHit_jishu >= this->zhen_duixiang->get_animation().TakeHit->num)
		{
			this->TakeHit_jishu = 0;
		}
		return;
	}

	
	if (this->zhen_duixiang->RIGBODY->direction == 1 && (this->zhen_duixiang->player_state<4&& this->zhen_duixiang->player_state>0))
	{
		switch (this->zhen_duixiang->player_state)
		{
		case 1:
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack1->GetImage_black(), (this->zhen_duixiang->player_weight * this->attack1_jishu), 0, SRCAND);//透明化

			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack1->GetImage(), (this->zhen_duixiang->player_weight * this->attack1_jishu), 0, SRCPAINT);

			if (this->attack1_jishu==1&&this->zhen_duixiang->tag=="player")
			{
				for (int i = this->zhen_duixiang->position_x + this->zhen_duixiang->attack1_collision[0].x; i< this->zhen_duixiang->position_x + this->zhen_duixiang->attack1_collision[1].x; i++)
				{
					for (int j = this->zhen_duixiang->position_y + this->zhen_duixiang->attack1_collision[0].y; j < this->zhen_duixiang->position_y + this->zhen_duixiang->attack1_collision[1].y; j++)
					{
						if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入
						this->zhen_duixiang->PHY_SYS->phy_mapA[i][j] = 3;
					}
				}
			}
			this->attack1_jishu++;
			if (this->attack1_jishu >= this->zhen_duixiang->get_animation().attack1->num)
			{
				this->attack1_jishu = 0;
				this->zhen_duixiang->player_state = 4;
			}
			
			break;	
		case 2:
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack2->GetImage_black(), (this->zhen_duixiang->player_weight * this->attack2_jishu), 0, SRCAND);//透明化

			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack2->GetImage(), (this->zhen_duixiang->player_weight * this->attack2_jishu), 0, SRCPAINT);

			if (this->attack2_jishu == 1 && this->zhen_duixiang->tag == "player")
			{
				for (int i = this->zhen_duixiang->position_x + this->zhen_duixiang->attack2_collision[0].x; i < this->zhen_duixiang->position_x + this->zhen_duixiang->attack2_collision[1].x; i++)
				{
					for (int j = this->zhen_duixiang->position_y + this->zhen_duixiang->attack2_collision[0].y; j< this->zhen_duixiang->position_y + this->zhen_duixiang->attack2_collision[1].y; j++)
					{
						if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入
						this->zhen_duixiang->PHY_SYS->phy_mapA[i][j] = 3;
					}
				}
			}
			this->attack2_jishu++;
			if (this->attack2_jishu >= this->zhen_duixiang->get_animation().attack2->num)
			{
				this->attack2_jishu = 0;
				this->zhen_duixiang->player_state = 5;
			}
				break;
		case 3 :
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack3->GetImage_black(), (this->zhen_duixiang->player_weight * this->attack3_jishu), 0, SRCAND);//透明化

			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack3->GetImage(), (this->zhen_duixiang->player_weight * this->attack3_jishu), 0, SRCPAINT);

			if (this->attack3_jishu == 1 && this->zhen_duixiang->tag == "player")
			{
				for (int i = this->zhen_duixiang->position_x + this->zhen_duixiang->attack3_collision[0].x; i < this->zhen_duixiang->position_x + this->zhen_duixiang->attack3_collision[1].x; i++)
				{
					for (int j = this->zhen_duixiang->position_y + this->zhen_duixiang->attack3_collision[0].y; j< this->zhen_duixiang->position_y + this->zhen_duixiang->attack3_collision[1].y; j++)
					{
						if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入
						this->zhen_duixiang->PHY_SYS->phy_mapA[i][j] = 3;
					}
				}
			}
			this->attack3_jishu++;
			if (this->attack3_jishu >= this->zhen_duixiang->get_animation().attack1->num)
			{
				this->attack3_jishu = 0;
				this->zhen_duixiang->player_state = 0;
			}
			break;
		}

		return;
	}
	else if (this->zhen_duixiang->RIGBODY->direction == 0 && (this->zhen_duixiang->player_state < 4 && this->zhen_duixiang->player_state>0))
	{
		switch (this->zhen_duixiang->player_state)
		{
		case 1:
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack1R->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().attack1->num - 1 - this->attack1_jishu)), 0, SRCAND);//透明化

			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack1R->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().attack1->num - 1 - this->attack1_jishu)), 0, SRCPAINT);

			if (this->attack1_jishu == 1 && this->zhen_duixiang->tag == "player")
			{
				for (int i = this->zhen_duixiang->position_x + this->zhen_duixiang->player_weight - this->zhen_duixiang->attack1_collision[1].x; i < this->zhen_duixiang->position_x + this->zhen_duixiang->player_weight - this->zhen_duixiang->attack1_collision[0].x; i++)
				{
					for (int j = this->zhen_duixiang->position_y + this->zhen_duixiang->attack1_collision[0].y; j < this->zhen_duixiang->position_y + this->zhen_duixiang->attack1_collision[1].y; j++)
					{
						if(i>0&&i<1000&&j>0&&j<400)                                        //保护程序不溢出写入
						this->zhen_duixiang->PHY_SYS->phy_mapA[i][j] = 3;
					}
				}
			}

			this->attack1_jishu++;
			if (this->attack1_jishu >= this->zhen_duixiang->get_animation().attack1->num)
			{
				this->attack1_jishu = 0;
				this->zhen_duixiang->player_state = 4;
			}

			break;
		case 2:
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack2R->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().attack2->num - 1 - this->attack2_jishu)), 0, SRCAND);//透明化

			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack2R->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().attack2->num - 1 - this->attack2_jishu)), 0, SRCPAINT);

			if (this->attack2_jishu == 1 && this->zhen_duixiang->tag == "player")
			{
				for (int i = this->zhen_duixiang->position_x + this->zhen_duixiang->player_weight - this->zhen_duixiang->attack2_collision[1].x; i < this->zhen_duixiang->position_x + this->zhen_duixiang->player_weight - this->zhen_duixiang->attack2_collision[0].x; i++)
				{
					for (int j = this->zhen_duixiang->position_y + this->zhen_duixiang->attack2_collision[0].y; j < this->zhen_duixiang->position_y + this->zhen_duixiang->attack2_collision[1].y; j++)
					{
						if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入

						this->zhen_duixiang->PHY_SYS->phy_mapA[i][j] = 3;
					}
				}
			}

			this->attack2_jishu++;
			if (this->attack2_jishu >= this->zhen_duixiang->get_animation().attack2->num)
			{
				this->attack2_jishu = 0;
				this->zhen_duixiang->player_state = 5;
			}
			break;
		case 3:
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack3R->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().attack3->num - 1 - this->attack3_jishu)), 0, SRCAND);//透明化
			
			putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().attack3R->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().attack3->num - 1 - this->attack3_jishu)), 0, SRCPAINT);

			if (this->attack3_jishu == 1 && this->zhen_duixiang->tag == "player")
			{
				for (int i = this->zhen_duixiang->position_x +this->zhen_duixiang->player_weight- this->zhen_duixiang->attack3_collision[1].x; i < this->zhen_duixiang->position_x + this->zhen_duixiang->player_weight - this->zhen_duixiang->attack3_collision[0].x; i++)
				{
					for (int j = this->zhen_duixiang->position_y + this->zhen_duixiang->attack3_collision[0].y; j < this->zhen_duixiang->position_y + this->zhen_duixiang->attack3_collision[1].y; j++)
					{
						if (i > 0 && i < 1000 && j>0 && j < 400)                                //保护程序不溢出写入
						this->zhen_duixiang->PHY_SYS->phy_mapA[i][j] = 3;
					}
				}
			}

			this->attack3_jishu++;
			if (this->attack3_jishu >= this->zhen_duixiang->get_animation().attack1->num)
			{
				this->attack3_jishu = 0;
				this->zhen_duixiang->player_state = 0;
			}
			break;
		}

		return;
	}


	if (this->zhen_duixiang->RIGBODY->direction == 1 && this->zhen_duixiang->RIGBODY->volocity_y < -0.01)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Jump->GetImage_black(), (this->zhen_duixiang->player_weight * this->Jump_jishu), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Jump->GetImage(), (this->zhen_duixiang->player_weight * this->Jump_jishu), 0, SRCPAINT);

		this->Jump_jishu++;
		if (this->Jump_jishu >= this->zhen_duixiang->get_animation().Jump->num)
		{
			this->Jump_jishu = 0;
		}
		return;
	}
	else if (this->zhen_duixiang->RIGBODY->direction == 0 && this->zhen_duixiang->RIGBODY->volocity_y < -0.01)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().JumpR->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().Jump->num-1-this->Jump_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().JumpR->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().Jump->num - 1 - this->Jump_jishu)), 0, SRCPAINT);

		this->Jump_jishu++;
		if (this->Jump_jishu >= this->zhen_duixiang->get_animation().Jump->num)
		{
			this->Jump_jishu = 0;
		}
		return;
	}

	if (this->zhen_duixiang->RIGBODY->direction==1&&this->zhen_duixiang->RIGBODY->volocity_y>0.01)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Fall->GetImage_black(), (this->zhen_duixiang->player_weight * this->Fall_jishu), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Fall->GetImage(), (this->zhen_duixiang->player_weight * this->Fall_jishu), 0, SRCPAINT);

		this->Fall_jishu++;
		if (this->Fall_jishu >= this->zhen_duixiang->get_animation().Fall->num)
		{
			this->Fall_jishu = 0;
		}
		return;
	}
	else if (this->zhen_duixiang->RIGBODY->direction == 0 && this->zhen_duixiang->RIGBODY->volocity_y > 0.01)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().FallR->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().Fall->num - 1 - this->Fall_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().FallR->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().Fall->num - 1 - this->Fall_jishu)), 0, SRCPAINT);

		this->Fall_jishu++;

		if (this->Fall_jishu >= this->zhen_duixiang->get_animation().Fall->num)
		{
			this->Fall_jishu = 0;
		}
		return;
	}



	if ((this->zhen_duixiang->OnMove ==1)&&this->zhen_duixiang->RIGBODY->direction==1)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Run->GetImage_black(), (this->zhen_duixiang->player_weight * this->Run_jishu), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Run->GetImage(), (this->zhen_duixiang->player_weight * this->Run_jishu), 0, SRCPAINT);

		this->Run_jishu++;
		if (this->Run_jishu >= this->zhen_duixiang->get_animation().Run->num)
		{
			this->Run_jishu = 0;
		}
		return;
	}
	else if ( this->zhen_duixiang->OnMove == 1 && zhen_duixiang->RIGBODY->direction == 0)

	{

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().RunR->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().RunR->num - 1 - this->Run_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().RunR->GetImage(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().RunR->num - 1 - this->Run_jishu)), 0, SRCPAINT);

		this->Run_jishu++;
		if (this->Run_jishu >= this->zhen_duixiang->get_animation().Run->num)
		{
			this->Run_jishu = 0;
		}
		
		
		return;
	}


	if (this->zhen_duixiang->RIGBODY->direction == 1&& this->zhen_duixiang->OnMove == 0)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Idle->GetImage_black(), (this->zhen_duixiang->player_weight * this->Idle_jishu), 0, SRCAND);//透明化

 		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().Idle->GetImage(), (this->zhen_duixiang->player_weight * this->Idle_jishu), 0, SRCPAINT);
		this->Idle_jishu++;
		if (this->Idle_jishu >= this->zhen_duixiang->get_animation().Idle->num)
		{
			this->Idle_jishu = 0;
		}
	}
	else if (this->zhen_duixiang->RIGBODY->direction == 0 && this->zhen_duixiang->OnMove == 0)
	{
		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().IdleR->GetImage_black(), (this->zhen_duixiang->player_weight * (this->zhen_duixiang->get_animation().Idle->num - 1 - this->Idle_jishu)), 0, SRCAND);//透明化

		putimage(this->zhen_duixiang->position_x, this->zhen_duixiang->position_y, this->zhen_duixiang->player_weight, this->zhen_duixiang->player_hight, &this->zhen_duixiang->get_animation().IdleR->GetImage(), (this->zhen_duixiang->player_weight * ( this->zhen_duixiang->get_animation().Idle->num-1-this->Idle_jishu)), 0, SRCPAINT);
		this->Idle_jishu++;
		if (this->Idle_jishu >= this->zhen_duixiang->get_animation().Idle->num)
		{
			this->Idle_jishu = 0;
		}
	}
}


Boss::Boss(float B_x, float B_y, GameObject* ToFindPlayer, Physics_System* ph) :player(B_x, B_y)
{
	this->COLLISION->collision_tag = "attack";
	this->tag = "attack";
	To_Find_Player = ToFindPlayer;
	this->contoller = new Boss_script(this);
	if (this->COLLISION != NULL)
	{
		delete COLLISION;
		COLLISION = NULL;
	}
	this->COLLISION = new collision(this, "obstacle", ph);      //初始化碰撞体

	zuobiao foo1(70, 62);
	COLLISION->collision_picture1 = foo1;
	foo1.set_zuobiao(97, 102);
	COLLISION->collision_picture2 = foo1;

}



Boss_script::Boss_script(Boss* Duixiang_) :script(Duixiang_)
{
	duixianG = Duixiang_;
	distance_to_player = 1000;
	
}


void Boss_script::Show_NPC_Happen()
{
	this->duixianG->MyAnimator->show_player();
}

void Boss_script::Do_script()
{
	if (this->duixianG->position_x < 5)
		this->duixianG->position_x = 5;
	else if (this->duixianG->position_x > 995)
		this->duixianG->position_x = 995;
	if (this->duixianG->position_y > 400)
		this->duixianG->position_y = 0;
	    distance_to_player = (this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x )) > 0 ? (this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x )) : -(this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x ));

		if (duixianG-> wudi == 0 && this->duixianG->COLLISION->On_attack_collision() )
		{
			this->duixianG->TAKE_HIT();
		}

		if (this->duixianG->player_state >= 0 && this->duixianG->player_state < 90)
		{
			if ( this->random_dash() && (this->duixianG->player_state == 0 || this->duixianG->player_state == 4 || this->duixianG->player_state == 5) && (this->duixianG->Dash_sleep == 0))
			{
				
				mciSendString("close audio\\main.wav", 0, 0, 0);
				mciSendString("close audio\\buttom.wav", 0, 0, 0);
				mciSendString("close audio\\player\\dash.wav", 0, 0, 0);
				mciSendString("open audio\\player\\dash.wav", 0, 0, 0);
				mciSendString("play audio\\player\\dash.wav", 0, 0, 0);

				this->duixianG->Dash_sleep++;
				this->duixianG->wudi = 12;
				this->duixianG->player_state = 95;
					this->duixianG->RIGBODY->volocity_x = (this->duixianG->RIGBODY->direction == 1 ? 1 : -1) * this->duixianG->dash_v;
					this->duixianG->RIGBODY->volocity_y = 0;
			}
			if ((distance_to_player<30) && this->duixianG->attack_sleep == 0 && (this->duixianG->player_state == 0 || this->duixianG->player_state == 4 || this->duixianG->player_state == 5))
			{
				//attack函数
				mciSendString("close audio\\main.wav", 0, 0, 0);
				mciSendString("close audio\\buttom.wav", 0, 0, 0);
				mciSendString("close audio\\player\\dash.wav", 0, 0, 0);
				mciSendString("close audio\\player\\kill.wav", 0, 0, 0);
				mciSendString("open audio\\player\\kill.wav", 0, 0, 0);
				mciSendString("play audio\\player\\kill.wav", 0, 0, 0);
				this->duixianG->attack_sleep++;
				switch (this->duixianG->player_state)
				{
				case 0:
					this->duixianG->player_state = 1;
					break;
				case 4:
					this->duixianG->player_state = 2;
					break;
				case 5:
					this->duixianG->player_state = 3;
					break;
					this->duixianG->OnMove = 0;
				}
			}
			if (this->duixianG->position_x<this->Duixiang->To_Find_Player->position_x)
			{
				if (this->duixianG->RIGBODY->volocity_x < this->duixianG->max_vx)
				{
					this->duixianG->RIGBODY->volocity_x += this->duixianG->vx;
				}
				{
					this->duixianG->OnMove = 1;
					this->duixianG->RIGBODY->direction = 1;
				}
			}
			else if (this->duixianG->position_x >=this->Duixiang->To_Find_Player->position_x)
			{
				if (this->duixianG->RIGBODY->volocity_x > -this->duixianG->max_vx)
				{
					this->duixianG->RIGBODY->volocity_x += -this->duixianG->vx;
				}
				{
					this->duixianG->OnMove = 1;
					this->duixianG->RIGBODY->direction = 0;
				}
			}
			else
			{
				this->duixianG->OnMove = 0;
			}
			if ((rand()%1000)<this->jump_posi)
			{
				if (this->duixianG->COLLISION->On_obstacle_collision_D())
				{
					this->duixianG->RIGBODY->volocity_y = this->duixianG->vJump;
				}
				this->duixianG->OnMove = 0;
			}

		}
		else
		{
			this->duixianG->player_state++;

			this->duixianG->OnMove = 0;
		}
		if (this->duixianG->player_state == 103)
		{
			this->duixianG->player_state = 0;
		}
		if (this->duixianG->attack_sleep != 0)
		{
			this->duixianG->attack_sleep++;
		}
		if (this->duixianG->attack_sleep >= 7)
		{
			this->duixianG->attack_sleep = 0;
		}
		if (this->duixianG->wudi > 0)
		{
			this->duixianG->wudi++;
			if (this->duixianG->wudi == 17)
			{
				this->duixianG->wudi = 0;
			}
		}
		if (this->duixianG->Dash_sleep > 0)
		{
			this->duixianG->Dash_sleep++;
			if (this->duixianG->Dash_sleep >= 18)
			{
				this->duixianG->Dash_sleep = 0;
			}
		}
		if (this->duixianG->RIGBODY->volocity_x > 16 || this->duixianG->RIGBODY->volocity_x < -16)
		{
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
			this->duixianG->RIGBODY->liner_Drag();
		}

		if ((this->duixianG->COLLISION->On_obstacle_collision_D()) && this->duixianG->RIGBODY->volocity_y > 0)//判断条件为collision脚是否着地
		{
			this->duixianG->RIGBODY->volocity_y = 0;
		}
		this->duixianG->RIGBODY->volocity_DO();
}

bool Boss_script::random_dash()
{
	if((rand()%1000)<dash_posi)
	return 1;
	else
	{
		return 0;
	}
}

void Boss_script::Collision_Happen()
{
}
