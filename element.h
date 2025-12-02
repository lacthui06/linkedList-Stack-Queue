#pragma once
#include <bits/stdc++.h>
using namespace std;
class Element
{
private:
   int data;
   Element *ptr;
public:
   Element();
   Element(int);
   void showData();
   int getData() const;
   void setData(int val);
   Element *getPointer();
   void setPointer(Element *p);
};