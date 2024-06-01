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



void solve(vector<int>&nums){


	int n = nums.size();

	for(int i=0;i<n;i++){

		int tmp = nums[i];
		int ind = i;

		for(int j=i+1;j<n;j++){
			if(nums[j] < tmp){
				tmp = nums[j];
				ind = j;
			}
		}	

		swap(nums[ind], nums[i]);
	}

}




int main()
{

	// vector<int> nums = {4, 1, 3, 9, 7};
	vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	solve(nums);

	deb(nums);

	return 0;
}