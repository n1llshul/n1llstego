#include"stego.h"

//0 - lat
//1 - cyr

bool isZero(std::string bin_text)
{
	int length = bin_text.size();
	for(int i = 0; i < length; i++)
	{
		if(bin_text[i] == '1')
		{		
			return false;
		}
	}
	return true;
}

crtable Table;
std::string readFile(std::string path)
{
	std::string tmp, input;
	input = "";
	std::ifstream inFile(path);
	if(inFile)
	{
		while(getline(inFile, tmp))
		{
			input += tmp;
		}
	}
	else
	{
		std::cout << "Could not open input file " << path << std::endl;
		return "";
	}
	inFile.close();
	return input;
}

unsigned long long int stringToInt(std::string str)
{
	int length = str.size();
	unsigned long long int res = 0;
	for(int i = 0; i < length; i++)
	{
		if(str[i] == '1')
		{
			res += pow(2, i);
		}
	}
	return res;
}

encres Encode(unsigned long long int num, std::string input, int rem, int index)
{

	//std::cout << "\nNew encoding\n";
	encres obj;
	int length, num_counter;
	bool global_break = false;
	num_counter = 0;
	std::string conv_num;
	obj.result = "";
	conv_num = std::bitset<64>(num).to_string();
	std::reverse(conv_num.begin(), conv_num.end());
	//std::cout << "rem " << rem << std::endl;
	if(rem != -2 && rem != 64)
	{
		//std::cout << " erase" << std::endl;
		conv_num.erase(conv_num.begin(), conv_num.begin()+64-rem);
		//std::cout << conv_num << std::endl << std::endl;
		//if(isZero(conv_num))
		//{
		//	obj.result = input;
		//	obj.remain = 0;
		//	return obj;
		//}
	}
	else if(rem == -2)
	{
		//std::cout << conv_num << std::endl;
	}
	//std::cout << conv_num << std::endl;
	//std::cout << conv_num.size() << std::endl;
	//std::cout << std::endl << input << std::endl;
	length = input.size();
	int i = index;
	for(; i < length; i++)
	{
		bool coded = false;
		for(int j = 0; j < Table.size; j++)
		{
			if(num_counter < conv_num.size())
			{
				if(input[i] == Table.lat[j])
				{
					//std::cout << input[i] << " ";
					if(conv_num[num_counter] == '1')
					{
						obj.result += Table.cyr[j*2];
						obj.result += Table.cyr[j*2+1];
						coded = true;
						//std::cout << "1" << std::endl;
					}	
					//std::cout << conv_num[num_counter];
					num_counter++;
					break;
				}
			}
			else
			{
				if(i != length-1)
				{
					global_break = true;
					break;
				}
			}
			if(coded)
			{
				break;
			}
		}
		if(global_break)
		{
			break;
		}
		obj.result = coded ? obj.result : obj.result + input[i];
		
	}
	obj.remain = conv_num.size() - num_counter;
		if(obj.remain == 0)
	{
		//std::cout << "Remainder = 0." << std::endl;
	}	
	//std::cout << i << std::endl;
	if(obj.remain == 0 && num_counter == conv_num.size() && global_break)
	{
		//std::cout << "Condition accepted" << std::endl;
		bool hasLat = false;
		for(int k = i; k < length; k++)
		{
			for(int j = 0; j < Table.size; j++)
			{
				if(input[k] == Table.lat[j])
				{
					//std::cout << input[i] << std::endl;
					hasLat = true;
					break;
				}
			}
			if(hasLat)
			{
				obj.index = k;
				obj.remain = -1;
				//std::cout << "Remainder minus one.\n";
				
				break;
			}
			else
			{
				obj.result += input[k];
			}
		}
		if(not hasLat)
		{
			obj.index = 0;
		}
	}
	else
	{
		obj.index = 0;	
	}/*
	if(global_break && obj.remain != -1)
	{
		for(int j = i; j < length; j++)
		{
			obj.result += input[j];
		}
	}*/
	//std::cout << num_counter << std::endl;
	//std::cout << obj.remain << std::endl << std::endl;
	//std::cout << "Endoding ended successfully.\n";
	//std::cout << input << std::endl;
	//std::cout << obj.result << std::endl << std::endl;
	return obj;
}

std::string Decode(std::string input)
{
	int length, zero_count;
	zero_count = 0;
	std::string decoded;
	decoded = "";
	length = input.size();

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < Table.size*2; j++)
		{
			if(input[i] == Table.cyr[j] && i+1 < length && input[i+1] == Table.cyr[j+1])
			{
				decoded += '1';
				i++;
				zero_count = 0;
				//std::string tmp = "";
				//tmp += char(input[i]); 
				//tmp += char(input[i+1]);
				//std::cout << tmp << "1\n"; 

				break;
			}
			else if(j < Table.size && input[i] == Table.lat[j])
			{
				decoded += '0';
				zero_count++;
				if(zero_count == 64)
				{
					std::reverse(decoded.begin(), decoded.end());
					decoded.erase(decoded.begin(), decoded.begin()+64);
					std::reverse(decoded.begin(), decoded.end());
					return decoded;	
				}
				//std::cout << i << " " << input[i] << " 0\n";
				break;
			}
		}
		//std::cout << std::endl;
	}
	//std::cout << "Decoding ended succesfully." << std::endl;
	return decoded;
}
