#include <iostream>
// Target
// Car.hpp
class Car
{
public:
    virtual int GetCarSpeed() = 0;
};
// Bus.hpp
class Bus : public Car
{
public:
    Bus(int Speed) : Speed(Speed) {};
    int GetCarSpeed() override
    {
        return this->Speed;
    }

private:
    int Speed;
};
// Adaptee
// Motorcycle.hpp
class Motorcycle
{
public:
    virtual int GetMotorcyleSpeed() = 0;
};
// Scooter.hpp
class Scooter : public Motorcycle
{
public:
    Scooter(int Speed) : Speed(Speed) {};
    int GetMotorcyleSpeed() override
    {
        return this->Speed;
    }

private:
    int Speed;
};
// Adapter
// MotorcycleToCar.hpp
class MotorcycleToCar : public Car
{
public:
    MotorcycleToCar(Motorcycle *_Motorcycle) : _Motorcycle(_Motorcycle) {};
    int GetCarSpeed() override
    {
        int Speed = _Motorcycle->GetMotorcyleSpeed();
        return Speed;
    }

private:
    Motorcycle *_Motorcycle;
};
int main()
{
    Scooter *_Scooter = new Scooter(2);
    MotorcycleToCar *_MotorcycleToCar = new MotorcycleToCar(_Scooter);
    std::cout << _MotorcycleToCar->GetCarSpeed() << std::endl;

    delete _Scooter;
    delete _MotorcycleToCar;
    return 0;
}