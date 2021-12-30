#include "better_copy_constructor.hpp"
struct EmployeeFactory {
  static inline Contact main{"", new Address{"123 East Dr", "London", 0}};
  static inline Contact aux{"", new Address{"123B East Dr", "London", 0}};

  static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite) {
    return NewEmployee(name, suite, main);
  }

  static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite) {
    return NewEmployee(name, suite, aux);
  }

 private:
  static unique_ptr<Contact> NewEmployee(string name, int suite,
                                         Contact& proto) {
    auto result = make_unique<Contact>(proto);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

int main() {
  auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
  auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);

  john->introduce();
  jane->introduce();
  return 0;
}