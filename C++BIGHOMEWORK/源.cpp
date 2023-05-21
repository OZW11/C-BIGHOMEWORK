
///////////////仿unity结构的游戏开发////////////////////////
#include"guanqia.h"
#include"joy-control.h"
#include <thread>
#include<time.h>

extern player* P1=new player(2, 250);
static animation V(1, Vc, V_blackc, 640, 400);
static animation talk_bolck(1, talk_blockc, talk_block_blackc, 1000, 400);
static guanqia* guan1;
///////////////////////////
scene* guanqia::My_Game_scene=NULL;
Physics_System* guanqia::PHY= NULL;
///////////////////
void RandomMap(guanqia* guan1);
int main()
{	
	static thread* t;
	cout << "选择游戏模式\na.键盘模式    b.街机模式";
	if (_getch()=='b')
	{
		t = new thread(co_main);
		t->detach();
	}
	cout << "\n欢迎游玩POWER MAN ヾ(≧▽≦*)o\n";
	system("pause");
	auto Window=initgraph(1000, 400);
	SetWindowText(Window,"POWER MAN");
	MoveWindow(Window,250,100,1000,440,1);
		char* mianfooc = new char[256] {"animation\\UI\\main.png"};                  //初始化动画main
		animation* mainfoo=new animation(13, mianfooc, mianfooc, 1000, 400);
		mciSendString("close audio\\main.wav", 0, 0, 0);
		mciSendString("open audio\\main.wav", 0, 0, 0);
		mciSendString("play audio\\main.wav", 0, 0, 0);
		for (int lla = 0; lla < mainfoo->num||lla==0; lla++)
		{
			mainfoo->Play_animation(0, 0, 1000, 400);
			Sleep(200);
		}
		delete[]mianfooc;
		mianfooc = NULL;
		delete mainfoo;
		mainfoo = NULL;
		settextcolor(RGB(0,0,0));
		settextstyle(50,0,"微软雅黑");
		setbkmode(TRANSPARENT);
	Sleep(6000);
	mciSendString("play audio\\backgrond.mp3", 0, 0, 0);
	//////场景1的静态数据////////////
	{
		bool **phy_map1= new bool*[1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <= 20 || i >= 980 || (i > 0 && i < 999 && j>114 && j < 146))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk1_1_fooc = new char[256] {"animation\\UI\\tlak11_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk1_1_fooc,1000,400);
		char* talk1_2_fooc = new char[256] { "animation\\UI\\tlak12_black.png"};
		guan1->add_ani(1, talkfooc, talk1_2_fooc, 1000, 400);
		char* talk1_3_fooc = new char[256] {"animation\\UI\\tlak13_black.png"};
		guan1->add_ani(1, talkfooc, talk1_3_fooc, 1000, 400);
		delete[] talk1_1_fooc;
		talk1_1_fooc = NULL;
		delete[] talkfooc;
		talkfooc = NULL;
		delete[] talk1_1_fooc;
		talk1_1_fooc = NULL;
		delete[] talk1_2_fooc;
		talk1_2_fooc = NULL;
		delete[] talk1_2_fooc;
		talk1_3_fooc = NULL; 
		delete[] sky_foo;
		sky_foo = NULL;
		
		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i]=NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	//////////////////////////

	////////////////////////
	for(int i=0;i<899;i+=30 )

	guan1->NEW_BOX(250, 157+33);
	guan1->NEW_BOX(250, 157);
	guan1->NEW_BOX(250, 127);
	guan1->NEW_BOX(250, 127 + 65);
	guan1->NEW_BOX(250, 127 + 65 + 33);
	//guan1->NEW_Boss(1000-250, 127 + 65 + 33);
	guan1->My_Game_scene->UPDATE_show_scene();

	////场景1的对话//////////////////
	{
		int j = 0;
		
		for (vector<animation>::iterator i = guan1->ani_scene.begin(); i < guan1->ani_scene.end(); i++)
		{
			talk_bolck.Play_animation(0, 20, 1000, 400);
			V.Play_animation(-70, 0, 640, 400);
			guan1->ani_scene[j].Play_animation(50, 0, 1000, 4000);
			Sleep(500);
			system("pause");
			mciSendString("close audio\\main.wav", 0, 0, 0);
			mciSendString("close audio\\buttom.wav", 0, 0, 0);
			mciSendString("open audio\\buttom.wav", 0, 0, 0);
			mciSendString("play audio\\buttom.wav", 0, 0, 0);
			j++;
			
		}
		talk_bolck.Play_animation(0, 20, 1000, 400);
		V.Play_animation(-70, 0, 640, 400);
		outtextxy(400, 260, "存档   B");
		outtextxy(400, 320, "读档   N");
		talk_bolck.Play_animation(0, 20, 1000, 400);
		V.Play_animation(-70, 0, 640, 400);
		outtextxy(400, 260, "自己找到过关的方法");
		outtextxy(400, 320, "共有8关");
		Sleep(500);
		system("pause");
	}
	//
	//////////////////////////////
	/////////update//////////////////
	int foop = 1;
/////////////////////////////////	foop = 0;
	while (foop)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}
		

		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();
		
		guan1->My_Game_scene->UPDATE_show_scene();
		
		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag=="attack"&&(*i)->health>0)
			{
				break;
			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
			
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}

	////////////////////////////////////////////////
