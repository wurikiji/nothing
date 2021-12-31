
// Problem for all:
// 1. static single instance dependencies
// 2. how to handle when destructor is called
struct Database {
  // Problem 1: hard to imply this is singleton object
  // Problem 2: can not predict the initialization order of global instances
  static Database database{};

 private:
  // Do not use more than one instance
  Database() {}
};

struct DatabaseWithMethod {
  // Solution 1
  // Problem: static variable can be destoryed.
  static Database& get_database() {
    // Problem 1: not thread-safe
    // (From c++11, this is thread-safe)
    static Database database;
    return database;
  }

  // Solution 2
  // database is allocated in Heap, so it will remain forever until program
  // exits.
  static Database& get_database() {
    // Problem 1: not thread-safe
    // (From c++11, this is thread-safe)
    static Database* database = new Database();
    return *database;
  }

  // should explicitly remove clone, copy, assign constructor/operator
  // This can be simplified with `boost::noncopyable`
  Database(Database const&) = delete;
  Database(Database&&) = delete;
  Database& operator=(Database const&) = delete;
  Database& operator=(Database&&) = delete;

 private:
  Database() {}
};