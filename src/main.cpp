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
	cout << "I have 5 type of test but you should enter 2 for number of tr and ct" << endl; 

	flag = 1;
    int flag2 = 0, exit = 1;
	while(exit)
	{
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
					
					shared_ptr<Gun> Gun1 = make_shared<Gun>(10 , 100 , 0 , 14);
					shared_ptr<Gun> Gun2 = make_shared<Gun>(10 , 100 , 0 , 15);
					shared_ptr<Gun> Gun3 = make_shared<Gun>(10 , 100 , 0 , 16);
					shared_ptr<Gun> Gun4 = make_shared<Gun>(10 , 100 , 0 , 17);
					shared_ptr<Gun> Gun5 = make_shared<Gun>(5 , 100 , 3 , 50);
					shared_ptr<Gun> Gun6 = make_shared<Gun>(10 , 100 , 3 , 18);
					RegisterGun(Gun1);
					RegisterGun(Gun2);
					RegisterGun(Gun3);
					RegisterGun(Gun4);
					RegisterGun(Gun5);
					RegisterGun(Gun6);

					gunDatabase[Gun1->GetId()] = Gun1;
    				gunDatabase[Gun2->GetId()] = Gun2;
    				gunDatabase[Gun3->GetId()] = Gun3;
    				gunDatabase[Gun4->GetId()] = Gun4;
    				gunDatabase[Gun5->GetId()] = Gun5;
    				gunDatabase[Gun6->GetId()] = Gun6;

    				int your_test;
    				cout << "enter number from 1 until 5 for test : " ;
    				cin >> your_test ;

    				vector<CT> SPlayerCT;
    				vector<Terrorist> SPlayerTR;

    					if(your_test == 1) // ct win
    					{
    						Terrorist Terrorist1(0 , 1 , "mahdy" , Gun1->GetName() , Gun1->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							Terrorist Terrorist2(0 , 0 , "ali" , Gun2->GetName() , Gun2->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							CT CT1(0 , 1 , "roga" , Gun6->GetName() , Gun6->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							CT CT2(0 , 1 , "crazy" , Gun4->GetName() , Gun4->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							Terrorist1.insert(Gun1->GetId());
							Terrorist1.insert(Gun5->GetId());

							Terrorist2.insert(Gun2->GetId());
							Terrorist2.insert(Gun5->GetId());

					
							CT1.insert(Gun6->GetId());
							CT1.insert(Gun5->GetId());

							CT2.insert(Gun4->GetId());
							CT2.insert(Gun5->GetId());

							SPlayerCT.push_back(CT1);
							SPlayerCT.push_back(CT2);

							SPlayerTR.push_back(Terrorist1);
							SPlayerTR.push_back(Terrorist2);
    					} 
    					/*
    					if I get ct :
    						CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player defeated Terrorist_player
							CT_player defeated Terrorist_player
							CT Team Wins

							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player defeated Terrorist_player
							CT_player defeated Terrorist_player
							CT_player defeated Terrorist_player
							CT Team Wins
						*/

    					else if(your_test == 2) // if choose tr , draw : tr win  , else , tr : win   
    					{
    						Terrorist Terrorist1(0 , 1 , "mahdy" , Gun1->GetName() , Gun1->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							Terrorist Terrorist2(0 , 0 , "ali" , Gun6->GetName() , Gun6->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							CT CT1(0 , 1 , "roga" , Gun2->GetName() , Gun2->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							CT CT2(0 , 1 , "crazy" , Gun4->GetName() , Gun4->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							Terrorist1.insert(Gun1->GetId());
							Terrorist1.insert(Gun5->GetId());

							Terrorist2.insert(Gun6->GetId());
							Terrorist2.insert(Gun5->GetId());

					
							CT1.insert(Gun2->GetId());
							CT1.insert(Gun5->GetId());

							CT2.insert(Gun4->GetId());
							CT2.insert(Gun5->GetId());

							SPlayerCT.push_back(CT1);
							SPlayerCT.push_back(CT2);

							SPlayerTR.push_back(Terrorist1);
							SPlayerTR.push_back(Terrorist2);
    					} 

    					/*
    					if I choose ct : 
    						CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player defeated Terrorist_player
							Terrorist_player defeated CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player defeated CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player defeated CT_player
							Terrorist Team Wins
						if I choose tr :
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player defeated Terrorist_player
							Terrorist_player defeated CT_player
							Terrorist_player damaged CT_player
							No team wins. Both teams have no players left.
						*/

    					else if(your_test == 3) // ct win
    					{
    						Terrorist Terrorist1(0 , 1 , "mahdy" , Gun1->GetName() , Gun1->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							Terrorist Terrorist2(0 , 0 , "ali" , Gun2->GetName() , Gun2->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							CT CT1(0 , 1 , "roga" , Gun4->GetName() , Gun4->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							CT CT2(0 , 1 , "crazy" , Gun6->GetName() , Gun6->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							Terrorist1.insert(Gun1->GetId());
							Terrorist1.insert(Gun5->GetId());

							Terrorist2.insert(Gun2->GetId());
							Terrorist2.insert(Gun5->GetId());

					
							CT1.insert(Gun4->GetId());
							CT1.insert(Gun5->GetId());

							CT2.insert(Gun6->GetId());
							CT2.insert(Gun5->GetId());

							SPlayerCT.push_back(CT1);
							SPlayerCT.push_back(CT2);

							SPlayerTR.push_back(Terrorist1);
							SPlayerTR.push_back(Terrorist2);
    					}
    					/*
    					if I choose ct :
    						CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player defeated Terrorist_player
							CT_player defeated Terrorist_player
							CT Team Wins
						if I choose tr :
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player damaged Terrorist_player
							CT_player defeated Terrorist_player
							CT_player defeated Terrorist_player
							CT_player defeated Terrorist_player
							CT Team Wins
						*/

    					else if(your_test == 4) // if choose tr , tr : win , if choose ct , draw : draw
    					{
    						Terrorist Terrorist1(0 , 1 , "mahdy" , Gun6->GetName() , Gun6->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							Terrorist Terrorist2(0 , 0 , "ali" , Gun2->GetName() , Gun2->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							CT CT1(0 , 1 , "roga" , Gun1->GetName() , Gun1->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							CT CT2(0 , 1 , "crazy" , Gun4->GetName() , Gun4->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							Terrorist1.insert(Gun6->GetId());
							Terrorist1.insert(Gun5->GetId());

							Terrorist2.insert(Gun2->GetId());
							Terrorist2.insert(Gun5->GetId());

					
							CT1.insert(Gun1->GetId());
							CT1.insert(Gun5->GetId());

							CT2.insert(Gun4->GetId());
							CT2.insert(Gun5->GetId());

							SPlayerCT.push_back(CT1);
							SPlayerCT.push_back(CT2);

							SPlayerTR.push_back(Terrorist1);
							SPlayerTR.push_back(Terrorist2);
    					}
    					/*
    					if I choose ct :
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player defeated CT_player
							CT_player defeated Terrorist_player
							Terrorist_player damaged CT_player
							No team wins. Both teams have no players left.
    					if I choose tr :
    						Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player damaged CT_player
							CT_player damaged Terrorist_player
							Terrorist_player defeated CT_player
							CT_player defeated Terrorist_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player damaged CT_player
							Terrorist_player defeated CT_player
							Terrorist Team Wins
						*/

    					else // its 2
    					{
    						Terrorist Terrorist1(0 , 1 , "mahdy" , Gun1->GetName() , Gun1->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							Terrorist Terrorist2(0 , 0 , "ali" , Gun6->GetName() , Gun6->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							CT CT1(0 , 1 , "roga" , Gun2->GetName() , Gun2->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);
							CT CT2(0 , 1 , "crazy" , Gun4->GetName() , Gun4->GetId() ,2000 , 0 , 1 , 0 , gameSettings.AMoney);

							Terrorist1.insert(Gun1->GetId());
							Terrorist1.insert(Gun5->GetId());

							Terrorist2.insert(Gun6->GetId());
							Terrorist2.insert(Gun5->GetId());

					
							CT1.insert(Gun2->GetId());
							CT1.insert(Gun5->GetId());

							CT2.insert(Gun4->GetId());
							CT2.insert(Gun5->GetId());

							SPlayerCT.push_back(CT1);
							SPlayerCT.push_back(CT2);

							SPlayerTR.push_back(Terrorist1);
							SPlayerTR.push_back(Terrorist2);
    					} 

					int your_team;
					cout << "please choose your team : (for tr enter one and for ct enter zero) ";
					cin >> your_team;

					switch (your_team)
					{
						case 1:
						{
							Terrorist Terrorist3(0 , 1 , YourLogIU.GetName(), Gun3->GetName(), Gun3->GetId(), 100, 0, 1, 0, gameSettings.AMoney);
							Terrorist3.insert(Gun3->GetId());
							Terrorist3.insert(Gun5->GetId());
							SPlayerTR.push_back(Terrorist3);
							gameSettings.NumTR += 1;
							break;
						}
						case 0:
						{
							CT CT3(0 , 1 , YourLogIU.GetName(), Gun3->GetName(), Gun3->GetId(), 2000, 0, 1, 0, gameSettings.AMoney);
							CT3.insert(Gun3->GetId());
							CT3.insert(Gun5->GetId());
							SPlayerCT.push_back(CT3);
							gameSettings.NumCT += 1;
							break;
						}
						default:
						{
							cout << "its not true you are tr" << endl;
							Terrorist Terrorist3(0 , 1 , YourLogIU.GetName(), Gun3->GetName(), Gun4->GetId(), 2000, 0, 1, 0, gameSettings.AMoney);
							Terrorist3.insert(Gun4->GetId());
							Terrorist3.insert(Gun3->GetId());
							SPlayerTR.push_back(Terrorist3);
							gameSettings.NumTR += 1;
							break;
						}
					}						
					StartGame(YourLogIU , gameSettings , SPlayerCT , SPlayerTR , your_team);

					SPlayerTR.clear();
					SPlayerCT.clear();
					flag2 = 0;
				}
				else 
				{
					system("clear");
					cout << "First you should set the setting " << endl;
				}
				break;
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
	}
	return 0;
}
//g++ *cpp -o main -lssl -lcrypto