///////////////关卡2///////////////////////////
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <= 20 || i >= 980 || (i > 0 && i < 999 && j>114 && j < 146))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox1.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk2_1_fooc = new char[256] { "animation\\UI\\tlak21_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk2_1_fooc, 1000, 400);
		delete[] talk2_1_fooc;
		talk2_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	//////场景2的对话//////////////////
	{
		int j = 0;

		for (vector<animation>::iterator i = guan1->ani_scene.begin(); i < guan1->ani_scene.end(); i++)
		{
			talk_bolck.Play_animation(0, 20, 1000, 400);
			V.Play_animation(-70, 0, 640, 400);
			guan1->ani_scene[j].Play_animation(50, 0, 1000, 4000);
			Sleep(500);
			system("pause");
			mciSendString("close audio\\main.wav", 0, 0, 0);
			mciSendString("close audio\\buttom.wav", 0, 0, 0);
			mciSendString("open audio\\buttom.wav", 0, 0, 0);
			mciSendString("play audio\\buttom.wav", 0, 0, 0);
			j++;
		}
	}
	foop = 1;
	//////////////////foop = 0;
	guan1->NEW_zhanwuzha(800, 150);
	guan1->NEW_BOX(250, 157 + 33);
	guan1->NEW_BOX(250, 157);
	while (foop)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();

		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;

			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
				
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}



	////////////关卡3///////////////////////////
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <= 20 || i >= 980 || (i > 0 && i < 999 && j>114 && j < 146))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk3_1_fooc = new char[256] { "animation\\UI\\tlak31_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk3_1_fooc, 1000, 400);
		delete[] talk3_1_fooc;
		talk3_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	//////场景3的对话//////////////////
	{
		int j = 0;

		for (vector<animation>::iterator i = guan1->ani_scene.begin(); i < guan1->ani_scene.end(); i++)
		{
			talk_bolck.Play_animation(0, 20, 1000, 400);
			V.Play_animation(-70, 0, 640, 400);
			guan1->ani_scene[j].Play_animation(50, 0, 1000, 4000);
			Sleep(500);
			system("pause");
			mciSendString("close audio\\main.wav", 0, 0, 0);
			mciSendString("close audio\\buttom.wav", 0, 0, 0);
			mciSendString("open audio\\buttom.wav", 0, 0, 0);
			mciSendString("play audio\\buttom.wav", 0, 0, 0);
			j++;
		
		}
		talk_bolck.Play_animation(0, 20, 1000, 400);
		V.Play_animation(-70, 0, 640, 400);
		outtextxy(400,300,"能量槽满时，按I");
		Sleep(500);
		system("pause");
	}
	P1->power = 12;
	foop = 1;
	//////////foop = 0;
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200); 
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);
	guan1->NEW_zhanwuzha(810, 150);
	guan1->NEW_zhanwuzha(820, 150);
	guan1->NEW_zhanwuzha(830, 150);
	guan1->NEW_zhanwuzha(840, 150);
	guan1->NEW_zhanwuzha(800, 200);


	guan1->NEW_BOX(250, 157 + 33);
	guan1->NEW_BOX(250, 157);
	guan1->NEW_BOX(250, 127);
	guan1->NEW_BOX(250, 127 + 65);
	guan1->NEW_BOX(250, 127 + 65 + 33);
	while (foop)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();

		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;

			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
			
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}
	

	
	////////////////////////////////////////////////
