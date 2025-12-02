#include "element.h"
Element:: Element()
{
   data = 0;
   ptr = nullptr;
}
Element:: Element(int d)
{
   data = d;
   ptr = NULL;
}
void Element:: showData()
{
   cout<< data;
}
int Element:: getData() const
{
   return data;
}
void Element::setData(int val)
{
   data = val;
}
Element* Element :: getPointer()
{
   return ptr;
}
void Element:: setPointer(Element *val)
{
   ptr = val;
}