#include <iostream>

typedef int datatype;

struct Item
{
datatype data;
Item* next;
//Item* previous; //у випадку двозв’язного списку
};

Item *head = NULL; //, *temp, *front, *rear;

void push(datatype data)
{
    Item *temp = new Item;
    temp->data = data;
    temp->next = head;
    head = temp;
}
 void pop()
 {
     if (head == NULL)
     {
         std::cout << "Stack is empty\n";
         return;
     }
     Item *temp = head;
     head = temp->next;
     delete temp;
 }

 void show()
 {
     Item *temp = head;
     while(temp != NULL)
     {
        std::cout << temp->data << ' ';
        temp = temp->next;
     }
     std::cout << std::endl;
 }

 int main()
 {
    push(3);
    push(5);
    push(1);
    push(0);
    show();

    return 0;
 }

