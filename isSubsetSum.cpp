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



bool solve(int ind, int sum,  vector<int>&nums, vector<vector<int>>&dp){


	if(ind==0) return nums[ind]==sum;
	if(dp[ind][sum]!=-1) return dp[ind][sum];

	
	bool pick =  solve(ind-1, sum-nums[ind], nums, dp);
	
	bool notPick = solve(ind-1, sum, nums, dp);

	return dp[ind][sum] = (pick | notPick);

}










int main()
{

	// vector<int> nums = {3, 34, 4, 12, 5, 2};
	// vector<int> nums = {11, 4, 4, 12, 5, 2};
	vector<int> nums = {16, 15, 12, 16, 4, 20, 16};
	int n = nums.size();
	int sum = 21;
	vector<vector<int>>dp(n, vector<int>(sum+1, -1));
	bool ans = solve(n-1, sum,  nums, dp);
	deb(ans);

	return 0;
}