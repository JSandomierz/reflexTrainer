#include <chrono>
#include <ratio>
#ifndef TIMER_H
#define TIMER_H

class Timer
{
    public:
        Timer();
        void start();
        void stop();
        int getSeconds();
        double getMilliseconds();
    private:
        std::chrono::steady_clock::time_point timeA,timeB;
};

#endif // TIMER_H
