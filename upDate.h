//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/01/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#ifndef PROG4_UPDATE_H
#define PROG4_UPDATE_H

#include <string>

using namespace std;

class upDate {
    public:
        upDate();
        upDate(int M, int D, int Y);
        upDate(int J);
        upDate(const upDate& obj);
        ~upDate();

        void setDate(int M, int D, int Y);

        int getMonth() const;
        int getDay() const;
        int getYear() const;
        string getMonthName() const;

        upDate& operator =(const upDate& obj);
        upDate& operator +=(int x);
        upDate& operator -=(int x);
        upDate& operator +(int x);
        upDate& operator -(int x);

        upDate& operator ++();
        upDate& operator ++(int x);
        upDate& operator --();
        upDate& operator --(int x);

        friend upDate operator +(int x, const upDate& obj);
        friend upDate operator -(int x, const upDate& obj);
        friend ostream& operator <<(ostream& out, upDate &obj);

        static int GetDateCount();

        int julian() const;

    private:
        int *_data;
        static int _counter;

        void julian2Greg(int JD, int & month, int & day, int & year);
        void addDay(int x);
        void removeDay(int x);

};


#endif //PROG4_UPDATE_H
