#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>

class Add : public Base {
public:
   Add(Base* op_1, Base* op_2) : Base() {
      this->op_1 = op_1;
      this->op_2 = op_2;
   }
   ~Add() {
      delete op_1;
      delete op_2;
   }
   virtual double evaluate() {
      return (op_1->evaluate() + op_2->evaluate());
   }
   virtual std::string stringify() {
      std::ostringstream oss;
      oss << op_1->stringify() << " + " << op_2->stringify();
      std::string oss_value = oss.str();
      return oss_value;
   }
   virtual int number_of_children() { return 2; }
   virtual Base* get_child(int i) {
      if (i == 0) {
         return op_1;
      }
      else {
         return op_2;
      }
   }
   virtual void accept(Visitor* visitor, int index) {
      if (index == 0) { visitor->visit_add_begin(this); }
      else if (index == 1) { visitor->visit_add_middle(this); }
      else { visitor->visit_add_end(this); }
   }

private:
   Base* op_1;
   Base* op_2;
};
#endif //__ADD_HPP__
