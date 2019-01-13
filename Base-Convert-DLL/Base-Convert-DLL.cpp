// Base-Convert-DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Base-Convert-DLL.h"

__declspec(dllexport) long int BinToDec(string x);
__declspec(dllexport) string DecToBin(long int x);
__declspec(dllexport) string BinToHex(string x);
__declspec(dllexport) string HexToBin(string x);
__declspec(dllexport) string DecToHex(long int x);
__declspec(dllexport) long int HexToDec(string x);

long int BinToDec(string x)
{
	long int y = 0;
	for (int i = 0; i < x.length(); i++)
	{
		if ((int)(x[i]) == 49)
		{
			y += pow(2, x.length() - 1 - i);
		}
	}
	return y;
}

string DecToBin(long int x)
{
	string y = "";
	do {
		y = to_string((x % 2 == 0) ? 0 : 1) + y;
		x /= 2;
	} while (x != 0);
	return y;
}

string BinToHex(string x)
{
	while (x.length() % 4 != 0)
	{
		x = "0" + x;
	}
	string y = "";
	for (int i = 0; i < x.length(); i += 4)
	{
		string str;
		str.append(x, i, 4);
		switch (BinToDec(str))
		{
		case 10:
			y += "A";
			break;
		case 11:
			y += "B";
			break;
		case 12:
			y += "C";
			break;
		case 13:
			y += "D";
			break;
		case 14:
			y += "E";
			break;
		case 15:
			y += "F";
			break;
		default:
			y += to_string(BinToDec(str));
		}
	}
	return y;
}

string HexToBin(string x)
{
	string y = "";
	for (int i = 0; i < x.length(); i++)
	{
		switch (x[i])
		{
		case 48:
			y += "0000";
			break;
		case 49:
			y += "0001";
			break;
		case 50:
			y += "0010";
			break;
		case 51:
			y += "0011";
			break;
		case 52:
			y += "0100";
			break;
		case 53:
			y += "0101";
			break;
		case 54:
			y += "0110";
			break;
		case 55:
			y += "0111";
			break;
		case 56:
			y += "1000";
			break;
		case 57:
			y += "1001";
			break;
		case 65:
			y += "1010";
			break;
		case 66:
			y += "1011";
			break;
		case 67:
			y += "1100";
			break;
		case 68:
			y += "1101";
			break;
		case 69:
			y += "1110";
			break;
		case 70:
			y += "1111";
			break;
		default:
			break;
		}
	}
	return y.substr(y.find("1"));
}

string DecToHex(long int x)
{
	return BinToHex(DecToBin(x));
}

long int HexToDec(string x)
{
	return BinToDec(HexToBin(x));
}
