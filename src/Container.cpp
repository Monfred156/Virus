#include "Container.h"

Container::Container(int sizeOfContainer) : _sizeOfContainer(sizeOfContainer), _numberOfContaminated(0), _totalCube(pow(sizeOfContainer, 3)) {
    for (int x = 0; x < sizeOfContainer; x++) {
        for (int y = 0; y < sizeOfContainer; y++) {
            for (int z = 0; z < sizeOfContainer; z++) {
                _cubeList.emplace(std::make_pair(std::to_string(x) + "|" + std::to_string(y) + "|" + std::to_string(z),
                                                 Cube((float) x, (float) y, (float) z)));
            }
        }
    }
}

Container::~Container() {

}

std::ostream &operator<<(std::ostream &output, const Container& container) {
    for(auto & it : container._cubeList)
    {
        std::cout << it.second << std::endl;
    }
    return output;
}

bool Container::contaminates(const Vector3& position)
{
    if (position.getX() < 0 || (int)position.getX() >= _sizeOfContainer || position.getY() < 0 ||
    (int)position.getY() >= _sizeOfContainer || position.getZ() < 0 || (int)position.getZ() >= _sizeOfContainer) {
        return false;
    }
    if (_cubeList.at(std::to_string((int) position.getX())  + "|"  + std::to_string((int) position.getY()) + "|"  +
                      std::to_string((int) position.getZ())).isContaminated())
    {
        return false;
    }
    _numberOfContaminated++;
    _cubeList.at(std::to_string((int)position.getX()) + "|"  + std::to_string((int)position.getY()) + "|"  + std::to_string((int)position.getZ())).setContaminated(true);
    return true;
}

int Container::getNumberOfContaminated() const {
    return _numberOfContaminated;
}

double Container::getTotalCube() const {
    return _totalCube;
}
