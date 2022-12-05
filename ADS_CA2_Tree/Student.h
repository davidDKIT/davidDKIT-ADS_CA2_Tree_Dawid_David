#pragma once
#include <ostream>
#include <string>
#include "Date.h"
using namespace std;

/// <summary>
/// Represents a row of data in a CSV file of Student records
/// </summary>
class Student {
#pragma region Fields
	string userid;
	int ranking;
	string country;
	Date date;
#pragma endregion

public:

#pragma region Constructors
	Student(string userid, int ranking, string country, Date date)
		: userid(userid), ranking(ranking), country(country), date(date)
	{
	}
#pragma endregion

#pragma region Get/Set
	string getUserid() const { return this->userid; }
	int getRanking() const { return this->ranking; }
	string getCountry() const { return this->country; }
	Date getDate() const { return this->date; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const Student& student)
	{
		return this->userid == student.userid
			&& this->ranking == student.ranking
			&& this->country == student.country
			&& this->date == student.date;
	}

	friend ostream& operator<<(ostream& output, Student& student) {
		output << student.userid << ",";
		output << student.ranking << ",";
		output << student.country << ",";
		output << student.date;
		return output;
	}

	friend istream& operator>>(istream& input, Student& student) {
		string studentAsStr;
		input >> studentAsStr;

		return input;
	}

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<string>()(this->userid)
			+ 31 * std::hash<int>()(this->ranking)
			+ std::hash<string>()(this->country)
			+ 349 * date.hash();
	}

#pragma endregion
};