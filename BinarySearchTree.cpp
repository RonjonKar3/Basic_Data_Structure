#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node*left,*right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
    void Display()
    {
        cout << "Data: "<< data;
    }

};
class BST
{
public:
    Node*node;

    // 1.Insert
    Node*insert(Node*node,int d)
    {
        if(node ==  NULL)
        {
            node = new Node(d);
        }
        else if(node->data > d)
        {
            node-> left = insert(node->left,d);
        }
        else
        {
            node -> right = insert(node -> right,d);
        }
        return node;
    }

    // 2.Search
    Node*search(Node*node, int value)
    {
        if(node ==  NULL || node->data == value)
        {
            return node;
        }
        else if(node->data > value)
        {
            return search(node -> left,value);
        }
        else
        {
            return search(node -> right,value);
        }

    }

    // 3.Traversal Operation
    // Preorder
    void preorder(Node* node)
    {
        if (node != NULL)
        {
            cout << node -> data << " ";
            preorder(node -> left);
            preorder(node -> right);
        }
    }

    //Inorder
    void inorder(Node* node)
    {
        if (node != NULL)
        {
            inorder(node -> left);
            cout << node -> data << " ";
            inorder(node -> right);
        }
    }

    // Postorder
    void postorder(Node* node)
    {
        if (node != NULL)
        {
            postorder(node -> left);
            postorder(node -> right);
            cout << node -> data << " ";
        }
    }

    // 4.Delete
    Node*Delete(Node*node, int value)
    {
        if(node == NULL)
        {
            return node;
        }
        else if(node->data > value)
        {
            node->left = Delete(node->left,value);
        }
        else if(node->data < value)
        {
            node->right = Delete(node->right,value);
        }
        else
        {
            if(node->left == NULL && node->right == NULL )
            {
                delete node;
                return NULL;
            }
            else if(node->left != NULL && node->right == NULL )
            {
                Node*temp = node;
                delete temp;
                node = node->left;
                return node;
            }
            else if(node->left == NULL && node->right != NULL )
            {
                Node*temp = node;
                delete temp;
                node = node->right;
                return node;
            }
            else
            {
                Node*temp = minimum(node->right);
                node->data = temp->data;
                node->right = Delete(node->right, temp->data);
                return node;

            }
        }
    }

    // Exercise 5:
    // Smallest
     Node*minimum(Node*node)
    {
        if(node->left == NULL)
        {
            return node;
        }
        else
        {
            return minimum(node->left);
        }
    }

    // Largest
    Node*maximum(Node*node)
    {
        if(node->right == NULL)
        {
            return node;
        }
        else
        {
            return maximum(node->right);
        }
    }
};
int main()
{

    BST*b = new BST();
    Node*root = NULL;
    int m,n,data,i,num;

    // Insert
    cout << "Enter Size to insert: ";
    cin >> n;

    cout << "Enter Data: "<< endl;
    for(i=0; i<n; i++)
    {
        cin >> data;
        root = b->insert(root,data);
    }
    cout << endl << endl;

    // Tree Traversal
    cout << "InOrder: ";
    b->inorder(root);
    cout << endl;
    cout << "PreOrder: ";
    b->preorder(root);
    cout << endl;
    cout << "PostOrder: ";
    b->postorder(root);
    cout << endl << endl;

    // Search
    cout << "Enter a Number for Search: ";
    cin >> num;
    Node *flag = b->search(root, num);
    if (flag != nullptr)
    {
        cout << num << " is Found." << endl;
    }
    else
    {
        cout << num << " is Not Found." << endl;
    }
    cout << endl << endl;


    //Find Minimum and Maximum
    Node*max = b->maximum(root);
    Node*min = b->minimum(root);
    cout <<"Maximum Value: " << max << endl;
    cout <<"Minimum Value: " << min << endl;

    //Delete
    cout << "Enter a Data to Delete: ";
    cin >> m;

    b->Delete(root,m);
    cout << "InOrder: ";
    b->inorder(root);

}
