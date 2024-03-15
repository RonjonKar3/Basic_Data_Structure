#include<iostream>
using namespace std;
void Number(int n)
{
    if(n<1)
    {
        return;
    }
    else
    {
        cout << n << " ";
        return Number(n-1);
    }
}
int main()
{
    int number;
    cout <<"Enter the Number: ";
    cin >> number;
    cout
            << "Number: ";
    Number(number);
    return 0;
}
