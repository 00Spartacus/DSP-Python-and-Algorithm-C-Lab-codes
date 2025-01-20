#include<bits/stdc++.h>
using namespace std;

//Recursive function to find the power of a number
//using the divide and conquer approach
long long Power(int x, int n)
{
	if(n == 0) return 1;
	else if( n % 2 == 0) return Power(x,n/2) * Power(x, n/2);
	else return x * Power(x,n/2) * Power (x, n/2);
}

int main()
{
	int x, n;
	// x is the base and n is the power
	cin >> x >> n;
	cout << Power(x,n) << endl;
}