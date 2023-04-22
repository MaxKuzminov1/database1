#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <vector>

using namespace std;

struct Speed {
	int one;
};
struct Date {
	int day;
};
struct  Location {
	int lokal;
};
struct Data {
	Speed speed;
	Date date;
	Location location;
};

void ReadingData(Data* (&d), int& n, string filename);
void Print(Data* d, int n);
void SpeedSorting (Data* d, int n);
void Excel(Data* d, int n);
