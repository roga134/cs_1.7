#ifndef LOGIU_H
#define LOGIU_H

#include <string>

class LogIU
{
	private:
		std::string UserName;
		std::string Name;
		std::string Pass;
		int WinNum;
	public:
		LogIU(){WinNum = 0;}
		~LogIU(){}

		void SetUserName(std::string SUserName);
		void SetName(std::string SName);
		void SetPass(std::string SPass);
		void SetWinNum(int SWinNum);

		std::string GetUserName();
		std::string GetName();
		std::string GetPass();
		int GetWinNum();
};

std::string sha256(const std::string& input);

void MainLU(LogIU& YourLogIU);
void SubmitInfo(LogIU& YourLogIU);

bool mainIN(LogIU& YourLogIU);

#endif