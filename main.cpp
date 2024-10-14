#include "main.h"
//#include "stego/stego.h"
//#include "txtoint/txtoint.h"

void writeFile(std::string msg, std::string filename)
{
	std::ofstream outFile(filename);
	outFile << msg;
	outFile.close();
}

void mDec()
{
	//DECODING START__________________________________
	
	std::string ct = readFile("ct.txt");
	std::string msg = "";
	std::string dec = Decode(ct);
	//std::reverse(dec.begin(), dec.end());
	std::cout << dec << std::endl;
	int dec_length = dec.size() / 64;
	dec_length = dec.size() % 64 == 0 ? dec_length : dec_length + 1;
	std::string decarr[dec_length];
	splitString(dec, decarr, dec_length, 64);
	unsigned long long int numarr[dec_length];
	//std::cout << dec_length << std::endl;
	for(int i = 0; i < dec_length; i++)
	{
	//	std::cout << decarr[i] << std::endl << std::endl;
		if(isZero(decarr[i]))
		{
			break;
		}
		numarr[i] = stringToInt(decarr[i]);
		//std::cout << decarr[i] << std::endl;
		//std::cout << numarr[i] << std::endl;
		//std::cout << numarr[i] << std::endl << std::endl;
		msg += intToTxt(numarr[i]);
		//std::cout << intToTxt(numarr[i]) << std::endl;
	}
	
	std::cout << "Decoding ended successfully. Here's the message:\n";
	std::cout << msg << std::endl;

	// DECODING END_____________________________________________

}

int mEnc()
{
	// ENCODING START___________________________________________

	std::string msg = readFile("msg.txt");
	std::string pt = readFile("input.txt");
	std::string ct = "";
	int msg_length = subByFive(msg);
	int pt_length = subByFive(pt);
	std::string msgarr[msg_length];
	std::string ptarr[pt_length];
	splitString(pt, ptarr, pt_length, 5);
	splitString(msg, msgarr, msg_length, 5);
	unsigned long long int numarr[msg_length];
	for(int i = 0; i < msg_length; i++)
	{
		//std::cout << msgarr[i] << std::endl;
		numarr[i] = txtToInt(msgarr[i]);
		//std::string str = std::bitset<64>(numarr[i]).to_string();
		//std::reverse(str.begin(), str.end());
		//std::cout << str << std::endl;
		///std::cout << numarr[i] << std::endl;
		//std::cout << intToTxt(numarr[i]) << std::endl;
	}
	int pt_counter = 0;
	std::cout << msg_length << std::endl;	
	encres r;
	r.result = "";
	r.index = 0;
	for(int i = 0; i < msg_length; i++)
	{
		r.remain = -2;
		while(r.remain != 0)
		{
			r = Encode(numarr[i], ptarr[pt_counter], r.remain, r.index);
			//std::cout << "remain " << r.remain << std::endl;
			//std::cout << r.result << std::endl;
			ct += r.result;
			
			if(r.remain == -1)
			{
				i++;
				r.remain = 64;
				r = Encode(numarr[i], ptarr[pt_counter], r.remain, r.index);
				ct += r.result;
				//std::cout << r.result.size() << std::endl;
			}
			pt_counter++;
			if(pt_counter == pt_length && numarr[i] != 0)
			{

				std::cout << "Stegocontainter is too small." << std::endl;
				return -1;
			}
		}
	
	}
	for(int i = pt_counter; i < pt_length; i++)
	{
		ct += ptarr[i];
	}	
	writeFile(ct, "ct.txt");
	//std::cout << ct << std::endl;
	//std::cout << std::endl << std::endl << Decode(ct) << std::endl;
	std::cout << "Encoding ended successfully.\n";
	return 0;
	// ENCODING END_________________________________
	
}

int main()
{

	char answer;
	while(1)
	{
		std::cout << "\nEncode or decode?[E,D]: ";
		std::cin >> answer;
		if(answer == 'E' || answer == 'D' || answer == 'e' || answer == 'd')
		{
			if(answer == 'E' || answer == 'e')
			{
				mEnc();
			}
			else
			{
				mDec();
			}
		}	
		else
		{
			std::cout << "Invalid option. Try again.\n";
		}
	}
	return 0;
}

