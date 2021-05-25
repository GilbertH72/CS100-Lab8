#include "visitorlatex.hpp"
#include "iterator.hpp"
#include "iterator.cpp"

int main(int argc, char** argv) {

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
   std::cout << "LaTeX Format: " << v.PrintLaTeX(div) << std::endl;

   delete div;
   delete it;
   return 0;
}
