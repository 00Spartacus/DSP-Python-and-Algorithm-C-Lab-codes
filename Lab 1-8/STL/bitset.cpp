#include<bits/stdc++.h>
using namespace std;


int main()
{
	bitset<8> b1(29);
	
	cout << b1 << endl;
	
	bitset<8> b2;
	
	cout << b2 << endl;
	
	cout << b1.all() << endl;
	
	cout << b1.any() << endl;
	
	cout << b1.none() << endl;
}
