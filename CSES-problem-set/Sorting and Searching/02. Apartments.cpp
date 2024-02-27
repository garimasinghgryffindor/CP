#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;    cin>>n>>m>>k;

    vector<int> applicants(n), appartments(m);

    for(int i = 0; i < n; i++) cin>>applicants[i];
    for(int i = 0; i < m; i++) cin>>appartments[i];

    sort(applicants.begin(), applicants.end());
    sort(appartments.begin(), appartments.end());

    int i = 0, j = 0, res = 0;

    while(i < n && j < m) {
        if(applicants[i] >= appartments[j]-k && applicants[i] <= appartments[j]+k) {
            i++;    j++;
            res++;
        } else if(applicants[i] < appartments[j]-k) {
            i++;
        } else {
            j++;
        }
    }

    cout<<res<<endl;

    return 0;
}
