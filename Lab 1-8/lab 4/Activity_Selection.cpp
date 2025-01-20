#include<bits/stdc++.h>
using namespace std;

// The main idea is to sort the activities based on their end times
// Then select the first activity and loop through the rest of the activities
// If the start time of the current activity is after or at the end time of the last selected activity
// Then select the current activity
//Greedy algorithm
int main()
{
    int n;
    cin >> n; //the number of activities is n
    
    // vector pair to store the start and end times of the activities
    vector<pair<int, int>> activities(n);
    
    for(int i = 0 ; i < n ; i++)
        cin >> activities[i].first >> activities[i].second; // first = start time, second = end time 
    
    // Sort the activities based on their end times using the second element of the pair
    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // Compare based on the end time (second element)
    });
    
    // Select the first activity (always included)
    int i = 0;
    cout << activities[i].first << ", " << activities[i].second << endl;
    
    // Loop through the rest of the activities and select compatible ones
    for(int j = 1 ; j < n ; j++)
    {
        // If the start time of the current activity is after or at the end time of the last selected activity
        if(activities[i].second <= activities[j].first)
        {
            cout << activities[j].first << " , " << activities[j].second << "\n";
            i = j; // Update the last selected activity
        }
    }
    cout << endl; 
}
