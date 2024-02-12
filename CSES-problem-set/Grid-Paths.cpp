#include <iostream>
using namespace std;

const int GRID_SIZE = 9;
bool vis[GRID_SIZE][GRID_SIZE];
string s; 

int recur(int r, int c, int idx) {
    if ((vis[r][c - 1] && vis[r][c + 1]) &&
	    (!vis[r - 1][c] && !vis[r + 1][c]))
		return 0;
	if ((vis[r - 1][c] && vis[r+ 1][c]) &&
	    (!vis[r][c - 1] && !vis[r][c + 1]))
		return 0;

    // if all cells are visited
    if(idx == 48) {
        if(r == 7 && c == 1) {
            return 1;
        }
        return 0;
    }

    // if that index is visited before visiting all the other cells
    if(r == 7 && c == 1) return 0;

    vis[r][c] = true;
    int ret = 0;
    if(s[idx] == '?') {
        // then you can do any operation down, up, left or right
        //cout<<"Fuck off    ";
        if(!vis[r-1][c]) ret += recur(r-1,c,idx+1);
        if(!vis[r][c-1]) ret += recur(r,c-1,idx+1);
        if(!vis[r+1][c]) ret += recur(r+1,c,idx+1);
        if(!vis[r][c+1]) ret += recur(r,c+1,idx+1);
    } else if(s[idx] == 'U') {
        if(!vis[r-1][c]) ret += recur(r-1,c,idx+1);
    } else if(s[idx] == 'D') {
        if(!vis[r+1][c]) ret += recur(r+1,c,idx+1);
    } else if(s[idx] == 'L') {
        if(!vis[r][c-1]) ret += recur(r,c-1,idx+1);
    } else {
        if(!vis[r][c+1]) ret += recur(r,c+1,idx+1);
    }
    vis[r][c] = false;

    return ret;
}

int main()
{
    cin>>s;
    for(int i = 0; i < GRID_SIZE; i++) {
        vis[0][i] = true;
		vis[8][i] = true;
		vis[i][0] = true;
		vis[i][8] = true;
    }

    for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) { vis[i][j] = false; }
	}

    int r = 1, c = 1, idx = 0;
    int ans = recur(r, c, idx);
    cout<<ans<<endl;

    return 0;
}