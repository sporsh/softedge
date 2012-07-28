#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "tuple3.h"
#include "real.h"

#include <math.h>

namespace softedge {

typedef Tuple3 Vector3;

inline real dot(const Vector3& A, const Vector3& B) {
    return (A.x * B.x) + (A.y * B.y) + (A.z * B.z);
}

inline Vector3 cross(const Vector3& A, const Vector3& B) {
    return Vector3(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z,
                   A.x * B.y - A.y * B.x);
}

inline real length(const Vector3& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

inline Vector3 resize(const Vector3& v, const real s) {
    return v * (s / length(v));
}

inline Vector3 normalize(const Vector3& v) {
    return resize(v, 1);
}

}  // namespace softedge
#endif /* VECTOR3_H_ */
