#ifndef VIRUS_VECTOR3_H
#define VIRUS_VECTOR3_H

class Vector3
{
public:
    Vector3(float x, float y, float z);
    ~Vector3();

    void setX(float x);
    void setY(float y);
    void setZ(float z);
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    float _x;
    float _y;
    float _z;
};

static float Distance(Vector3 vector1, Vector3 vector2);

#endif //VIRUS_VECTOR3_H
