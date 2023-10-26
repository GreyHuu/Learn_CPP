#include "complex.cpp"
#include <iostream>

int main() {
    complex com1;
    complex com2(3.0, 6.0);
    std::cout << com1;
    std::cout << (com1 += com2);
}