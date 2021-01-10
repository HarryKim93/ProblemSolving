#include <iostream>
#include <thread>

using namespace std;

void doSomeWork() {
    for (int i = 0; i < 5; i++) {
        cout << i << "\n";
    }

    cout << "Thread throwing a runtime_error exception..." << "\n";
    throw runtime_error("Exception from thread");
}

void threadFunc(exception_ptr& err) {
    try {
        doSomeWork();
    } catch(...) {
        cout << "Thread caught exception, returning exception..." << "\n";
        err = current_exception();
    }
}

void doWorkInThread() {
    exception_ptr error;
    thread t {threadFunc, ref(error)};
    t.join();
    
    if (error) {
        cout << "Main thread received exception, rethrowing it..." << "\n";
        rethrow_exception(error);
    } else {
        cout << "Main thread did not receive any exception" << "\n";
    }
}

int main() {
    try {
        doWorkInThread();
    } catch(const exception& e) {
        cout << "Main function caught: '" << e.what() << "'" << "\n";
    }
}
