#include<bits/stdc++.h>
using namespace std;

// Structure to store job details
struct Job {
    char a; // Job identifier
    int dl; // Deadline of the job
    int profit; // Profit earned by completing the job
};

// Comparator function to sort jobs based on profit in descending order
bool cmp(Job a, Job b) {
    return a.profit > b.profit; // Job with higher profit comes first
}

int main() {
    int n;
    cin >> n; // Input the number of jobs
    
    // Array of jobs
    Job job[n + 5];
    
    // Input the job details: job identifier, deadline, and profit
    for (int i = 0; i < n; i++) {
        cin >> job[i].a >> job[i].dl >> job[i].profit; // Job 'a', Deadline 'dl', Profit 'profit'
    }

    // Sort the jobs in descending order based on profit using the comparator function
    sort(job, job + n, cmp);
    
    vector<char> ans; // Vector to store the sequence of jobs in the result
    int pr = 0; // Variable to store the total profit
    vector<bool> slot(n, 0); // Array to track which slots are occupied (initialized to 0)

    // Loop through the jobs to schedule them
    for (int i = 0; i < n; i++) {
        // Try to find a free slot for this job starting from the last possible slot (job's deadline)
        for (int j = min(n, job[i].dl) - 1; j >= 0; j--) {
            if (!slot[j]) { // If the slot is free
                slot[j] = 1; // Mark the slot as occupied
                pr += job[i].profit; // Add the job's profit to the total profit
                ans.push_back(job[i].a); // Add the job identifier to the result
                break; // Exit the loop since the job is scheduled
            }
        }
    }

    // total profit
    cout << pr << endl;

    // the sequence of jobs selected
    for (int i = 0; i < ans.size(); i++) 
        //Selected job id sequence
        cout << ans[i] << " ";
    
    cout << endl;

    return 0;
}
