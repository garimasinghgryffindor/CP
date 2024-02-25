#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

long long findCost(int n, vector<int>&vec) {
    long long cost = 0;
    for(auto x: vec) {
        cost += abs(x-n);
    }
    return cost;
}

int main()
{
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end());

    if(n%2 != 0) {
        int mid = vec[n/2];
        cout<<findCost(mid, vec)<<endl;
    } else {
        int mid = vec[n/2];
        long long cost1 = findCost(mid, vec);
        mid = vec[n/2-1];
        long long cost2 = findCost(mid, vec);
        cout<<min(cost1, cost2)<<endl;
    }

    // 2 3 1 5 2
    // 1 2 2 3 5
    // if 1=> 1+1+2+4 = 8
    // if 2=> 1+1+3 = 5
    // if 3=> 2+1+1+2 = 6

    // if two numbers like -> 2, 5 => your choice choose as 2 or 5 will take same cost of 3
    // if three numbers like -> 2, 3, 5 => if 2=> 1+3 = 4, if 3=>1+2 = 3, if 4=>2+1+1=4,  if 5=> 3+2 = 5
    // so therefore the answer is a number at the mid (after we sort the array)
    

    return 0;
}
