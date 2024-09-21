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



int solve(int r, int c1, int c2, int m, int n, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){

	if(r==m) return 0;
	if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];

	vector<int> dd = {-1, 0, 1};
	int ans = INT_MIN;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){

			int dc1 = c1 + dd[i];
			int dc2 = c2 + dd[j];

			if(dc1>=0 && dc1<n && dc2>=0 && dc2<n){
				ans = max(ans, solve(r+1, dc1, dc2, m, n, grid, dp));
			}

		}
	}

	int val = (c1==c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);

	return dp[r][c1][c2] = val + ans;

}

















int main()
{

	vector<vector<int>>grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
	// vector<vector<int>>grid = {{2,3,1,2},{3,4,2,2},{5,6,3,5}};

	int m = grid.size();
	int n = grid[0].size();
	vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));


	int ans = solve(0, 0, n-1, m, n, grid, dp);
	deb(ans);


	return 0;
}