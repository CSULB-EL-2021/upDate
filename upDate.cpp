//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/01/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.


#include "upDate.h"
#include <iostream>

int upDate::_counter = 0;

upDate::upDate()
{
    _data = new int[3];

    _data[0] = 5;
    _data[1] = 11;
    _data[2] = 1959;

    _counter++;
}
upDate::upDate(int M, int D, int Y)
{
    _data = new int[3];

    this->setDate(M, D, Y);
    _counter++;
}
upDate::upDate(int J)
{
    _data = new int[3];

    this->julian2Greg(J, _data[0], _data[1], _data[2]);
    _counter++;
}
upDate::upDate(const upDate &obj)
{
    _data = new int[3];
    _data[0] = obj._data[0];
    _data[1] = obj._data[1];
    _data[2] = obj._data[2];

    _counter++;
}

upDate::~upDate()
{
    _counter--;
    delete[] _data;
}

void upDate::setDate(int M, int D, int Y)
{
    _data[0] = M;
    _data[1] = D;
    _data[2] = Y;

    this->julian2Greg(this->julian(), _data[0], _data[1], _data[2]);
    if (_data[0] != M || _data[1] != D || _data[2] != Y) {
        _data[0] = 5;
        _data[1] = 11;
        _data[2] = 1959;
    }
}

int upDate::getMonth() const
{
    return _data[0];
}
int upDate::getDay() const
{
    return _data[1];
}
int upDate::getYear() const
{
    return _data[2];
}
string upDate::getMonthName() const
{
    const std::string months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    return months[_data[0] - 1];
}

int upDate::julian() const
{
    int month = _data[0];
    int day = _data[1];
    int year = _data[2];

    return day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
}
void upDate::julian2Greg(int JD, int &month, int &day, int &year) {
    int L, N, I, J, K;

    L = JD+68569;
    N = 4*L/146097;
    L = L-(146097*N+3)/4;
    I = 4000*(L+1)/1461001;
    L = L-1461*I/4+31;
    J = 80*L/2447;
    K = L-2447*J/80;
    L = J/11;
    J = J+2-12*L;
    I = 100*(N-49)+I+L;

    year = I;
    month = J;
    day = K;
}

upDate &upDate::operator=(const upDate& obj)
{
    _data = new int[3];
    _data[0] = obj._data[0];
    _data[1] = obj._data[1];
    _data[2] = obj._data[2];

    return *this;
}
upDate &upDate::operator+=(int x)
{
    this->addDay(x);
    return *this;
}
upDate &upDate::operator-=(int x)
{
    this->removeDay(x);
    return *this;
}
upDate &upDate::operator+(int x)
{
    this->addDay(x);
    return *this;
}
upDate &upDate::operator-(int x)
{
    this->removeDay(x);
    return *this;
}

upDate &upDate::operator++(int x)
{
    this->addDay(1);
    return *this;
}
upDate &upDate::operator++()
{
    this->addDay(1);
    return *this;
}
upDate &upDate::operator--(int x)
{
    this->removeDay(1);
    return *this;
}
upDate &upDate::operator--()
{
    this->removeDay(1);
    return *this;
}

upDate operator+(int x, const upDate& obj)
{
    upDate tmp(obj);
    return tmp + x;
}
upDate operator-(int x, const upDate &obj)
{
    upDate tmp(obj);
    return tmp - x;
}
ostream &operator<<(ostream &os, upDate &obj)
{
    os << obj.getMonth() << "/" << obj.getDay() << "/" << obj.getYear();
    return os;
}

void upDate::addDay(int x)
{
    int day = this->julian() + x;
    this->julian2Greg(day, _data[0], _data[1], _data[2]);
}
void upDate::removeDay(int x)
{
    int day = this->julian() - x;
    this->julian2Greg(day, _data[0], _data[1], _data[2]);
}

int upDate::GetDateCount()
{
    return _counter;
}

bool upDate::operator==(const upDate& obj) const
{
    return this->julian() == obj.julian();
}


bool upDate::operator<(const upDate& obj) const
{
    return this->julian() < obj.julian();
}

bool upDate::operator>(const upDate& obj) const
{
    return this->julian() > obj.julian();
}





