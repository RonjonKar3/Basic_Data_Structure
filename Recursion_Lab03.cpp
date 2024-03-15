#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n<=0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return Fibonacci(n-2)+ Fibonacci(n-1);
    }

}
int main(){
    int n,sum=0,i;
    cout <<"Enter the Size: ";
    cin >> n;

    for(i=0; i<n-1; i++){
        sum = sum+Fibonacci(i);
    }
    cout << "Number: " <<  sum;


    return 0;
}
