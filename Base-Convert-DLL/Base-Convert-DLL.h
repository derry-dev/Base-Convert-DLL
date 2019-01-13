#pragma once

#include <string>
#include <math.h>
#include <iostream>

using namespace std;

extern "C"
{
	__declspec(dllexport) long int BinToDec(string x);
	__declspec(dllexport) string DecToBin(long int x);
	__declspec(dllexport) string BinToHex(string x);
	__declspec(dllexport) string HexToBin(string x);
	__declspec(dllexport) string DecToHex(long int x);
	__declspec(dllexport) long int HexToDec(string x);
}