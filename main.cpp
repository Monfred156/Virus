#include <iostream>
#include <random>
#include <chrono>
#include "Container.h"

int randomInRange(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    return distr(gen);
}

void stopChrono(std::chrono::time_point<std::chrono::system_clock> start , int sizeCube, Container container)
{
    auto stop = std::chrono::high_resolution_clock::now();
    auto durationSeconds = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    auto durationMilli = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationMicro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by program: " << durationSeconds.count() << "s," << durationMilli.count() << "," << durationMicro.count() << " for cube of size " << sizeCube << " wich represent " << container.getTotalCube() << " sub cubes" << std::endl;
}

void startSimulation(int sizeCube)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto container = Container(sizeCube);
    std::vector<Vector3> lastContaminated;
    std::vector<Vector3> lastContaminatedTemp;

    Vector3 positionFirstContaminated = Vector3(randomInRange(0, sizeCube - 1), randomInRange(0, sizeCube - 1), randomInRange(0, sizeCube - 1));
    container.contaminates(positionFirstContaminated);
    lastContaminated.emplace_back(positionFirstContaminated);

    int i = 1;
    while(container.getNumberOfContaminated() < container.getTotalCube())
    {
        for (auto & contaminated : lastContaminated)
        {
            std::vector<Vector3> faces;

            //TODO: Loop through config
            faces.emplace_back(Vector3(contaminated.getX() + 1, contaminated.getY(), contaminated.getZ()));
            faces.emplace_back(Vector3(contaminated.getX(), contaminated.getY() + 1, contaminated.getZ()));
            faces.emplace_back(Vector3(contaminated.getX(), contaminated.getY(), contaminated.getZ() + 1));
            faces.emplace_back(Vector3(contaminated.getX() - 1, contaminated.getY(), contaminated.getZ()));
            faces.emplace_back(Vector3(contaminated.getX(), contaminated.getY() - 1, contaminated.getZ()));
            faces.emplace_back(Vector3(contaminated.getX(), contaminated.getY(), contaminated.getZ() - 1));
            for (auto & face : faces)
            {
                if (container.contaminates(face)) {lastContaminatedTemp.emplace_back(face);}
            }
        }
        lastContaminated.clear();
        lastContaminated = lastContaminatedTemp;
        lastContaminatedTemp.clear();
        std::cout << "Contaminated: " << container.getNumberOfContaminated() << std::endl;
        std::cout << "Iteration: " << i << std::endl << std::endl;
        std::cout << "Percentage of contamination: " << container.getNumberOfContaminated() * 100 / container.getTotalCube() << std::endl;
        i++;
    }
    stopChrono(start, sizeCube, container);
}

int main(int ac, char **av)
{
    int sizeCube = 200;
    startSimulation(sizeCube);
}