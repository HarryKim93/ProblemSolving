#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

once_flag gOnceFlag;

void initializeSharedResources() {

    cout << " " << "Shared resources initialized." << "\n";
}

void processingFunction() {
    call_once(gOnceFlag, initializeSharedResources);
    cout << "Processing" << "\n";
}

int main() {
    vector<thread> threads(3);
    for (auto& t : threads) {
        t = thread { processingFunction };
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}