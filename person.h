#pragma once

#include <string>
#include <iostream>
#include "hand.h"

class Person
{
public:
   Person(std::string&& name);
   ~Person() = default;
   Person(const Person&) = delete;
   Person& operator = (const Person&) = delete;
public:   
   virtual bool isHitting() const = 0;
   bool isBusted() const;
   void showBust() const;
   void showWin() const;
private:
   std::string m_name;
   Hand m_hand;
};