///////////////关卡4///////////////////////////
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <= 20 || i >= 980 || (i > 0 && i < 999 && j>114 && j < 146))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox3.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk4_1_fooc = new char[256] { "animation\\UI\\tlak41_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk4_1_fooc, 1000, 400);
		delete[] talk4_1_fooc;
		talk4_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	//////////////////////////场景4的对话//////////////////
	{
		int j = 0;

		for (vector<animation>::iterator i = guan1->ani_scene.begin(); i < guan1->ani_scene.end(); i++)
		{
			talk_bolck.Play_animation(0, 20, 1000, 400);
			V.Play_animation(-70, 0, 640, 400);
			guan1->ani_scene[j].Play_animation(50, 0, 1000, 4000);
			Sleep(500);
			system("pause");
			mciSendString("close audio\\main.wav", 0, 0, 0);
			mciSendString("close audio\\buttom.wav", 0, 0, 0);
			mciSendString("open audio\\buttom.wav", 0, 0, 0);
			mciSendString("play audio\\buttom.wav", 0, 0, 0);
			j++;
			
		}

	}

	for(int i=30;i<930;i+=35)
	{
		guan1->NEW_fruit(i, 250);
	}
	
	foop = 1;
	//////////////////foop = 0;
	while (foop)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();

		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;
			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
 
			
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}

	////////////////////////////////////////////////
 /////////////////关卡5///////////////////////////



	
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <= 20 || i >= 980 || (i > 0 && i < 840 && j>114 && j < 146))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox2.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk4_1_fooc = new char[256] { "animation\\UI\\tlak41_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk4_1_fooc, 1000, 400);
//////////////////////////////////////////////对话//////////////////////
		talk_bolck.Play_animation(0, 20, 1000, 400);
		V.Play_animation(-70, 0, 640, 400);
		outtextxy(400, 260,"当冲刺时你是无敌的");
		outtextxy(400, 320, "充分利用这一点");
		Sleep(500);
		system("pause");
		mciSendString("close audio\\main.wav", 0, 0, 0);
		mciSendString("close audio\\buttom.wav", 0, 0, 0);
		mciSendString("open audio\\buttom.wav", 0, 0, 0);
		mciSendString("play audio\\buttom.wav", 0, 0, 0);
		



		/////////////////////////////////////////
		delete[] talk4_1_fooc;
		talk4_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	for(int i=30;i<930;i+=30)
	{
		guan1->NEW_fruit(i, 270);
	}
	guan1->NEW_BOX(250, 157 + 33);
	guan1->NEW_BOX(250, 157);
	guan1->NEW_BOX(250, 127);
	guan1->NEW_BOX(250, 127 + 65);
	guan1->NEW_BOX(250, 127 + 65 + 33);

	
	      for (int i = 30; i < 400; i += 30)
		  {
			guan1->NEW_fruit(900, i);
	    	}
	foop = 1;
	//////////////////foop = 0;
	static int kk__LL = 0;
	while (foop)
	{
		
		if (kk__LL == 0)
		{
			guan1->NEW_zhanwuzha(755, 230);
			guan1->NEW_zhanwuzha(750, 220);
			kk__LL++;
		}
		else
		{
			kk__LL++;
			if (kk__LL >= 20)
			{
				kk__LL = 0;
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();


			if(P1->position_x<30&&P1->position_y<80)
			{
			   P1->GameObject_list.clear();
			   P1->position_x = 2;
			   P1->position_y = 200;
		       foop = 0;
			   break;
			}
	}

	////////////////////////////////////////////////
///////////////关卡5///////////////////////////
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400;j++) 
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <= 20 || i >= 980 || (i > 0 && i < 999 && j>114 && j < 146) || (i > 392 && j > 211 && i < (392 + 32) && j>0) || (i > 0 && i < 999 && j>114 && j < 146) || (i > 533 && j > 211 && i < (533 + 32) && j>0) || (i > 0 && i < 999 && j>114 && j < 146) || (i > 211 && j > 211 && i < (211 + 32) && j>0) || (i > 0 && i < 999 && j>114 && j < 146) || (i > 808 && j > 211 && i < (808 + 32) && j>0) || (i > 0 && i < 999 && j>114 && j < 146) || (i > 664 && j > 211 && i < (664 + 32) && j>0))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox4.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk4_1_fooc = new char[256] { "animation\\UI\\tlak41_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk4_1_fooc, 1000, 400);
		delete[] talk4_1_fooc;
		talk4_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}

	for (int i = 30; i < 930; i += 50)
	{
		guan1->NEW_fruit(i, 250);
	}
	guan1->NEW_BOX(618,258);
	guan1->NEW_BOX(618, 258+33);
	guan1->NEW_BOX(618, 258 + 66);
	guan1->NEW_BOX(618, 258+111);
	guan1->NEW_zhanwuzha(761, 324);
	guan1->NEW_zhanwuzha(764, 324);
	guan1->NEW_zhanwuzha(361, 324);
	guan1->NEW_zhanwuzha(364, 324);
	guan1->NEW_zhanwuzha(761, 324);
	guan1->NEW_zhanwuzha(764, 324);
	guan1->NEW_zhanwuzha(361, 324);
	guan1->NEW_zhanwuzha(364, 324);
	guan1->NEW_zhanwuzha(761, 324);
	guan1->NEW_zhanwuzha(764, 324);
	guan1->NEW_zhanwuzha(361, 324);
	guan1->NEW_zhanwuzha(364, 324);
	foop = 1;
	///////////////////////	foop = 0;
	while (foop)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();

		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
            
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;
			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}
	////////////////////////////////////////////////
