#include <boost/atomic.hpp>
#include <boost/thread.hpp>

// This file is for before c++11
struct Database {
  static Database& get_instance();

 private:
  static boost::atomic<Database*> instance;
  static boost::mutex mtx;
};

// expllicitly use locking
Database& Database::get_instance() {
  Database* db = instance.load(boost::memory_order_consume);
  if (!db) {
    boost::mutex::scoped_lock lock(mtx);
    db = instance.load(boost::memory_order_consume);
    if (!db) {
      db = new Database();
      instance.store(db, boost::memory_order_release);
    }
  }
  return *db;
}