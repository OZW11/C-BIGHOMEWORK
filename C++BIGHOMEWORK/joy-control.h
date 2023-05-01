#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<Windows.h>
//添加joystick操作api的支持库
#include<MMSystem.h>
#pragma comment(lib, "Winmm.lib")
#include <windows.h>
// for key pushing
BYTE scan_code(DWORD pKey)
{
	const DWORD result = MapVirtualKey(pKey, MAPVK_VK_TO_VSC);
	return static_cast<BYTE>(result);
}
void press_key(DWORD pKey)
{
	keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), 0, 0);
}
void release_key(DWORD pKey)
{
	keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), KEYEVENTF_KEYUP, 0);
}
// for testing
#define PRESS(x) press_key(x); std::cout << "Press: " #x << std::endl
#define RELEASE(x) release_key(x); std::cout << "Release: " #x << std::endl
// test


int co_main()
{
	JOYINFO joyinfo;//定义joystick信息结构体
	JOYINFOEX joyinfoex;
	joyinfoex.dwSize = sizeof(JOYINFOEX);
	joyinfoex.dwFlags = JOY_RETURNALL;
	while (1)
	{
		//读取手柄信息
		UINT joyNums;
		joyNums = joyGetNumDevs();
		if (joyNums >= 1)
		{
			MMRESULT joyreturn = joyGetPosEx(JOYSTICKID1, &joyinfoex);
			if (joyreturn == JOYERR_NOERROR)
			{
				/*std::cout << (joyinfoex.dwXpos) << std::endl;
				std::cout << (joyinfoex.dwYpos) << std::endl;
				std::cout << (joyinfoex.dwZpos) << std::endl;
				std::cout << (joyinfoex.dwPOV) << std::endl;
				std::cout << (joyinfoex.dwButtons) << std::endl;*/

				int x = joyinfoex.dwXpos, y = joyinfoex.dwYpos, buttom = (joyinfoex.dwButtons);
				/////////////////////////////////////////////////////////////
					//读摇杆

				if (x > 32511)
				{
					PRESS('D');
				}
				else
				{
					RELEASE('D');
				}
				if (x < 32511)
				{
					PRESS('A');
				}
				else
				{
					RELEASE('A');
				}
				if (y > 32511)
				{
					PRESS('S');
				}
				else
				{
					RELEASE('S');
				}
				if (y < 32511)
				{
					PRESS('W');
				}
				else
				{
					RELEASE('W');
				}

				/////////////////////////////////
				//读按键
				switch (buttom)
				{
				case 1:
					PRESS('U');

					break;
				case 2:
					PRESS('I');

					break;
				case 4:
					PRESS('O');

					break;
				case 8:
					PRESS('J');


					break;

				case 16:
					PRESS('K');

					break;
				case 32:
					PRESS(VK_SPACE);

					break;
				case 3:
					PRESS('U');
					PRESS('U');

					break;
				case 5:
					PRESS('U');
					PRESS('O');
					break;
				case 9:
					PRESS('U');
					PRESS('J');

					break;
				case 17:
					PRESS('U');
					PRESS('K');
					break;
				case 33:
					PRESS('U');
					PRESS(VK_SPACE);

					break;
				case 6:
					PRESS('I');
					PRESS('O');

					break;
				case 10:
					PRESS('I');
					PRESS('J');

					break;
				case 18:
					PRESS('I');
					PRESS('K');

					break;
				case 34:
					PRESS('I');
					PRESS(VK_SPACE);


					break;
				case 12:
					PRESS('O');
					PRESS('J');


					break;
				case 20:
					PRESS('O');
					PRESS('K');


					break;
				case 36:
					PRESS('O');
					PRESS(VK_SPACE);


					break;
				case 24:
					PRESS('J');
					PRESS('K');


					break;
				case 40:
					PRESS('J');
					PRESS(VK_SPACE);


					break;
				case 48:
					PRESS('K');
					PRESS(VK_SPACE);

					break;
				case 7:
					PRESS('U');
					PRESS('I');
					PRESS('O');

					break;
				case 56:
					PRESS('J');
					PRESS('K');
					PRESS(VK_SPACE);


					break;
				case 63:
					PRESS('J');
					PRESS('K');
					PRESS(VK_SPACE);
					PRESS('J');
					PRESS('K');
					PRESS(VK_SPACE);


					break;
				case 512:
					PRESS('P');

					break;
				case 256:
					PRESS(VK_SPACE);

					break;
				default:
					RELEASE('J');
					RELEASE('K');
					RELEASE(VK_SPACE);
					RELEASE('U');
					RELEASE('I');
					RELEASE('O');
					RELEASE(VK_SPACE);
					RELEASE('P');
					break;
				}
			}
			else
			{
				switch (joyreturn)
				{
				case JOYERR_PARMS:
					cout<<"bad parameters\n";
					break;
				case JOYERR_NOCANDO:
					cout<<"request not completed\n";
					break;
				case JOYERR_UNPLUGGED:
					cout<<"joystick is unplugged\n";
					break;
				default:
					cout<<"未知错误\n";
					break;
				}
				cout << "请链接街机摇杆\n";
				system("pause");
			}
		}

		Sleep(50);

	}
	return 0;

}
//虚拟按键扫描参考博客https://blog.csdn.net/wdjhzw/article/details/38586339