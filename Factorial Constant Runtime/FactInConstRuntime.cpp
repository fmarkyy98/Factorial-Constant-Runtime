#include <iostream>

template<unsigned long long int i>
struct Fact
{
    static const unsigned long long int value = i * Fact<i - 1>::value;
    friend std::ostream& operator<<(std::ostream& os, Fact<i>& f);
};

template<>
struct Fact<0>
{
    static const int value = 1;
    friend std::ostream& operator<<(std::ostream& os, Fact& f);
};

template<unsigned long long int i>
std::ostream& operator<<(std::ostream& os, Fact<i>& f)
{
    os << f.value;
    return os;
}

int main()
{
    Fact<10> f; // Type any number that doesn't owerflow with its factorial a 64bit unsigned int,
                // not my fault, that the C++ doesn't have larger Integral type.
    std::cout << f.value;
}
