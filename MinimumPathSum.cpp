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




int solve(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&dp){

	if(r==0 && c==0) return grid[r][c];
	if(dp[r][c]!=-1) return dp[r][c];

	int top = INT_MAX, left = INT_MAX;

	if((r-1)>=0){
		top = solve(r-1, c, grid, dp);
	}

	if((c-1)>=0){
		left = solve(r, c-1, grid,dp);
	}

	return dp[r][c] = grid[r][c] + min(top, left);



}













int main()
{

	
	// vector<vector<int>>grid = {{1,3,1},{1,5,1},{4,2,1}};
	vector<vector<int>>grid = {{1,2,3},{4,5,6}};

	int m =  grid.size();
	int n = grid[0].size();
	vector<vector<int>>dp(m, vector<int>(n, -1));

	int ans = solve(m-1, n-1, grid,dp);

	deb(ans);



	return 0;
}