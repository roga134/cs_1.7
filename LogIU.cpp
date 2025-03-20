#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include "LogIU.h"

using namespace std;

void LogIU::SetUserName(string SUserName)
{
	UserName = SUserName;
}

void LogIU::SetName(string SName)
{
	Name = SName;
}

void LogIU::SetPass(string SPass)
{
	Pass = SPass;
}

void LogIU::SetWinNum(int SWinNum)
{
	WinNum = SWinNum;
}

string LogIU::GetUserName()
{
	return UserName;
}
		
string LogIU::GetName()
{
	return Name;
}
		
string LogIU::GetPass()
{
	return Pass;
}
		
int LogIU::GetWinNum()
{
	return WinNum;
}

string sha256(const string& input) 
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.length(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) 
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void MainLU(LogIU& YourLogIU)
{
	string YourUserName;
	string YourName;
	string YourPass;

	cout << "please enter your user name : ";
	cin.ignore();
	getline(cin , YourUserName);

	cout << "please enter your name : ";
	getline(cin , YourName);

	cout << "please enter your password : ";
	getline(cin , YourPass);

	YourLogIU.SetUserName(YourUserName);
	YourLogIU.SetName(YourName);
	YourLogIU.SetPass(YourPass);
	
	SubmitInfo(YourLogIU);
}

void SubmitInfo(LogIU& YourLogIU)
{
	ofstream file("informatin.csv", ios::app);

	file << YourLogIU.GetUserName() << "," << YourLogIU.GetName() << "," << sha256(YourLogIU.GetPass()) <<  "," << YourLogIU.GetWinNum() << endl; 

    file.close();
}

bool mainIN(LogIU& YourLogIU)
{
	string YourUserName;
	string YourPass;
	string SYourUserName;
	string SYourName;
	string SYourPass;
	int SYourWinNum;
	string line;
	int flag = 0;

	cout << "please enter your user name : ";
	cin.ignore();
	getline(cin , YourUserName);
	cout << "please enter your password : ";
	getline(cin , YourPass);

	ifstream file("informatin.csv");

	while (getline(file, line)) 
	{
        stringstream ss(line); 
        string SYourWinNumsrt;

        getline(ss, SYourUserName, ',');
        getline(ss, SYourName, ',');
        getline(ss, SYourPass, ',');
        getline(ss, SYourWinNumsrt, ',');

        SYourWinNum = stoi(SYourWinNumsrt);

        if (sha256(YourPass) ==  SYourPass && YourUserName == SYourUserName)
        {
        	cout << sha256(YourPass) << endl;
        	flag = 1;
        	break;
        }
    }

    file.close();

    if (flag)
    {
    	YourLogIU.SetUserName(SYourUserName);
    	YourLogIU.SetName(SYourName);
    	YourLogIU.SetPass(SYourPass);
    	YourLogIU.SetWinNum(SYourWinNum);
    	return 1;
    }
    
	return 0;
}