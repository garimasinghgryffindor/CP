#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }

    long long res = INT_MIN;
    long long currSum = 0;

    for(int i = 0; i < n; i++) {
        currSum += vec[i];
        res = max(res, currSum);
        if(currSum < 0) currSum = 0;
    }

    cout<<res<<endl;

    return 0;
}
