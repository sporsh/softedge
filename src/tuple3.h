#ifndef TUPLE3_H_
#define TUPLE3_H_

#include "real.h"

namespace softedge {

class Tuple3 {
public:
    real& x;
    real& y;
    real& z;

    Tuple3();
    Tuple3(const Tuple3& tuple);
    Tuple3(const real array[3]);
    Tuple3(real x, real y, real z);

    Tuple3& operator =(const Tuple3& tuple);


    Tuple3 operator -(const Tuple3& t) const;
    Tuple3 operator +(const Tuple3& t) const;
    Tuple3 operator *(const Tuple3& t) const;
    Tuple3 operator /(const Tuple3& t) const;
    Tuple3& operator -=(const Tuple3& t);
    Tuple3& operator +=(const Tuple3& t);
    Tuple3& operator *=(const Tuple3& t);
    Tuple3& operator /=(const Tuple3& t);

    Tuple3 operator *(real s) const;
    Tuple3 operator /(real s) const;
    Tuple3& operator *=(real s);
    Tuple3& operator /=(real s);

private:
    real tuple[3];
};

struct Vec {
    real Tuple3::* x;
    real Tuple3::* y;
    real Tuple3::* z;
};

} /* namespace softedge */
#endif /* TUPLE3_H_ */
