#include<iostream>
using namespace std;

void Number(int n)
{
    if(n==1)
    {
        cout << 1<< " ";
        return;
    }
    else
    {
        Number(n-1);
        cout << n << " ";
    }

}
int main()
{
    int number;
    cout <<"Enter the Number: ";
    cin >> number;

    cout << "Number: ";
    Number(number);
    return 0;
}

