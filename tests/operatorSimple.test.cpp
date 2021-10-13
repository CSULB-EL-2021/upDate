//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/01/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "../upDate.h"

BOOST_AUTO_TEST_SUITE(testOperator)

struct cout_redirect {
        cout_redirect( std::streambuf * new_buffer )
                : old( std::cout.rdbuf( new_buffer ) )
        { }

        ~cout_redirect( ) {
            std::cout.rdbuf( old );
        }

    private:
        std::streambuf * old;
};

BOOST_AUTO_TEST_CASE(OperatorEqual) {
    upDate tmp(3, 4, 2000);
    upDate tmp2;

    tmp2 = tmp;
    BOOST_CHECK_EQUAL(tmp2.getMonth(),3);
    BOOST_CHECK_EQUAL(tmp2.getDay(),4);
    BOOST_CHECK_EQUAL(tmp2.getYear(),2000);
}
BOOST_AUTO_TEST_CASE(OperatorAddEqualX) {
    upDate tmp(3, 4, 2000);
    int x = 10;

    tmp += x;
    BOOST_CHECK_EQUAL(tmp.getMonth(),3);
    BOOST_CHECK_EQUAL(tmp.getDay(),4 + x);
    BOOST_CHECK_EQUAL(tmp.getYear(),2000);
}
BOOST_AUTO_TEST_CASE(OperatorRemoveEqualX) {
    upDate tmp(3, 4, 2000);

    tmp -= 10;
    BOOST_CHECK_EQUAL(tmp.getMonth(),2);
    BOOST_CHECK_EQUAL(tmp.getDay(),23);
    BOOST_CHECK_EQUAL(tmp.getYear(),2000);
}

BOOST_AUTO_TEST_CASE(OperatorAddX) {
    upDate tmp(3, 4, 2000);

    auto tmp2 = 10 + tmp;
    BOOST_CHECK_EQUAL(tmp2.getMonth(),3);
    BOOST_CHECK_EQUAL(tmp2.getDay(),14);
    BOOST_CHECK_EQUAL(tmp2.getYear(),2000);
}
BOOST_AUTO_TEST_CASE(OperatorAddPostfixX) {
    upDate tmp(3, 4, 2000);

    auto tmp2 = tmp + 10;
    BOOST_CHECK_EQUAL(tmp2.getMonth(),3);
    BOOST_CHECK_EQUAL(tmp2.getDay(),14);
    BOOST_CHECK_EQUAL(tmp2.getYear(),2000);
}

BOOST_AUTO_TEST_CASE(OperatorRemoveX) {
    upDate tmp(3, 4, 2000);

    auto tmp2 = 2 - tmp;
    BOOST_CHECK_EQUAL(tmp2.getMonth(), 3);
    BOOST_CHECK_EQUAL(tmp2.getDay(), 2);
    BOOST_CHECK_EQUAL(tmp2.getYear(), 2000);
}
BOOST_AUTO_TEST_CASE(OperatorRemovePostfixX) {
    upDate tmp(3, 4, 2000);

    auto tmp2 = tmp - 2;
    BOOST_CHECK_EQUAL(tmp2.getMonth(), 3);
    BOOST_CHECK_EQUAL(tmp2.getDay(), 2);
    BOOST_CHECK_EQUAL(tmp2.getYear(), 2000);
}

BOOST_AUTO_TEST_CASE(OperatorAddAddX) {
    upDate tmp(3, 4, 2000);

    tmp++;
    BOOST_CHECK_EQUAL(tmp.getMonth(), 3);
    BOOST_CHECK_EQUAL(tmp.getDay(), 5);
    BOOST_CHECK_EQUAL(tmp.getYear(), 2000);
}
BOOST_AUTO_TEST_CASE(OperatorAddAddPostfixX) {
    upDate tmp(3, 4, 2000);

    ++tmp;
    BOOST_CHECK_EQUAL(tmp.getMonth(), 3);
    BOOST_CHECK_EQUAL(tmp.getDay(), 5);
    BOOST_CHECK_EQUAL(tmp.getYear(), 2000);
}

BOOST_AUTO_TEST_CASE(OperatorRemoveRemoveX) {
    upDate tmp(3, 4, 2000);

    tmp--;
    BOOST_CHECK_EQUAL(tmp.getMonth(), 3);
    BOOST_CHECK_EQUAL(tmp.getDay(), 3);
    BOOST_CHECK_EQUAL(tmp.getYear(), 2000);
}
BOOST_AUTO_TEST_CASE(OperatorRemoveRemovePostfixX) {
    upDate tmp(3, 4, 2000);

    --tmp;
    BOOST_CHECK_EQUAL(tmp.getMonth(), 3);
    BOOST_CHECK_EQUAL(tmp.getDay(), 3);
    BOOST_CHECK_EQUAL(tmp.getYear(), 2000);
}

BOOST_AUTO_TEST_CASE(OsStreamOutput) {
    upDate tmp(3, 3, 2000);

    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());
        std::cout << tmp << std::endl;
    }

    BOOST_CHECK(output.is_equal( "3/3/2000\n"));
}

BOOST_AUTO_TEST_SUITE_END()