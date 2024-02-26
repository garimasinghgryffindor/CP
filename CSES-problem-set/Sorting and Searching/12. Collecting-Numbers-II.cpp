#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;  cin>>n;
    int op;     cin>>op;

    vector<int>vec(n);
    vector<int>indices(n);

    for(auto &x: vec) {
        cin>>x;
        x--;
    }

    int res = 1;

    for(int i = 0; i < n; i++) {
        indices[vec[i]] = i;
    }

    for(int i = 1; i < n; i++) {
        if(indices[i-1] > indices[i]) {
            res++;
        }
    }

    for(int i = 0; i < op; i++) {
        int x, y;   cin>>x>>y;
        x--;    y--;
        int posx = indices[vec[x]],  posy = indices[vec[y]];

        if(abs(vec[x]-vec[y]) == 1) {
            // i.e; they are consecutive elements
            int mn = min(vec[x], vec[y]);
            int mx = max(vec[x], vec[y]);
            int posx = indices[mn],  posy = indices[mx];
            //x = mn; y = mx;
            if(mn != 0) {
                if(indices[mn-1] > posx) {
                    res--;
                }
                if(mn+1 != n && indices[mn+1] < posx) {
                    res--;
                }
            } else {
                if(indices[1] < indices[0]) {
                    res--;
                }
            }

            if(mx != 0) {
                if(mx+1 != n && indices[mx+1] < posy) {
                    res--;
                }
            }

        } else {
            if(vec[x] != 0) {
                if(indices[vec[x]-1] > posx) {
                    res--;
                }
                if(vec[x]+1 != n && indices[vec[x]+1] < posx) {
                    res--;
                }
            } else {
                if(indices[1] < indices[0]) {
                    res--;
                }
            }

            if(vec[y] != 0) {
                if(indices[vec[y]-1] > posy) {
                    res--;
                }
                if(vec[y]+1 != n && indices[vec[y]+1] < posy) {
                    res--;
                }
            } else {
                if(indices[1] < indices[0]) {
                    res--;
                }
            }
        }

        swap(vec[x], vec[y]);
        swap(indices[vec[x]], indices[vec[y]]);

        if(abs(vec[x]-vec[y]) == 1) {
            // i.e; they are consecutive elements
            int mn = min(vec[x], vec[y]);
            int mx = max(vec[x], vec[y]);
            int posx = indices[mn],  posy = indices[mx];
            //x = mn; y = mx;
            if(mn != 0) {
                if(indices[mn-1] > posx) {
                    res++;
                }
                if(mn+1 != n && indices[mn+1] < posx) {
                    res++;
                }
            } else {
                if(indices[1] < indices[0]) {
                    res++;
                }
            }

            if(mx != 0) {
                if(mx+1 != n && indices[mx+1] < posy) {
                    res++;
                }
            }

        } else {
            if(vec[x] != 0) {
                if(indices[vec[x]] < indices[vec[x]-1]) {
                    res++;
                }
                if(vec[x]+1 != n && indices[vec[x]+1] < posx) {
                    res++;
                }
            } else {
                if(indices[1] < indices[0]) {
                    res++;
                }
            }

            if(vec[y] != 0) {
                if(indices[vec[y]] < indices[vec[y]-1]) {
                    res++;
                }
                if(vec[y]+1 != n && indices[vec[y]+1] < posy) {
                    res++;
                }
            } else {
                if(indices[1] < indices[0]) {
                    res++;
                }
            }
        }

        cout<<res<<endl;
    }

    return 0;
}
