#ifndef C_COMPLEX_H
#define C_COMPLEX_H

#include <iostream>

using namespace std;

class complex {
public:
    complex(double real = 2.0, double imag = 3.0) : re(real), im(imag) {};

    complex &operator+=(const complex &complex2);



    double getReal() const {
        return re;
    }

    double getImag() const {
        return im;
    }

private:
    double re, im;

    friend complex &_doapl(complex *com1, const complex &com2);
};

ostream &operator<<(ostream &os, const complex &complex);
#endif //C_COMPLEX_H
