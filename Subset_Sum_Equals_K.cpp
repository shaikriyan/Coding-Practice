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


// bool solve(int ind, int n, vector<int>&nums, int sum, int k){

// 	if(ind==n){
// 		return (sum==k);
// 	}

// 	if(solve(ind+1, n, nums, sum+nums[ind], k)) return true;
// 	return solve(ind+1, n, nums, sum, k);
	
// }


// bool helper(vector<int>&nums, int n, int k){
// 	long long sum = 0;
// 	bool ans = solve(0, n, nums, sum, k);
// 	return ans;
// }


int solve(int ind, int n, vector<int>&nums, int sum, int k, vector<vector<int>>&dp){

	if(dp[ind][k]!=-1) return dp[ind][sum];	
	
	if(ind==n){
		return (sum==k);
	}
	

	int M = 1000000000+7;

	int pick = solve(ind+1, n, nums, sum+nums[ind], k, dp);
	int notPick = solve(ind+1, n, nums, sum, k, dp);
		
	return dp[ind][k] = (((pick%M) + (notPick%M))%M);
}


int helper(vector<int>&nums, int n, int k){
	long long sum = 0;
	vector<vector<int>>dp(n+1, vector<int>(k, -1));

	for(auto it : dp){
		deb(it);
	}
	cout<<endl;

	int ans = solve(0, n, nums, sum, k, dp);

	for(auto it : dp){
		deb(it);
	}

	return ans;
}




int main()
{

	vector<int> nums = {5, 2, 3, 10, 6, 8};
	int n = nums.size();
	int k = 10;
	int ans = helper(nums, n, k);
	deb(ans);

	return 0;
}