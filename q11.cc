#include <iostream>
#include <iomanip>      // std::setw
#include <sstream>      // std::ostringstream
#include <string>
#include <map>
#include <vector>
#include <utility>      // std::pair
#include <algorithm>    // std::sort

using namespace std;

/* Turn a token to a string - tokens cannot contain spaces or other characters that are not valid for a variable name. */
#define X(token) #token

string null = X(NULL);

string department_names[] = {
   X(Sales)
   , X(Engineering)
   , X(Clerical)
   , X(Marketing)
};

string employee_names[] = {
   X(Rafferty)
   , X(Jones)
   , X(Heisenberg)
   , X(Robinson)
   , X(Smith)
   , X(Williams)
};

/* Table department: columns = DepartmentID, DepartmentName */
map<int, string *> department = { {31, department_names+0}
                                 ,{33, department_names+1}
                                 ,{34, department_names+2}
                                 ,{35, department_names+3} };
/* Table employee: columns = LastName, DepartmentID */
map<string *, int> employee = { {employee_names+0, 31}
                               ,{employee_names+1, 33}
                               ,{employee_names+2, 33}
                               ,{employee_names+3, 34}
                               ,{employee_names+4, 34}
                               ,{employee_names+5,  0} };

string get_null_or_X(int x) {
  ostringstream os;  os << setw(15);
  if (0 == x) os << null ;
  else        os << x ;
  return os.str();
}
string get_null_or_X(const string *x) {
  ostringstream os;  os << setw(15);
  if (nullptr == x) os << null ;
  else              os << *x ;
  return os.str();
}
string get_null_or_X(const char *x) {
  ostringstream os;
  os << setw(15) << x ;
  return os.str();
}

void print_dep() {
    cout << get_null_or_X(X(DepartmentID))
         << get_null_or_X(X(DepartmentName)) << endl;

    // the code below will create a vector of department entries
    vector<pair<int, string *>> departments(department.begin(), department.end());

    // Now to sort the vector by DepartmentName
    sort(departments.begin(), departments.end(),
         [](const pair<int, string *> &a, const pair<int, string *> &b) {
             return *(a.second) < *(b.second);
         });

    // This will print the sorted departments
    for (const auto &[dept_id, dept_name] : departments) {
        cout << get_null_or_X(dept_id)
             << get_null_or_X(dept_name) << endl;
    }
}

void print_emp() {
    cout << get_null_or_X(X(LastName))
         << get_null_or_X(X(DepartmentID)) << endl;

    for (const auto& [last_name_ptr, dept_id] : employee) {
        cout << get_null_or_X(last_name_ptr)
             << get_null_or_X(dept_id) << endl;
    }
}

void print_inner_join() {
    cout << get_null_or_X(X(LastName))
         << get_null_or_X(X(DepartmentID))
         << get_null_or_X(X(DepartmentName)) << endl;

    for (const auto& [last_name_ptr, dept_id] : employee) {
        auto it = department.find(dept_id);
        if (it != department.end()) {
            cout << get_null_or_X(last_name_ptr)
                 << get_null_or_X(dept_id)
                 << get_null_or_X(it->second) << endl;
        }
    }
}

int main() {
  print_dep();
  print_emp();
  print_inner_join();
  return 0;
}

