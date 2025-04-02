#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <sstream>

#include "Gun.h"
#include "Player.h"
#include "Terrorist.h"
#include "ct.h"
#include "GameMap.h"
#include "GameManager.h"

#include "LogIU.h"
#include "MainMenu.h"

using namespace std;
	
int main()
{	
	system("clear");

	cout << "=====Wellcome=====" << endl;

	int flag = 1;

	starting_again:

	LogIU YourLogIU;
	InfoSetting gameSettings;

	while(flag)
	{
		int YourChoose;

		cout << "Please choose one :" << endl;
		cout << "1. Log up" << endl ;
		cout << "2. Log in" << endl ;
		cout << "3. Exit" << endl;
		cout << "Enter : " ;

		cin >> YourChoose ;

		switch(YourChoose)
		{	
			case 1:
				system("clear");

				MainLU(YourLogIU);

				system("clear");

				cout << "your log up is successful" << endl;

				goto starting_again;

				break;
			case 2:
				system("clear");

				if(mainIN(YourLogIU))
				{
					system("clear");

					flag = 0;
				}
				else 
				{
					system("clear");

					cout << "its not correct please try again :" << endl; 
				}

				break;
			case 3:
				cout << "have good day" << endl ;
				return 0;
			default:
				system("clear");

				cout << "Your entery is not correct please try again :" << endl;

				break;
		}
	}


	cout << "Wellcome " << YourLogIU.GetName() << endl;

	starting_again2:

	flag = 1;
	int flag2 = 0;

	while(flag)
	{

		int YourChoose;

		cout << "Please choose one : "  << endl;
		cout << "1. start game " << endl;
		cout << "2. setting" << endl;
		cout << "3. history" << endl; 
		cout << "4. information" << endl;
		cout << "5. exit" << endl;
		cout << "Enter : ";
		cin >> YourChoose ;

		ifstream inputFile("informatin.csv");
		string line;

		switch(YourChoose)
		{
			case 1:
				if (flag2)
				{
					system("clear");
					
					shared_ptr<Gun> Gun1 = make_shared<Gun>(60 , 100 , 0 , 14);
					shared_ptr<Gun> Gun2 = make_shared<Gun>(60 , 200 , 1 , 21);
					shared_ptr<Gun> Gun3 = make_shared<Gun>(60 , 300 , 2 , 22);
					shared_ptr<Gun> Gun4 = make_shared<Gun>(60 , 100 , 0 , 20);
					shared_ptr<Gun> Gun5 = make_shared<Gun>(1 , 50 , 3 , 100);
					RegisterGun(Gun1);
					RegisterGun(Gun2);
					RegisterGun(Gun3);
					RegisterGun(Gun4);
					RegisterGun(Gun5);

					gunDatabase[Gun1->GetId()] = Gun1;
    				gunDatabase[Gun2->GetId()] = Gun2;
    				gunDatabase[Gun3->GetId()] = Gun3;
    				gunDatabase[Gun4->GetId()] = Gun4;
    				gunDatabase[Gun5->GetId()] = Gun5;

					Terrorist Terrorist1(0 , 1 , "mahdy" , Gun1->GetName() , Gun1->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
					Terrorist Terrorist2(0 , 0 , "ali" , Gun2->GetName() , Gun2->GetId() ,2000 , 50 , 1 , 0 , gameSettings.AMoney);

					Terrorist1.insert(Gun1->GetId());
					Terrorist1.insert(Gun5->GetId());

					Terrorist2.insert(Gun2->GetId());
					Terrorist2.insert(Gun5->GetId());

					CT CT1(0 , 1 , "roga" , Gun3->GetName() , Gun3->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
					CT CT2(0 , 1 , "crazy" , Gun4->GetName() , Gun4->GetId() ,2000 , 30 , 1 , 0 , gameSettings.AMoney);

					CT1.insert(Gun3->GetId());
					CT1.insert(Gun5->GetId());

					CT2.insert(Gun4->GetId());
					CT2.insert(Gun5->GetId());
					
					vector<CT> SPlayerCT;
					SPlayerCT.push_back(CT1);
					SPlayerCT.push_back(CT2);

					vector<Terrorist> SPlayerTR;
					SPlayerTR.push_back(Terrorist1);
					SPlayerTR.push_back(Terrorist2);
				
					StartGame(YourLogIU , gameSettings , SPlayerCT , SPlayerTR);

					break ;
				}
				else 
				{
					system("clear");

					cout << "First you should set the setting " << endl;

					break;
				}
			case 2:
				system("clear");

				Setting(&gameSettings);

				system("clear");

				flag2 = 1;

				break ;
			case 3:
				system("clear");

				while (getline(inputFile, line)) 
				{
        			istringstream ss(line);
        			vector<std::string> tokens;
        			string token;
        
        			while (std::getline(ss, token, ',')) 
        			{
            			tokens.push_back(token);
        			}

        			if (tokens[0] == YourLogIU.GetUserName())
        			{
        				for (int i = 4; i < tokens.size() - 1; ++i)
        				{
        					if (stoi(tokens[i]) == 1)
        					{
        						cout << "Round " << i - 3 << ": Winner : TR" << endl;
        					}
        					else
        					{
        						cout << "Round " << i - 3 << ": Winner : CT" << endl;
        					}
        				}
        				break;
        			}
        		}
        		
        		cout << endl;

   				inputFile.close();

   				break;
			case 4:
				system("clear");

				Info(YourLogIU);

				break;
			case 5:
				system("clear");

				cout << "Good bye" << endl;

				return 0;
			default:
				system("clear");

				cout << "Your entery is not correct please try again :" << endl;

				break;
		}
	}

	return 0;
}
//g++ *cpp -o main -lssl -lcrypto