///////////////关卡6///////////////////////////
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;
				if(i<=5||j<=5||i>=995||j>=395 ||(i>260&&i<555&&j>320)||(i > 0 && i < 260 && j>355) || (i > 259 && i < 555 && j > 355)||(i>289&&i<555&&j>301&&j<318)||(i>320&&i<555&&j<298&&j>264)||(i>320&&i<555&&j<298&&j>265)||(i>321&&i<555&&j>265)||(i>411&&i<555&&j>192)||(i>465&&i<589&&j>173)||(i>588&&j>209&&i<648)||(i>647&&j>302&&i<709)||(i>708&&i<770&&j>365)||(i>707&&i<771&&j>355)||(i>770&&j<352&&j>337)||(i>772&&j<337&&j>319)||(i>798&&j>320)||(i>856&&j<319&&j>300)||(i>860&&j>299))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox6.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk4_1_fooc = new char[256] { "animation\\UI\\tlak41_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk4_1_fooc, 1000, 400);
		delete[] talk4_1_fooc;
		talk4_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}


	
	guan1->NEW_fruit(390, 88);
	guan1->NEW_fruit(294, 177);
	guan1->NEW_fruit(188, 270);
	guan1->NEW_zhanwuzha(755, 230);
	guan1->NEW_zhanwuzha(750, 220);
	guan1->NEW_zhanwuzha(750, 200);
	guan1->NEW_zhanwuzha(750, 200);
	guan1->NEW_zhanwuzha(500, 100);
	guan1->NEW_zhanwuzha(500, 120);
	guan1->NEW_zhanwuzha(550, 100);
	guan1->NEW_zhanwuzha(550, 120);
	foop = 1;
	//////////////	foop = 0;

	while (foop)
	{
		
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		else
		{
			kk__LL++;
			if (kk__LL >= 300)
			{
				kk__LL = 0;
			}
		}
		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();

		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;

			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
			
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}

	delete guan1;
	////////////////////////boss

	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;

				if (j >= 359 || i <=20|| i >= 980 || (i > 0 && i < 999 && j>114 && j < 146))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk1_1_fooc = new char[256] {"animation\\UI\\tlak11_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk1_1_fooc, 1000, 400);
		char* talk1_2_fooc = new char[256] { "animation\\UI\\tlak12_black.png"};
		guan1->add_ani(1, talkfooc, talk1_2_fooc, 1000, 400);
		char* talk1_3_fooc = new char[256] {"animation\\UI\\tlak13_black.png"};
		guan1->add_ani(1, talkfooc, talk1_3_fooc, 1000, 400);
		delete[] talk1_1_fooc;
		talk1_1_fooc = NULL;
		delete[] talkfooc;
		talkfooc = NULL;
		delete[] talk1_1_fooc;
		talk1_1_fooc = NULL;
		delete[] talk1_2_fooc;
		talk1_2_fooc = NULL;
		delete[] talk1_2_fooc;
		talk1_3_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	//////////////////////////

	////////////////////////

		for (int i = 30; i < 930; i+=30+rand()%20)
		{
			guan1->NEW_fruit(i, 250-rand()%100);
		}
   guan1->NEW_BOX(250, 157 + 33);
	guan1->NEW_BOX(250, 157);
	guan1->NEW_BOX(250, 127);
	guan1->NEW_BOX(250, 127 + 65);
	guan1->NEW_BOX(250, 127 + 65 + 33);
	guan1->NEW_Boss(700, 127 + 65 + 33);
	guan1->My_Game_scene->UPDATE_show_scene();

	//////boss的对话//////////////////
	{
		int j = 0;
		talk_bolck.Play_animation(0, 20, 1000, 400);
		V.Play_animation(-70, 0, 640, 400);
		outtextxy(400, 260, "只有直面自己");
		outtextxy(400, 320, "才能找到真相");
		Sleep(500);
		system("pause");
	}
	///////////////////////////
	foop = 1;
	/////////////////////////////////	foop = 0;
	while (foop)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}


		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();


		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;
			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
				P1->position_x = 2;
				foop = 0;
				break;
			}
		}
	}

	///////////////关卡6///////////////////////////
	bool ccc = 1;

