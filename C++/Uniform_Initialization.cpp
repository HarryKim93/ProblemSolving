#include <iostream>
#include <functional>

class A {
private:
    int n;
public:
    A() { 
        std::cout << "A �� ������ ȣ��!" << std::endl;
        n = 3; 
    }

    A(int b) { 
        std::cout << "A �� ������ ȣ��!" << std::endl;
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

//�Լ� ���� (������ �ƴ�)
A b();
A bb(int cc);

int main() {
    A a();  // int get() �� ���� �Լ� ���Ƿ� �����Ϸ��� ����Ѵ�.
//  a.print(); ���� �̿� ���� �Լ��� ȣ���� �ȵȴ�.

    A b(3);
    b.print();

    return 0;
}