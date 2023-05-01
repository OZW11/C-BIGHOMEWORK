#include "animation.h"


#undef UNICODE
#undef _UNICODE





animation::animation(int num_zhen1, char file[], char file_black[],int ani_weight, int ani_hight)
{
	loadimage(&this->ani_zhen, file);
	loadimage(&this->ani_zhen_black, file_black);
	this->num = num_zhen1;
	foo_aa = 0;
}


/// <连续播放一个什么动画>
/// 
/// </summary>
/// <param name="x"></播放处x坐标>
/// <param name="y"></播放处y坐标>
/// <param name="weight"></宽>
/// <param name="hight"></高>
/// <param name="active_trigger"></当为>=0时开始播放，-1闲置，激活时要跳过所有Player控制>
void animation::Play_animation(float x, float y,float weight,float hight,int& active_trigger)
{ 
	if (active_trigger <0)
	{
		active_trigger = 0;
	}
	
		putimage(x, y,weight,hight, &this->ani_zhen_black,(weight*active_trigger), 0, SRCAND);//透明化
		
		putimage(x, y, weight, hight, &this->ani_zhen,  (weight * active_trigger), 0,SRCPAINT);//彩色化
		
		active_trigger++;
	
		if (active_trigger == this->num)
		{
			active_trigger = -1;
		}
		
	return;
}

void animation::Play_animation(float x, float y, float weight, float hight)
{
	

	putimage(x, y, weight, hight, &this->ani_zhen_black, (weight * foo_aa), 0, SRCAND);//透明化

	putimage(x, y, weight, hight, &this->ani_zhen, (weight * foo_aa), 0, SRCPAINT);//彩色化

	foo_aa++;

	if (foo_aa >= this->num)
	{
		foo_aa = 0;
	}

	return;
}

void animation::Play_animationR(float x, float y, float weight, float hight)
{
	
	putimage(x, y, weight, hight, &this->ani_zhen_black, (weight * (this->num-1-foo_aa)), 0, SRCAND);//透明化

	putimage(x, y, weight, hight, &this->ani_zhen_black, (weight * (this->num - 1 - foo_aa)), 0, SRCPAINT);//彩色化

	foo_aa++;

	if (foo_aa >= this->num)
	{
		foo_aa = 0;
	}

	return;
}

IMAGE& animation::GetImage()
{
	return ani_zhen;
}

IMAGE& animation::GetImage_black()
{
	return ani_zhen_black;
}
