#pragma once




class GameObject;
class animator
{
public:
	animator(GameObject* DUIXIANG);
	animator();
	/// <summary>
	/// show_object函数负责将该展现的图片展现
	/// </summary>
	//virtual void show_object();这句话会报错“无法解析的外部命令”，，暂时不这么写


	int bofang_jishuqi;                //值为0时开始播放，闲置状态为-1
	GameObject* diuxiang;

	void animation_Play(int Play_num);            

private:
	



};

