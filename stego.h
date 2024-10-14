#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
#include<algorithm>
#include<cmath>

bool isZero(std::string bin_text);

std::string readFile(std::string path);
unsigned long long int stringToInt(std::string str);
struct crtable
{
	const int size = 17;
	const std::string cyr = "АаВЕеКМНОоРрСсТХх";
	const std::string lat = "AaBEeKMHOoPpCcTXx";
};
struct encres
{
	std::string result;
	int remain;
	int index;
};


encres Encode(unsigned long long int num, std::string input, int rem, int index);

std::string Decode(std::string input);
