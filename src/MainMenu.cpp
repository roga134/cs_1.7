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

void StartGame(LogIU& YourLogIU , InfoSetting& SInfoSetting , vector<CT> SPlayerCT , vector<Terrorist> SPlayerTR , int your_team)
{
	GameMap gamemap(SInfoSetting.Map);

	GameManager& mainGameManager = GameManager::getInstance() ;

	mainGameManager.ResetGame();
	mainGameManager.SetPlayerTR(SPlayerTR);
	mainGameManager.SetPlayerCT(SPlayerCT);
	mainGameManager.SetName(gamemap.GetName());

	vector<CT> MainPlayerCT;
	vector<Terrorist> MainPlayerTR;

	MainPlayerCT = mainGameManager.GetPlayerCT();
	MainPlayerTR = mainGameManager.GetPlayerTR();

	int flag = 1;
	CT* PCT = MainPlayerCT.data();
	Terrorist* PTR = MainPlayerTR.data();
	
	int alivect = 1;
	int alivetr = 1;

	int max =  0;

	while(alivect == 1 && alivetr == 1)
	{
		++max;
		int j = 0;
		int flag_cou = 1;
		for (int i = 0 ; i != SInfoSetting.NumCT ; ++i , ++j)
		{
	
			while((PCT+i)->GetAlive() == 0)
			{
				++i;
				if (i == SInfoSetting.NumCT)
				{
					alivect = 0;
					break;
				}
			}

			while((PTR+j)->GetAlive() == 0)
			{
				++j;
				if (j == SInfoSetting.NumTR)
				{
					alivetr = 0;
					break;
				}
			}

			if (j == SInfoSetting.NumTR)
			{
				break ;
			}

			if (i == SInfoSetting.NumCT)
			{
				break;
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

			//cout << " powe ct : " << powerCT << " power tr : " << powerTR << endl;

			if (powerCT > powerTR)
			{
				if (((PTR+j)->GetHealth() - powerCT) <= 0)
				{
					(PTR+j)->SetHealth(0);
				}
				else
				{
					(PTR+j)->SetHealth((PTR+j)->GetHealth() - powerCT);
				}

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
				if (((PCT+i)->GetHealth() - powerTR) <= 0)
				{
					(PCT+i)->SetHealth(0);
				}
				else
				{
					(PCT+i)->SetHealth((PCT+i)->GetHealth() - powerTR);
				}

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

		if(max == 100)
		{
    		alivect = 0;
    		alivetr = 0;
		}
	}

	if (alivect && !alivetr) 
	{
    	cout << "\033[34mCT Team Wins\033[0m" << endl;
    	mainGameManager.SetIsTRWin(0);  
	} 
	else if (alivetr && !alivect)
	{
    	cout << "\033[31mTerrorist Team Wins\033[0m" << endl;
    	mainGameManager.SetIsTRWin(1);  
	} 
	else 
	{
    	cout << "No team wins. Both teams have no players left." << endl;
    	mainGameManager.SetIsTRWin(0); 
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
            	if (your_team == mainGameManager.GetIsTRWin())
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

    MainPlayerCT.clear();
    MainPlayerTR.clear();

}

void Info(LogIU& YourLogIU)
{
	cout << "\n" ;
	cout << "User Name :     " << YourLogIU.GetUserName() << endl ;
	cout << "Name :          " << YourLogIU.GetName() << endl ;
	cout << "Password :      " << YourLogIU.GetPass() << endl ;

	ifstream inputFile("informatin.csv");

	string num_win;
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

        for (int i = 0; i < 2; ++i) 
        {
            if (tokens[0] == YourLogIU.GetUserName() && tokens[1] == YourLogIU.GetName()) 
            {
            	num_win = tokens[3];
                break;
            }
        }
    }

    inputFile.close();

	cout << "NUmber of win : " << num_win << endl ;
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
	cout << "1. Beach (day)" << endl;
	cout << "2. Dust2 (night)" << endl;
	cout << "3. House (night)" << endl;
	cout << "4. Cave (day)" << endl;
	cout << "5. Office (day)" << endl;
	cout << "Enter : " ;
	cin >> ChooseMap ;

	GameMap your_Map;

	switch (ChooseMap)
    {
    case 1:
    	your_Map.SetName("Beach");
    	your_Map.SetNameMaker("roga");
    	your_Map.SetIsNight(0);
    	break;
    case 2: 
    	your_Map.SetName("Dust2");
    	your_Map.SetNameMaker("mahdy");
    	your_Map.SetIsNight(1);
    	break;
    case 3: 
    	your_Map.SetName("House");
    	your_Map.SetNameMaker("ali");
    	your_Map.SetIsNight(1);
    	break;
    case 4: 
    	your_Map.SetName("Cave");
    	your_Map.SetNameMaker("mmad");
    	your_Map.SetIsNight(0);
    	break;
    case 5: 
    	your_Map.SetName("Office");
    	your_Map.SetNameMaker("ahmad");
    	your_Map.SetIsNight(0);
    	break;
    default:
        cout << "Invalid choice. Defaulting to Beach." << endl;
        break;
    }

    SInfoSetting->Map = your_Map;

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

	cout << "please enter your first size of money :(better is more than 100) " ;
	cin >> SInfoSetting->AMoney ;
}