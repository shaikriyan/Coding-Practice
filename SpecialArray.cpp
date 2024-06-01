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

bool isSpecial(vector<int>&nums, int x){
	int cnt = 0;
	for(auto it : nums) if(it>=x) cnt++;
	return (cnt==x);
}


int solve(vector<int>&nums){

	int n = nums.size();
	int ans = -1;
	for(int i=n;i>=0;i--){
		if(isSpecial(nums, i)){
			ans = i;
			break;
		}
	}
	return ans;
}




int main()
{

	// vector<int> nums = {0,4,3,0,4};
	vector<int> nums = {3,6,7,7,0};
	int x = solve(nums);
	deb(x);

	return 0;
}