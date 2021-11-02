//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/01/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#include "upDate.h"
#include <iostream>

void display(const upDate &date) {
    std::cout << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;
}

int main()
{
    upDate tmp1;
    upDate tmp2(3, 3, 2000);
    upDate tmp3;

    display(tmp1);
    display(tmp2);
    std::cout << "------" << std::endl;

    // tmp3 = 2 + tmp2 ;
    tmp3 = 2 + tmp2;
    display(tmp1);
    display(tmp2);
    display(tmp3);


    return 0;
}
