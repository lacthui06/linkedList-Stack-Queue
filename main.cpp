#include <iostream>
#include "linkedList.h"
using namespace std;

int main()
{
   linkedList *list = new linkedList();
   Element *e;
   e = new Element(9);
   list->insertTail(e);

   e = new Element(10);
   list->insertTail(e);

   e = new Element(8);
   list->insertTail(e);
   list->traverse();

   e = new Element(11);
   list->insertFirst(e);
   Element *newNode = new Element(99);
   list->insertAfterP(e, newNode);

   //list->deleteFirst();
   cout<<"\nSum list : ";
   cout << list->sumList();
   cout<<"\nMax of list : ";
   cout << list->maxList();
   cout<<"\nHave "<<list->countPrime()<<" prime in list";
   list->two_List(10);
   //list->removeAll();
   //list->traverse();
}