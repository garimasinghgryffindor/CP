#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<long long> ans;
    
    while(t--) {
        long long r, c;
        cin >> r >> c;

        long long mx;
        if(r > c) {
            mx = r;
        } else {
            mx = c;
        }

        bool flow = false;
        if(mx % 2 == 0) {
            flow = true;
        }

        long long prevMax = (mx - 1) * (mx - 1);
        long long res;

        if(!flow) {
            if(mx == c) {
                res = prevMax + (mx * 2 - 1 - (r - 1));
            } else {
                res = prevMax + c;
            }
        } else {
            if(mx == c) {
                res = prevMax + r;
            } else {
                res = prevMax + (mx * 2 - 1 - (c - 1));
            }
        }

        ans.push_back(res);
    }

    for(long long x : ans) {
        cout << x << endl;
    }

    return 0;
}
