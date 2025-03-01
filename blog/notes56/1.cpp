#include <iostream>
class Sports;
class Bus;
// client
// SpeedStrategy.hpp
template <typename T>
class SpeedStrategy
{
public:
    ~SpeedStrategy() {};
    virtual void Speed(T &_T) = 0;
};
// SportsSpeed.hpp
class SportsSpeed : public SpeedStrategy<Sports>
{
public:
    ~SportsSpeed() {};
    void Speed(Sports &_Sports) override { std::cout << _Sports.GetAcceleration() << std::endl; };
};
// BusSpeed.hpp
class BusSpeed : public SpeedStrategy<Bus>
{
public:
    ~BusSpeed() {};
    virtual void Speed(Bus &_Bus) { std::cout << _Bus.GetAcceleration() << std::endl; };
};
// object structure
//  car.hpp
class Car
{
public:
    ~Car() {};
    virtual void Speed() = 0;
};
// Sports.hpp
class Sports : public Car
{
public:
    Sports(int _Acceleration, std::unique_ptr<SportsSpeed> _SportsSpeed) : Acceleration(_Acceleration), _Speed(std::move(_SportsSpeed)) {};
    ~Sports() {};
    void Speed() { _Speed->Speed(*this); };
    int GetAcceleration() { return this->Acceleration; };

private:
    int Acceleration;
    std::unique_ptr<SportsSpeed> _Speed;
};
// Bus.hpp
class Bus : public Car
{
public:
    Bus(int _Acceleration, std::unique_ptr<BusSpeed> _BusSpeed) : Acceleration(_Acceleration), _Speed(std::move(_BusSpeed)) {};
    ~Bus() {};
    void Speed() { _Speed->Speed(*this); };
    int GetAcceleration() { return this->Acceleration; };

private:
    int Acceleration;
    std::unique_ptr<BusSpeed> _Speed;
};
int main()
{
    using Cars = std::vector<std::unique_ptr<Car>>;
    Cars _Cars{};

    _Cars.emplace_back(std::make_unique<Sports>(5, std::make_unique<SportsSpeed>()));
    _Cars[0]->Speed();
    _Cars.emplace_back(std::make_unique<Bus>(5, std::make_unique<BusSpeed>()));
    _Cars[1]->Speed();
    
    return 0;
}