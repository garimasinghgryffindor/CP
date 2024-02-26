#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;  cin>>n;
    vector<int> vec(n), indices(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
        vec[i]--;
    }

    for(int i = 0; i < n; i++) {
        indices[vec[i]] = i;
    }

    int res = 1;

    for(int i = 1; i < n; i++) {
        res += indices[i] < indices[i-1];
    }

    cout<<res<<endl;

    return 0;
}