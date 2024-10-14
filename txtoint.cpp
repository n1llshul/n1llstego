#include"txtoint.h"

unsigned long long int txtToInt(std::string text)
{
	std::string compiled, tmp;
	compiled = "";
	tmp = "";
	for(char ch : text)
	{
		tmp = std::bitset<8>(int(ch)).to_string();
		std::reverse(tmp.begin(), tmp.end());
		compiled += tmp; 
		//std::cout << compiled << std::endl;
	}
	//std::cout << stringToInt(compiled) << "!" << std::endl;
	return stringToInt(compiled);
}

std::string intToTxt(unsigned long long int number)
{
	std::string compiled, result, tmp;
	tmp = "";
	result = "";
	compiled = std::bitset<40>(number).to_string();
	std::reverse(compiled.begin(), compiled.end());
	//std::cout << compiled << std::endl;
	
	int counter = 0;
	for(char ch : compiled)
	{
		tmp += ch;
		counter++;
		//std::cout << ch << std::endl;
		if(counter == 8)
		{
			counter = 0;
			result += char(stringToInt(tmp));
			//std::cout << tmp << std::endl;
			//std::cout << stringToInt(tmp) << std::endl;
			tmp = "";
		}
	}
	//std::reverse(result.begin(), result.end());
	return result;
}

int subByFive(std::string text)
{
	int n = text.size() / 5;
	n = text.size() % 5 == 0 ? n : n + 1;
	return n;
}

void splitString(std::string text, std::string *arr, int n, int order)
{
	int counter = 0;
	//std::cout << text.size() << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::string tmp = "";
		while(counter < order)
		{
			if(i*order+counter < text.size())
			{
				//std::cout << i*n+counter << " " << int(text[i*n+counter]) << std::endl;
				tmp += text[i*order+counter];
			}
			counter++;
		}
		counter = 0;
		//std::cout << tmp << std::endl;
		arr[i] = tmp;
	}
}
