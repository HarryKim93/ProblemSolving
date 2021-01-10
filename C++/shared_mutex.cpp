#include <iostream> 
#include <type_traits> 
#include <thread> 
#include <mutex> 
#include <shared_mutex> // 원자적인 카운터

using namespace std;

class AtomicCounter {
private:
    int m_counter = 0;
    mutable shared_mutex m_mutex;

public:
    int getCount() const
    {
        shared_lock lk{m_mutex};
        return m_counter;
    }
    void increase()
    {
        lock_guard lk{m_mutex};
        ++m_counter;
    }
};

AtomicCounter counter; // 표준 출력 동기화용 뮤텍스. (집중할 부분 아님)
mutex coutMutex;  // counter의 값을 증가시키는 작업 함수.

void incJob() { 
    counter.increase(); 
}

// counter의 값을 출력하는 작업 함수.

void printJob(){
    lock_guard lk{coutMutex};
    cout << counter.getCount() << endl;
} 


// 쪼인 올!
template <typename... TArgs>
void joinAll(TArgs &&... args)
{
    static_assert((is_base_of_v<thread, decay_t<TArgs>> && ...), "스레드만 받아요...");
    (args.join(), ...);
}

int main()
{
    thread t1{printJob};
    thread t2{incJob};
    thread t3{printJob};
    thread t4{incJob};
    thread t5{printJob};
    thread t6{incJob};
    
    joinAll(t1, t2, t3, t4, t5, t6);
    return 0;
}