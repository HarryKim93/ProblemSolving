#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
// namespace A 구역을 선언

std::tuple<int, bool, std::string> charToInt(char c);

namespace A
{
    class Test {
    public:
        void function() {
            /* code */
        }
    };
}

// Goo is a namespace inside the Foo namespace (C++17 style)
namespace Foo::Goo { 
    const int g_x = 5; 
}

// void* operator new(std::size_t count) {
//   std::cout << count << " bytes 할당 " << std::endl;
//   return malloc(count);
// }

// // 문자열에 "very" 라는 단어가 있으면 true 를 리턴함
// bool contains_very(const std::string& str) {
//   return str.find("very") != std::string::npos;
// }

// int main() {
//   // 암묵적으로 std::string 객체가 불필요하게 생성된다.
//   std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
//             << std::endl;

//   std::cout << contains_very("c++ string is not easy to use") << std::endl;
// }

// #include <iostream>
// #include <string>

// void* operator new(std::size_t count) {
//   std::cout << count << " bytes 할당 " << std::endl;
//   return malloc(count);
// }

// int main() {
//   std::cout << "string -----" << std::endl;
//   std::string s = "sometimes string is very slow";
//   std::cout << "--------------------" << std::endl;
//   std::cout << s.substr(0, 20) << std::endl << std::endl;

//   std::cout << "string_view -----" << std::endl;
//   std::string_view sv = s;
//   std::cout << "--------------------" << std::endl;
//   std::cout << sv.substr(0, 20) << std::endl;
// }

int main () {

    // map<string, int> m;
    // m.insert();

    string a = "abc";
    string b = "def";
    a.append(b);
    cout << a << "\n";

    // if (auto [num, success, err] = charToInt('?'); success) {
    //      cout << num << endl; 
    // } else { 
    //     cout << "Error: " << err << endl; 
    // }

    return 0;
}