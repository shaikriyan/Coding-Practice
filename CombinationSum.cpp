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


/*// When repitation is allowed.
void solve(int ind, int n, vector<int>&nums, int K, vector<int>&temp, 
	vector<vector<int>> &ans){


	if(ind>=n || K<=0){
		if(K==0) ans.push_back(temp);
		return;
	}

	if(K>= nums[ind]){
		temp.push_back(nums[ind]);
		solve(ind, n, nums, K-nums[ind], temp, ans);
		temp.pop_back();
	}
	solve(ind+1, n, nums, K, temp, ans);

	return;

}*/





// When repitation is not allowed.
void solve(int ind, int n, vector<int>&nums, int K, vector<int>&temp, 
	vector<vector<int>> &ans){

	if(ind>=n){
		if(K==0) ans.push_back(temp);
		return;
	}

	if(K>=nums[ind]){
		temp.push_back(nums[ind]);
		solve(ind+1, n, nums, K-nums[ind], temp, ans);
		temp.pop_back();
	}
	solve(ind+1, n, nums, K, temp, ans);

	return;

}



// When repitation is not allowed. CombinationSum2;
/*void solve(int ind, int n, vector<int>&nums, int K, vector<int>&temp, 
	vector<vector<int>> &ans){

	if(ind>=n || K<=0){
		if(K==0) ans.push_back(temp);
		return;
	}

	// 1 1 2 5 6 7 10 
	// _   _ _         => 1 + 2 + 5 = 8;
	//   _ _ _         => 1 + 2 + 5 = 8; 


	for(int i=ind;i<n;i++){
		if(i!=ind && nums[i]==nums[i-1]) continue;

		if(K>=nums[i]){
			temp.push_back(nums[i]);
			solve(i+1, n, nums, K-nums[i], temp, ans);
			temp.pop_back();
		}
		else break;
		
	}

	return;

}

*/




vector<vector<int>> helper(vector<int>&nums, int K){
	vector<int> temp;
	vector<vector<int>>ans;
	int ind = 0;
	int n = nums.size();
	solve(ind, n, nums, K, temp, ans);
	return ans;
}



int main()
{
	vector<int>nums = {10,1,2,7,6,1,5};
	sort(nums.begin(), nums.end());
	deb(nums);
	int target = 8;

	vector<vector<int>>ans = helper(nums, target);
	for(auto it : ans){
		deb(it);
	}

	return 0;
}