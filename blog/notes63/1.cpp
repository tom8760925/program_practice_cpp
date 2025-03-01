#include <iostream>
//Sports.hpp
class Sports
{
public:
    Sports(int Speed) : Speed(Speed) {};
    void GetSpeed()
    {
        std::cout << this->Speed << std::endl;
    }

private:
    int Speed;
};
//Bus.hpp
class Bus
{
public:
    Bus(int Speed) : Speed(Speed) {};
    void GetSpeed()
    {
        std::cout << this->Speed << std::endl;
    }

private:
    int Speed;
};
//CarConcept.hpp
class CarConcept
{
public:
    virtual void GetSpeed() = 0;
};
//CarModel.hpp
template <typename CarT, typename SpeedStrategyT>
class CarModel : public CarConcept
{
public:
    CarModel(CarT _CarT, SpeedStrategyT _SpeedStrategyT) : _CarT(_CarT), _SpeedStrategyT(_SpeedStrategyT) {};
    void GetSpeed() override
    {
        _SpeedStrategyT(_CarT);
    }

private:
    CarT _CarT;
    SpeedStrategyT _SpeedStrategyT;
};
//CarSpeedStrategy.hpp
class CarSpeedStrategy
{
public:
    void operator()(Sports &_Sports) { _Sports.GetSpeed(); };
    void operator()(Bus &_Bus) { _Bus.GetSpeed(); };
};
int main()
{
    CarConcept *SportsConcept = new CarModel<Sports, CarSpeedStrategy>(Sports(5), CarSpeedStrategy());
    CarConcept *BusConcept = new CarModel<Bus, CarSpeedStrategy>(Bus(1), CarSpeedStrategy());

    SportsConcept->GetSpeed();
    BusConcept->GetSpeed();
    return 0;
}