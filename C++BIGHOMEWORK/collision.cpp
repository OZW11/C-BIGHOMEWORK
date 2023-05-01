#include "collision.h"
#include"Physics_System.h"
#include"GameObject.h"
#include<math.h>



collision::collision(GameObject* Duixiang,string tagc, Physics_System* PHY_)
{
	this->duixiang = Duixiang;
	this->PHY = PHY_;
	active=1;
	collision_tag = tagc;
}




int collision::On_attack_collision()
{
	if (this->active==1)
	{
		for (int i = this->collision_picture1.x + this->duixiang->position_x; i < this->collision_picture2.x + this->duixiang->position_x; i++)
		{
			for (int j = this->collision_picture1.y + this->duixiang->position_y; j < this->collision_picture2.y + this->duixiang->position_y; j++)
			{
				if (this->duixiang->tag == "player"&&i>0&&i<1000&&j>0&&j<400)
				{
				    if (this->PHY->phy_mapA[i][j] == 2)
				    {
						return 1;
					}
					
					
				}
				else if (i > 0 && i < 1000 && j>0 && j < 400&&this->PHY->phy_mapA[i][j] == 3)
				{
						return 1;	
				}
			}
		}

	}
	return 0;
}


///这些碰撞代码以输出的真实位置计算是否碰撞，未考虑速度的不连续性，会导致穿模问题
//bool collision::On_obstacle_collision_B()
//{
//	for (int j = this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y; j < this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y-10; j++)
//	{
//		if (this->PHY->phy_map[-1 + (int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x)][j] == 1)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//bool collision::On_obstacle_collision_F()
//{
//	for (int j = this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y; j < this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y-10; j++)
//	{
//		if (this->PHY->phy_map[1 + (int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x)][j] == 1)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//bool collision::On_obstacle_collision_D()
//{
//	for (int i = this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x; i < this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x; i++)
//	{
//		if (this->PHY->phy_map[i][1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y)] == 1)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//bool collision::On_obstacle_collision_U()
//{
//	for (int i = this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x; i < this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x; i++)
//	{
//		if (this->PHY->phy_map[i][-1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y)] == 1)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

bool collision::On_obstacle_collision_B()
{
	for (int j = this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y; j < this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y - 5; j++)
	{
		if (this->duixiang->RIGBODY->volocity_x < 0)
		{
			for (int ll=-1;ll>= this->duixiang->RIGBODY->volocity_x;ll--)
			{
				if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y) + ll) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x + ll))>0&&(this->PHY->phy_map[  ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x + ll))%1000][j % 400] == 1||(this->PHY->phy_map[((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x + ll) )% 1000][j % 400] == 2) && this->duixiang->tag != "player"))
				{
					return 1;
				}
			}
		}
		else
		{
			if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y) ) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x ))>0&& (this->PHY->phy_map[( - 1 + (int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x)) % 1000][j % 400] == 1 || ((this->PHY->phy_map[(int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x) % 1000][j % 400] == 2) && this->duixiang->tag != "player")))
			{
				
				return 1;
			}
		}
	}
	return 0;
}

bool collision::On_obstacle_collision_F()
{
	for (int j = this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y; j < this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y - 5; j++)
	{
		if (this->duixiang->RIGBODY->volocity_x > 0)
		{
			for (int ll = 1; ll <= this->duixiang->RIGBODY->volocity_x; ll++)
			{
				if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y) + ll) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x + ll)) > 0 && (this->PHY->phy_map[ (int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x + ll) % 1000][j % 400] == 1||(this->PHY->phy_map[(int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x + ll) % 1000][j % 400] ==2&&this->duixiang->tag!="player")))
				{
					
					return 1;
				}
			}
		}
		else
		{
			if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y) ) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x )) > 0 && (this->PHY->phy_map[(1 + (int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x) )% 1000][j % 400] == 1 || (this->PHY->phy_map[(int)((this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x) ) % 1000][j % 400] ==2 && this->duixiang->tag != "player")))
			{
				
				return 1;
			}
		}
	}
	return 0;
}

bool collision::On_obstacle_collision_D()
{
	for (int i = this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x; i < this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x; i++)
	{
		if (this->duixiang->RIGBODY->volocity_y > 0)
		{
			for (int ll = 0; ll < this->duixiang->RIGBODY->volocity_y; ll++)
			{
				if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y) + ll) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x + ll)) > 0 && i>0&&(this->PHY->phy_map[i % 1000][(1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y + ll)) % 400] == 1 || (this->duixiang->tag != "player"&& this->PHY->phy_map[i % 1000][(1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y + ll)) % 400] == 2)))
				{
					return 1;
				}
			}
		}
		else
			if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y)) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x )) > 0 && (this->PHY->phy_map[i % 1000][(1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y)) % 400] == 1 || (this->duixiang->tag != "player" && this->PHY->phy_map[i % 1000][(1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture2.y )) % 400] == 2)))
			{
				return 1;
			}
	}
	return 0;
}

bool collision::On_obstacle_collision_U()
{
	for (int i = this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x; i < this->duixiang->position_x + this->duixiang->COLLISION->collision_picture2.x; i++)
	{
		if (this->duixiang->RIGBODY->volocity_y < 0)
		{
			for (int ll = 0; ll > this->duixiang->RIGBODY->volocity_y; ll--)
			{
				if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y)+ll) > 0 && ((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x + ll)) > 0 && (this->PHY->phy_map[i % 1000][( - 2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y + ll)) % 400] == 1 || (this->duixiang->tag != "player" && this->PHY->phy_map[i % 1000][( - 1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y + ll)) % 400] == 2)))
				{
					this->duixiang->RIGBODY->volocity_y = 0;
					return 1;
				}
			}
		}
		else
		{
			if ((-2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y ))>0&&((int)(this->duixiang->position_x + this->duixiang->COLLISION->collision_picture1.x )) > 0 && (this->PHY->phy_map[i % 1000][( - 2 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y))%400] == 1 || (this->duixiang->tag != "player" && this->PHY->phy_map[i % 1000][-1 + (int)(this->duixiang->position_y + this->duixiang->COLLISION->collision_picture1.y)] == 2)))
			{
				return 1;
			}
		}
	}
	return 0;
}