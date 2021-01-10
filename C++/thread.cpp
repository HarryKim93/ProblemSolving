#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void process(int& num) {
    num++;
    cout << num;
}

class Request {
public:
    Request(int id) : mId(id) {}

    void process() {
        cout << "Processing request " << mId << "\n";
    }

private:
    int mId;
};

class Counter {
public:
    Counter(int id, int numIterations) : mId(id), mNumIterations(numIterations) {}

    void operator()() const{
        
        for (int i = 0; i < mNumIterations; ++i) {
            
            cout << "Counter " << mId << " has value " << i << endl; 
        }
    }

private:
    int mId;
    int mNumIterations;
};

// int main() {
//     thread t1{Counter{1, 20}};
    
//     Counter c(2, 12);
//     thread t2(c);

//     thread t3(Counter(3, 10));

//     t1.join();
//     t2.join();
//     t3.join();
//     return 0;
// }

// int main() {
//     int id = 1;
//     int numIterations = 5;
//     thread t1([id, numIterations] {
//         for (int i = 0; i < numIterations; i++) {
//             cout << "Counter " << id << " has value " << i << "\n";
//         }
//     });
//     t1.join();
// }

int main() {
    Request req(100);
    // int k = 3;

    thread_local int num = 3;

    thread t1{process, ref(num)};
    thread t2{process, ref(num)};
    thread t3{process, ref(num)};
    thread t4{process, ref(num)};

//ref를 하게 되면 thread_local의 효과가 사라진다.
    thread t1{process, num};
    thread t2{process, num};
    thread t3{process, num};
    thread t4{process, num};
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}