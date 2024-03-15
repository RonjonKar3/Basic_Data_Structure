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
        cout << "Top: " <<top -> data << endl;
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
    Stack*temp = new Stack();

    int i,n,data;
    cout << "Enter Data Size: ";
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> data;
        s->Push(data);
    }
    cout << "Original Data: ";
    s->Display();

    Node*t = s->top;
    while (t != NULL)
    {
        temp->Push(t->data);
        t = t->next;
    }
    cout << "Reverse Data: ";
    temp->Display();
}


