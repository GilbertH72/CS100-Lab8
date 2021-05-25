#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "iterator.hpp"
#include "visitor.hpp"
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"
#include <string>

class VisitorLaTeX : public Visitor {
protected:
   std::string format = "";

public:
   std::string getstring() { return format; }

   virtual void visit_op(Op* node) {
      format += "{" + node->stringify() + "}";
   }
   virtual void visit_rand(Rand* node) {
      format += "{" + node->stringify() + "}";
   }

   virtual void visit_add_begin(Add* node) { format += "{("; }
   virtual void visit_add_middle(Add* node) { format += "+"; }
   virtual void visit_add_end(Add* node) { format += ")}"; }

   virtual void visit_sub_begin(Sub* node) { format += "{("; }
   virtual void visit_sub_middle(Sub* node) { format += "-"; }
   virtual void visit_sub_end(Sub* node) { format += ")}"; }

   virtual void visit_mult_begin(Mult* node) { format += "{("; }
   virtual void visit_mult_middle(Mult* node) { format += "\\cdot"; }
   virtual void visit_mult_end(Mult* node) { format += ")}"; }

   virtual void visit_div_begin(Div* node) { format += "{\\frac"; }
   virtual void visit_div_middle(Div* node) { format += ""; }
   virtual void visit_div_end(Div* node) { format += "}"; }

   virtual void visit_pow_begin(Pow* node) { format += "{("; }
   virtual void visit_pow_middle(Pow* node) { format += "^"; }
   virtual void visit_pow_end(Pow* node) { format += ")}"; }

   std::string PrintLaTeX(Base* ptr) { return "$" + format + "$"; }

};

#endif // __VISITOR_LATEX_HPP__
