#include<iostream>
using namespace std;
int GCD(int n1, int n2)
{
    if (n2 == 0)
    {
        return n1;
    }
    else
    {
        return
            GCD(n2,n1%n2);
    }
}
int main()
{
    int number1, number2;
    cout <<"Enter 1st Number: ";
    cin >>
        number1;
    cout <<"Enter 2nd Number: ";
    cin >> number2;
    int gcd = GCD(number1,number2);
    cout << "GCD: " << gcd;
    return 0;
}
