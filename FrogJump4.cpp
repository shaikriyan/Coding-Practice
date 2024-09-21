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





int solve(int n, int k, vector<int>&nums, vector<int>&dp){


	if(n==0) return 0;

	if(dp[n]!=-1) return dp[n];

	int minCost = INT_MAX;
	for(int i=1;i<=k;i++){

		if(n-i>=0){
		int cost = solve(n-i, k, nums, dp) + abs(nums[n]-nums[n-i]);
		minCost = min(minCost, cost);

		}
	}
	return dp[n] = minCost;


}















int main()
{

	int n = 5;
	int k = 3;
	vector<int> heights = {10, 30, 40, 50, 20};
	vector<int>dp(n, -1);

	int ans = solve(n-1, k, heights, dp);
	deb(ans);

	return 0;
}