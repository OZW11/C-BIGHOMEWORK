
#include"player.h"

GameObject::GameObject(float x, float y,string tagname)
{
    this->position_x = x;
	this->position_y= y;
	tag = tagname;
	health = 3;
	this->RIGBODY = new rigbody(this);
	
}

GameObject::~GameObject()
{

	if (this->COLLISION != NULL)
		delete this->COLLISION;
	if (this->contoller != NULL)
		delete this->contoller;
	if (this->RIGBODY != NULL)
		delete this->RIGBODY;
	if (this->ANIMATOR != NULL)
		delete this->ANIMATOR;
	

}

Box::Box(float B_x, float B_y, string tagname, GameObject* ToFindPlayer,Physics_System* PHY_):GameObject(B_x,B_y,tagname)
{
	this->weight = 32;
	this->hight = 32;
	this->health = 9999;
	To_Find_Player = ToFindPlayer;                              //��ӹ�������

	char Boxc[] = { "animation\\Box\\Box.png" };//��ʼ������
	this->ANIMATION = new animation*[1];
	this->ANIMATION[0] = new animation(1, Boxc, Boxc, this->weight, this->hight);

	this->ANIMATOR = new animator(this);    //��ʼ������������

	this->RIGBODY = new rigbody(this);                          //��ʼ������

	this->COLLISION = new collision(this,"obstacle",PHY_);      //��ʼ����ײ��

	this->COLLISION->collision_picture1.x = 0;
	this->COLLISION->collision_picture1.y = 0;
	this->COLLISION->collision_picture2.x = this->weight;
	this->COLLISION->collision_picture2.y = this->hight;

	this->contoller = new Box_script(this);
}

fruit::fruit(int x_, int y_, string tag_, GameObject* ToFindPlayer, Physics_System* PHY_) :GameObject(x_, y_, tag_)
{

	this->weight = 23;
	this->hight = 21;
	this->health = 9999;
	To_Find_Player = ToFindPlayer;                              //��ӹ�������

	char fruitc[] = { "animation\\fruit\\power_fruit.png" };//��ʼ������
	char fruit_blackc[] = { "animation\\fruit\\power_fruit_black.png" };//��ʼ������

	this->ANIMATION = new animation * [1];
	this->ANIMATION[0] = new animation(7, fruitc, fruit_blackc, this->weight, this->hight);

	this->ANIMATOR = new animator(this);                        //��ʼ������������

	//this->RIGBODY = new rigbody(this);                          //��ʼ������

	this->COLLISION = new collision(this, tag_, PHY_);      //��ʼ����ײ��

	this->COLLISION->collision_picture1.x = 8;
	this->COLLISION->collision_picture1.y = 8;
	this->COLLISION->collision_picture2.x = 15;
	this->COLLISION->collision_picture2.y = 15;

	this->contoller = new fruit_script(this);
}

fruit::~fruit()
{
	if (this->ANIMATION[0] != NULL)
	{
		delete this->ANIMATION[0];
	}
	if (this->ANIMATION != NULL)
	{
		delete this->ANIMATION;
	}

}

Box::~Box()
{
	if (ANIMATION[0] != NULL)
	{
		delete ANIMATION[0];
	}
	if (ANIMATION != NULL)
	{
		delete ANIMATION;
	}
}

