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



vector<vector<int>> solve(vector<int>&nums ){

	vector<vector<int>>ans;
	int n = nums.size();

	for(int i=0;i<pow(2, n);i++){

		vector<int>temp;
		// deb(i);

		for(int k=0;k<=31;k++){
			if((i & (1<<k))) temp.push_back(nums[k]);
		}

		ans.push_back(temp);
	}
	return ans;

}






int main()
{

	vector<int> nums = {1,2,3};
	vector<vector<int>>ans = solve(nums);

	for(auto it : ans){
		deb(it);
	}


	return 0;
}