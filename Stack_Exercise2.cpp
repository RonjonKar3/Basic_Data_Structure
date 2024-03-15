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
    Stack*source = new Stack();
    Stack*temp = new Stack();
    Stack*destination = new Stack();

    int i,n,data;

    cout << "Enter Data Size: ";
    cin >> n;

    cout << "Enter Data: ";
    for(i=0; i<n; i++)
    {
        cin >> data;
        source->Push(data);
    }
    cout << "Source Data: ";
    source->Display();

    Node*t1,*temp1 = source->top;
    while (temp1 != NULL)
    {
        temp->Push(temp1->data);
        temp1 = temp1->next;
    }
    Node*temp2 = temp->top;
    while (temp2 != NULL)
    {
        destination->Push(temp2->data);
        temp2 = temp2->next;
    }
    cout << "Destination Data: ";
    destination->Display();
}

