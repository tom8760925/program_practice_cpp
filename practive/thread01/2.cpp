#include "2.hpp"

a::a()
{
}
a::~a()
{
    delete _thread_run;
}
void a::test(int n)
{
    std::cout << n << std::endl;
}

void a::thread_main()
{
    this->_thread_run = new thread_run(this);
}
void a::thread_stop()
{
    this->_thread_run->thread_stop();
    delete _thread_run;
}

// thread_run
a::thread_run::thread_run(a *_a)
{
    this->_a = _a;
    this->thread_start();
}
a::thread_run::~thread_run()
{
    this->run_bool = false;
    if (_thread->joinable())
    {
        _thread->join();
    }
    delete _thread;
}
void a::thread_run::thread_start()
{
    this->run_bool = true;
    this->_thread = new std::thread(&a::thread_run::thread_loop, this);
}
void a::thread_run::thread_stop()
{
    this->run_bool = false;
}
void a::thread_run::thread_loop()
{
    int n = 0;
    while (this->run_bool)
    {
        this->_a->test(n);
        n++;
        std::this_thread::sleep_for(std::chrono::milliseconds(5 * 1000));
    }
}
