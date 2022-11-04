#include "../inc/Vector3.h"

float Distance(Vector3 &vector1, Vector3 &vector2) {
    return 0;
}

Vector3::Vector3(float x, float y, float z) : _x(x), _y(y), _z(z) {

}

Vector3::~Vector3() {

}

float Vector3::getX() const {
    return _x;
}

float Vector3::getY() const {
    return _y;
}

float Vector3::getZ() const {
    return _z;
}

void Vector3::setX(float x) {
    _x = x;
}

void Vector3::setY(float y) {
    _y = y;
}

void Vector3::setZ(float z) {
    _z = z;
}
