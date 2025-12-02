#include "element.h"
#pragma once
class linkedList
{
private:
   Element *head;
   Element *tail;
   int node;
public:
   linkedList();
   virtual ~linkedList();

   Element *getHead();
   void setHead(Element *val);
   Element *getTail();
   void setTail(Element *val);
   //
   void insertFirst(Element *);
   //
   void traverse();
   // 1. Viết hàm tính tổng giá trị các phần tử trên DSLK gồm các giá trị nguyên.
   int sumList();
   // 2. Viết hàm tìm giá trị nguyên lớn nhất trên DSLK
   Element *maxList();
   // 3. Viết hàm tính số lượng các phần tử là số nguyên tố của DSLK
   bool isPrime(int n);
   int countPrime();
   // 4.Viết hàm thêm vào cuối DSLK đơn một giá trị nguyên 
   void insertTail(Element *);
   // 5.Viết hàm phép thêm phần tử vào sau p(tham số truyền vào là 1 ptr)
   void insertAfterP(Element *, Element *);
   // 6.Viết hàm xóa phần tử đầu danh sách liên kết đơn
   bool deleteFirst();
   // Viết hàm removeAll xóa tất cả các phần tử trong DSLK
   void removeAll();
   // 7.Bổ sung chương trình mẫu cho phép xóa phần tử cuối DSLK
   bool deleteTail();
   // 8.Viết hàm xóa phần tử p(tham số truyền vào là 1 ptr) bất kỳ trong DSLK
   bool deleteP(Element *);
   // 9.Viết hàm cho biết số lượn phần tử trùng với x trong DSLK
   int countMatch(int x);
   // 10.Tạo DSLK gồm các phần tử mang giá trị nguyên trong đó không trùng nhau
   void insertNonDuplicate(int x);
   // 11.Tách DSLK đã cho thành 2: 1 ds nhỏ hơn giá trị x, 1 ds lớn hơn gt x
   void two_List(int x);
};

// STACK
class Stack
{
private:
   linkedList *linkedlist;
   int node;
public:
   Stack();
   virtual ~Stack();
   void push(int x);
   int pop();
   void printStack();
   void decToBi(int x);
};

// QUEUE

class Queue
{
private:
   int node;
   linkedList * linkedlist;
public:
   Queue();
   virtual ~Queue();
   void enQueue(int x);
   int deQueue();
   void printQueue();
};
