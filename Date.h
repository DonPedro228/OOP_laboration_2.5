#pragma once
#include "Triad.h"
using namespace std;

class Date
{
private:
	Triad date;
public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);

    void Init(int day, int month, int year);
    void Display() const;
    void Read();
    operator string() const;
    
    int getDay() const { return date.getDay(); }
    int getMonth() const { return date.getMonth(); }
    int getYear() const { return date.getYear(); }
    void setDay(int day) { date.setDay(day); }
    void setMonth(int month) { date.setMonth(month); }
    void setYear(int year) { date.setYear(year); }

    Date& operator ++();
    Date& operator --();

    friend ostream& operator << (ostream& out, const Date& m);
    friend istream& operator >> (istream& in, Date& m);

    Date& operator = (const Date& other);
    friend Date operator+(const Date& date, int days);


    ~Date(void);


};