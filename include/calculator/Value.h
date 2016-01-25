
#ifndef VALUE_H
#define VALUE_H 1

#include <string>
#include <iosfwd>

// abstract base class
struct Value {
  // better have virtual dtor
  virtual ~Value() {}
  // information functions
  virtual char const* type() const = 0;
  virtual std::string toString() const = 0;
  virtual bool isInt() const = 0;
  // conversion functions
  virtual int toInt() const = 0;
  virtual int toDouble() const = 0;
};

std::ostream& operator<<(std::ostream&, Value const&);

// specialization for int values
struct ValueInt final : public Value {
  ValueInt(int v) : value_(v) { }
  char const* type() const override final { return "int"; }
  std::string toString() const override final { return std::to_string(value_); }
  bool isInt() const override final { return true; }
  int toInt() const override final { return value_; }
  int toDouble() const override final { return static_cast<double>(value_); }
 
  int value_;
};
  
// specialization for double values
struct ValueDouble final : public Value {
  ValueDouble(double v) : value_(v) { }
  char const* type() const override final { return "double"; }
  std::string toString() const override final { return std::to_string(value_); }
  bool isInt() const override final { return false; }
  int toInt() const override final { return static_cast<int>(value_); }
  int toDouble() const override final { return value_; }
  
  double value_;
};

#endif
