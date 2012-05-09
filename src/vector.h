#ifndef VECTOR_H_
#define VECTOR_H_

#include "tuple.h"
#include "real.h"

namespace softedge {

class Vector: public Tuple<3, real> {
public:
    real& x;
    real& y;
    real& z;

    Vector();
    Vector(const Tuple<3, real>& tuple);
    Vector(const Vector& vector);
    Vector(real x, real y, real z);

    Vector& operator =(const Vector&);
};

real dot(const Vector& A, const Vector& B);
real length(const Vector& v);
Vector normalize(const Vector& v);
Vector resize(const Vector& v, const real length);

}  // namespace softedge
#endif /* VECTOR_H_ */
