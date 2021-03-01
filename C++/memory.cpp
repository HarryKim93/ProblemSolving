#include <iostream>
#include <memory>
#include <functional>
#include <vector>

using namespace std;

template<size_t N>
void doubleIntStack(int (&theArray)[N]) {
    for (size_t i = 0; i < N; i++) {
        theArray[i] *= 2;
        cout << theArray[i] << " ";
    }
}

void f2() {
    throw runtime_error("Hello World!");
}

void CloseFile(FILE* filePtr) {
    if (filePtr == nullptr)
        return ;
    fclose(filePtr);
    cout << "File closed." << "\n";
}

class Simple {
public:
    Simple() {
        cout << "instructor" << "\n";
        mIntPtr = unique_ptr<int>(new int(0));
    }

    Simple(int i) {
        cout << "Got " << i << "\n";
        mIntPtr = unique_ptr<int>(new int(i));
        setValue(i);
    }
    
    ~Simple() {
        cout << "destructor "<< "\n";
        cout << "Got = " << *mIntPtr << "\n";
    }

    void setValue(int value) {
        *mIntPtr = value;
    }

private:
    unique_ptr<int> mIntPtr;
};

void doSomething(unique_ptr<Simple>& outSimplePtr) {
    // cout << "2\n";
    outSimplePtr = make_unique<Simple>(2);
    // cout << "3\n";
}

void f1() {
    //unique_ptr<Simple> mySimplePtr(new Simple());
    auto mySimplePtr = make_unique<Simple>();
    //f2();
    cout << "Goodbye!";
}

void f0(unique_ptr<Simple> mySimplePtr1) {
    cout << "Hello World!\n";
}

// void ProcessData(Simple* simple) {
//     cout << "Processing Data\n";
//     simple->change(5);
// }

void doubleDelete() {
    Simple* mySimple = new Simple();
    shared_ptr<Simple> smartPtr1(mySimple);
    shared_ptr<Simple> smartPtr2(mySimple);
}

void noDoubleDelete() {
    auto smartPtr1 = make_shared<Simple>();
    auto smartPtr = shared_ptr<Simple>(smartPtr1);
    // or shared_ptr<Simple> smartPtr(smartPtr1);
}

void useResource(weak_ptr<Simple>& weakSimple) {
    auto resource = weakSimple.lock();
    if (resource) {
        cout << "Resource stil alive." << "\n";
    } else {
        cout << "Resource has been freed!" << "\n";
    }
}

class A {
private:
    string s;
    weak_ptr<A> other;
public:
    A(const string& s) : s(s) {
        cout << "ÀÚ¿øÀ» È¹µæÇÔ!" << "\n";
    }
    
    ~A() {
        cout << "¼Ò¸êÀÚ È£Ãâ!\n";
    }

    void set_other(weak_ptr<A> o) {
        other = o;
    }

    void access_other() {
        shared_ptr<A> o = other.lock();
        if (o) {
            cout << "Á¢±Ù : " << o->name() << "\n";
        } else {
            cout << "ÀÌ¹Ì ¼Ò¸ê" << "\n";
        }
    }

    string name() {
        return s;
    }
};

unique_ptr<Simple> create() {
    auto ptr = make_unique<Simple>();
    return ptr;
}

int main() {
    // auto simplePtr = make_unique<Simple>(1);
    // doSomething(simplePtr);
    // cout << "Hello World\n";

    int N;
    cin >> N;
    int a[N];

    for (int i = 0; i < N; i++) a[i] = 1;
    for (int i = 0; i < N; i++) cout << a[i] << "\n";
    return 0;
}

// int main() {
//     unique_ptr<Simple> mySmartPtr1 = create();
//     auto mySmartPtr2 = create();
//     return 0;
// }

// int main() {
    
//     vector<shared_ptr<A>> vec;
//     auto item = make_shared<A>("ÀÚ¿ø 1");
//     vec.push_back(shared_ptr<A>(item));
//     auto item2 = make_shared<A>("ÀÚ¿ø 2");
//     vec.push_back(shared_ptr<A>(item2));

//     shared_ptr<A> w = item;
//     if (w) {
//         cout << "?\n";
//     } else {
//         cout << "!\n";
//     }

//     item2.reset();
//     cout << item.use_count() << " " << item2.use_count() << "\n";

    // vec[0]->set_other(vec[1]);
    // vec[1]->set_other(vec[0]);

    // cout << vec[0].use_count() << "\n";
    // cout << vec[1].use_count() << "\n";

    // vec[0]->access_other();
    // vec.pop_back();
    // vec[0]->access_other();

    // auto sharedSimple = make_shared<Simple>();
    // weak_ptr<Simple> weakSimple(sharedSimple);

    // useResource(weakSimple);
    // sharedSimple.reset();
    // useResource(weakSimple);

//     return 0;
// }

    // auto sPtr = make_shared<Simple>();
    // shared_ptr<Simple> sPtr2(new Simple());

    // FILE* f = fopen("data.txt", "w");
    // unique_ptr<FILE, decltype(CloseFile)*> filePtr(fopen("data.txt", "w"), CloseFile);
    
    // if (filePtr == nullptr) {
    //     cerr << "Error opening file" << "\n";
    // } else {
    //     cout << "File opened" << "\n";
    // }

    // cout << "Hello World!\n";

    // unique_ptr<Simple, function<void(Simple*)>> foo(new Simple, [](Simple* simple)
    //     {
    //         delete simple;
    //     }
    // );

    // auto deleter = [](Simple* simple)
    // {
    //     delete simple;
    // };

    // unique_ptr<Simple, decltype(deleter)> foo2(new Simple, deleter);

    // try {
    //     auto ptr = make_unique<Simple>();
    //     ptr.get()->Print();

    //     ptr->go();
    //     ProcessData(ptr.get());

    //     ptr.get()->Print();
    // } catch (const exception &e ) {
    //     cout << e.what() << "\n";
    // }

//     return 0;
// }

// int main () {
//     int stackArray[] = {1,2,3,4,5,6};
//     doubleIntStack(stackArray);

//     try {
//         f1();
//     } catch (const exception &e ) {
//         cout << e.what() << "\n";
//     }

//     return 0;
// }