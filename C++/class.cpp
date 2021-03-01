#include <iostream>
#include <string>
#include <string_view>
#include <iostream>
#include <memory>

using namespace std;

// class MyClass
// {
// public:
//     MyClass(double value, SomeThing foobar) : something(foobar), mValue(value) {}
// private:
//     SomeThing something;
//     double mValue;
// }

class SomeThing {
public:
    SomeThing() : a(1), b(2) {
        cout << "constructor" << "\n";
    };
    
    SomeThing(int _a, int _b) : a(_a), b(_b) {}
    void print() {
        cout << a << " " << b << "\n";
    }

    SomeThing (const SomeThing& some) {
        cout << "Hello World\n";
        return some;
    }

private:
    int a;
    int b;
};

class SpreadsheetCell {
public:
    SpreadsheetCell() = default;

    SpreadsheetCell(double inValue) {
        mValue = inValue;
    }

    void setString(string_view inString) {
        mValue = stringToDouble(inString);
    }

    void setValue(double inValue) {
        mValue = inValue;
    }

    double getValue() const {
        return mValue;
    }

    string getString() const {
        return doubleToString(mValue);
    }

private:
    string doubleToString(double inValue) const {
        return to_string(mValue);
    }

    double stringToDouble(string_view inString) const {
        return strtod(inString.data(), nullptr);
    }

    double mValue;
};

int main() {
    SomeThing s, s2;
    SomeThing s1(3, 4);

    cout << "?\n";

    s2 = s = s1;
    s.print();
    s2.print();

    return 0;
}