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


/*void solve(int ind, int n, vector<int>&nums, int sum, vector<int>&ans){

	if(ind==n){
		ans.push_back(sum);
		return;
	}

	solve(ind+1, n, nums, sum+nums[ind], ans);
	solve(ind+1, n, nums, sum, ans);
	return;
}






vector<int> helper(vector<int>&nums, int n){
	vector<int>ans;
	long long sum = 0;
	solve(0, n, nums, sum, ans);
	return ans;
}
*/


void solve(int ind, int n, vector<int>&nums, vector<int> &temp, vector<vector<int>>&ans){

	ans.push_back(temp);

	for(int i=ind;i<n;i++){
		if(i!=ind && nums[i]==nums[i-1]) continue;

		temp.push_back(nums[i]);
		solve(i+1, n, nums, temp, ans);
		temp.pop_back();
	}

	return;
}

vector<vector<int>> helper(vector<int>&nums, int n){
	sort(nums.begin(), nums.end());
	vector<vector<int>>ans;
	vector<int>temp;
	solve(0, n, nums, temp, ans);
	return ans;
}









int main()
{

	vector<int> nums = {1,2,2};
	int n = nums.size();
	vector<vector<int>> ans = helper(nums, n);
	deb(ans);

	return 0;
}