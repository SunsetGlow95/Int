#ifndef INT_HPP
#define INT_HPP

#include <deque>
#include <iostream>

class Int
{
public:
    // construct/copy/destroy 

    Int();
    Int(const Int&) = default;
    Int(long);
    Int(unsigned long);
    ~Int() = default;
    Int& operator=(const Int&);

    // operate

    friend Int operator+(const Int&, const Int&);
    friend Int operator-(const Int&, const Int&);
    friend Int operator*(const Int&, const Int&);
    friend Int operator/(const Int&, const Int&);
    friend Int operator%(const Int&, const Int&);
    friend Int operator^(const Int&, const Int&);
    Int& operator+=(const Int&);
    Int& operator-=(const Int&);
    Int& operator*=(const Int&);
    Int& operator/=(const Int&);
    Int& operator%=(const Int&);
    Int& operator^=(const Int&);
    Int& operator++();
    Int& operator--();
    const Int operator++(int);
    const Int operator--(int);
    const Int operator+() const;
    const Int operator-() const;

    // compare

    friend bool operator==(const Int&, const Int&);
    friend bool operator!=(const Int&, const Int&);
    friend bool operator<(const Int&, const Int&);
    friend bool operator>(const Int&, const Int&);
    friend bool operator<=(const Int&, const Int&);
    friend bool operator>=(const Int&, const Int&);

    // input/output

    friend std::istream operator>>(std::istream&, Int&);
    friend std::ostream operator<<(std::ostream&, const Int&);

    // cast

    operator long() const;
    operator u_long() const;

private:
    typedef std::deque<int> digits_type;
    static const int RADIX = 10000;
    static const int DIGIT_WIDTH = 4;
    bool sign;
    digits_type digits;
    void adjust();
};

Int::Int()
{
    sign = true;
}

Int::Int(long n)
{
    if (n < 0) {
        n = -n;
    } else {
        sign = true;
    }
    while (n) {
        digits.push_back(n % RADIX);
        n /= RADIX;
    }
}

Int(unsigned long n)
{
    sign = true;
    while (n) {
        digits.push_back(n % RADIX);
        n /= RADIX;
    }
}

Int& Int::operator=(const Int& rhs)
{
    if (&rhs == this) return *this;
    digits = rhs.digits, sign = rhs.sign;
    return *this;
}

std::istream operator>>(std::istream& is, Int& n)
{
    // TODO: finish the input part
    return is;
}

std::ostream operator<<(std::ostream& os, const Int& n)
{
    for (Int::digits_type::const_iterator i(n.digits.begin()); i != n.digits.end(); ++i) {
        os.width(Int::DIGIT_WIDTH);
        os.fill('0');
        os << *i;
    }
    return os;
}

// TODO: finish operating functions

// TODO: finish comparing functions

// TODO: finish Int->long/Int->u_long

#endif
