#ifndef LATEX_TEST_HPP
#define LATEX_TEST_HPP

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "iterator.hpp"
#include "iterator.cpp"
#include "visitorlatex.hpp"

using namespace std;

TEST(VisitorLatexTest, test1)
{
   Base* two = new Op(2);
   Base* six = new Op(6);
   Base* zero = new Op(0);
   Sub* sub = new Sub(six, zero);
   Add* add = new Add(two, sub);

   Iterator* it = new Iterator(add);
   VisitorLaTeX v;

   while (!it->is_done())
   {
      if (it->current_node() != NULL)
      {
         it->current_node()->accept(&v, it->current_index());
         it->next();
      }
   }

   EXPECT_EQ(v.PrintLaTeX(add), "${({2}+{({6}-{0})})}$");
   delete add;
   delete it;
}

TEST(VisitorLatexTest, test2)
{
   Base* seven = new Op(7);
   Base* three = new Op(3);
   Pow* pow = new Pow(seven, three);

   Iterator* it = new Iterator(pow);
   VisitorLaTeX v;

   while (!it->is_done())
   {
      if (it->current_node() != NULL)
      {
         it->current_node()->accept(&v, it->current_index());
         it->next();
      }
   }

   EXPECT_EQ(v.PrintLaTeX(pow), "${({7}^{3})}$");
   delete pow;
   delete it;
}

TEST(VisitorLatexTest, test3)
{
   Base* eight = new Op(8);
   Base* four = new Op(4);
   Mult* mult = new Mult(four, eight);

   Iterator* it = new Iterator(mult);
   VisitorLaTeX v;

   while (!it->is_done())
   {
      if (it->current_node() != NULL)
      {
         it->current_node()->accept(&v, it->current_index());
         it->next();
      }
   }

   EXPECT_EQ(v.PrintLaTeX(mult), "${({4}\\cdot{8})}$");
   delete mult;
   delete it;
}

TEST(VisitorLatexTest, test4)
{
   Base* nine = new Op(9);
   Base* three = new Op(3);
   Div* div = new Div(nine, three);

   Iterator* it = new Iterator(div);
   VisitorLaTeX v;

   while (!it->is_done())
   {
      if (it->current_node() != NULL)
      {
         it->current_node()->accept(&v, it->current_index());
         it->next();
      }
   }

   EXPECT_EQ(v.PrintLaTeX(div), "${\\frac{9}{3}}$");
   delete div;
   delete it;
}

#endif // LATEX_TEST_HPP
