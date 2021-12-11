#pragma once
#include "Data.h"
#include <iostream>
#include <fstream> 
#include <nlohmann/json.hpp>

using namespace nlohmann;

struct Report
{
	virtual void getReport() = 0 ;
	Data* data;
	virtual ~Report() { delete data; };
};

struct TxtReport :Report {
	TxtReport(const string& path);
	void getReport() override;
};

struct JsonReport:Report {
	JsonReport(const string& path);
	void getReport() override;
private:
	json Json;
};

