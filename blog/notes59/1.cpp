#include <memory>
#include <set>
#include <iostream>
// 觀察者
template <typename CarShop>
class Observer
{
public:
    virtual void updata(CarShop &_CarShop) = 0;
};
// 被觀察者
class Shop
{
public:
    using ShopObserver = Observer<Shop>;
    void BuyObserver(ShopObserver *_Observer)
    {
        CarShopObserver.insert(_Observer);
    }
    void SellObserver(ShopObserver *_Observer)
    {
        CarShopObserver.erase(_Observer);
    }
    void NotifyObserver()
    {
        for (auto i = CarShopObserver.begin(); i != CarShopObserver.end();)
        {
            auto const p = i++;
            (*p)->updata(*this);
        }
    }
    // 更新
    void UpLogdShop()
    {
        NotifyObserver();
    }

private:
    std::set<ShopObserver *> CarShopObserver;
};
// 觀察者實作
class Client : public Observer<Shop>
{
public:
    Client(std::string Name) : Name(Name) {};
    void updata(Shop &_Shop)
    {
        std::cout << Name << std::endl;
    }

private:
    std::string Name;
};
int main()
{
    Shop _Shop;
    Client *tom = new Client("Tom");
    Client *ku = new Client("Ku");

    _Shop.BuyObserver(tom);
    _Shop.BuyObserver(ku);
    _Shop.UpLogdShop();

    _Shop.SellObserver(ku);
    _Shop.UpLogdShop();

    return 0;
}