#include <iostream>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>

using namespace std;
using namespace ariel;


TEST_CASE("check constructors:")
{
     
      Fraction defult;
      Fraction fraction2(3, 4);
      Fraction fraction3(0.5);
      Fraction copy_cons(fraction2);
      
      CHECK(defult.number1 == 0);
      CHECK(defult.number2 == 1);
      CHECK(fraction2.number1 == 3);
      CHECK(fraction2.number2 == 4);
      CHECK(fraction3.number1 == 1);
      CHECK(fraction3.number2 == 2);
      CHECK(copy_cons.number1 == 3);
      CHECK(copy_cons.number2 == 4);
}


TEST_CASE("IO Operators")
{
      Fraction fraction1(3, 4);
      Fraction fraction2;
      std::stringstream ss;
      std::stringstream ss2("1/2");
      ss << fraction1;
      ss2 >> fraction2;
      
      CHECK_NOTHROW(ss << fraction1);
      CHECK(fraction2.number1 == 1);
     
}

TEST_CASE("equality"){
      Fraction fraction1(4, 8);
      Fraction fraction2(12, 24);
      Fraction fraction3(1, 4);
      Fraction fraction4(2, 8);

      CHECK(fraction1 == fraction2);
      CHECK(fraction3 == fraction4);
 
}

TEST_CASE("operator ++ and operator -- "){
      Fraction fraction1(6, 7);
      fraction1++;
      CHECK(fraction1.number1 == 13);
      CHECK(fraction1.number2 == 7);
      fraction1--;
      CHECK(fraction1.number1 == 6);
      CHECK(fraction1.number2 == 7);
}
TEST_CASE("check operators:"){

    Fraction fraction1(3, 8);
    Fraction fraction2(4, 5);
    Fraction fraction3 = fraction1 + fraction2;
    Fraction fraction4 = fraction1 - fraction2;
    Fraction fraction5 = fraction1 * fraction2;
    Fraction fraction6 = fraction1 / fraction2;

    CHECK(fraction3.number1 == 47);
    CHECK(fraction3.number2 == 40);
    CHECK(fraction4.number1 == -17);
    CHECK(fraction4.number2 == 40);
    CHECK(fraction5.number1 == 3);
    CHECK(fraction5.number2 == 10);
    CHECK(fraction6.number1 == 15);
    CHECK(fraction6.number2 == 32);

}