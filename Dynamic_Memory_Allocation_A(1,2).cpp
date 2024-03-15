#include<iostream>
using namespace std;

class Product
{
private:
    int id, quantity;
    string name, brand, type;
    double price;

public:
    void setId(int id)
    {
        this -> id = id;
    }
    int getId()
    {
        return id;
    }
    void setName(string name)
    {
        this -> name = name;
    }
    string getName()
    {
        return name;
    }
    void setQuantity(int quantity)
    {
        this -> quantity = quantity;
    }
    int getQuantity()
    {
        return quantity;
    }
    void setBrand(string brand)
    {
        this -> brand = brand;
    }
    string getBrand()
    {
        return brand;
    }
    void setType(string type)
    {
        this -> type = type;
    }
    string getType()
    {
        return type;
    }
    void setPrice(double price)
    {
        this -> price = price;
    }
    double getPrice()
    {
        return price;
    }
    void Display()
    {
        cout << "\n\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Brand: " << brand << endl;
        cout << "Type: " << type << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;

    }
};

int main()
{
// 1.(a)
    cout << "1.(a)\n" << endl;
    int i,m,d,q;
    string n,b,t;
    int pr;

    cout << "Enter Array Size: " ;
    cin >> m ;

    Product p[m] ;

    for (i=0 ; i<m ; i++)
    {
        cout << "\n\n";
        cout << "Enter Product ID: ";
        cin >> d;
        p[i].setId(d);

        cout << "Enter Product Name: ";
        cin >> n;
        p[i].setName(n);

        cout << "Enter Product Brand Name: ";
        cin >> b;
        p[i].setBrand(b);

        cout << "Enter Product Type: ";
        cin >> t;
        p[i].setType(t);

        cout << "Enter Product Quantity: ";
        cin >> q;
        p[i].setQuantity(q);

        cout <<  "Enter Product Price: ";
        cin >> pr;
        p[i].setPrice(pr);
    }

    for(i= 0; i<m; i++)
    {
        if (p[i]. getPrice()> 40.00 )
        {
            p[i].Display();
        }
        else
        {
            cout << "\nProduct Price is Under 40\n" ;
        }
    }

    // 1.(b)
    cout << "\n1.(b)"<< endl;
    int j,k, sizes;
    cout << "\nEnter Array size: ";
    cin >> sizes;
    Product *ptr = new Product[sizes];

    for(j=0; j<sizes; j++)
    {
        cout << "\n\n";
        cout << "Enter Product ID: ";
        cin >> d;
        ptr[j].setId(d);

        cout << "Enter Product Name: ";
        cin >> n;
        ptr[j].setName(n);

        cout << "Enter Product Brand Name: ";
        cin >> b;
        ptr[j].setBrand(b);

        cout << "Enter Product Type: ";
        cin >> t;
        ptr[j].setType(t);

        cout << "Enter Product Quantity: ";
        cin >> q;
        ptr[j].setQuantity(q);

        cout <<  "Enter Product Price: ";
        cin >> pr;
        ptr[j].setPrice(pr);
    }
    for(j= 0; j<sizes; j++)
    {
        if (ptr[j].getPrice()> 40)
        {
            ptr[j].Display();
        }
        else
        {
            cout << "\nProduct Price is Under 40\n" ;
        }
    }

    cout << "\n2.(a)" << endl;
    string BrandName;
    cout << "\nEnter Brand Name: ";
    cin >> BrandName;

    bool flag = false;

    for(i= 0; i<sizes; i++)
    {
        if (ptr[i].getBrand() == BrandName)
        {
            ptr[i].Display();
            flag = true;
        }

    }
    cout << "\n2.(b)" << endl;
    for(i= 0; i<sizes; i++)
    {
        double asset = ptr[i].getQuantity() *  ptr[i].getPrice();
        cout << "For Product no " << (i+1) << " Asset " << asset << endl;
    }
    cout << "\n2.(c)" << endl;
    int sum = 0;
    for(i= 0; i<sizes; i++)
    {
        double asset = ptr[i].getQuantity() *  ptr[i].getPrice();
        sum = sum + asset;
    }
    cout << "Total Asset: " << sum << endl;

    delete[] ptr;
    return 0;

}


