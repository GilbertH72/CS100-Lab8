#include "gtest/gtest.h"

#include "children_test.hpp"
#include "latex_Test.hpp"

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
