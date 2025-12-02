#include "linkedList.h"
// LINKED LIST
linkedList:: linkedList()
{
   head = tail = NULL;
   node = 0;
}
linkedList:: ~linkedList()
{
   //
}

Element *linkedList:: getHead()
{
   return head;
}
void linkedList:: setHead(Element *val)
{
   head = val;
}
Element *linkedList:: getTail()
{
   return tail;
}
void linkedList:: setTail(Element *val)
{
   tail = val;
}

//
void linkedList:: insertFirst(Element *p)
{
   if (node == 0)
      head = tail = p;
   else
   {
      p->setPointer(head);
      head = p;
   }
   node++;
}
//
void linkedList:: traverse()
{
   for (Element *p = head; p != NULL; p = p->getPointer())
   {
      cout<<p->getData()<<' ';
   }
}
// 1. Viết hàm tính tổng giá trị các phần tử trên DSLK gồm các giá trị nguyên.
int linkedList:: sumList()
{
   Element *p;
   int sum = 0;
   for(p = head; p != NULL; p = p->getPointer())
   {
      sum+=p->getData();
   }
   return sum;
}
// 2. Viết hàm tìm giá trị nguyên lớn nhất trên DSLK
Element* linkedList:: maxList()
{
   Element * max = head;
   for (Element *p = head ->getPointer(); p != NULL; p = p->getPointer())
   {
      if(p ->getData() > max->getData()) max = p;
   }
   return max;
}
// 3. Viết hàm tính số lượng các phần tử là số nguyên tố của DSLK
bool linkedList:: isPrime(int n)
{
   if (n < 2) return false;
   else
   {
      for (int i = 2; i <= sqrt(n); i++)
         if(n % i == 0) return false;
   }
   return true;
}
int linkedList:: countPrime()
{
   Element *p;
   int count = 0;
   for (p = head; p != NULL; p = p->getPointer())
   {
      if (isPrime(p->getData())) count++;
   }
   return count;
}
// 4.Viết hàm thêm vào cuối DSLK đơn một giá trị nguyên
void linkedList:: insertTail(Element *p)
{
   if (node == 0) head = tail = p;
   else
   {
      tail ->setPointer(p);
      tail = p;
   }
   node++;
}
// 5.Viết hàm phép thêm phần tử vào sau p(tham số truyền vào là 1 ptr)
void linkedList:: insertAfterP(Element *p, Element *newNode)
{
   if (node == 0 || p == 0 || newNode == 0) return;
   Element *cur = head;
   while (cur != NULL && cur != p)
      cur = cur ->getPointer();
   if (cur == 0) return;
   newNode ->setPointer(p->getPointer());
   p ->setPointer(newNode);
   if (p == tail)
      tail = newNode;
   node++;
}
// 6.Viết hàm xóa phần tử đầu danh sách liên kết đơn
bool linkedList:: deleteFirst()
{
   if (node == 0) return false;
   if (head == tail)
   {
      delete head;
      head = tail = NULL;
      node = 0;
   }
   else
   {
      Element *p = head;
      head = head->getPointer();
      delete p;
      node--;
   }
   return true;
}
// Viết hàm removeAll xóa tất cả các phần tử trong DSLK
void linkedList:: removeAll()
{
   if (node == 0) return;
   Element *p = head;
   while (p != NULL)
   {
      head = head-> getPointer();
      delete p;
      p = head;
   }
   head = tail = NULL;
   node = 0;
}
// 7.Bổ sung chương trình mẫu cho phép xóa phần tử cuối DSLK
bool linkedList:: deleteTail()
{
   if (node == 0) return false;
   if (head == tail)
   {
      delete tail;
      head = tail = NULL;
      node = 0;
   }
   else 
   {
      Element *p = head;
      while (p->getPointer() != tail)
         p = p->getPointer();
      delete tail;
      tail = p;
      tail->setPointer(NULL);
      node--;
   }
   return true;
}
// 8.Viết hàm xóa phần tử p(tham số truyền vào là 1 ptr) bất kỳ trong DSLK
bool linkedList:: deleteP(Element *p)
{
   if (node == 0 || p == NULL) return false;
   if (node == 1)
   {
      deleteFirst();
      return true;
   }
   else
   {
      Element *cur = head;
      while (cur != NULL && cur->getPointer() != p)
         cur = cur->getPointer();
      if (cur == NULL) return false;
      cur->setPointer(p->getPointer());
      if (p == tail) tail = cur;
      delete p;
      node--;
      return true;
   }
}
// 9.Viết hàm cho biết số lượn phần tử trùng với x trong DSLK
int linkedList:: countMatch(int x)
{
   int count = 0;
   Element *p ;
   for (p = head; p != NULL; p = p->getPointer())
   {
      if (p ->getData() == x) count++;
   }
   return count;
}
// 10.Tạo DSLK gồm các phần tử mang giá trị nguyên trong đó không trùng nhau
void linkedList:: insertNonDuplicate(int x)
{
   for (Element *p = head; p != NULL; p = p->getPointer())
   {
      if (p->getData() == x) return; 
   }
   Element *p = new Element(x);
   if (node == 0) head = tail = p;
   else
   {
      tail -> setPointer(p);
      tail = p;
      node ++;
   }
}
// 11.Tách DSLK đã cho thành 2: 1 ds nhỏ hơn giá trị x, 1 ds lớn hơn gt x
void linkedList:: two_List(int x)
{
   linkedList greaterList;
   linkedList lessList;
   for (Element *p = head; p != NULL; p = p->getPointer())
   {
      Element *newNode = new Element(p->getData());
      if (p-> getData() > x) greaterList.insertTail(newNode);
      else if (p-> getData() < x) lessList.insertTail(newNode);
   }
   cout << "\nGreater list: ";
   greaterList.traverse();
   cout <<"\nLess list: ";
   lessList.traverse();
}

// STACK
Stack :: Stack()
{
   linkedlist = new linkedList();
   node = 0;
}
Stack :: ~Stack()
{
   // destruct
}
void Stack :: push(int x)
{
   Element *p = new Element(x);
   linkedlist -> insertFirst(p);
   node ++;
}
int Stack :: pop()
{
   if (linkedlist->getHead() == NULL)
      return 0;
   int p = linkedlist->getHead()->getData();
   linkedlist->deleteFirst();
   node --;
   return p;
}
void Stack :: printStack()
{
   linkedlist->traverse();
}
void Stack :: decToBi(int x)
{
   while (x != 0)
   {
      push(x % 2);
      x /= 2;
   }
   while (node != 0)
   {
      cout<< pop();
   }
}
// QUEUE
Queue :: Queue()
{
   linkedlist = new linkedList();
   node = 0;
}
Queue :: ~Queue()
{
   //destruct
}
void Queue :: enQueue(int x)
{
   Element *p = new Element(x);
   linkedlist -> insertTail(p);
   node ++;
}
int Queue :: deQueue()
{
   if (linkedlist->getHead() == NULL)
      return 0;
   int p = linkedlist->getHead()->getData();
   linkedlist->deleteFirst();
   node --;
   return p;
}
void Queue :: printQueue()
{
   linkedlist->traverse();
}