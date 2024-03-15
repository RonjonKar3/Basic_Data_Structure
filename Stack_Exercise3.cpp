#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
    void Display()
    {
        cout << data;
    }
};

class Stack
{
public:
    Node*top,*temp;
    Stack()
    {
        top = nullptr;
    }

    void Push(int value)
    {
        Node*newptr = new Node(value);

        if(top == nullptr)
        {
            top = newptr;
        }
        else
        {
            newptr->next = top;
            top = newptr;
        }
    }
    int Pop()
    {
        temp = top;
        top = temp->next;
        delete temp;
    }

    int Size()
    {
        int count = 0;
        temp = top;
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        cout << "Size: " << count << endl;
    }
    bool IsEmpty()
    {
        if(top == nullptr)
        {
            cout << "Is Empty: True" << endl;
        }
        else
        {
            cout << "Is Empty: False" << endl;
        }
    }
    int Destroy()
    {
        temp = top;
        while(temp != nullptr)
        {
            top = temp->next;
            delete temp;
            temp = temp->next;
        }
    }

    int Top()
    {
        cout << top -> data << endl;
    }
    void Display()
    {
        temp = top;
        while (temp != nullptr)
        {
            cout <<temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

};
int main()
{
  Stack*s = new Stack();

  int n, number;
  cout << "Enter Decimal Number: ";
  cin >> n;
  number = n;

  while (number > 0){
    int p = number % 2;
    s -> Push(p);
    number = number / 2;
  }
  cout << "The Binary Number of " << n <<" is: ";
  while (s->top != NULL){
    cout << s->top->data;
    s->Pop();
  }

}

