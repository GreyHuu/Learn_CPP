#include "complex.h"

inline complex &_doapl(complex *com1, const complex &com2) {
    com1->re += com2.re;
    com1->im += com2.im;
    return *com1;
}

complex &complex::operator+=(const complex &complex2) {
    return _doapl(this, complex2);
}

ostream &operator<<(ostream &os, const complex &complex) {
    return os << "( " << complex.getReal() << " , " << complex.getImag() << "i )" << endl;
}
