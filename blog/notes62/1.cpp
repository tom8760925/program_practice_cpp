#include <memory>
#include <iostream>
// Car.hpp
class Car
{
public:
    virtual void GetSpeed() = 0;
    virtual std::unique_ptr<Car> Close() = 0;
};
// Sports.hpp
class Sports : public Car
{
public:
    Sports(int Speed) : Speed(Speed) {};
    void GetSpeed()
    {
        std::cout << this->Speed << std::endl;
    }
    std::unique_ptr<Car> Close()
    {
        return std::make_unique<Sports>(*this);
    }

private:
    int Speed;
};

int main()
{
    std::unique_ptr<Car> _Sports = std::make_unique<Sports>(5);
    std::unique_ptr<Car> _Sports2 = _Sports->Close();

    _Sports->GetSpeed();
    _Sports2->GetSpeed();
    return 0;
}