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


/// <��������һ��ʲô����>
/// 
/// </summary>
/// <param name="x"></���Ŵ�x����>
/// <param name="y"></���Ŵ�y����>
/// <param name="weight"></��>
/// <param name="hight"></��>
/// <param name="active_trigger"></��Ϊ>=0ʱ��ʼ���ţ�-1���ã�����ʱҪ��������Player����>
void animation::Play_animation(float x, float y,float weight,float hight,int& active_trigger)
{ 
	if (active_trigger <0)
	{
		active_trigger = 0;
	}
	
		putimage(x, y,weight,hight, &this->ani_zhen_black,(weight*active_trigger), 0, SRCAND);//͸����
		
		putimage(x, y, weight, hight, &this->ani_zhen,  (weight * active_trigger), 0,SRCPAINT);//��ɫ��
		
		active_trigger++;
	
		if (active_trigger == this->num)
		{
			active_trigger = -1;
		}
		
	return;
}

void animation::Play_animation(float x, float y, float weight, float hight)
{
	

	putimage(x, y, weight, hight, &this->ani_zhen_black, (weight * foo_aa), 0, SRCAND);//͸����

	putimage(x, y, weight, hight, &this->ani_zhen, (weight * foo_aa), 0, SRCPAINT);//��ɫ��

	foo_aa++;

	if (foo_aa >= this->num)
	{
		foo_aa = 0;
	}

	return;
}

void animation::Play_animationR(float x, float y, float weight, float hight)
{
	
	putimage(x, y, weight, hight, &this->ani_zhen_black, (weight * (this->num-1-foo_aa)), 0, SRCAND);//͸����

	putimage(x, y, weight, hight, &this->ani_zhen_black, (weight * (this->num - 1 - foo_aa)), 0, SRCPAINT);//��ɫ��

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
