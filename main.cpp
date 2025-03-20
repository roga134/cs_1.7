#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "GameMat/Gun.h"
#include "GameMat/Player.h"
#include "GameMat/Terrorist.h"
#include "GameMat/ct.h"
#include "GameMat/GameMap.h"
#include "GameMat/GameManager.h"

#include "LogIU.h"

using namespace std;

int main()
{	
	system("clear");

	cout << "=====Wellcome=====" << endl;

	int flag = 1;

	starting_again:

	LogIU YourLogIU;

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

	cout << YourLogIU.GetUserName() << endl;
	return 0;
}