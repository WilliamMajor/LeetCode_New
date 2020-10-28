// TestBed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> 
#include <chrono>

using namespace std;
bool CheckEncoderDateValidity();
bool CheckEncoderMacAddress();
bool CheckEncoderTimeManipulaiton(); 
std::string exec(const char* cmd);
string testMac = "04-D9-F5-7D-1D-61";

int main()
{
	bool test = CheckEncoderDateValidity();
	bool test1 = CheckEncoderMacAddress();
	bool test2 = CheckEncoderTimeManipulaiton();
	
}


bool CheckEncoderDateValidity()
{
	HKEY hKey;
	LPCSTR sk = "SOFTWARE\\Microsoft\\WinRip";

	LONG openRes = RegOpenKeyExA(HKEY_CURRENT_USER, sk, 0, KEY_READ, &hKey);

	if (openRes != ERROR_SUCCESS)
	{
		return false;
	}
	//We are going to grab the trial end time
	size_t bufferSize = 0xFFF;
	std::string value = "lukkhal";
	std::string valueBuf;
	valueBuf.resize(bufferSize);
	auto cbData = static_cast<DWORD>(bufferSize * sizeof(wchar_t));

	auto rc = RegGetValueA(HKEY_CURRENT_USER, sk, value.c_str(), REG_SZ, nullptr, (void*)(valueBuf.data()), &cbData);

	cbData /= sizeof(char);
	valueBuf.resize(static_cast<size_t>(cbData - 1)); // remove end null character

	LONG closeOut = RegCloseKey(hKey);
	std::stringstream ss(valueBuf);
	std::tm tm = {};
	ss >> std::get_time(&tm, "%m / %d / %Y  %T");
	tm.tm_isdst = -1;
	auto trialPeriodTime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
	auto currentTime = std::chrono::system_clock::now();

	int test = difftime(std::chrono::system_clock::to_time_t(currentTime), std::chrono::system_clock::to_time_t(trialPeriodTime));

	if (test > 0)
	{
		return false;
	}

	return true;
}
bool CheckEncoderTimeManipulaiton()
{
	HKEY hKey;
	LPCSTR sk = "SOFTWARE\\Microsoft\\WinRip";

	LONG openRes = RegOpenKeyExA(HKEY_CURRENT_USER, sk, 0, KEY_READ, &hKey);

	if (openRes != ERROR_SUCCESS)
	{
		return false;
	}
	//We are going to grab the trial end time
	size_t bufferSize = 0xFFF;
	std::string value = "shzahjjlzzlk";
	std::string valueBuf;
	valueBuf.resize(bufferSize);
	auto cbData = static_cast<DWORD>(bufferSize * sizeof(wchar_t));

	auto rc = RegGetValueA(HKEY_CURRENT_USER, sk, value.c_str(), REG_SZ, nullptr, (void*)(valueBuf.data()), &cbData);

	cbData /= sizeof(char);
	valueBuf.resize(static_cast<size_t>(cbData - 1)); // remove end null character

	LONG closeOut = RegCloseKey(hKey);
	std::stringstream ss(valueBuf);
	std::tm tm = {};
	tm.tm_isdst = -1;
	ss >> std::get_time(&tm, "%m / %d / %Y  %T");
	auto lastAccessedTime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
	auto currentTime = std::chrono::system_clock::now();

	if (currentTime < lastAccessedTime)
	{
		return false;
	}

	return true;
}

bool CheckEncoderMacAddress()
{
	vector<string> vMacAddress;
	string sMacAddresses = exec("getmac");
	string sTempString;
	stringstream ssMacAddress(sMacAddresses);
	int index = 0;
	while (getline(ssMacAddress, sTempString, '\n'))
	{
		if (index++ > 2)
		{
			if (sTempString[0] != 'N')
			{
				vMacAddress.push_back(sTempString.substr(0, 17));
			}		
		}
	}
	for (auto value : vMacAddress)
	{
		if (value == testMac)
		{
			return true;
		}
	}
	return false;
}


std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	}
	catch (...) {
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return result;
}

