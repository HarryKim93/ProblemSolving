#include <iostream>
#include <string>
#include <thread>
#include <mutex>
 
thread_local unsigned int LRage = 1;
std::mutex coutMutex;
 
void IncreaseRage(const std::string& threadName)
{
    ++LRage;
 
    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << "Rage counter for " << threadName << ": " << LRage << '\n';
}
 
int main()
{
    // 유저쓰레드 2개 생성
    std::thread first(IncreaseRage, "first");
    std::thread second(IncreaseRage, "second");
 
    // 메인쓰레드 출력
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Rage counter for main: " << LRage << '\n';
    }
 
    // 유저쓰레드 종료 대기
    first.join();
    second.join();
 
    return 0;
}