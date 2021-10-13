//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/01/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "../upDate.h"

BOOST_AUTO_TEST_SUITE(testBasic)
BOOST_AUTO_TEST_CASE(ContructorEmpty) {
    upDate tmp;

    BOOST_CHECK_EQUAL(tmp.getMonth(),5);
    BOOST_CHECK_EQUAL(tmp.getDay(),11);
    BOOST_CHECK_EQUAL(tmp.getYear(),1959);
}

BOOST_AUTO_TEST_CASE(ContructorDate) {
    upDate tmp(3, 5, 2018);

    BOOST_CHECK_EQUAL(tmp.getMonth(),3);
    BOOST_CHECK_EQUAL(tmp.getDay(),5);
    BOOST_CHECK_EQUAL(tmp.getYear(),2018);
}

BOOST_AUTO_TEST_CASE(ContructorByRef) {
    upDate tmp(4, 3, 2000);
    upDate tmp2(tmp);


    BOOST_CHECK_EQUAL(tmp2.getMonth(),4);
    BOOST_CHECK_EQUAL(tmp2.getDay(),3);
    BOOST_CHECK_EQUAL(tmp2.getYear(),2000);
}

BOOST_AUTO_TEST_CASE(setDate) {
    upDate tmp(4, 3, 2000);

    BOOST_CHECK_EQUAL(tmp.getMonth(),4);
    BOOST_CHECK_EQUAL(tmp.getDay(),3);
    BOOST_CHECK_EQUAL(tmp.getYear(), 2000);

    tmp.setDate(10, 13, 2021);
    BOOST_CHECK_EQUAL(tmp.getMonth(), 10);
    BOOST_CHECK_EQUAL(tmp.getDay(), 13);
    BOOST_CHECK_EQUAL(tmp.getYear(), 2021);
}

BOOST_AUTO_TEST_CASE(getMonthName) {
    upDate tmp(4, 3, 2000);

    BOOST_CHECK(tmp.getMonthName() == "April");
}

BOOST_AUTO_TEST_CASE(Static) {
    upDate tmp(3, 4, 2000);
    upDate tmp2;
    auto tmp3 = new upDate();

    BOOST_CHECK_EQUAL(tmp.GetDateCount(), 3);

    delete tmp3;
    BOOST_CHECK_EQUAL(tmp.GetDateCount(), 2);
}

BOOST_AUTO_TEST_SUITE_END()