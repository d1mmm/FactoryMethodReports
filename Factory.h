#pragma once
#include "Report.h"
struct Factory
{
	Report* ChooseReport(const string& report, const string& path);
};

