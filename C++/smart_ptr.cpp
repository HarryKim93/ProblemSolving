#include <memory>

using namespace std;

void leaky() {
    
}

#include <iostream>
using namespace std;
class classA
{
public:
  classA();
  virtual ~classA();
};
class classB : public classA
{
public:
  classB();
  ~classB();
};
classA::classA() {
  cout << "A" << endl;
}
classA::~classA() {
  cout << "~A" << endl;
}
classB::classB() {
  cout << "B"<< endl;
}
classB::~classB() {
  cout << "~B" << endl;
}
int main() {
  cout << "START" << endl;
  classB *B = new classB;
  classA *A = B;
  delete A;
  return 0;
}

int main() {
    

    return 0;
}