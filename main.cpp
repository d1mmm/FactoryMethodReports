#include "Factory.h"
#include <iostream>


int main() {
	setlocale(LC_ALL, "Russian");
	string path, report;
	cout << "Enter your path to directory -> ";
	getline(cin, path);
	cout << "Enter your type of report (txt | json) -> ";
	getline(cin, report);
	try {
		Factory factory;
		factory.ChooseReport(report, path);
	}
	catch (const exception& ex) {
		cout << "Error -> " << ex.what() << endl;
	}
	system("pause");
	return 0;
}