#include <iostream>
using namespace std;     // File: q3.cc
class person {
    int age;
public:
    person(int a = 10) : age(a) {}
    int get_age() const {
        return age;
    }
};

int main() {
    person p1;
    cout << p1.get_age() << endl; // should print 10

    int* ptr = (int*)&p1;
    *ptr = 25;

    cout << p1.get_age() << endl; // should print 25
    return 0;
}
