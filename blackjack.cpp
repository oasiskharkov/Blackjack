#include <iostream>
#include "deck.h"
#include "card.h"
#include <cassert>

int main()
{
   Deck deck;
   deck.shuffle();
   std::unique_ptr<Card> card = deck.getCard();

   return 0;
}