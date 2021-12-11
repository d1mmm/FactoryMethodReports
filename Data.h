#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <filesystem>

using namespace std;
using namespace filesystem;
using namespace chrono;

struct Data
{
	Data(const string& path);
	const vector<string> ReadInfoAboutFiles();
private:
	char* ConvertTime(const path& path) const;
	vector<string> InfoAboutFiles;
};

