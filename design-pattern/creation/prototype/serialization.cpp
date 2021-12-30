// **PROBLEM**
// We have to create copy constructor for every single object.

#ifndef BETTER_COPY_CONSTRUCTOR_HPP
#define BETTER_COPY_CONSTRUCTOR_HPP

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/access.hpp>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

struct Address {
  string street, city;
  int suite;
  Address() = default;
  Address(const Address &other) {
    street = other.street;
    city = other.city;
    suite = other.suite;
  }
  Address(const string &street, const string &city, const int suite)
      : street{street}, city{city}, suite{suite} {}

 private:
  friend class boost::serialization::access;
  template <class Ar>
  void serialize(Ar &ar, const unsigned int version) {
    ar &street;
    ar &city;
    ar &suite;
  }
};

struct Contact {
  string name;
  Address *address;
  Contact() = default;

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

 private:
  friend class boost::serialization::access;
  template <class Ar>
  void serialize(Ar &ar, const unsigned int version) {
    ar &name;
    ar &address;
  }
};

int main() {
  auto clone = [](const Contact &c) {
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << c;
    string s = oss.str();

    istringstream iss(oss.str());
    boost::archive::text_iarchive ia(iss);
    Contact result;
    ia >> result;
    return result;
  };

  Contact john{"John", new Address{"asdf", "ji city", 0}};
  Contact jane = clone(john);
  jane.name = "Jane";
  cout << "we have two people " << jane.name << " and " << john.name << endl;
  return 0;
}
#endif