#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
};
void insert(node *&head,int data)
{
    node *temp=new node();
    temp->data=data;
     node *q=head;
     head=temp;
     temp->next=q;
     return;
}
void display(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     cout<<endl;
}
void sort(node *&head,node *p1,node *p2)
{
    if(p2==NULL)
    {
        return;
    }
   node *p3=p1->next;
   while(p3!=NULL)
    {
        if(p1->data>p3->data)
        {
            swap(p1->data,p3->data);
        }
        p3=p3->next;
    }
    sort(head,p2,p2->next);
}
int main()
{
    node *head1=NULL;
    int n;
    cout << "Enter Size: ";
    cin>>n;
    int data;
    cout << "Enter Data: ";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insert(head1,data);
    }

    sort(head1,head1,head1->next);
    cout<<"After Sorting:"<<endl;
    display(head1);
}
