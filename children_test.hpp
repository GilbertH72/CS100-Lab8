#ifndef CHILDREN_TEST_HPP
#define CHILDREN_TEST_HPP

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"

TEST(ChildrenTest, AddChild) {
   Op* op1 = new Op(6);
   Op* op2 = new Op(7);
   Add* test = new Add(op1, op2);
   EXPECT_EQ(test->number_of_children(), 2);
   EXPECT_EQ(test->get_child(0), op1);
   EXPECT_EQ(test->get_child(1), op2);
   delete test;
}

TEST(ChildrenTest, MultChild) {
   Op* op1 = new Op(6);
   Op* op2 = new Op(7);
   Mult* test = new Mult(op1, op2);
   EXPECT_EQ(test->number_of_children(), 2);
   EXPECT_EQ(test->get_child(0), op1);
   EXPECT_EQ(test->get_child(1), op2);
   delete test;
}

TEST(ChildrenTest, DivChild) {
   Op* op1 = new Op(6);
   Op* op2 = new Op(7);
   Div* test = new Div(op1, op2);
   EXPECT_EQ(test->number_of_children(), 2);
   EXPECT_EQ(test->get_child(0), op1);
   EXPECT_EQ(test->get_child(1), op2);
   delete test;
}

TEST(ChildrenTest, SubChild) {
   Op* op1 = new Op(6);
   Op* op2 = new Op(7);
   Sub* test = new Sub(op1, op2);
   EXPECT_EQ(test->number_of_children(), 2);
   EXPECT_EQ(test->get_child(0), op1);
   EXPECT_EQ(test->get_child(1), op2);
   delete test;
}

TEST(ChildrenTest, PowChild) {
   Op* op1 = new Op(6);
   Op* op2 = new Op(7);
   Pow* test = new Pow(op1, op2);
   EXPECT_EQ(test->number_of_children(), 2);
   EXPECT_EQ(test->get_child(0), op1);
   EXPECT_EQ(test->get_child(1), op2);
   delete test;
}


#endif
