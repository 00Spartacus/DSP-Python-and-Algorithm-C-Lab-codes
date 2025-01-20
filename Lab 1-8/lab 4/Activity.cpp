#include<bits/stdc++.h>
using namespace std;


struct Act{
	int start, end;
};


bool cmp(Act a, Act b)
{
	if(a.end < b.end) return 1;
	else return 0;
}

int main()
{
    int n;
	cin >> n;
	
	Act arr[n+5];
	
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].start >> arr[i].end;
	}	
	
	
	sort(arr,arr+n,cmp);
	
	
	int i = 0;
	
	cout << arr[i].start << ", "<<arr[i].end<<endl;
	
	for(int j = 1 ; j < n ; j++)
	{
		if(arr[i].end <= arr[j].start)
		{
			cout << arr[j].start << ","<<arr[j].end << "\n";
			i = j;
		}
	 } 
	 
	 cout << endl;
}
