#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Counter {
public:
    Counter(int id, int numIterations) : mId(id), mNumIterations(numIterations) {}

    void operator()() const{
        
        for (int i = 0; i < mNumIterations; ++i) {
            lock_guard<mutex> lock(sMutex);
            cout << "Counter " << mId << " has value " << i << endl; 
        }
    }

private:
    int mId;
    int mNumIterations;
    static mutex sMutex;
};

mutex Counter::sMutex;

int main() {
    thread t1{Counter{1, 20}};
    
    Counter c(2, 12);
    thread t2(c);

    thread t3(Counter(3, 10));

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}