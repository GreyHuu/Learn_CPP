#include "String.cpp"
#include <iostream>

int main() {
    String str("123");
    String str2(str);
    String str4("456");
    String str3 = str4;

    std::cout << str.get_c_str() << std::endl;
    std::cout << str2.get_c_str() << std::endl;
    std::cout << str3.get_c_str() << std::endl;
    std::cout << str4.get_c_str() << std::endl;
}