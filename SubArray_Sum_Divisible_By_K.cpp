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



// pending...
vector<vector<int>> solve(vector<int>&nums, int k){


	int n = nums.size();
	vector<vector<int>>ans;

//  print all the sub Arrays 
	// for(int i=0;i<n;i++){
	// 	for(int j=i;j<n;j++){
	// 		vector<int>temp;
	// 		for(int k=i;k<=j;k++){
	// 			temp.push_back(nums[k]);
	// 		}
	// 		ans.push_back(temp);
	// 	}
	// }


	// for(int i=0;i<n;i++){
	// 	vector<int>temp;
	// 	long long sum =0;
	// 	for(int j=i;j<n;j++){
	// 		sum+=nums[j];
	// 		temp.push_back(nums[j]);

	// 		if(sum%k==0){
	// 			ans.push_back(temp);
	// 		}

	// 	}
	// }

	long long sum = 0;
	vector<int>prefix;
	for(int i=0;i<n;i++){
		sum+=nums[i];
		prefix.push_back(sum);
	}

	deb(prefix);
	return ans;


}






int main()
{
	vector<int> nums = {4,5,0,-2,-3,1};
	int k = 5;

	vector<vector<int>> ans = solve(nums, k);

	for(auto it : ans){
		deb(it);
	}

	return 0;
}