zhanwuzha::zhanwuzha(float B_x, float B_y, string tagname, GameObject* ToFindPlayer, Physics_System* PHY_) :GameObject(B_x, B_y, tagname)
{

	this->weight = 48;
	this->hight = 40;
	this->health = 3;
	To_Find_Player = ToFindPlayer;                              //��ӹ�������
	tag = "attack";

	char a_zhanwuzhac[] = { "animation\\zhanwuzha\\Run\\Run.png" };//��ʼ������
	char a_zhanwuzha_blackc[] = { "animation\\zhanwuzha\\Run\\Run_black.png" };//��ʼ������
	this->ANIMATION = new animation * [5];
	this->ANIMATION[0] = new animation(4, a_zhanwuzhac, a_zhanwuzha_blackc, this->weight, this->hight);
	char a_zhanwuzhaRc[] = { "animation\\zhanwuzha\\Run\\RunR.png" };//��ʼ������
	char a_zhanwuzha_blackRc[] = { "animation\\zhanwuzha\\Run\\Run_blackR.png" };//��ʼ������
	this->ANIMATION[1] = new animation(4, a_zhanwuzhaRc, a_zhanwuzha_blackRc, this->weight, this->hight);
	char ATTACKa_zhanwuzhac[] = { "animation\\zhanwuzha\\attack\\attack.png" };//��ʼ������
	char ATTACKa_zhanwuzha_blackc[] = { "animation\\zhanwuzha\\attack\\attack_black.png" };//��ʼ������
	this->ANIMATION[2] = new animation(8, ATTACKa_zhanwuzhac, ATTACKa_zhanwuzha_blackc, this->weight, this->hight);
	char ATTACKa_zhanwuzhaRc[] = { "animation\\zhanwuzha\\attack\\attackR.png" };//��ʼ������
	char ATTACKa_zhanwuzha_blackRc[] = { "animation\\zhanwuzha\\attack\\attack_blackR.png" };//��ʼ������
	this->ANIMATION[3] = new animation(8, ATTACKa_zhanwuzhaRc, ATTACKa_zhanwuzha_blackRc, this->weight, this->hight);
	char diec[] = { "animation\\zhanwuzha\\die\\die.png" };//��ʼ������
	char die_blackc[] = { "animation\\zhanwuzha\\die\\die_black.png" };//��ʼ������
	this->ANIMATION[4] = new animation(1, diec, die_blackc, this->weight, this->hight);

	this->ANIMATOR = new animator(this);                        //��ʼ������������

	this->RIGBODY = new rigbody(this);                          //��ʼ������

	this->COLLISION = new collision(this, "obstacle", PHY_);      //��ʼ����ײ��

	this->COLLISION->collision_picture1.x = 15;
	this->COLLISION->collision_picture1.y = 11;
	this->COLLISION->collision_picture2.x = 32;
	this->COLLISION->collision_picture2.y = 37;

	this->contoller = new zhanwuzha_script(this);

}


zhanwuzha::~zhanwuzha()
{
	for (int i = 0; i < 5; i++)
	{
		if (this->ANIMATION[i] != NULL)
		{
			delete this->ANIMATION[i];
			this->ANIMATION[i] = NULL;
		}
	}
	if (this->ANIMATION != NULL)
	{
		delete this->ANIMATION;
	}
}

script::script(GameObject* Duixiang_)
{
	this->Duixiang = Duixiang_;
	ani_num = 0;
}

Box_script::Box_script(GameObject* Duixiang_):script(Duixiang_)
{
//�ø�������˶���ָ��
}

float Box_script::boundance = 0.75;

void Box_script::Collision_Happen()
{
	if (this->Duixiang->position_x > this->Duixiang->To_Find_Player->position_x+55)//��55����Ϊ������ʼ�㲢�����˵���λ�ã���������
	{
		this->Duixiang->RIGBODY->volocity_x += 15;
		this->Duixiang->RIGBODY->volocity_y -=23;
	}
	else
	{
		this->Duixiang->RIGBODY->volocity_x += -15;
		this->Duixiang->RIGBODY->volocity_y -= 23;
	}
}

void Box_script::Show_NPC_Happen()
{
	this->Duixiang->ANIMATOR->animation_Play(this->ani_num);
}

void Box_script::Do_script()
{

	if ( this->Duixiang->COLLISION->On_attack_collision())
	{
		this->Collision_Happen();
	}

  if (this->Duixiang->COLLISION->On_obstacle_collision_B()&& this->Duixiang->RIGBODY->volocity_x<0)
	{
		/*if (this->Duixiang->RIGBODY->volocity_x < 0)
			this->Duixiang->RIGBODY->volocity_x = 0;*/                              //��ȫ�ǵ�����ײ
		this->Duixiang->RIGBODY->volocity_x = -this->Duixiang->RIGBODY->volocity_x; //��ȫ������ײ
	}
  if(this->Duixiang->COLLISION->On_obstacle_collision_F()&& this->Duixiang->RIGBODY->volocity_x>0)
	{

	/*	if (this->Duixiang->RIGBODY->volocity_x > 0)
			this->Duixiang->RIGBODY->volocity_x = 0;*/                                //��ȫ�ǵ�����ײ
		this->Duixiang->RIGBODY->volocity_x = -this->Duixiang->RIGBODY->volocity_x;  //��ȫ������ײ

	}
	this->Duixiang->COLLISION->On_obstacle_collision_U();
	this->Duixiang->COLLISION->On_obstacle_collision_D();


	if ((this->Duixiang->COLLISION->On_obstacle_collision_D()) && this->Duixiang->RIGBODY->volocity_y > 0)
	{
	
		this->Duixiang->RIGBODY->volocity_y*=-this->boundance;
		if (this->Duixiang->RIGBODY->volocity_y < 3)
			this->Duixiang->RIGBODY->volocity_y = 0;
	}
	

	this->Duixiang->RIGBODY->volocity_DO();

}

