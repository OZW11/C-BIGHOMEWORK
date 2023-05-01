#pragma once
#include<vector>
#include<graphics.h>
using namespace std;

class animation 
{
public:
	animation(int num_zhen1, char file[], char file_black[], int ani_weight, int ani_hight);//file为地址  高和宽是单张图的高宽

	/// <这个函数播放连续的动画，只用于TakeHit  Attack等死动画!!!!!!!>
	void Play_animation(float x, float y, float weight, float hight,int& active_trigger);
	void Play_animation(float x, float y, float weight, float hight);
	void Play_animationR(float x, float y, float weight, float hight);
	//用一个int& 记录播放的时间点
	IMAGE& GetImage();
	IMAGE& GetImage_black();
	int num;////动画总图片数
	//////////////////////////////////////
	

	


private:
	IMAGE ani_zhen;//用于存储每一帧的图片
	IMAGE ani_zhen_black;
	int foo_aa;




};


