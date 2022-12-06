// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Student.h"
#include "Date.h"
#include "TNode.h"
#include "BinaryTree.h"

using namespace std;

void demoSimpleHash();
void demoDateHash();
void demoParseString();
void demoCSVToObject();

int main()
{
	cout << endl << "demoSimpleHash()..........." << endl;
	demoSimpleHash();

	cout << endl << "demoDateHash()..........." << endl;
	demoDateHash();

	cout << endl << "demoParseString()..........." << endl;
	demoParseString();

	cout << endl << "demoCSVToObject()..........." << endl;
	demoCSVToObject();

	return 0;
}

void demoSimpleHash() {
	//hasher for strings
	hash<string> hasherStr;
	string email = "john.smith@hotmail.com";
	cout << "hash[" << email << "]: " << hasherStr(email) << endl;

	//hasher for doubles
	hash<double> hasherDbl;
	double price = 123123.322;
	cout << "hash[" << price << "]: " << hasherDbl(price) << endl;

	//we can re-use a hasher
	double weight = 12345.9897;
	cout << "hash[" << weight << "]: " << hasherDbl(weight) << endl;

	//we can store the hash value using size_t (basically an unsigned int)
	size_t myHash = hasherStr("this is a hash value store in a uint");
	cout << myHash << endl;
}

void demoDateHash() {
	Date myDate(25, 12, 2022);
	cout << myDate << endl;
	cout << "hash[" << myDate << "]: " << myDate.hash() << endl;
}

//useful - fails when a row of data contains a field (e.g., address) which contains commas
void demoParseString(std::string& passed)
{
	string str = passed;
	string delimiter = ",";

	vector<string> rowFromCSV = splitString(str, delimiter);

	if (rowFromCSV.size() == 4)
	{
		string userid = rowFromCSV[0];
		int ranking = stoi(rowFromCSV[1]);
		string country = rowFromCSV[2];
		vector<string> dateWords = splitString(rowFromCSV[3], "/");

		if (dateWords.size() == 3)
		{
			int date_day = stoi(dateWords[0]);
			int date_month = stoi(dateWords[1]);
			int date_year = stoi(dateWords[2]);

			Date registrationDate(date_day, date_month, date_year);
			Student myStudent(userid, ranking, country, registrationDate);

			cout << "Student: " << myStudent << endl;
		}
	}
}

//best - supports rows of data that contain commas and parenthesis - thanks for Derek!
void demoCSVToObject()
{
	string delimiter = ",";
	//note: data is a sub-folder under the folder with main CPP file
	string fileName = "data/data_4.csv";
	vector<vector<string>> allData = readDelimitedRows(fileName);

	for (vector<string> row : allData) {
		for (std::string field : row) {
			cout << field << ",";
			demoParseString(field);
		}
		cout << endl;
	}
	
}