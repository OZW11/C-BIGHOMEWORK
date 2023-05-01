#include "rigbody.h"
#include"GameObject.h"
rigbody::rigbody(GameObject* Duixiang)
{
	this->volocity_x = 0;
	this->volocity_y = 0;
	this->dui_xiang = Duixiang;
	this->direction = 1;
}
void rigbody::liner_Drag()
{
	if(this->volocity_x>2)
	{
		this->volocity_x -= this->Drag_Power;
	}
	else if (this->volocity_x < -2)
	{
		this->volocity_x += this->Drag_Power;
	}
	else
	{
		this->volocity_x = 0;
	}
}
void rigbody::volocity_DO()//先计入重力,obstacle，再速度转位置
{
	if(this->dui_xiang->COLLISION->On_obstacle_collision_D())
	this->liner_Drag();
	if(!(this->dui_xiang->COLLISION->On_obstacle_collision_D()))
	{
		volocity_y += this->Gravity;
	}
	if ((this->dui_xiang->COLLISION->On_obstacle_collision_U()) && volocity_y < 0)
	{
		volocity_y = 0;
	}
	if (this->dui_xiang->tag == "player")
	{
		if (this->dui_xiang->COLLISION->On_obstacle_collision_F()&& this->volocity_x > 0)
		{
			this->volocity_x = 0;
		}
		 if (this->dui_xiang->COLLISION->On_obstacle_collision_B() && this->volocity_x < 0)
		 {
			this->volocity_x = 0;
		 }
	}

	this->dui_xiang->position_x += this->volocity_x;
	this->dui_xiang->position_y += this->volocity_y;
}
