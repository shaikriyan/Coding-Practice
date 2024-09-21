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



int solve(int start, int ind , vector<int>&nums, vector<int>&dp){

	if(ind<start) return 0;
	if(dp[ind]!=-1) return dp[ind];


	int pick = nums[ind] + solve(start, ind-2, nums, dp);
	int notPick = solve(start, ind-1, nums, dp);

	return dp[ind] = max(pick, notPick);

}






int main()
{

	vector<int>nums = {1,2,3,1};
	

	int n = nums.size();
	vector<int>dp1(n, -1);
	int end = n-1;
	int start = 1;


	int ans1 = solve(start, end, nums, dp1);
	
	start = 0;
	end = n-2;

	vector<int>dp2(n, -1);
	int ans2 = solve(start, end, nums, dp2);


	deb(ans1);
	deb(ans2);

	return 0;
}