#pragma once
#include"player.h"
#include"AudioClip.h"
//��ʱ���ð���include"Physics_System"


class scene
{
public:
	scene(char sky_name[]);

	~scene();
	
	void UPDATE_show_scene();                         //�����ʱ�亯��  ������³���
	
	player* PLAYER;

	

private:
	IMAGE skybox;

	static int die_time;

	void camera_shake(int shake_range, int shake_rangey);

	const int zhenglv=26;                           //����֡��//sleep()
	
	animation* blood_back;

	animation* heart;

	animation* power_tiao;
};

