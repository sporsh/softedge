#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "tuple.h"
#include "real.h"

namespace softedge {

class Vector3: public Tuple<3, real> {
public:
    real& x;
    real& y;
    real& z;

    Vector3();
    Vector3(const Tuple<3, real>& tuple);
    Vector3(const Vector3& vector);
    Vector3(real x, real y, real z);

    Vector3& operator =(const Vector3&);

public:
    static const Vector3 X, Y, Z, ZERO;
};

real dot(const Vector3& A, const Vector3& B);
Vector3 cross(const Vector3& A, const Vector3& B);
real length(const Vector3& v);
Vector3 normalize(const Vector3& v);
Vector3 resize(const Vector3& v, const real length);

}  // namespace softedge
#endif /* VECTOR3_H_ */
