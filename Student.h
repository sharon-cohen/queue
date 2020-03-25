#pragma once

#include <iostream>
using namespace std;

class Student
{
public:
    Student(int age, double avg) : _age(age), _avg(avg) {}

public:
    int			getAge() const { return _age; }
    double		getAvg() const { return _avg; }

private:
    int			_age;
    double		_avg;
};

ostream& operator << (ostream& out, const Student& s1);

class CompareByAge
{
public:
    template <class T>
    bool operator()(const T& hasAge1, const T& hasAge2)
    {
        return hasAge1.getAge() < hasAge2.getAge();
    }
};

class CompareByAvg
{
public:
    template <class T>
    bool operator()(const T& hasAvg1, const T& hasAvg2) const
    {
        return hasAvg1.getAvg() < hasAvg2.getAvg();
    }
};