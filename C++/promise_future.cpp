#include <iostream>
#include <thread>
#include <future>

using namespace std;

void DoWork(promise<int> thePromise) {
    thePromise.set_value(42);
}

int main() {
    promise<int> myPromise;
    auto theFuture = myPromise.get_future();
    thread theThread{ DoWork, move(myPromise) };

    int result = theFuture.get();
    cout << "Result: " << result << "\n";

    theThread.join();

    return 0;
}