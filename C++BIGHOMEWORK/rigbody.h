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
	bool direction;           //ֵΪ1ʱ���ң�Ϊ0ʱ����
	GameObject* dui_xiang;
	float Gravity = 2.9;   //������С
private:
	const float Drag_Power=1.34;//Ħ�����Ĵ�С


};

