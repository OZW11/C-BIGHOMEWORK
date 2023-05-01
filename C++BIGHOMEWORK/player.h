#pragma once
#include "GameObject.h"
#include<conio.h>

class player_animator;
class player_ani
{

public:
    player_ani();
    ~player_ani();
    animation* TakeHit;//������
    animation* attack1;//������
    animation* attack2;//������
    animation* attack3;//������
    animation* Dash;//������
    animation* death;//������
    animation* Fall;//���
    animation* Idle;//���
    animation* Jump;//���
    animation* Run;//���
    animation* TakeHitR;//������
    animation* attack1R;//������
    animation* attack2R;//������
    animation* attack3R;//������
    animation* deathR;//������
    animation* DashR;//������
    animation* FallR;//���
    animation* IdleR;//���
    animation* JumpR;//���
    animation* RunR;//���
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
    player(float x,float y);                    //��ʼ��λ��x��y
    player_animator* MyAnimator;
    player_ani get_animation();
    void P_script();
    void TAKE_HIT();
    int dazhaotime = 0;                        //���ڴ��е���Ч��
    Physics_System* PHY_SYS;
    void conect_PHYSYS();
    vector<GameObject*> GameObject_list;

private:
    player_ani Player_Animation;              //����д�ɸ����е�AMNIMATION��(�ЩЩn�Щ�)
    const int max_vx = 10;                    //����ٶ�
    const int vx = 3;                    //�����ô��� �ͽ��ͳɼ��ٶȰ�//���ٶ�
    const int vJump = -18;
    const int dash_v = 78;
    int player_state;                         //��������ڿ�����ҵ�����״̬//��0ʱ����������//Ϊ����ʱ���ܲ���//Ϊ1��2��3�������ڽ��й���123,����Ϊ4 5 Ϊ����׼��״̬ 6�������� // >50ʱ�������ڳ��//
    bool OnMove;
    const int player_weight = 160;
    const int player_hight = 111;
    int attack_sleep;                                  //��attsleepΪ0ʱ�ſɹ�����������ֵΪ1��ÿ�ε���scriptʱ++ֵΪ6ʱ��0
    int Dash_sleep;                                    //��Dash_sleepΪ0ʱ�ſ�dash��dash��ֵΪ1��ÿ�ε���scriptʱ++ֵΪ24ʱ��0
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
    Boss_script(Boss* Duixiang_);//posi�ǿ����԰�ǧ��֮����
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

   // ͨ�� script �̳�
   virtual void Collision_Happen() override;
};