#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <iostream>
#include <sstream>

class Div : public Base {
public:
   Div(Base* op1, Base* op2) : Base() {
      this->op1 = op1;
      this->op2 = op2;
   }
   ~Div() {
      delete op1;
      delete op2;
   }
   virtual double evaluate() {
      return op1->evaluate() / op2->evaluate();
   }
   virtual std::string stringify() {
      std::ostringstream oss;
      oss << op1->stringify() << " / " << op2->stringify();
      std::string oss_value = oss.str();
      return oss_value;
   }
   int number_of_children() {
      return 2;
   }
   Base* get_child(int i) {
      if (i == 0) {
         return op1;
      }
      else {
         return op2;
      }
   }

private:
   Base* op1;
   Base* op2;

};

#endif // __DIV_HPP__
