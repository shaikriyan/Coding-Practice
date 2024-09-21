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



int solve(int r, int c, vector<vector<int>>&dp){


	if(r==0 && c==0) return 1;
	if(dp[r][c]!=-1) return dp[r][c];

	int top = 0, left = 0;

	// I will choose to move up.
	if((r-1)>=0){
		top = solve(r-1, c,dp);
	}

	if((c-1)>=0){
		left = solve(r, c-1,dp);
	}

	return dp[r][c] = top + left;

}













int main()
{

	int m = 3;
	int n = 7;
	vector<vector<int>>dp(m, vector<int>(n, -1));

	int ans = solve(m-1, n-1, dp);
	deb(ans);

	return 0;
}