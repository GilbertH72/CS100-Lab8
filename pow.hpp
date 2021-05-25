#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>
#include <cmath>

class Pow : public Base {
public:
   Pow(Base* op_1, Base* op_2) : Base() {
      this->op_1 = op_1;
      this->op_2 = op_2;
   }
   ~Pow() {
      delete op_1;
      delete op_2;
   }
   virtual double evaluate() {
      return pow(op_1->evaluate(), op_2->evaluate());
   }
   virtual std::string stringify() {
      std::ostringstream oss;
      oss << op_1->stringify() << " ** " << op_2->stringify();
      std::string oss_value = oss.str();
      return oss_value;
   }
   virtual int number_of_children() { return 2; }
   virtual Base* get_child(int i) {
      if (int i = 0) {
         return op_1;
      }
      else {
         return op_2;
      }
   }
   virtual void accept(Visitor* visitor, int index) {
      if (index == 0) { visitor->visit_pow_begin(this); }
      else if (index == 1) { visitor->visit_pow_middle(this); }
      else { visitor->visit_pow_end(this); }
   }

private:
   Base* op_1;
   Base* op_2;
};
#endif //__POW_HPP__
