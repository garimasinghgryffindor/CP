#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

string recur(string s, int&k, int&n) {
    vector<bool>found(k, false);
    int count = 0;
    string res = "";
    for(char x: s) {
        if(res.size() == n) {
            return "YES";
        }
        if(!found[x-'a']) {
            count++;
            found[x-'a'] = true;
        }
        if(count == k) {
            res = res + x;
            count = 0;
            found.assign(k, false);
        }
    }
    if(res.size() == n) {
        return "YES";
    }

    string ans = "NO\n";
   
    for(int i = 0; i < k; i++) {
        if(!found[i]) {
            while(res.length() < n) {
                char x = 'a' + i;
                res = res + x;
            }
            return ans + res;
        }
    }

    return "";
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, k, m;
        cin>>n>>k>>m;
        string s;
        cin>>s;

        string ans = recur(s, k, n);
        cout<<ans<<endl;
    }

    return 0;
}
