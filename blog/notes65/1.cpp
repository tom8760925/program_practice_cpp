#include <iostream>
#include <memory>
// 物件
//  Sports.hpp
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
// Bus.hpp
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
// 實作
//  Detail.hpp
namespace Detail
{
    class CarConcept
    {
    public:
        virtual void GetSpeed() const = 0;
        virtual std::unique_ptr<CarConcept> Close() const = 0;
    };
    template <typename CarT, typename SpeedStrategyT>
    class CarModel : public CarConcept
    {
    public:
        CarModel(CarT _CarT, SpeedStrategyT _SpeedStrategyT) : _CarT(_CarT), _SpeedStrategyT(_SpeedStrategyT) {};
        void GetSpeed() const override
        {
            _SpeedStrategyT(_CarT);
        }
        std::unique_ptr<CarConcept> Close() const override
        {
            return std::make_unique<CarModel>(*this);
        }

    private:
        CarT _CarT;
        SpeedStrategyT _SpeedStrategyT;
    };
}
// 呼叫
//  Car.hpp
class Car
{
public:
    template <typename CarT, typename SpeedStrategyT>
    Car(CarT _CarT, SpeedStrategyT _SpeedStrategyT)
    {
        pimpl = std::make_unique<Detail::CarModel<CarT, SpeedStrategyT>>(std::move(_CarT), std::move(_SpeedStrategyT));
    }
    Car(Car &_Car) : pimpl(_Car.pimpl->Close()) {};

    Car &operator=(Car &_Car)
    {
        Car copy(_Car);
        pimpl.swap(copy.pimpl);
        return *this;
    }

private:
    friend void GetSpeed(Car &_Car)
    {
        _Car.pimpl->GetSpeed();
    }

private:
    std::unique_ptr<Detail::CarConcept> pimpl;
};

int main()
{
    Sports _Sports(5);
    auto speed = [](Sports s)
    { s.GetSpeed(); };
    Car _Car(_Sports, speed);
    GetSpeed(_Car);
    return 0;
}