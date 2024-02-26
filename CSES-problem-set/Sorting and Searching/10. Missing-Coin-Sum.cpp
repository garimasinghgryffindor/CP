#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;  cin>>n;
    vector<int>coins(n);

    for(int i = 0; i < n; i++) {
        cin>>coins[i];
    }

    // first brute force approach
    sort(coins.begin(), coins.end());

    long res = 0;

    for(int i = 0; i < n; i++) {
        if(res+1 >= coins[i]) {
            res = res + coins[i];
        } else {
            break;
        }
    }

    cout<<res+1<<endl;

    return 0;
}
