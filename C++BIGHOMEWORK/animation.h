#pragma once
#include<vector>
#include<graphics.h>
using namespace std;

class animation 
{
public:
	animation(int num_zhen1, char file[], char file_black[], int ani_weight, int ani_hight);//fileΪ��ַ  �ߺͿ��ǵ���ͼ�ĸ߿�

	/// <����������������Ķ�����ֻ����TakeHit  Attack��������!!!!!!!>
	void Play_animation(float x, float y, float weight, float hight,int& active_trigger);
	void Play_animation(float x, float y, float weight, float hight);
	void Play_animationR(float x, float y, float weight, float hight);
	//��һ��int& ��¼���ŵ�ʱ���
	IMAGE& GetImage();
	IMAGE& GetImage_black();
	int num;////������ͼƬ��
	//////////////////////////////////////
	

	


private:
	IMAGE ani_zhen;//���ڴ洢ÿһ֡��ͼƬ
	IMAGE ani_zhen_black;
	int foo_aa;




};


