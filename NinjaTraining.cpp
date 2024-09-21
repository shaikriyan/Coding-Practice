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



int solve(int r, vector<vector<int>>&grid, int last, vector<vector<int>>&dp){

	// base condition
	if(r<0) return 0;
	if(last!=-1 && dp[r][last]!=-1) return dp[r][last];

	int running = INT_MIN, fighting = INT_MIN, newMove = INT_MIN;


	if(last!=0) running = grid[r][0] + solve(r-1, grid, 0, dp);

	if(last!=1) fighting = grid[r][1] + solve(r-1, grid, 1, dp);

	if(last!=2) newMove = grid[r][2] + solve(r-1, grid, 2, dp);


	return dp[r][last] = max(newMove, max(running, fighting));


}












int main()
{
	// vector<vector<int>>grid = {{1,2,5},{3,1,1},{3,3,3}};
	vector<vector<int>>grid = {{10,40,70},{20,50,80},{30,60,90}};
	int n = grid.size();

	vector<vector<int>>dp(n, vector<int>(3+1, -1));
	int last = 3;

	int ans = solve(n-1, grid, last,dp);

	for(auto it : dp){
		deb(it);
	}


	deb(ans);

	return 0;
}