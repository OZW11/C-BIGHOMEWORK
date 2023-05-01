#pragma once

class GameObject;

class rigbody
{
public:
	rigbody(GameObject* Duixiang);
	float volocity_x;
	float volocity_y;
	void liner_Drag();
	void volocity_DO();
	bool direction;           //值为1时向右，为0时向左
	GameObject* dui_xiang;
	float Gravity = 2.9;   //重力大小
private:
	const float Drag_Power=1.34;//摩擦力的大小


};

