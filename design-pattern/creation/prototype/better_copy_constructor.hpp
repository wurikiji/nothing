
// **PROBLEM**
// We have to create copy constructor for every single object.

#ifndef BETTER_COPY_CONSTRUCTOR_HPP
#define BETTER_COPY_CONSTRUCTOR_HPP

#include <cstdio>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Address {
  string street, city;
  int suite;
  Address(const Address &other) {
    street = other.street;
    city = other.city;
    suite = other.suite;
  }
  Address(const string &street, const string &city, const int suite)
      : street{street}, city{city}, suite{suite} {}
};

struct Contact {
  string name;
  Address *address;

  Contact(const string &name, Address *address)
      : name{name}, address{address} {}
  Contact(const Contact &other)
      : name{other.name}, address{new Address{*other.address}} {}
  Contact &operator=(const Contact &other) {
    if (this == &other) return *this;
    name = other.name;
    address = other.address;
    return *this;
  }

  void introduce() {
    cout << "My name is " << name << ", and my room number is "
         << address->suite << endl;
  }
};

#endif