#include <iostream>
using namespace std;

class LinkedList
{
public:

    class Node
    {
    public:
        int data;
        Node* next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };

    Node* head;

    void push(int data)
    {
        Node* node = new Node(data);
        node->next = head;
        head = node;
    }
    Node* Delete(Node* head, int k)
    {
        if (k < 1)
            return head;

        if (head == NULL)
            return NULL;

        if (k == 1)
        {
            Node *r = head->next;
            delete(head);
            return r;
        }

        head->next = Delete(head->next, k-1);
        return head;
    }

    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{

    LinkedList* l = new LinkedList();

    int n;
    cout << "Enter Size: ";
    cin>>n;
    int data;
    cout << "Enter Data: ";
    for(int i=0; i<n; i++)
    {
        cin>>data;
        l->push(data);
    }

    cout << "Linked List Before Deletion " << endl;
    l->display();

    int pos;
    cout << "Enter Position: ";
    cin >> pos;

    l->Delete(l->head, pos);

    cout << "Linked List After Deletion: "<< endl;
    l->display();

    return 0;
}

