#include "Factory.h"
Report* Factory::ChooseReport(const string& report, const string& path)
{
	if (report == "txt") {
		return new TxtReport(path);
	}
	else if (report == "json") {
		return new JsonReport(path);
	}
	else
		throw exception("Incorrect type of report!");
}