#pragma once

#include <string>
#include <iostream>
#include "hand.h"

class Person
{
public:
   Person(std::string&& name);
   virtual ~Person() = default;
   Person(const Person&) = delete;
   Person& operator = (const Person&) = delete;
public:   
   virtual bool isHitting() const = 0;
   Hand& hand();
   const Hand& hand() const;
   const std::string name() const;
   bool isBusted() const;
   void showWin() const;
private:
   std::string m_name;
   Hand m_hand;
};

std::ostream& operator << (std::ostream& out, const Person& person);