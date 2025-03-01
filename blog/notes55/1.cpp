#include <vector>
#include <iostream>
class Sports;
class Bus;
// client
//  CarVisitor.hpp
class CarVisitor
{
public:
    virtual void visit(Sports *_Sports) = 0;
    virtual void visit(Bus *_Bus) = 0;
};
// Speed.hpp
class Speed : public CarVisitor
{
public:
    void visit(Sports *_Sports) override
    {
        speed = _Sports->GetAcceleration;
    }
    void visit(Bus *_Bus) override
    {
        speed = _Bus->GetAcceleration;
    }
    int GetSpeed()
    {
        return this->speed;
    }

private:
    int speed;
};
// object structure
//  car.hpp
class Car
{
public:
    ~Car() {};
    virtual void accept(CarVisitor *_CarVisitor) = 0;
};
// Sports.hpp
class Sports : public Car
{
public:
    Sports(int _Acceleration) : Acceleration(_Acceleration) {};
    ~Sports() {};
    void accept(CarVisitor *_CarVisitor) override
    {
        _CarVisitor->visit(this);
    }
    int GetAcceleration() { return this->Acceleration; };

private:
    int Acceleration;
};
// Bus.hpp
class Bus : public Car
{
public:
    Bus(int _Acceleration) : Acceleration(_Acceleration) {};
    ~Bus() {};
    void accept(CarVisitor *_CarVisitor) override
    {
        _CarVisitor->visit(this);
    }
    int GetAcceleration() { return this->Acceleration; };

private:
    int Acceleration;
};

int main()
{
    // 建立
    std::vector<Car *> Cars = {new Sports(5), new Bus(1)};
    Speed _speed;
    // 設定動作
    Cars[0]->accept(&_speed);
    // 取得速度
    std::cout << _speed.GetSpeed() << std::endl;
    return 0;
}