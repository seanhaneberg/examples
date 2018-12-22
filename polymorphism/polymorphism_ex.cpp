#include <stdio.h>

class Vehicle
{
  public:
    // Remove the "virtual" keyword to "turn off" polymorphism
    virtual void makeNoise()
    {
        printf("doot!\n");
    }
};

class Car : public Vehicle
{
    void makeNoise()
    {
        printf("honk!\n");
    }
};

class Train : public Vehicle
{
    void makeNoise()
    {
        printf("chuga!\n");
    }
};

void pokeVehicle(Vehicle &v)
{
    v.makeNoise();
}

int main()
{
    Vehicle vehicle;
    Car car;
    Train train;

    pokeVehicle(vehicle);
    pokeVehicle(car);
    pokeVehicle(train);
    return 0;
}