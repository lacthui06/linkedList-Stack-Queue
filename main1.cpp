#include "linkedList.h"
int main()
{

   Stack *s = new Stack();
   s->push(7);
   s->push(10);
   s->push(18);
   cout<<"List stack : ";
   s->printStack();
   cout<< "\nPop : ";
   for (int i = 0; i < 4; i++)
   {
      int value = s->pop();
      if (value == 0)
         cout << "\nSTACK RONG, KHONG LAY DUOC PHAN TU\n";
      else cout << value << " ";
   }
   Queue *q = new Queue();
   q->enQueue(5);
   q->enQueue(8);
   q->enQueue(14);
   cout<<"\nList queue : ";
   q->printQueue();
   cout<<"\nDequeue : ";
   for (int i = 0; i < 4; i++)
   {
      int value = q->deQueue();
      if (value == 0)
         cout << "\nQUEUE RONG, KHONG LAY DUOC PHAN TU\n";
      else cout << value << " ";
   }
   int n;
   do{
      cout<< "Nhap vao gia tri n : "; cin>>n;
   }while (n <= 0);
   cout<< n <<" chuyen tu he co so 10 sang 2 la : ";
   Stack s1;
   s1.decToBi(n);
}