#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void recur(string s, set<string>&res, int idx) {
    if(idx == s.length()-1) {
        res.insert(s);   return;
    }

    for(int i = idx; i < s.length(); i++) {
        if(i != idx && s[i] == s[idx]) continue;
        swap(s[i], s[idx]);
        recur(s, res, idx+1);
        swap(s[i], s[idx]);
    }
}

int main()
{
    set<string> res;
    string s;   cin>>s;

    sort(s.begin(), s.end());
    recur(s,res,0);
    cout<<res.size()<<endl;
    
    for(string x: res) {
        cout<<x<<endl;
    }

    return 0;
}