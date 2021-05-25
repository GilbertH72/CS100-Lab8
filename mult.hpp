#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>

class Mult : public Base
{
public:
   Mult(Base* op_1, Base* op_2) : Base()
   {
      this->op_1 = op_1;
      this->op_2 = op_2;
   }
   ~Mult() {
      delete op_1;
      delete op_2;
   }
   virtual double evaluate()
   {
      return op_1->evaluate() * op_2->evaluate();
   }
   virtual std::string stringify()
   {
      std::ostringstream oss;
      oss << op_1->stringify() << " * " << op_2->stringify();
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
      if (index == 0) { visitor->visit_mult_begin(this); }
      else if (index == 1) { visitor->visit_mult_middle(this); }
      else { visitor->visit_mult_end(this); }
   }

private:
   Base* op_1;
   Base* op_2;
};
#endif //__MULT_HPP__
