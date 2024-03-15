#include<iostream>
using namespace std;

class Rectangle
{
private:
    double height, width;
public:
    Rectangle() {};
    Rectangle(double height, double width)
    {
        this -> height = height;
        this -> width = width;
    };
    void setheight(double h)
    {
        height = h;
    }
    void setwidth(double w)
    {
        width = w;
    }
    double getheight()
    {
        return height;
    }
    double getwidth()
    {
        return width;
    }
    void displayArea()
    {
        double area = height*width;
        cout << "Area: " << area << endl;
    }

};

int main()
{

    double ht,wt;
    cout << "Enter Height of Rectangle: " ;
    cin >> ht ;
    cout << "Enter Width of Rectangle: ";
    cin >> wt ;

// i.
    Rectangle rectangle1(ht, wt);
    rectangle1.displayArea();

// ii.
    Rectangle *rectangle2 = new Rectangle();

    rectangle2->setheight(ht);
    rectangle2->setwidth(wt);
    rectangle2->displayArea();

// iii.
    int i, n;
    double height, width;
    cout << "\nEnter Array Size: ";
    cin >> n;
    Rectangle rectangle3[n];

    for(i=0; i<n; i++)
    {

        cout << endl;
        cout << "Enter Height of Rectangle no " << (i+1) <<": " ;
        cin >> height;
        cout << "Enter Width of Rectangle no " << (i+1) <<": " ;
        cin >> width;


        rectangle3[i] = Rectangle(height, width);
    }

    for(i=0; i<n; i++)
    {
        rectangle3[i].displayArea();
    }

    // iv.
    Rectangle *rectanglePtr;

    for(i=0; i<n; i++)
    {

        cout << endl;
        cout << "Enter Height of Rectangle no " << (i+1) <<": " ;
        cin >> height;
        cout << "Enter Width of Rectangle no " << (i+1) <<": " ;
        cin >> width;

        rectanglePtr = new Rectangle(height, width);
        rectanglePtr->displayArea();
    }

}
