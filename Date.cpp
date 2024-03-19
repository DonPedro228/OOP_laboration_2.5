#include "Date.h"
#include "Triad.h"
#include <sstream>
using namespace std;

Date::Date() {}

Date::Date(int day, int month, int year) 
{
    date.Init(day, month, year);
}

Date::Date(const Date& other) {}

void Date::Init(int day, int month, int year)
{   
    date.Init(day, month, year);
}

void Date::Display() const 
{
    date.Display();
}

void Date::Read() 
{
    date.Read();
}

Date::operator string() const 
{
    return string(date);
}

Date& Date::operator++() 
{
    ++date;
    return *this;
}

Date& Date::operator--() 
{
    --date;
    return *this;
}

Date& Date::operator=(const Date& other)
{
    if (this != &other) {
        date = other.date;
    }
    return *this;
}

Date operator+(const Date& date, int days) {
    int day = date.getDay() + days;
    int month = date.getMonth();
    int year = date.getYear();

    while (day > 31 || (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29) ||
        (month == 2 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) && day > 28) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                day -= 29;
            }
            else {
                day -= 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            day -= 30;
        }
        else {
            day -= 31;
        }
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    Date result(date); 
    result.setDay(day);
    result.setMonth(month);
    result.setYear(year);

    return result; 
}

ostream& operator << (ostream& out, const Date& m)
{
    out << m.date;
    return out;
}


istream& operator >> (istream& in, Date& m)
{
    in >> m.date;
    return in;
}


Date::~Date() {}