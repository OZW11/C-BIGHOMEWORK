#pragma once




class GameObject;
class animator
{
public:
	animator(GameObject* DUIXIANG);
	animator();
	/// <summary>
	/// show_object�������𽫸�չ�ֵ�ͼƬչ��
	/// </summary>
	//virtual void show_object();��仰�ᱨ���޷��������ⲿ���������ʱ����ôд


	int bofang_jishuqi;                //ֵΪ0ʱ��ʼ���ţ�����״̬Ϊ-1
	GameObject* diuxiang;

	void animation_Play(int Play_num);            

private:
	



};

