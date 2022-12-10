#pragma once
#include <string>
#include "Date.h"
using namespace std;

class sKey
{
    string userid;
    string fname;
    string phone;
public:

    sKey(string userid, string surname,
        string phone) :
        userid(userid), fname(fname), phone(phone)
    {
    }

    string getuserid() const { return this->userid; }
    string getFname() const { return this->fname; }
    string getPhone() const { return this->phone; }

    friend ostream& operator<<(ostream& output, sKey& student) {
        output << student.userid << ",";
        output << student.fname << ",";
        output << student.phone << ",";

        return output;
    }

    std::size_t hash() const
    {
        //What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
        //What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
        size_t hash = std::hash<string>()(this->userid)
            + 31 * std::hash<string>()(this->fname)
            + 57 * std::hash<string>()(this->phone);
    }
};