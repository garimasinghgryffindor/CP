#include <iostream>
#include <list>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int n;  cin>>n;

    list<int> ls(n);
    iota(ls.begin(), ls.end(), 1);
    vector<int>res;

    auto it = ls.begin();
    it++;
    while(ls.size()) {
        if(ls.size() == 1) {
            res.push_back(*(ls.begin()));
            break;
        }
        while(it!=ls.end()) {
            res.push_back(*it);
            it = ls.erase(it);
            if(it == ls.end()) {
                if(ls.size() == 1) {
                    break;
                }
                it = ls.begin();
                it++;
                break;
            }
            it++;
            if(it == ls.end()) {
                it = ls.begin();
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<res[i]<<" ";
    }

    return 0;
}



// USING QUEUE
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(ll N)
{
	queue<ll> q;
	// Push all the children to the queue
	for (int i = 1; i <= N; i++)
		q.push(i);

	// Set the flag to false, so that the first child does
	// not get removed
	bool flag = false;

	while (!q.empty()) {
		int ele = q.front();
		q.pop();
		// If we have to remove the element, print it
		if (flag) {
			cout << ele << " ";
		}
		// If we don't have to remove the element, push it
		// back to the queue
		else {
			q.push(ele);
		}
		// Toggle the value of flag so that only the
		// alternate elements get removed
		flag = !flag;
	}
}

int main()
{
	ll N;
    cin>>N;
	solve(N);
}
