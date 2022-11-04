#include "../inc/Cube.h"

Cube::Cube(float x, float y, float z) {
    _position = new Vector3(x, y, z);
}

Cube::~Cube() {

}

std::ostream &operator<<(std::ostream &output, const Cube& cube) {
    output << "x:" << cube._position->getX() << "|y:" << cube._position->getY() << "|z:" << cube._position->getZ() << "|Infected:" << cube._contaminated;
    return output;
}

bool Cube::isContaminated() const {
    return _contaminated;
}

void Cube::setContaminated(bool contaminated) {
    _contaminated = contaminated;
}
