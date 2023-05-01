#pragma once
#include "GameObject.h"
#include<conio.h>

class player_animator;
class player_ani
{

public:
    player_ani();
    ~player_ani();
    animation* TakeHit;//死动画
    animation* attack1;//死动画
    animation* attack2;//死动画
    animation* attack3;//死动画
    animation* Dash;//死动画
    animation* death;//死动画
    animation* Fall;//活动画
    animation* Idle;//活动画
    animation* Jump;//活动画
    animation* Run;//活动画
    animation* TakeHitR;//死动画
    animation* attack1R;//死动画
    animation* attack2R;//死动画
    animation* attack3R;//死动画
    animation* deathR;//死动画
    animation* DashR;//死动画
    animation* FallR;//活动画
    animation* IdleR;//活动画
    animation* JumpR;//活动画
    animation* RunR;//活动画
};
 

class player;
class player_animator :public animator
{
public:
    player_animator(player *duixiang) ;
     void show_player();
     player* zhen_duixiang;
private:
     int Fall_jishu;
     int Idle_jishu;
     int Jump_jishu;
     int Run_jishu;
     int attack1_jishu;
     int attack2_jishu;
     int attack3_jishu;
     int TakeHit_jishu;
     int death_jishu;
     int Dash_jishu;
};



class player :public GameObject
{
    friend class fruit_script;
    friend class player_animator;
    friend class scene;
    friend class Boss_script;
public:
    player(float x,float y);                    //初始化位置x，y
    player_animator* MyAnimator;
    player_ani get_animation();
    void P_script();
    void TAKE_HIT();
    int dazhaotime = 0;                        //用于大招的震动效果
    Physics_System* PHY_SYS;
    void conect_PHYSYS();
    vector<GameObject*> GameObject_list;

private:
    player_ani Player_Animation;              //忘记写成父类中的AMNIMATION了(┬┬﹏┬┬)
    const int max_vx = 10;                    //最大速度
    const int vx = 3;                    //符号用错了 就将就成加速度吧//加速度
    const int vJump = -18;
    const int dash_v = 78;
    int player_state;                         //这个量用于控制玩家的特殊状态//当0时可正常操作//为负数时不能操作//为1、2、3代表正在进行攻击123,不能为4 5 为攻击准备状态 6必须闲置 // >50时代表正在冲刺//
    bool OnMove;
    const int player_weight = 160;
    const int player_hight = 111;
    int attack_sleep;                                  //当attsleep为0时才可攻击，攻击后赋值为1，每次调用script时++值为6时归0
    int Dash_sleep;                                    //当Dash_sleep为0时才可dash，dash后赋值为1，每次调用script时++值为24时归0
    zuobiao attack1_collision[2];
    zuobiao attack2_collision[2];
    zuobiao attack3_collision[2];
    int backgrondmusic_xunhanqi;
    void Dazhao();
    int no_gravity = 0;
};



class Boss :public player
{

public:
    Boss(float B_x, float B_y, GameObject* ToFindPlayer,Physics_System* ph);



private:


};

class Boss_script :public script
{
public:
    Boss_script(Boss* Duixiang_);//posi是可能性按千分之计算
    Boss* duixianG;
    void Show_NPC_Happen();
    void Do_script();
    int distance_to_player;
    const int jump_posi=45;
    const int dash_posi=32;
private:
    const int jifeix=60;
   const int jifeiy=30;
   bool random_dash();

   // 通过 script 继承
   virtual void Collision_Happen() override;
};