#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int da)
    {
        data = da;
        next = nullptr;
    }
    void Display()
    {
        cout << data;
    }
};

class SLL
{
public :
    Node *head= nullptr;
    void add(int da)
    {
        Node *newptr;
        newptr =new Node(da);
        if(head == nullptr)
        {
            head = newptr;
        }
        else
        {
            Node *temp = head;
            while(temp->next!= nullptr)
            {
                temp = temp->next;
            }
            temp-> next =newptr;
        }
    }
    void addbegin(int da)
    {
        Node *newptr= new Node(da);
        if(head==NULL)
            head=newptr;
        else
        {
            newptr->next=head;
            head=newptr;
        }

    }
    void addanypos(int pos, int da)
    {
        Node *newptr = new Node(da);
        Node *temp = head, *temp1;
        for(int i=0 ; i<pos; i++)
        {
            temp1 =temp;
            temp = temp-> next;
        }
        temp1-> next = newptr;
        newptr-> next = temp;
    }

    bool contains(int da)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if(temp->data == da)
            {
                cout << "True" <<endl;
            }
            else
            {
                cout << "False" <<endl;
            }
            temp = temp->next;
        }
    }

    void sizeofList()
    {
        int count = 0;

        Node* temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout <<"Size: "<< count << endl;
    }
    bool isEmpty()
    {
        int count = 0;

        Node* temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << count << endl;

        if (count < 1)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    int get(int pos)
    {
        int count = 0;

        Node* temp = head;

        while (count < pos)
        {
            temp = temp->next;
            count++;
        }

        if(pos >=0 && pos <= count)
        {
            cout << temp->data << " is index " << pos << endl;

        }
        else
        {
            cout << "Error" << endl;
        }
    }

    int indexOf(int da)
    {
        Node *temp = head;
        int pos = 0;
        while (temp != nullptr)
        {
            if(temp->data == da)
            {
                cout << da << " is index: " << pos <<endl;

            }
            temp = temp->next;
            pos++;
        }
    }

    void removefirst()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void removelast()
    {
        Node *temp = head, *newptr,*p;
        while (temp->next != nullptr)
        {
            p = temp;
            temp = temp->next;
        }
        delete temp;
        p->next = nullptr;
    }
    void removefromanypos(int pos)
    {
        Node *temp = head,*temp1;
        for(int i=1; i<pos; i++)
        {
            temp1 = temp;
            temp =temp->next;
        }
        temp1->next = temp->next;
        delete temp;
    }
    void reverse()
    {
        Node* prev = nullptr;
        Node* temp = head;
        Node* next = nullptr;

        while (temp != nullptr)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        head = prev;
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


    void Display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout <<temp -> data << " ";

            temp = temp -> next;
        }
        cout << endl << endl;
    }

};

int main()
{
    int input, data,pos;
    SLL *s = new SLL();
    while(1)
    {
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
        cout << "Press 14 for Display" << endl;
        cout << "Press 15 for Exit" << endl << endl;
        cout << "Press Option: " ;
        cin >> input;
        cout << endl;
        if (input == 1)
        {
            cout << "Enter Data: ";
            cin >> data;
            s->add(data);

        }
        else if (input == 2)
        {
            cout << "Enter Data: ";
            cin >> data;
            s->addbegin(data);

        }
        else if (input == 3)
        {
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Data: ";
            cin >> data;
            s->addanypos(pos, data);
        }
        else if (input == 4)
        {
            cout << "Enter Data: ";
            cin >> data;
            s->contains(data);

        }
        else if (input == 5)
        {
            s->sizeofList();
        }
        else if (input == 6)
        {
            s->isEmpty();
        }
        else if (input == 7)
        {
            cout << "Enter Position: ";
            cin >> pos;
            s-> get(pos);
        }
        else if (input == 8)
        {
            cout << "Enter Data: ";
            cin >> data;
            s->indexOf(data);

        }
        else if (input == 9)
        {
            s-> removefirst();
        }
        else if (input == 10)
        {
            s-> removelast();
        }
        else if (input == 11)
        {
            cout << "Enter Position: ";
            cin >> pos;
            s-> removefromanypos(pos);
        }
        else if (input == 12)
        {
            s-> reverse();
            cout << "After Reverse: ";
            s-> Display();
        }
        else if (input == 13)
        {
            s-> sort();
            cout << "After Sorting in ascending order: ";
            s-> Display();
        }
        else if (input == 14)
        {
            s-> Display();
        }
        else if (input == 15)
        {
            break;
        }
        else {
            cout << "Wrong Key"<< endl << endl;
        }
    }
}
