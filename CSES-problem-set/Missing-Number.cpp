#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n-1);
    ll sum = 0;
    for(int i = 0; i < n-1; i++) {
        int x;  cin>>x;
        vec[i] = x;
        sum += x;
    }

    ll idealSum = (ll)n*(n+1)/2;

    cout<<idealSum-sum<<endl;

    return 0;
}