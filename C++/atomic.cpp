#include <atomic>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

class Foo { private: int mArray[123]; };
class Bar { private: int mInt; };

void increment(atomic<int>& counter) {
    int result = 0;
    for (int i = 0; i < 100; i++) {
        result++;
        this_thread::sleep_for(1ms);
    }
    counter += result;
}

int main() {
    // atomic<Foo> f;
    // cout << is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << "\n";

    // 저장, 불러오기, 증가 작업을 하나의 아토믹 트랜잭션으로 처리한다.
    atomic<int> counter(0);
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(thread{ increment, ref(counter) });
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "Result = " << counter << "\n";

    return 0;
}