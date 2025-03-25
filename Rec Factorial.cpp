/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int factorial(int n){
    if( n==1 || n==0 ) 
        return 1;
    
    int x = n*factorial(n-1);
    return x;
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<endl;
    int ans = factorial(n);
    cout<<"The factorial of your no. is "<<ans;
    return 0;
}