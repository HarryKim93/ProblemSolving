#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <new>

using namespace std;

#ifdef __cpp_lib_hardware_interference_size
    using std::hardware_constructive_interference_size;
    using std::hardware_destructive_interference_size;
#else
    // Lucky guess │ __cacheline_aligned │ L1_CACHE_BYTES │ L1_CACHE_SHIFT │ ...
    // constexpr std::size_t hardware_constructive_interference_size
    //     = 2 * sizeof(std::max_align_t);
    // constexpr std::size_t hardware_destructive_interference_size
    //     = 2 * sizeof(std::max_align_t);
#endif

alignas(hardware_destructive_interference_size) long long num1 = 0;
alignas(hardware_destructive_interference_size) long long num2 = 0;
long long num3 = 0;

void fun1() {
    for (long long i = 0; i < 1000000000; i++)
        num1 += 1;
}

void fun2() {
    for (long long i = 0; i < 1000000000; i++)
        num2 += 1;
}

void fun3() {
    for (long long i = 0; i < 2000000000; i++) {
        num3 += 1;
    }
}
int main() {
    cout << hardware_destructive_interference_size << "\n";
    auto beginTime = std::chrono::high_resolution_clock::now();

    std::thread t1(fun1);   //Multi Thread 실행
    std::thread t2(fun2);   //Multi Thread 실행

    t1.join(); t2.join();

    auto endTime = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> resultTime = endTime - beginTime;

    printf("%lld\n", num1 + num2);
    std::cout << resultTime.count() << std::endl;
    printf("--------------------\n");
    beginTime = std::chrono::high_resolution_clock::now();

    fun3(); //Single Thread 실행
    
    endTime = std::chrono::high_resolution_clock::now();
    resultTime = endTime - beginTime;
    printf("%lld\n", num3);
    std::cout << resultTime.count() << std::endl;
}