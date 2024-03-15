#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node*next,*prev;

    Node(int data)
    {
        prev = nullptr;
        this->data = data;
        next = nullptr;
    }
    void Display()
    {
        cout << data;
    }
};

class DLL{

    public:

    Node*newptr,*head,*temp;

    void add(int item)
    {
        Node*newptr = new Node(item);
        Node*temp;

        if (head == nullptr)
        {
            head = newptr;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            newptr->prev = temp;
            temp->next = newptr;

        }
    }
    void addbegin(int item)
    {
        newptr = new Node(item);
        temp = head;
        newptr->data = item;
        newptr->next = nullptr;
        newptr->prev = nullptr;
        if (head == nullptr){
            head = newptr;
        }
        else{

        temp->prev = newptr;
        newptr->next = head;
        head = newptr;
        }
    }
    void addanypos(int pos,int item)
    {
        Node*newptr = new Node(item);
        Node*temp,*temp1;
        newptr = new Node(item);
        temp = head;
        newptr->data = item;

        if (head == NULL)
        {
            head = newptr;
        }
        else

            for(int i=0; i<pos; i++)
            {
                temp1 = temp;
                temp = temp->next;
            }
           temp1->next = newptr;
           newptr->prev = temp1;
           newptr->next = temp;
        }
    bool contains(int item)
    {
        Node*temp = head;
        while(temp->next != nullptr )
        {
            if(temp->data == item)
            {
                cout << "True " << endl;
                break;
            }
            temp = temp->next;
        }
        cout << endl << endl;
    }
    int size()
    {
        Node*temp = head;
        int count = 0;
        while(temp != nullptr)
        {
            count++;
            temp = temp -> next;
        }
        cout << "Size: " << count << endl;
    }
    bool isEmpty()
    {
        if(head == nullptr){
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    int get(int pos)
    {
        Node*temp = head;
        int count = 0;
        while(count < pos)
        {
            temp = temp -> next;
            count++;
        }

        if(pos >= 0 && pos <=count)
        {
            cout << temp->data << endl;
        }
        else{
            cout << "Error" << endl;
        }

    }
    int indexOf(int item)
    {
       Node*temp = head;
       int position = 0;
        while(temp != nullptr )
        {
            if(temp->data == item)
            {
                cout << "Item Position: " << position << endl;
            }
            temp = temp->next;
            position++;
        }
        cout << endl << endl;
    }
    void removefirst(){
        Node*temp = head;
        head = temp->next;
        head->prev = nullptr;
        delete temp;
    }
     void removelast(){
        Node*temp = head, *temp1;
        while(temp->next != nullptr )
        {
            temp1 = temp;
            temp = temp->next;
        }
        delete temp;
        temp1->next = nullptr;
        cout <<"Remove Successfully!!"<< endl;
     }
     void remove(int pos){
        Node *temp = head,*temp1,*temp2;
        for(int i=0; i<pos; i++)
        {
            temp1 = temp;
            temp =temp->next;
            temp2 = temp;
        }
        temp1->next = temp->next;
        temp2 -> prev = temp1;
        delete temp;

        cout << endl << endl;
     }
     void reverse(){
        Node *temp = head,*temp1,*temp2;
        temp = head;
        temp1 = temp->next;
        temp->next = nullptr;
        temp->prev = temp1;

        while(temp1!=nullptr){
            temp1->prev = temp1->next;
            temp1->next = temp;
            temp = temp1;
            temp1 = temp1->prev;
        }
        head = temp;
        cout << endl;
     }
     void sort()
    {
        Node*i,*j;
        for (i = head; i != nullptr; i = i->next)
        {
            for (j = i->next; j != nullptr; j = j->next)
            {
                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    void Display(){
        cout << endl;
        Node*temp = head;
        int count = 0;
        cout << "Data: ";
        while(temp != nullptr)
        {

            cout << temp -> data << " " ;
            count++;
            temp = temp -> next;


        }
        cout << endl << endl;
    }
};
int main(){
    DLL *dll = new DLL();
    int input, item,pos;

    while(1)
    {
        cout << "Press 0 for Exit" << endl ;
        cout << "Press 1 for add at last" << endl;
        cout << "Press 2 for add at begin" << endl;
        cout << "Press 3 for add at any Position" << endl;
        cout << "Press 4 for contains" << endl;
        cout << "Press 5 for size" << endl;
        cout << "Press 6 for isEmpty" << endl;
        cout << "Press 7 for get" << endl;
        cout << "Press 8 for indexOf" << endl;
        cout << "Press 9 for remove from first" << endl;
        cout << "Press 10 for remove from last" << endl;
        cout << "Press 11 for remove from any Position" << endl;
        cout << "Press 12 for reverse" << endl;
        cout << "Press 13 for sort" << endl;
        cout << "Press 14 for Display" << endl << endl;
        cout << "Press Option: " ;
        cin >> input;
        cout << endl;
        if(input == 0)
        {
            break;
        }
        else if(input == 1)
        {
            cout << "Enter Item: ";
            cin>>item;

            dll->add(item);

        }
        else if(input == 2)
        {
            cout << "Enter Item: ";
            cin>>item;

            dll->addbegin(item);
        }
         else if(input == 3)
        {
            cout << "Enter Position: ";
            cin>>pos;

            cout << "Enter Item: ";
            cin>>item;

            dll->addanypos(pos,item);
        }
        else if(input == 4)
        {

            cout << "Enter Item: ";
            cin>>item;
            dll->contains(item);

        }
        else if(input == 5)
        {
            dll->size();
        }

        else if(input == 6)
        {
            dll->isEmpty();
        }

        else if(input == 7)
        {

            cout << "Enter Position: ";
            cin >> pos;

            dll->get(pos);
        }
        else if(input == 8)
        {

            cout << "Enter Item: ";
            cin >> item;

            dll->indexOf(item);
        }
        else if(input == 9)
        {
            dll->removefirst();
        }
        else if(input == 10)
        {

            dll->removelast();
      }
        else if(input == 11)
        {
            cout << "Enter Position: ";
            cin >> pos;

            dll->remove(pos);

        }
        else if(input == 12)
        {

            dll->reverse();
            cout << "After Reverse ";
            dll->Display();
        }
        else if(input == 13)
        {

            dll->sort();
            cout << "After Sorting ";
            dll->Display();
        }
         else if(input == 14)
        {
            dll->Display();
        }
        else
        {
            cout << "Wrong Key, Press any key between 0 to 14 "<< endl;
        }
    }
}

