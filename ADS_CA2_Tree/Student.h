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
	string fname;
	string surname;
	string gender;
	Date date_of_birth;
	string email;
	string phone;
	string postcode;
	string country;
	string last_log_date;
	string last_log_time;
	string join_date;
	string account_credit;
	string address;
#pragma endregion

public:

#pragma region Constructors
	Student(string userid, int ranking, string fname, string surname, string gender, Date date_of_birth,
	string email, string phone, string postcode, string country, string last_log_date, string last_log_time, string join_date,
		string address)
		: userid(userid), ranking(ranking), fname(fname), surname(surname), gender(gender), date_of_birth(date_of_birth), email(email)
		, phone(phone), postcode(postcode), country(country), last_log_date(last_log_date), last_log_time(last_log_time), join_date(join_date),
		address(address)

	{
	}
#pragma endregion

#pragma region Get/Set
	string getUserid() const { return this->userid; }
	int getRanking() const { return this->ranking; }
	string getFname() const { return this->fname; }
	string getSurname() const { return this->surname; }
	string getGender() const { return this->gender; }
	Date getDOB() const { return this->date_of_birth; }
	string getEmail() const { return this->email; }
	string getPhone() const { return this->phone; }
	string getPostcode() const { return this->postcode; }
	string getCountry() const { return this->country; }
	string getLastLogDate() const { return this->last_log_date; }
	string getLastLogTime() const { return this->last_log_time; }
	string getJoinDate() const { return this->join_date; }
	string getAddress() const { return this->address; }


#pragma endregion

#pragma region Operators & Hash

	bool operator==(const Student& student)
	{
		return this->userid == student.userid
			&& this->ranking == student.ranking
			&& this->fname == student.fname
			&& this->surname == student.surname
			&& this->gender == student.gender
			&& this->date_of_birth == student.date_of_birth
			&& this->email == student.email
			&& this->phone == student.phone
			&& this->postcode == student.postcode
			&& this->country == student.country
			&& this->last_log_date == student.last_log_date
			&& this->last_log_time == student.last_log_time
			&& this->join_date == student.join_date
			&& this->address == student.address;
	}

	friend ostream& operator<<(ostream& output, Student& student) {
		output << student.userid << ",";
		output << student.ranking << ",";
		output << student.fname << ",";
		output << student.surname << ",";
		output << student.country << ",";
		output << student.gender << ",";
		output << student.date_of_birth << ",";
		output << student.email << ",";
		output << student.phone << ",";
		output << student.postcode << ",";
		output << student.country << ",";
		output << student.last_log_date << ",";
		output << student.last_log_time << ",";
		output << student.join_date << ",";
		output << student.address << ",";
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
			+ 31 * std::hash<string>()(this->fname)
			+ 57 * std::hash<string>()(this->phone)
			+ 349 * date_of_birth.hash();
	}

#pragma endregion
};