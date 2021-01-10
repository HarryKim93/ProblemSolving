#include <iostream>
#include <functional>

class A {
private:
    int n;
public:
    A() { 
        std::cout << "A 의 생성자 호출!" << std::endl;
        n = 3; 
    }

    A(int b) { 
        std::cout << "A 의 생성자 호출!" << std::endl;
        n = b; 
    }

    void print() {
        std::cout << n << "\n";
    }
};

struct B {
    size_t operator()(){
        return 3;
    } 
};

//함수 정의 (생성자 아님)
A b();
A bb(int cc);

int main() {
    A a();  // int get() 과 같은 함수 정의로 컴파일러가 취급한다.
//  a.print(); 따라서 이와 같은 함수가 호출이 안된다.

    A b(3);
    b.print();

    return 0;
}