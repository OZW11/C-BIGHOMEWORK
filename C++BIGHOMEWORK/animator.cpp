#include "animator.h"
#include"player.h"

animator::animator(GameObject* DUIXIANG)
{
	this->diuxiang = DUIXIANG;
	this->bofang_jishuqi = -1;

}

animator::animator()
{
	this->diuxiang = NULL;
}

/// <summary>
/// ����animation��[Play_num]�Ķ���
/// </summary>
/// <param name="Play_num"></�������>
void animator::animation_Play(int Play_num)
{
	this->diuxiang->ANIMATION[Play_num]->Play_animation(this->diuxiang->position_x, this->diuxiang->position_y, this->diuxiang->weight,this->diuxiang->hight);
}


