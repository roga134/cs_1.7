#include <iostream>
#include <string>
#include <thread>  
#include <chrono>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "MainMenu.h"
#include "GameManager.h"

using namespace std;

void StartGame(LogIU& YourLogIU , InfoSetting& SInfoSetting , vector<CT> SPlayerCT , vector<Terrorist> SPlayerTR)
{
	GameManager& mainGameManager = GameManager::getInstance() ;

	mainGameManager.SetPlayerTR(SPlayerTR);
	mainGameManager.SetPlayerCT(SPlayerCT);
	mainGameManager.SetName(SInfoSetting.MapName);

	vector<CT> MainPlayerCT;
	vector<Terrorist> MainPlayerTR;

	MainPlayerCT = mainGameManager.GetPlayerCT();
	MainPlayerTR = mainGameManager.GetPlayerTR();

	int flag = 1;
	CT* PCT = MainPlayerCT.data();
	Terrorist* PTR = MainPlayerTR.data();
	
	
	int alivect = 1;
	int alivetr = 1;
	int min1 = min(SInfoSetting.NumCT , SInfoSetting.NumTR);

	while(alivect == 1 && alivetr == 1)
	{
		int j = 0;
		int flag_cou = 1;
		for (int i = 0 ; i != min1 ; ++i , ++j)
		{
			if (j == min1)
			{
				break ;
			}

			while((PCT+i)->GetAlive() == 0)
			{
				++i;
				if (i == min1)
				{
					flag_cou = 0;
					break;
				}
			}

			while((PTR+j)->GetAlive() == 0)
			{
				++j;
				if (j == min1)
				{
					flag_cou = 0;
					break;
				}
			}

			if (flag_cou == 0)
			{
				alivect = 0;
				alivetr = 0;
				break ;
			}

			int PoweNumber = 0;
			GunIdStruct* current = (PCT+i)->GetHead();
        	do 
        	{
        		string gunId = current->id;
            	shared_ptr<Gun> CTGun = (PCT+i)->GetGun(gunId);
            	PoweNumber += CTGun->GetPowerAmmo() * CTGun->GetAmmo();
            	current = current->next;

        	} while (current != (PCT+i)->GetHead());

			int powerCT = (PCT+i)->GetMoney() + PoweNumber;

			PoweNumber = 0;
			GunIdStruct* current2 = (PTR+j)->GetHead();
        	do 
        	{
        		string gunId = current2->id;
            	shared_ptr<Gun> TRGun = (PTR+j)->GetGun(gunId);
            	PoweNumber += TRGun->GetPowerAmmo() * TRGun->GetAmmo();
            	current2 = current2->next;

        	} while (current2 != (PTR+j)->GetHead());

			int powerTR = (PTR+j)->GetMoney() + PoweNumber;

			if (powerCT > powerTR)
			{
				(PTR+j)->SetHealth((PTR+j)->GetHealth() - powerCT);

				if ((PTR+j)->GetHealth() <= 0)
				{
					cout << "\033[34mCT_player defeated Terrorist_player\033[0m" << endl;
					(PTR+j)->SetIsAlive(0);
				}
				else
				{
					cout << "\033[34mCT_player damaged Terrorist_player\033[0m" << endl;
				}	
			}
			else if (powerCT < powerTR)
			{
				(PCT+i)->SetHealth((PCT+i)->GetHealth() - powerTR);

				if ((PCT+i)->GetHealth() <= 0)
				{
					cout << "\033[31mTerrorist_player defeated CT_player\033[0m" << endl;
					(PCT+i)->SetIsAlive(0);
				}
				else
				{
					cout << "\033[31mTerrorist_player damaged CT_player\033[0m" << endl;
				}
			}
			else if (powerCT == powerTR)
			{
				continue;
			}

			this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}

	int winct = 0;
	int wintr = 0;

	bool yourteam;

	for (int i = 0; i < SInfoSetting.NumCT; ++i)
	{
		if ((PCT+i)->GetName() == YourLogIU.GetUserName())
		{
			yourteam = 0;
			break;
		}
	}

	for (int i = 0; i < SInfoSetting.NumTR; ++i)
	{
		if ((PTR+i)->GetName() == YourLogIU.GetUserName())
		{
			yourteam = 1;
			break;
		}
	}

	for (int i = 0; i < SInfoSetting.NumCT; ++i)
	{
		if ((PCT+i)->GetAlive())
		{
			winct = 1;
			break;
		}
	}

	for (int i = 0; i < SInfoSetting.NumTR; ++i)
	{
		if ((PTR+i)->GetAlive())
		{
			wintr = 1;
			break;
		}
	}

	if (winct)
	{

		mainGameManager.SetIsTRWin(0);
	}
	else if (wintr)
	{
		mainGameManager.SetIsTRWin(1);
	}
	else
	{
		mainGameManager.SetIsTRWin(0); // because terrorist is bad
	}

	ifstream inputFile("informatin.csv");
    ofstream outputFile("temp.csv");

	string line;
	while (getline(inputFile, line)) 
	{
        istringstream ss(line);
        vector<std::string> tokens;
        string token;
        
        while (std::getline(ss, token, ',')) 
        {
            tokens.push_back(token);
        }

        for (int i = 0; i < tokens.size(); ++i) 
        {
            if (tokens[i] == "-1" && tokens[0] == YourLogIU.GetUserName() && tokens[1] == YourLogIU.GetName()) 
            {
            	if (yourteam == mainGameManager.GetIsTRWin())
            	{
            		int number = stoi(tokens[3]);
            		number+= 1;
            		tokens[3] = to_string(number);
            	}
                tokens.insert(tokens.begin() + i, mainGameManager.GetIsTRWin()? "1" : "0");
                break;
            }
        }

        for (size_t i = 0; i < tokens.size(); ++i) 
        {
            outputFile << tokens[i];
            if (i < tokens.size() - 1) outputFile << ",";
        }
        outputFile << "\n";
    }

    inputFile.close();
    outputFile.close();

    remove("informatin.csv");      
    rename("temp.csv", "informatin.csv");

}

void Info(LogIU& YourLogIU)
{
	cout << "\n" ;
	cout << "User Name :     " << YourLogIU.GetUserName() << endl ;
	cout << "Name :          " << YourLogIU.GetName() << endl ;
	cout << "Password :      " << YourLogIU.GetPass() << endl ;
	cout << "NUmber of win : " << YourLogIU.GetWinNum() << endl ;
	cout << "\n" ;
}

void Setting(InfoSetting* SInfoSetting)
{
	int ChooseMap;
	int NumCTPlayer;
	int NumTRPlayer;
	int flag = 1;
	int YourMoney;

	cout << "choose one map : " << endl;
	cout << "1. Beach" << endl;
	cout << "2. Dust2" << endl;
	cout << "3. House" << endl;
	cout << "4. Cave" << endl;
	cout << "5. Office" << endl;
	cout << "Enter : " ;
	cin >> ChooseMap ;

	switch (ChooseMap)
    {
    case 1: SInfoSetting->MapName = "Beach"; break;
    case 2: SInfoSetting->MapName = "Dust2"; break;
    case 3: SInfoSetting->MapName = "House"; break;
    case 4: SInfoSetting->MapName = "Cave"; break;
    case 5: SInfoSetting->MapName = "Office"; break;
    default:
        cout << "Invalid choice. Defaulting to Beach." << endl;
        SInfoSetting->MapName = "Beach";
    }

	while(flag)
	{
		cout << "please enter the number of ct player : ";
		cin >> SInfoSetting->NumCT;
		cout << "please enter the number of terrorist player : ";
		cin >> SInfoSetting->NumTR;

		if (((SInfoSetting->NumCT * 1.0) / (SInfoSetting->NumTR * 1.0 )) < 1.05 && ((SInfoSetting->NumCT * 1.0) / (SInfoSetting->NumTR * 1.0 )) > 0.95)
		{
			flag = 0;
		}
		else
		{
			system("clear");

			cout << "its not correct please try again :" << endl;
		}
	}

	cout << "please enter your first size of money : " ;
	cin >> SInfoSetting->AMoney ;
}