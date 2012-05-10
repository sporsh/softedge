#ifndef RAY_H_
#define RAY_H_

namespace softedge {

class Vector3;

class Ray {
public:
    Ray(Vector3 origin, Vector3 direction);

//private:
    Vector3 origin;
    Vector3 direction;
};

}  // namespace softedge
#endif /* RAY_H_ */
