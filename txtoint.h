#pragma once
#include<iostream>
#include<string>
#include<bitset>
#include<algorithm>
#include<cmath>
#include<fstream>
#include "stego.h"

unsigned long long int txtToInt(std::string text);

std::string intToTxt(unsigned long long int number);

int subByFive(std::string text);

void splitString(std::string text, std::string *arr, int n, int order);

