//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/01/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "../upDate.h"

BOOST_AUTO_TEST_SUITE(testLogic)

BOOST_AUTO_TEST_CASE(OperatorEqual) {
    upDate tmp(3, 4, 2000);

    auto tmp2 = tmp;
    BOOST_CHECK(tmp == tmp2);
}

BOOST_AUTO_TEST_CASE(OperatorSup) {
    upDate tmp(3, 4, 2000);
    upDate tmp2(3, 10, 2000);

    BOOST_CHECK(tmp < tmp2);
}

BOOST_AUTO_TEST_CASE(OperatorLess) {
    upDate tmp(3, 4, 2000);
    upDate tmp2(1, 4, 2000);

    BOOST_CHECK(tmp > tmp2);
}

BOOST_AUTO_TEST_SUITE_END()