#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>

Rational a(4, 3);
Rational b(1, 2);

Rational sum(11, 6);
Rational dif(5, 6);
Rational prod(2, 3);
Rational div(8, 3);
Rational mod(1, 3);

TEST_CASE("checking arithmetic") {
    CHECK(a + b == sum);
    CHECK(a - b == dif);
    CHECK(a * b == prod);
    CHECK(a / b == dev);
    CHECK(a % b == mod);
}

Rational thirdPow_a(8, 27);
Rational sqr_a(4, 9);

TEST_CASE("checking custom") {
    CHECK(pow(a, 3) == thirdPow_a);
    CHECK(sqr(a) == sqr_a);
}

bool less = false;
bool equal = false;
bool bigger = true;

TEST_CASE("checking boolean") {
    CHECK((a < b) == less);
    CHECK((a == b) == equal);
    CHECK((a > b) == bigger);
}
