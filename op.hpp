#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

class Op : public Base {
public:
   Op(double value) : Base() {
      this->value = value;
   }
   ~Op() {}
   virtual double evaluate() {
      return value;
   }
   virtual std::string stringify() {
      std::ostringstream oss;
      oss << std::setprecision(8) << std::noshowpoint << value;
      std::string oss_value = oss.str();
      return oss_value;
   }
   virtual int number_of_children() { return 0; }
   virtual Base* get_child(int i) { return nullptr; }
   virtual void accept(Visitor* visitor, int index) {
      visitor->visit_op(this);
   }
private:
   double value;
};

#endif //__OP_HPP__
