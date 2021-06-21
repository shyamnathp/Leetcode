//
// Created by shyamnath on 5/9/21.
//

#ifndef LEETCODE_BIGINTEGER_H
#define LEETCODE_BIGINTEGER_H

#include <cstdint>

class BIgInteger {
public:
    BIgInteger(unsigned long long value): m_value(value)
    {}

    BIgInteger& operator++()
    {
        ++m_value;
        return *this;
    }

    template<typename T>
    bool operator<(const T& compare)
    {

    }

private:
  unsigned long long m_value;
};


#endif//LEETCODE_BIGINTEGER_H
