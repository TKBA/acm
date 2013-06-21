#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class A {
private:
    int value;

public:
    A(int n) { value = n;}
    A(A& other) { value = other.value;}
    void Print() {std:: cout << value << endl;}
};

int main(int argc, char* argv[]) {
    A a(10);
    A b = a;
    b.Print();
    return 0;
}

