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






int solve(int n, vector<int>&nums, vector<int>&dp){

	// base conditions
	if(n==0) return 0;
	if(n==1) return abs(nums[0]-nums[1]);
	if(n==2) return abs(nums[0]-nums[2]);

	if(dp[n]!=-1) return dp[n];

	int oneStepEnergy = abs(nums[n]-nums[n-1]) + solve(n-1, nums,dp);
	int twoStepEnergy = abs(nums[n]-nums[n-2]) + solve(n-2, nums,dp);

	return dp[n] = min(oneStepEnergy, twoStepEnergy);

}


int solveTabulation(int n, vector<int>&nums){

	vector<int> dp(n, -1);

	// base case
	dp[0] = 0;
	dp[1] = abs(nums[0]-nums[1]);
	dp[2] = abs(nums[0]-nums[2]);

	for(int i=3;i<n;i++){

		int oneStepEnergy = abs(nums[i]-nums[i-1]) + dp[i-1];
		int twoStepEnergy = abs(nums[i]-nums[i-2]) + dp[i-2];

		dp[i] = min(oneStepEnergy, twoStepEnergy);
	}
	return dp[n-1];


}




int main()
{

	int n = 4;
	vector<int>height = {10, 20, 30, 10};
	
	vector<int>dp(n, -1);
	int ans = solve(n-1, height, dp);
	deb(ans);

	ans = solveTabulation(n, height);
	deb(ans);



	return 0;
}