#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void recur(int n, int &res,int j,vector<string>temp,int ans) {
    if(ans == n) {
        //res.insert(temp);
        res++;
        return;
    }
    
    for(int k=0 ; k<n ; k++) {
            
        int flag = 1;

        int x = k;
        int y = j;

        if(temp[x][y] == '*') continue;

        // validation check over here for the index (x,y)
        // checking rows and cols
        for(int k=0 ; k<n ; k++) {
            if(temp[x][k] == 'Q' || temp[k][y] == 'Q') {
                // not valid
                flag = 0;
                break;
            }
        }

        // checking diagonal elements
        int u = x, v = y;
        // towards top-left
        while(u>=0 && v>=0) {
            if(temp[u][v] == 'Q') {
                // not valid
                flag = 0;
                break;
            }
            u--, v--;
        }
        u=x,v=y;
        // towards bottom-right
        while(u<n && v<n) {
            if(temp[u][v] == 'Q') {
                // not valid
                flag = 0;
                break;
            }
            u++, v++;
        }
        u=x,v=y;
        // towards top-right
        while(u>=0 && u<n && v<n && v>=0) {
            if(temp[u][v] == 'Q') {
                // not valid
                flag = 0;
                break;
            }
            u--;
            v++;
        }
        u=x,v=y;
        // towards top-left
        while(u<n && u>=0 && v>=0 && v<n) {
            if(temp[u][v] == 'Q') {
                // not valid
                flag = 0;
                break;
            }
            u++;
            v--;
        }
        // checking diagonal elements ends here
        

        if(flag == 0)
            continue;

        // valid index otherwise
        temp[x][y] = 'Q';
        ans++;

        if(ans == n) {
            res++;
            continue;
        }

        // make a recursive function call
        recur(n,res,y+1,temp,ans);

        // backtrack
        temp[x][y] = '.';
        ans--;
    }
    
}

int solveNQueens(vector<string>&board) { 
    int ans=0, res = 0;
     
    recur(8, res, 0, board, ans);
    
    return res;
}

int main()
{
    vector<string>board(8);

    for(int i = 0; i < 8; i++) {
        cin>>board[i];
    }

    int res = solveNQueens(board);
    
    cout<<res<<endl;

    return 0;
}
