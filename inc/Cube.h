#ifndef VIRUS_CUBE_H
#define VIRUS_CUBE_H

#include "iostream"
#include "Vector3.h"

class Cube{
public:
    Cube(float x, float y, float z);
    ~Cube();
    friend std::ostream& operator<<(std::ostream& output, const Cube& cube);

    void setContaminated(bool contaminated);
    bool isContaminated() const;

private:
    Vector3* _position;
    bool _contaminated = false;
};

#endif //VIRUS_CUBE_H
