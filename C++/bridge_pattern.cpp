#include <memory>

using namespace std;

class X {
public:
    X() {
        ximple = make_unique<Ximple>();
    }

    void doSomething() {
        ximple->doSomething();
    }

private:
    class Ximple;
    unique_ptr<Ximple> ximple;
};

class X::Ximple {
public:
    Ximple() = default;

    void doSomething() {
        // do something;
    }
};

int main() {
    return 0;
}
