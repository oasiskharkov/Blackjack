#include "person.h"

Person::Person(std::string&& name) :
   m_name{std::move(name)}
{

}

Hand& Person::hand()
{
   return m_hand;
}

const Hand& Person::hand() const
{
   return m_hand;
}

const std::string Person::name() const
{
   return m_name;
}

bool Person::isBusted() const
{
   return m_hand.total() > GameParams::blackjack;
}

void Person::showWin() const
{
   std::cout << m_name << ' ' << "win!" << std::endl;
}

std::ostream& operator << (std::ostream& out, const Person& person)
{
   out << person.name() << ":\t";

   const auto& hand = person.hand();
   if (!hand.empty())
   {
      hand.printCards(out);

      if (hand.total() != 0)
      {
         out << "(" << hand.total() << ")";
      }
   }
   else
   {
      throw std::logic_error("Hand is empty. Can't show cards!");
   }

   return out;
}
