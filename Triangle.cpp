#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}
template<typename T, typename V> void print(pair<T,V> pr){ cout<<"{ "; print(pr.first); cout<<" : "; print(pr.second); cout<<" },"; }
template<typename T> void print(vector<T> v){ cout<<"[ "; for(auto it : v){ print(it); cout<<" "; } cout<<"]"; }
template<typename T> void print(set<T> v){ cout<<"[ "; for(auto it :v){ print(it);cout<<" "; } cout<<"]"; }
template<typename K, typename V> void print(unordered_map<K, V> umap){ cout<<"{ "; for(auto it : umap){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename K, typename V> void print(map<K, V> mp){ cout<<"{ "; for(auto it : mp){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename T> void print(stack<T> st){ cout<<"[ "; while(!st.empty()){ print(st.top());cout<<" "; st.pop(); } cout<<"]"; }


int solve(int r, int c, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){

	if(r==m-1) return grid[r][c];
	if(dp[r][c]!=-1) return dp[r][c];

	// I can visit two places--> one is bottom and bottomRight


	int bottom 			= solve(r+1, c, 	m, n, grid, dp);
	int bottomRight 	= solve(r+1, c+1, 	m, n, grid, dp);

	return dp[r][c] = grid[r][c] + min(bottom, bottomRight);

}






int main()
{

	vector<vector<int>> grid = {{2},{3,4},{6,5,7},{4,1,8,3}};

	int m = grid.size();
	int n = grid[m-1].size();
	vector<vector<int>>dp(m, vector<int>(n,-1));


	int ans = solve(0, 0, m, n, grid, dp);
	deb(ans);


	return 0;
}