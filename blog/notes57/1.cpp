#include <iostream>
// Command
// CarCommand.hpp
class CarCommand
{
public:
    ~CarCommand() {};
    virtual void execute() = 0;
};
// Receiver
// Start.hpp
class Start
{
public:
    void on() { std::cout << "ON" << std::endl; };
    void off() { std::cout << "OFF" << std::endl; };
};
// ConcreteCommand
// StartOn.hpp
class StartOn : public CarCommand
{
public:
    StartOn(std::unique_ptr<Start> _Start) : _Start(std::move(_Start)) {};
    void execute() override
    {
        _Start->on();
    }

private:
    std::unique_ptr<Start> _Start;
};
class StartOff : public CarCommand
{
public:
    StartOff(std::unique_ptr<Start> _Start) : _Start(std::move(_Start)) {};
    void execute() override
    {
        _Start->off();
    }

private:
    std::unique_ptr<Start> _Start;
};
// Invoker
// Car.hpp
class Car
{
public:
    Car(std::unique_ptr<CarCommand> _CarCommand) : _CarCommand(std::move(_CarCommand)) {};
    void start() { _CarCommand->execute(); };
    void SetCarCommand(std::unique_ptr<CarCommand> _CarCommand)
    {
        this->_CarCommand.release();
        this->_CarCommand = std::move(_CarCommand);
    };

private:
    std::unique_ptr<CarCommand> _CarCommand;
};

int main()
{
    std::unique_ptr<Start> _Start = std::make_unique<Start>();
    std::unique_ptr<CarCommand> _StartOn = std::make_unique<StartOn>(std::move(_Start));
    std::unique_ptr<CarCommand> _StartOff = std::make_unique<StartOff>(std::move(_Start));
    std::unique_ptr<Car> _Car = std::make_unique<Car>(std::move(_StartOn));
    _Car->start();
    _Car->SetCarCommand(std::move(_StartOff));
    _Car->start();
    return 0;
}