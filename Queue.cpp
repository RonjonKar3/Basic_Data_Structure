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
class Queue
{
public:
    Node*front,*rear,*temp,*temp1;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int value)
    {
        Node*newptr = new Node(value);
        if(front == nullptr)
        {
            front = rear = newptr;
        }
        else
        {
            rear->next = newptr;
            rear = newptr;
        }

    }
    void dequeue()
    {
        if(front == nullptr)
        {
            cout << "Queue is Empty" << endl;

        }
        else
        {
            temp = front;
            front = temp->next;
            delete temp;
        }

    }
    bool isEmpty()
    {
        if(front == nullptr)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }

    }
    int Size()
    {
        int count = 0;
        temp = front;
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        cout << "Size: " << count << endl;
    }
    void Display()
    {
        temp = front;
        while (temp != nullptr)
        {
            cout <<temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    void Destroy()
    {
        if(rear == nullptr)
        {
            cout << "Queue is Empty" << endl;

        }
        else
        {
            while (front != nullptr)
            {
                temp = front;
                front = front->next;
                delete temp;
            }
            rear = nullptr;
            cout << endl;
        }
    }
    void Front()
    {
        temp = front;
        while (temp != nullptr)
        {
            temp = temp -> next;
        }
        cout << endl;
        cout << "Front: " << front->data << endl;
    }
    void Rear()
    {
        temp = front;
        while (temp != nullptr)
        {
            temp = temp -> next;
        }
        cout << endl;
        cout << "Rear: " << rear->data << endl;
    }
};
class Main
{
public:
    void lab01()
    {
        Queue *queue, Q1,Q2;
        int size, data,i;

        cout << "Enter Size: ";
        cin >> size;

        cout << "Enter Data: ";
        for (i=0; i<size; i++)
        {
            cin >> data;
            Q1.enqueue(data);
        }

        Node* temp = Q1.front;
        while (temp != nullptr)
        {
            Q2.enqueue(temp->data);
            temp = temp->next;
        }
        Q2.Display();

    }
    void lab02()
    {
        Queue *queue, Q,Q1;
        int size, data,i;
        cout << "Enter Size: ";
        cin >> size;

        cout << "Enter Data: " << endl;
        for (i=0; i<size; i++)
        {
            cin >> data;
            Q.enqueue(data);
        }
        cout << "Original Queue: ";
        Q.Display();
        for(i=0; i<size; i++)
        {
            int value = Q.front->data;

            if (value < 0)
            {
                Q.dequeue();
                Q1.enqueue(value);

            }
            else
            {
                Q.dequeue();
                Q.enqueue(value);
            }
        }
        cout << "Remaining elements in queue Q: ";
        Q.Display();

        cout << "Negative elements in queue Q1: ";
        Q1.Display();

    }
    void lab03()
    {
        Queue q;
        int size, data,i,n;
        cout << "Enter Size: ";
        cin >> size;
        int arr[size],value1,value2;

        cout << "Enter Data: " << endl;
        for (i=0; i<size; i++)
        {
            cin >> data;
            q.enqueue(data);
        }

        cout << "Enter the value of K: ";
        cin >> n;
        int K = n;

        cout << "Original Queue: ";
        q.Display();

        Node* prev = nullptr;
        Node* temp = q.front;
        Node* next = nullptr;

        for (i=0; i<K; i++)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        q.front = prev;

        cout << "Modified Queue: ";
        q.Display();
    }
};
int main()
{
    Main*m = new Main();
    int input;
    while(1)
    {
        cout << "Press 0 for Exit" << endl;
        cout << "Press 1 for Lab01" << endl;
        cout << "Press 2 for Lab02" << endl;
        cout << "Press 3 for Lab03" << endl;
        cout << "Enter Option: ";
        cin >> input;
        cout << endl;
        if (input == 0)
        {
            break;
        }
        else if(input == 1)
        {
            m->lab01();
        }
        else if(input == 2)
        {
            m->lab02();
        }
        else if(input == 3)
        {
            m->lab03();
        }
        else
        {
            cout << "Wrong Key!!!";
        }
    }
    return 0;
}



