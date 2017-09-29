#include "Timer.h"

Timer::Timer()
{
}
void Timer::start()
{
    timeA=std::chrono::steady_clock::now();
    timeB=timeA;
}
void Timer::stop()
{
    timeB=std::chrono::steady_clock::now();
}
int Timer::getSeconds()
{
    std::chrono::seconds seconds=std::chrono::duration_cast<std::chrono::seconds>(timeB-timeA);
    return seconds.count();
}
double Timer::getMilliseconds()
{
    std::chrono::milliseconds seconds=std::chrono::duration_cast<std::chrono::milliseconds>(timeB-timeA);
    return seconds.count();
}
