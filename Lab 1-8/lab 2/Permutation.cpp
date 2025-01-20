#include<bits/stdc++.h>
using namespace std;

vector<int>nums;
vector<vector<int> > ans;
void Solve(int index)
{
	if(index >= nums.size())
	{
		ans.push_back(nums);
		return ;
	}
	
	
	for(int j = index ; j < nums.size(); j++)
	{
		swap(nums[index], nums[j]);
		
		Solve(index + 1);
		
		swap(nums[index],nums[j]);
	}
}

int main()
{
	
	int n;
	cin >> n;
	
	nums.resize(n);
	
	for(int i = 0 ; i < n ; i++)   cin >> nums[i];
	
	Solve(0);
	
	for(int i = 0 ; i < ans.size() ; i++)
	{
		for(int j = 0 ; j < ans[i].size() ; j++)
		{
			cout << ans[i][j];
		}
		cout << " ";
	}
	cout << endl;
	
	
	return 0;
	
}
