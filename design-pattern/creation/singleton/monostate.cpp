class Printer {
  // Problem 1: users can not know this is static
  static int id;

 public:
  int get_id() const { return id; }
  void set_id(int value) const { id = value; }
};