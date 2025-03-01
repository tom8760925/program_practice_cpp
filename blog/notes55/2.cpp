#include <vector>
#include <iostream>
// object structure
// Sports.hpp
class Sports
{
public:
    Sports(int _Acceleration) : Acceleration(_Acceleration) {};
    ~Sports() {};
    int GetAcceleration() { return this->Acceleration; };

private:
    int Acceleration;
};
// Bus.hpp
class Bus
{
public:
    Bus(int _Acceleration) : Acceleration(_Acceleration) {};
    ~Bus() {};
    int GetAcceleration() { return this->Acceleration; };

private:
    int Acceleration;
};
//  car.hpp
using Car = std::variant<Sports, Bus>;
//  cars.hpp
using Cars = std::vector<Car>;

// client
// Speed.hpp
void Speed(Cars &_Cars)
{
    for (auto car : _Cars)
    {
        if (Sports *_Sports = std::get_if<Sports>(&car))
        {
            std::cout << _Sports->GetAcceleration() << std::endl;
        }
        else if (Bus *_Bus = std::get_if<Bus>(&car))
        {
            std::cout << _Bus->GetAcceleration() << std::endl;
        }
    }
}

int main()
{
    Cars _cars;
    _cars.emplace_back(Sports{5});
    _cars.emplace_back(Bus{1});
    Speed(_cars);
    return 0;
}