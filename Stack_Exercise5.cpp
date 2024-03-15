#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node*next;

    Node(int data)
    {
        this -> data = data;
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
    Node*top,*newnode,*temp;
    Stack()
    {
        top = nullptr;
    }

    void push(int value)
    {
        newnode = new Node(value);
        if(top == nullptr)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    int pop()
    {
        temp = top;
        top = temp->next;
        delete temp;
    }

    int size()
    {
        int c = 0;
        temp = top;
        while(temp!=nullptr)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    bool IsEmpty()
    {
        if(size()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Top()
    {
        return top->data;
    }

    int Parse(string c)
    {

        for(int i=0; i<c.size(); i++)
        {
            if(c[i] == '(' || c[i] == '[' || c[i] == '{')
            {
              push(c[i]);
            }
            else if(c[i] == ')')
            {
                if(!IsEmpty() && Top() == '(')
                {
                    pop();
                }
                else if(IsEmpty())
                {
                    cout << "Stack is Undeflow and ";
                    push(1);
                }
            }
            else if(c[i] == '}')
            {
                if(!IsEmpty() && Top() == '{')
                {
                    pop();
                }
                else if(IsEmpty())
                {
                    cout << "Stack is Undeflow and ";
                    push(1);
                }
            }
            else if(c[i] == ']')
            {
                if(!IsEmpty() && Top() == '[')
                {
                    pop();
                }
                else if(IsEmpty())
                {
                    cout << "Stack is Undeflow and ";
                    push(1);
                }
            }
        }
        if (IsEmpty())
        {
            cout << "Equation is Balanced" << endl;
        }
        else
        {
            cout << "Equation is Not Balanced" << endl;
        }
    }
};
int main()
{
    Stack*s = new Stack();

    char s[] = "{(Check) [Eq(ua)tion]}";
    s->Parse(s);



}

