#include <iostream>
// Engine.hpp
class Engine
{
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
};
// GasEngine.hpp
class GasEngine : public Engine
{
public:
    void Start() override
    {
        std::cout << "汽油引擎發動" << std::endl;
    }
    void Stop() override
    {
        std::cout << "汽油引擎關閉" << std::endl;
    }
};
// Car.hpp
class Car
{
private:
    Engine *_Engine;

protected:
    Car(Engine *_Engine) : _Engine(_Engine) {};
    Engine *GetEngine()
    {
        return this->_Engine;
    }

public:
    virtual void Use() = 0;
};
// GasCar.hpp
class GasCar : public Car
{
public:
    GasCar(Engine *_Engine) : Car(_Engine) {};
    void Use() override
    {
        GetEngine()->Start();
        GetEngine()->Stop();
    }
};

int main()
{
    Engine *_GasEngine = new GasEngine();
    Car *_GasCar = new GasCar(_GasEngine);

    _GasCar->Use();

    return 0;
}