zhanwuzha_script::zhanwuzha_script(GameObject* Duixiang_, int speed_ , int a_speed_ , int jump_speed_ , int search_range_ , int dash_v_ ,int jump_posi_,int dash_posi_):script(Duixiang_)
{
	//�ø�������˶���ָ��
	this->Duixiang->RIGBODY->volocity_x = speed;
	this->Duixiang->RIGBODY->direction = this->Duixiang->RIGBODY->volocity_x > 0;
	this->distance_to_player = 1000;
	speed = speed_;
	a_speed = a_speed_;
	 jump_speed = -jump_speed_;
	search_range = search_range_;
	dash_v = dash_v_;
	jifeix = 40;
	jifeiy = 25;
	jump_posi = jump_posi_;
	dash_posi = dash_posi_;
}

void zhanwuzha_script::Collision_Happen()                                     //�ܹ�����Ϊ
{
	this->Duixiang->health--;                                  
	if (this->Duixiang->position_x > this->Duixiang->To_Find_Player->position_x + 55)//��55����Ϊ������ʼ�㲢�����˵���λ�ã���������
	{
		this->Duixiang->RIGBODY->volocity_x += jifeix;
		this->Duixiang->RIGBODY->volocity_y -= jifeiy;
	}
	else
	{
		this->Duixiang->RIGBODY->volocity_x += -jifeix;
		this->Duixiang->RIGBODY->volocity_y -= jifeiy;
	}
	//this->ani_num = 1;���˶���
	this->Duixiang->wudi = 1;
}

void zhanwuzha_script::Show_NPC_Happen()
{
	this->Duixiang->ANIMATOR->animation_Play(this->ani_num);
}

void zhanwuzha_script::Do_script()
{
	if (this->Duixiang->health > 0)
	{
		
		distance_to_player = (this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x + 55)) > 0 ? (this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x + 55)) : -(this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x + 55));
		if (this->Duixiang->COLLISION->On_attack_collision() && this->Duixiang->wudi < 1)
		{
			if (this->Duixiang->To_Find_Player->power < 12)
				this->Duixiang->To_Find_Player->power++;
			this->Collision_Happen();
		}
		else if (distance_to_player < search_range)
		{
			this->auto_attack();
		}
		else
		{
			if (this->Duixiang->RIGBODY->direction)
			{
				this->Duixiang->RIGBODY->volocity_x = speed;
			}
			else
			{
				this->Duixiang->RIGBODY->volocity_x = -speed;
			}
			if (this->Duixiang->RIGBODY->volocity_x > 0)
			{
				this->ani_num = 0;
			}
			else if (this->Duixiang->RIGBODY->volocity_x < 0)
			{
				this->ani_num = 1;
			}
		}

		if (this->Duixiang->COLLISION->On_obstacle_collision_D())
			this->random_jump();
		this->random_dash();
	}
	else
	{
		this->ani_num = 4;
	}

	if (this->Duixiang->COLLISION->On_obstacle_collision_B())
	{
		if (this->Duixiang->health > 0)
		{
			this->Duixiang->RIGBODY->volocity_x = speed;
			this->Duixiang->RIGBODY->direction = this->Duixiang->RIGBODY->volocity_x > 0;
		}
		else if(this->Duixiang->RIGBODY->volocity_x<0)
		{
			this->Duixiang->RIGBODY->volocity_x = -this->Duixiang->RIGBODY->volocity_x;
		}
	}
	if (this->Duixiang->COLLISION->On_obstacle_collision_F())
	{
		if (this->Duixiang->health > 0)
		{
			this->Duixiang->RIGBODY->volocity_x = -speed;
			this->Duixiang->RIGBODY->direction = this->Duixiang->RIGBODY->volocity_x > 0;
		}
		else if (this->Duixiang->RIGBODY->volocity_x > 0)
		{
			this->Duixiang->RIGBODY->volocity_x = -this->Duixiang->RIGBODY->volocity_x;
		}
	}
	this->Duixiang->COLLISION->On_obstacle_collision_U();                                 // �������Դ��������

	if ((this->Duixiang->COLLISION->On_obstacle_collision_D()) && this->Duixiang->RIGBODY->volocity_y > 0)
	{
		this->Duixiang->RIGBODY->volocity_y = 0;
	}
	
	this->Duixiang->RIGBODY->volocity_DO();
	
	if (this->Duixiang->wudi > 0)
	{
		this->Duixiang->wudi++;
		if (this->Duixiang->wudi == 12)
		{
			this->Duixiang->wudi = 0;
		}
	}
	if (this->Duixiang->RIGBODY->volocity_x > 16 || this->Duixiang->RIGBODY->volocity_x < -16)
	{
		this->Duixiang->RIGBODY->liner_Drag();
		this->Duixiang->RIGBODY->liner_Drag();
	}
}

