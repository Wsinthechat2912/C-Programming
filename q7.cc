#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>
using namespace std; // File: q7.cc

class m2dvector {
    vector<int> vi = {0, 0};

public:
    m2dvector(vector<int> some_vi) : vi(some_vi) {
        if (some_vi.size() > 2)
            throw std::invalid_argument("Input vector should have size 2.");
    }

    const vector<int> &get_data() const { 
        return vi; 
    }

    // This will overload operator for the output (<<)
    friend ostream &operator<<(ostream &os, const m2dvector &v) {
        const auto &data = v.get_data();
        os << "<" << data[0] << " " << data[1] << ">";
        return os;
    }

    // And now this will overload operator for the input (>>)
    friend istream &operator>>(istream &is, m2dvector &v) {
        char ch1, ch2;
        int x, y;
        is >> ch1 >> x >> y >> ch2;
        if (ch1 != '<' || ch2 != '>') {
            is.setstate(ios::failbit); // This is an invalid format
            return is;
        }
        v = m2dvector({x, y}); // To assign new data to the variable v
        return is;
    }
};

int main() {
    try {
        vector<int> vi = {11, 12, 13, 14, 15};
        m2dvector z1({vi[0], vi[1]});
        m2dvector z2({vi[3], vi[4]});
        cout << z1 << endl; /* should print: <11 12> */
        cout << z2 << endl; /* should print: <14 15> */
        string s1 = "<11 12>    <13 14>a"; /* s1 is a *single* test – code 
                                              must work in general */
        istringstream iss(s1);
        iss >> z2 >> z1;
        cout << z1 << endl; /* should print: <13 14> */
        cout << z2 << endl; /* should print: <11 12> */
        char c;
        iss >> c;
        cout << c << endl; /* should print ‘a’ – the char after the 2nd m2dvector above. */
        ostringstream oss;
        oss << z2;
        string so = oss.str();
        for (char c : so)
            if (c == '\n') {
                cout << "Output contains a newline\n";
                return 0;
            }
        cout << "Output does not contain a newline\n";
    } catch (...) {
        throw;
    }
    return 0;
}
