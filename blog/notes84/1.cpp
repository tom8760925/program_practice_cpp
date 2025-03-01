class a
{
public:
    virtual int Getn() const = 0;
    virtual void Setn(int n) = 0;
};
class b final : public a
{
public:
    int Getn() const override
    {
        return n;
    }
    void Setn(int n) override
    {
        this->n = n;
    }

private:
    int n = 0;
};
// final加上後不能被繼承（不能用class c :public b{};）
class c : public a
{
public:
    int Getn() const override
    {
        return n;
    }
    // 加上final後繼承的就不能override這個函式
    void Setn(int n) final override
    {
        this->n = n;
    }

private:
    int n = 0;
};
class d final : public a
{
public:
    // 設定default
    d() = default;
    ~d() = default;
    // 設定不能使用
    d(int n) = delete;
    int Getn() const override
    {
        return n;
    }
    void Setn(int n) override
    {
        this->n = n;
    }

private:
    int n = 0;
};

int main()
{
    return 0;
}