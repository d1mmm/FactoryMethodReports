#include "Report.h"

TxtReport::TxtReport(const string& path)
{
	data = new Data(path);
	this->getReport();
}

void TxtReport::getReport()
{
	const vector<string> Info = data->ReadInfoAboutFiles();
	if (Info.empty())
		cout << "File not created!" << endl;
	else {
		ofstream file("TxtReport.txt");
		for (auto it = Info.begin(); it != Info.end(); it++)
			file << *it << endl;
		file.close();
		cout << "Succses!" << endl;
	}
}

JsonReport::JsonReport(const string& path)
{
	data = new Data(path);
	this->getReport();
}

void JsonReport::getReport()
{
	const vector<string> Info = data->ReadInfoAboutFiles();
	if (Info.empty())
		cout << "File not created!" << endl;
	else {
		ofstream file("JsonReport.json");
		Json = Info;
		file << setw(4) << Json << endl;
		file.close();
		cout << "Succses!" << endl; //debug
	}
}

