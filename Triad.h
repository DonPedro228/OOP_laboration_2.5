#pragma once
#include <iostream>
#include <string>
using namespace std;

class Triad
{
private:
    int date[3];
public:
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    Triad();
    Triad(int day, int month, int year);
    Triad(const Triad& other);

    void Init(int day, int month, int year);
    void Display() const;
    void Read();

    Triad& operator ++();
    Triad& operator --();

    Triad& operator = (const Triad& other);
    friend ostream& operator << (ostream& out, const Triad& m);
    friend istream& operator >> (istream& in, Triad& m);
    operator string () const;


    ~Triad(void);
};