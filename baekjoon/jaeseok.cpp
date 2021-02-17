#include <iostream>
#include <string>
//#include <cstdlib>

using namespace std;

int main() {
    string A, B;
    string C, temp;
    int a_len = 0, b_len = 0;
    int _bigger = 0;
    int num_1 = 0, num_2 = 0;

    cin >> A >> B;

    a_len = A.length();
    b_len = B.length();

    // insert 연산은 string을 전부 다시 복사함
    // string a = "bbb" 가 있을 때, a.insert(0, "2") 를 하면
    // a = "2bbb" 가 되는 데, 실제 동작 시에, 2를 먼저 집어넣고, bbb를 다시 넣는다.
    // 따라서 insert 할 때마다 전체 문자열이 복사됨
    if (a_len > b_len) {
        for (int i = 0; i < (a_len - b_len); i++) {
            B.insert(0, "0");
            _bigger = a_len;
        }
    }
    else if (a_len == b_len) {
        _bigger = a_len;
    }
    else {
        for (int i = 0; i < (b_len - a_len); i++) {
            A.insert(0, "0");
            _bigger = b_len;
        }
    }

    for (int i = (_bigger - 1); i >= 0; i--) {
        num_1 = (A[i] - '0') + (B[i] - '0') + num_2;
        if (num_1 >= 10) {
            num_1 = num_1 - 10;
            num_2 = 1;
        }
        else {
            num_2 = 0;
        }
        //temp = NULL;
        temp.push_back(num_1 + '0');
        // temp.length()를 for 문 반복 횟수만큼 호출해야하므로 overhead가 든다.
        // 자료구조인 stack을 사용 (C++ 라이브러리로 제공함)
        // (문자열 + 문자열) 연산도 위와 마찬가지로, 모든 문자열을 복사해서 새로운 문자열을 만듦 
        C = temp[temp.length() - 1] + C;
    }

    if (num_2 == 1) {
        temp.push_back(num_2 + '0');
        // temp.length()를 for 문 반복 횟수만큼 호출해야하므로 overhead가 든다.
        // 자료구조인 stack을 사용 (C++ 라이브러리로 제공함)
        // (문자열 + 문자열) 연산도 위와 마찬가지로, 모든 문자열을 복사해서 새로운 문자열을 만듦 
        C = temp[temp.length() - 1] + C;
    }

    cout << C << endl;

    return 0;
}