void zhanwuzha_script::auto_attack()
{
	
	if ( this->distance_to_player< this->search_range/7&&(this->Duixiang->To_Find_Player->health>0))
	{
		if (this->Duixiang->RIGBODY->direction)
		{
			this->ani_num = 3;
		}
		else
		{
			this->ani_num = 2;
		}
    }
	else
	{
		if (this->Duixiang->RIGBODY->volocity_x > 0)
		{
			this->ani_num = 0;
		}
		else if (this->Duixiang->RIGBODY->volocity_x < 0)
		{
			this->ani_num = 1;
		}
	}
	{    //�����ܶ�
		if ((this->Duixiang->position_x - (this->Duixiang->To_Find_Player->position_x + 55)) < 0)//��55����Ϊ������ʼ�㲢�����˵���λ�ã���������
		{
			if (this->Duixiang->RIGBODY->volocity_x < speed)
			{
				this->Duixiang->RIGBODY->volocity_x += a_speed;
			}
		}
		else
		{
			if (this->Duixiang->RIGBODY->volocity_x > -speed)
			{
				this->Duixiang->RIGBODY->volocity_x -= a_speed;
			}
		}
	
	}
	

}

void zhanwuzha_script::random_jump()
{
	
	int foo_ = rand()%1001;
	if (foo_ < jump_posi)
	{
		this->Duixiang->RIGBODY->volocity_y += this->jump_speed;
	}
}

void zhanwuzha_script::random_dash()
{
	int foo_ = rand() % 1001;
	if (foo_ < dash_posi)
	{
		this->Duixiang->RIGBODY->volocity_x += this->Duixiang->RIGBODY->direction ? dash_v : -dash_v;
	}
	
}

fruit_script::fruit_script(GameObject* Duixiang_):script(Duixiang_)
{
//��ɽű�����ָ��
	activt_or_not = 1;
}

void fruit_script::Collision_Happen()
{
	
}

void fruit_script::Show_NPC_Happen()
{
	if(activt_or_not)
	this->Duixiang->ANIMATOR->animation_Play(this->ani_num);
}

void fruit_script::Do_script()
{
	if (activt_or_not < 1)
	{
		activt_or_not++;
		if (activt_or_not == 1)
		{
			this->Duixiang->COLLISION->active = 1;
		}
		return;
	}
	if ((this->Duixiang->COLLISION->On_obstacle_collision_B() || this->Duixiang->COLLISION->On_obstacle_collision_F() || this->Duixiang->COLLISION->On_obstacle_collision_U() || this->Duixiang->COLLISION->On_obstacle_collision_D())&&((player*)this->Duixiang->To_Find_Player)->player_state<50&& ((player*)this->Duixiang->To_Find_Player)->Dash_sleep!=0)
	{
		((player*)this->Duixiang->To_Find_Player)->Dash_sleep = 0;
		this->activt_or_not = -sleep_time;
		this->Duixiang->COLLISION->active = 0;
	}
	
}