LOOP:
	delete guan1;
	{
		bool** phy_map1 = new bool* [1000];
		for (int i = 0; i < 1000; i++)
		{
			phy_map1[i] = new bool[400];
		}

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				phy_map1[i][j] = 0;
				if (i <= 5 || j <= 5 || i >= 995 || j >= 395 || (i > 260 && i < 555 && j>320) || (i > 0 && i < 260 && j>355) || (i > 259 && i < 555 && j > 355) || (i > 289 && i < 555 && j>301 && j < 318) || (i > 320 && i < 555 && j < 298 && j>264) || (i > 320 && i < 555 && j < 298 && j>265) || (i > 321 && i < 555 && j>265) || (i > 411 && i < 555 && j>192) || (i > 465 && i < 589 && j>173) || (i > 588 && j > 209 && i < 648) || (i > 647 && j > 302 && i < 709) || (i > 708 && i < 770 && j>365) || (i > 707 && i < 771 && j>355) || (i > 770 && j < 352 && j>337) || (i > 772 && j < 337 && j>319) || (i > 798 && j > 320) || (i > 856 && j < 319 && j>300) || (i > 860 && j > 299))
				{
					phy_map1[i][j] = 1;
				}
			}
		}
		char* sky_foo = new char[256] {"skybox6.png"};
		guan1 = new guanqia(sky_foo, phy_map1);
		char* talk4_1_fooc = new char[256] { "animation\\UI\\tlak41_black.png"};
		char* talkfooc = new char[256] {"animation\\UI\\talk.png"};
		guan1->add_ani(1, talkfooc, talk4_1_fooc, 1000, 400);
		delete[] talk4_1_fooc;
		talk4_1_fooc = NULL;
		delete[] sky_foo;
		sky_foo = NULL;
		delete[] talkfooc;
		talkfooc = NULL;

		for (int i = 0; i < 1000; i++)
		{
			delete[] phy_map1[i];
			phy_map1[i] = NULL;
		}
		delete[] phy_map1;
		phy_map1 = NULL;
	}
	if(ccc)
	{
		talk_bolck.Play_animation(0, 20, 1000, 400);
		V.Play_animation(-70, 0, 640, 400);
		outtextxy(300, 260, "你现在已经掌握了POWER");
		outtextxy(300, 320, "在这无尽的轮回中提升POWER吧");
		Sleep(500);
		system("pause");
	}
	guan1->NEW_fruit(390, 88);
	guan1->NEW_fruit(294, 177);
	guan1->NEW_fruit(188, 270);


	foop = 1;
	//////////////	foop = 0;
	/*guan1->NEW_BOX(250, 157 + 33);
	guan1->NEW_BOX(250, 157);
	guan1->NEW_BOX(700, 127);
	guan1->NEW_BOX(700, 180);
	guan1->NEW_BOX(250, 127 + 65);
	guan1->NEW_BOX(250, 127 + 65 + 33);*/
	RandomMap(guan1);
	RandomMap(guan1);
	RandomMap(guan1);




	while (foop)
	{

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			MessageBox(GetHWnd(), "EXIT", "WASTE", MB_OK);
			exit(0);
		}
		else if (GetAsyncKeyState('B'))
		{
			Store();
		}
		else if (GetAsyncKeyState('N'))
		{
			Read();
		}

		if (kk__LL == 0)
		{
			guan1->NEW_zhanwuzha(100+rand()%860, 2);
			guan1->NEW_zhanwuzha(100 + rand() % 860, 2);
			guan1->NEW_zhanwuzha(100 + rand() % 860, 2);
	
			kk__LL++;
		}
		else
		{
			kk__LL++;
			if (kk__LL >= 150)
			{
				kk__LL = 0;
			}
		}
		guan1->PHY->Player_NPC_script_Do();

		guan1->PHY->SET();

		guan1->My_Game_scene->UPDATE_show_scene();

		for (vector<GameObject*>::iterator i = P1->GameObject_list.begin(); i < P1->GameObject_list.end(); i++)
		{
			if ((*i)->tag == "attack" && (*i)->health > 0)
			{
				break;

			}
			if (P1->position_x > 850 && i == (P1->GameObject_list.end() - 1))
			{
			
				P1->position_x = 2;
				P1->position_y = 0;
				foop = 0;
				break;
			}
		}
	
	}

	ccc = 0;
		goto LOOP;
}
