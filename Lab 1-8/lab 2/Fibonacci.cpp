#include<bits/stdc++.h>
using namespace std;

//Recursive function to find the nth Fibonacci number
int Fib(int n)
{
	//Base case
	
	if(n <=1 ) return n;
	return Fib(n-1) + Fib(n-2);
}
int main()
{
	int n;
	// n is the number of Fibonacci numbers in the series
	cin >> n;
	for(int i = 0 ; i <= n ; i++)
		cout << "Fibonacci of " << i <<" is "<< Fib(i) << endl;
	return 0;
}