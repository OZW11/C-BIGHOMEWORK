#pragma once
#include"player.h"
#include"AudioClip.h"
//暂时不用包含include"Physics_System"


class scene
{
public:
	scene(char sky_name[]);

	~scene();
	
	void UPDATE_show_scene();                         //程序的时间函数  负责更新场景
	
	player* PLAYER;

	

private:
	IMAGE skybox;

	static int die_time;

	void camera_shake(int shake_range, int shake_rangey);

	const int zhenglv=26;                           //设置帧数//sleep()
	
	animation* blood_back;

	animation* heart;

	animation* power_tiao;
};

