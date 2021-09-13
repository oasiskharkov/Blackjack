#include <iostream>

#include "table.h"

int main()
{
   try
   {
      std::string name;
      std::cout << "Enter your name: ";
      std::getline(std::cin, name);
      std::unique_ptr<Table> table{Table::getInstance(std::move(name))};
      table->play();
   }
   catch (const std::exception& ex)
   {
      std::cerr << ex.what() << std::endl;
   }
   catch (...)
   {
      std::cerr << "Something goes wrong!" << std::endl;
   }

   return 0;
}