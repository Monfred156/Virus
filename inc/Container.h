#ifndef VIRUS_CONTAINER_H
#define VIRUS_CONTAINER_H
#include <cmath>
#include <unordered_map>
#include "Cube.h"

class Container
{
public:
    Container(int sizeOfContainer);
    ~Container();

    bool contaminates(const Vector3& position);

    int getNumberOfContaminated() const;
    double getTotalCube() const;

    friend std::ostream& operator<<(std::ostream& output, const Container& container);
    std::unordered_map<std::string, Cube> _cubeList;
private:

    unsigned long _numberOfContaminated;
    double _totalCube;
    int _sizeOfContainer;
};

#endif //VIRUS_CONTAINER_H
