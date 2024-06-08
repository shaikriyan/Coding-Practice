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

void solve(int ind, int n, vector<int> &nums, vector<int>&temp, vector<vector<int>>&ans){


	if(ind>=n){
		ans.push_back(temp);
		return;
	}

	temp.push_back(nums[ind]);
	solve(ind+1, n, nums, temp, ans);

	temp.pop_back();
	solve(ind+1, n, nums, temp, ans);

	return;
}




int main()
{

	vector<int> nums = {1,2,3};
	vector<int>temp;
	vector<vector<int>>ans;

	solve(0, nums.size(), nums, temp, ans);

	for(auto it : ans){
		deb(it);
	}

	return 0;
}