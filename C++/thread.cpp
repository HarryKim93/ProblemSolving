#include <thread>
#include <iostream>

using namespace std;

void counter(int id, int numIterations) {
    for (int i = 0; i < numIterations; i++) {
        cout << "Counter " << id << "has value " << i << "\n";
    }
}

class Counter {
public:
    Counter(int id, int numIterations) : mId(id), mNumIterations(numIterations) {}
    void operator()() const {
        for (int i = 0; i < mNumIterations; i++) {
            cout << "Counter " << mId << " has value " << i << "\n";
        }
    }
private:
    int mId;
    int mNumIterations;
};

int main() {
    // thread t1{Counter{1, 6}};
    // t1.join();

    return 0;
}