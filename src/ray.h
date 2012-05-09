#ifndef RAY_H_
#define RAY_H_

namespace softedge {

class Vector;

class Ray {
public:
    Ray(Vector origin, Vector direction);

private:
    Vector origin;
    Vector direction;
};

}  // namespace softedge
#endif /* RAY_H_ */
