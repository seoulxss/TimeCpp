#include <iostream>
#include "Timer/Timer.h"

//Test
int main()
{
    {
        std::vector<std::shared_ptr<int>> data;
        data.reserve(100'000);

        TimerInScope time;
        for (auto i = 0; i < 100'000; ++i)
        {
            data.push_back(std::make_shared<int>(55));
        }
    }

    Timer someTimer;

    someTimer.Start();
    //doing sth...
    someTimer.Stop();
    std::cout << someTimer.GetDurMs() << std::endl;

    return 0;
}

