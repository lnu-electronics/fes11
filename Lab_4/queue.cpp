#include <iostream>

typedef int datatype;

struct Item
{
datatype data;
Item* next;
//Item* previous; //у випадку двозв’язного списку
};

Item *front = NULL, *rear = NULL;//, *temp, *front, *rear;

void enqueue(datatype data)
{
    Item *temp = new Item;
    temp->data = data;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}
 void dequeue()
 {
     if (front == NULL)
     {
         std::cout << "Queue is empty\n";
         return;
     }
     Item *temp = front;
     front = temp->next;
     delete temp;
 }

 void show()
 {
     Item *temp = front;
     while(temp != NULL)
     {
        std::cout << temp->data << ' ';
        temp = temp->next;
     }
     std::cout << std::endl;
 }

 int main()
 {
    enqueue(3);
    enqueue(5);
    enqueue(1);
    enqueue(0);
    show();
    dequeue();
    show();

    return 0;
 }

