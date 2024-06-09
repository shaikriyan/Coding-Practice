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


void solve(int ind, int k, int n, vector<int>&vis, vector<int>&temp, vector<vector<int>>&ans){

	if(k==0){
		if(n==0) ans.push_back(temp);
		return;
	}

	for(int i=ind;i<10;i++){
		if(n>=i){
			if(!vis[i]){
				vis[i] = 1;
				temp.push_back(i);
				solve(i+1, k-1, n-i, vis, temp, ans);
				temp.pop_back();
				vis[i] = 0;
			}
		}
		else break;
	}
	return;

}




vector<vector<int>> helper(int k, int n){

	vector<int> vis(10, 0);
	vector<int> temp;
	int ind = 1;
	vector<vector<int>>ans;

	solve(ind, k, n, vis, temp, ans);
	return ans;

}



int main()
{

	int k=4;
	int n = 1;

	vector<vector<int>> ans = helper(k, n);
	for(auto it : ans){
		deb(it);
	}

	return 0;
}