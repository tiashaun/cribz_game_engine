#ifndef _CRIBZDEBUG_H_
#define _CRIBZDEBUG_H_
#include <iostream>
using namespace std;

class CribzDebug
{
	public:
		static void PrintToConsole(char* message){cout << message << endl;}
		static void PrintToConsole(char* message, int x){cout << message << x << endl;}
};

#endif