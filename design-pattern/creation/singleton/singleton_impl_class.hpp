#include <map>
#include <string>
#include <vector>

using namespace std;
class Database {
 public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database {
  SingletonDatabase() {
    /*
            read data from database
    */
  }
  std::map<std::string, int> capitals;

 public:
  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;
  static SingletonDatabase& get() {
    static SingletonDatabase db;
    return db;
  }
  int get_population(const std::string& name) override {
    return capitals[name];
  }
};

// Problematic class
struct SingletonRecordFinder {
  int total_population(std::vector<std::string> names) {
    int result = 0;
    // Depends on global singleton object.
    // Problem 1: not flexible for testing with dummy database
    for (auto& name : names)
      result += SingletonDatabase::get().get_population(name);
    return result;
  }
};

// Solves dependency problem
struct ConfigurableRecordFinder {
  Database& db;
  // Flexible dependency
  explicit ConfigurableRecordFinder(Database& db) : db{db} {}
  int total_population(std::vector<std::string> names) {
    int result = 0;
    for (auto& name : names) result += db.get_population(name);
    return result;
  }
};