#include "Rational.h"

Rational::Rational() {
    num = 0;
    denum = 1;
}
Rational::Rational(int32_t numInp) {
    num = numInp;
    denum = 1;
}
Rational::Rational(const Rational& myRat) {
    num = myRat.num;
    denum = myRat.denum;
}
Rational::Rational(const int32_t numInp, const int32_t denumInp) {
    if (denumInp <= 0) {
        throw std::invalid_argument("Expected positive denumerator");
    }
    num = numInp;
    denum = denumInp;
    reducing();
}

Rational& Rational::operator=(const Rational& rhs) {
    num = rhs.num;
    denum = rhs.denum;
    return *this;
}
Rational& Rational::operator+=(const Rational& rhs) {
    int32_t mult = rhs.denum / gcd(denum, rhs.denum);
    num *= mult;
    denum *= mult;
    num += denum / rhs.denum * rhs.num;
    reducing();
    return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
    int32_t mult = rhs.denum / gcd(denum, rhs.denum);
    num *= mult;
    denum *= mult;
    num -= denum / rhs.denum * rhs.num;
    reducing();
    return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
    num *= rhs.num;
    denum *= rhs.denum;
    reducing();
    return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.isZero()) {
        throw std::overflow_error("Divide by zero exception");
    }
    num *= rhs.denum;
    denum *= rhs.num;
    reducing();
    return *this;
}

Rational& Rational::operator++() {
    *this += 1;
    return *this;
}
Rational Rational::operator++(int) {
    Rational tmp(*this);
    ++(*this);
    return tmp;
}
Rational& Rational::operator--() {
    *this -= 1;
    return *this;
}
Rational Rational::operator--(int) {
    Rational tmp(*this);
    --(*this);
    return tmp;
}

Rational& Rational::operator%=(const Rational& rhs) {
    int32_t mult = rhs.denum / gcd(denum, rhs.denum);
    num *= mult;
    denum *= mult;
    num %= denum / rhs.denum * rhs.num;
    reducing();
    return *this;
}

bool Rational::isPositive() const {
    return num > 0;
}
bool Rational::isZero() const {
    return num == 0;
}
bool Rational::isNegative() const {
    return num < 0;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}

Rational& operator+(Rational& rhs) {
    return rhs;
}
Rational& operator-(Rational& rhs) {
    Rational tmp;
    tmp -= rhs;
    return tmp;
}

Rational operator+(Rational lhs, const Rational& rhs) {
    lhs += rhs;
    return lhs;
}
Rational operator-(Rational lhs, const Rational& rhs) {
    lhs -= rhs;
    return lhs;
}
Rational operator*(Rational lhs, const Rational& rhs) {
    lhs *= rhs;
    return lhs;
}
Rational operator/(Rational lhs, const Rational& rhs) {
    lhs /= rhs;
    return lhs;
}
Rational sqr(Rational myRat) {
    myRat *= myRat;
    return myRat;
}
Rational pow(Rational myRat, int32_t power) {
    Rational answer(1);
    while (power) {
        if (power & 1) {
            answer *= myRat;
        }
        myRat = sqr(myRat);
        power >>= 1;
    }
    return answer;
}

Rational operator%(Rational lhs, const Rational& rhs)
{
    lhs %= rhs;
    return lhs;
}

bool operator==(Rational lhs, const Rational& rhs) {
    lhs -= rhs;
    return lhs.isZero();
}
bool operator>(Rational lhs, const Rational& rhs) {
    Rational diff = lhs - rhs;
    return diff.Rational::isPositive();
}
bool operator<(Rational lhs, const Rational& rhs) {
    Rational diff = lhs - rhs;
    return diff.Rational::isNegative();
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !operator==(lhs, rhs);
}
bool operator<=(const Rational& lhs, const Rational& rhs) {
    return !operator>(lhs, rhs);
}
bool operator>=(const Rational& lhs, const Rational& rhs) {
    return !operator<(lhs, rhs);
}

int32_t Rational::gcd(int32_t a, int32_t b) const {
    while (a != 0) {
        if (a < b) {
            std::swap(a, b);
        }
        a %= b;
    }
    return b;
}

void Rational::reducing() {
    int32_t dev = gcd(std::abs(num), denum);
    num /= dev;
    denum /= dev;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num << slash << denum;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    int32_t numInp(0);
    char separator(0);
    int32_t denumInp(0);
    istrm >> numInp >> separator >> denumInp;
    if (istrm.good()) {
        if (Rational::slash == separator) {
            if (denumInp <= 0) {
                throw std::invalid_argument("Expected positive denumerator");
            }
            num = numInp;
            denum = denumInp;
            reducing();
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
