// FIRST APPROACH
//*******************************
// *************************
// RTE
//****************************
// ***************************

// #include <iostream>
// //#include <bits/stdc++.h>
// #include <vector>
// using namespace std;

// #define ll long long
// vector<vector<int> > mem;

// bool recur(vector<int>&nums, ll oneSetSum, int idx, vector<bool>&vec) {
//     if(oneSetSum < 0) return false;
//     if(oneSetSum == 0) return true;
//     if(idx >= nums.size()) return false;
//     if(mem[idx][oneSetSum] == 2) return true;
//     if(mem[idx][oneSetSum] == 1) return false;

//     // not take it
//     vec[idx] = true;
//     bool ans = recur(nums, oneSetSum-nums[idx], idx+1, vec);
//     if(ans) { mem[idx][oneSetSum] = 2; return true; }
//     vec[idx] = false;

//     // take it
//     ans = recur(nums, oneSetSum, idx+1, vec);
//     if(ans) { mem[idx][oneSetSum] = 2; }
//     else { mem[idx][oneSetSum] = 1; }
//     return ans;
// }

// int main()
// {
//     int n;
//     cin>>n;

//     if(n == 1) {
//         cout<<"NO\n";
//     } else {
//         ll sum = (ll)n*(n+1)/2;
//         if(sum % 2 == 1) {
//             cout<<"NO\n";
//         } else {
//             ll oneSetSum = sum/2;

//             vector<int>nums(n);
//             for(int i = 0; i < n; i++) {
//                 nums[i] = i+1;
//             }

//             // 0/1 knapsack
//             vector<bool>vec(n, false);
//             mem.resize(n+1, vector<int>(oneSetSum+1, false));
//             bool ans = recur(nums, oneSetSum, 0, vec);
//             if(!ans) cout<<"NO\n";
//             else {
//                 cout<<"YES\n";
//                 int count = 0;
//                 for(auto x: vec) {
//                     if(x) count++;
//                 }
//                 cout<<count<<endl;
//                 for(int i = 0; i < n; i++) {
//                     if(vec[i]) {
//                         cout<<i+1<<" ";
//                     }
//                 }
//                 cout<<endl<<n-count<<endl;
//                 for(int i = 0; i < n; i++) {
//                     if(!vec[i]) {
//                         cout<<i+1<<" ";
//                     }
//                 }
//                 cout<<endl;
//             }
//         }
        
//     }

//     return 0;
// }


// **************************************************************************************************************************
// **************************************************************************************************************************
// **************************************************************************************************************************
// AND
// THE
// SMARTER APPROACH
// HERE WE GO

#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;

    ll sum = (ll)n*(n+1)/2;
    if(sum%2 == 1) {
        cout<<"NO\n";
    } else {
        vector<int> a, b;
        if(n%2 == 0) {
            // for even numbers
            bool flow = true;
            for(int i = 1; i <= n/2; i++) {
                if(flow) {
                    a.push_back(i);
                    a.push_back(n-i+1);
                } else {
                    b.push_back(i);
                    b.push_back(n-i+1);
                }
                flow = !flow;
            }
        } else {
            // for odd numbers
            bool flow = true;
            for(int i = 1; i <= n/2; i++) {
                if(flow) {
                    a.push_back(i);
                    a.push_back(n-i);
                } else {
                    b.push_back(i);
                    b.push_back(n-i);
                }
                flow = !flow;
            }
            if(flow) {
                a.push_back(n);
            } else {
                b.push_back(n);
            }
        }
        cout<<"YES\n";
        cout<<a.size()<<endl;
        for(int x: a) cout<<x<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for(int x: b) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}
