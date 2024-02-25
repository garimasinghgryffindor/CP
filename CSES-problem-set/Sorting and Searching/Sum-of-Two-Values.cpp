#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;  cin>>n;
    long val;    cin>>val;
    vector<pair<int, int> >vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i].first;
        vec[i].second = i+1;
    }

    sort(vec.begin(), vec.end());

    int l = 0, r = n-1;
    long sum = 0;
    while(l < r) {
        sum = (long)vec[l].first + vec[r].first;
        if(sum == val) {
            cout<<vec[l].second<<" "<<vec[r].second<<endl;
            break;
        } else if(sum < val) {
            l++;
        } else {
            r--;
        }
    }

    if(sum != val) {
        cout<<"IMPOSSIBLE\n";
    }

    return 0;
}