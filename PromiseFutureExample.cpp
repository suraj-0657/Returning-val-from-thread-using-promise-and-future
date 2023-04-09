#include <iostream>
#include <thread>
#include <future>

using ull = unsigned long long;

void findOddSum(std::promise<ull>&& oddSumPromise, ull start, ull end)
{
    ull oddSum{0};
    for(ull i{0}; i <= end; i++)
    {
        if(i%2 != 0)
            oddSum += i;
    }
    oddSumPromise.set_value(oddSum);
}

int main()
{
    ull start{0}, end{1900000000};
    std::promise<ull> oddSumPromise;
    std::future<ull> oddSumFuture = oddSumPromise.get_future();
    std::cout << "Thread Created!!" << "\n";
    std::jthread t(findOddSum, std::move(oddSumPromise), start, end);
    std::cout << "Waiting for result!!" << "\n";
    std::cout << "OddSum: " << oddSumFuture.get() << "\n";
    std::cout << "Completed!!" << "\n";
    return 0;
}
