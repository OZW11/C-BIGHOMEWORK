#pragma once
//#pragma warning(disable:4996)                    //有一个unsafe的函数/
#include<Windows.h>
#include<string>
typedef  int(__stdcall* w32mci)(const char*, char*, int, int);
typedef int(__stdcall* w32mcierror)(int, char*, int);
class Mci
{
public:
	HINSTANCE hins;
	w32mci wmci;
	w32mcierror wmcierror;
public:
	Mci();
	Mci(Mci& a);
	~Mci();
	char buf[256];
	bool send(std::string command);//error  return false 
};
class AudioClip
{
private:
	Mci mci;
	std::string filename;
	std::string alias;
	int length_ms;
public:

	AudioClip();
	~AudioClip();
	bool load(const  std::string& _filename);
	bool play(int start_ms = 0, int end_ms = -1);
	bool stop();
	bool pause();
	bool unpause();
	int milliseconds();
	Mci getMci();
};

