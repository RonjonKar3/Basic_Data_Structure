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
    int Destroy(){
        temp = top;
        while(temp != nullptr){
        top = temp->next;
        delete temp;
        temp = temp->next;
    }
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
        if(top == nullptr){
            cout << "Is Empty: True" << endl;
        }
        else {
            cout << "Is Empty: False" << endl;
        }
    }
    void Display(){
        temp = top;
        while (temp != nullptr)
        {
            cout <<temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
     void Top(){
        cout << "Top: " <<top -> data << endl;
    }
};
int main()
{
    Stack*s1 = new Stack();
    cout << "After Push: ";
    s1-> Push(1);
    s1-> Push(2);
    s1-> Push(3);
    s1-> Push(4);
    s1-> Push(5);
    s1-> Display();
    s1-> Top();
    s1-> Size();
    s1-> IsEmpty();
    cout << "After Pop: ";
    s1-> Pop();
    s1-> Display();
    cout << "After Destroy: ";
    s1-> Destroy();
    s1-> Display();
    s1-> IsEmpty();
}
