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



void solve(int ind, int n, string &s, string &temp, vector<string> &ans, unordered_map<char, string> &umap){

	if(ind==n){
		ans.push_back(temp);
		return;
	}

		string x = umap[s[ind]];
		for(int j=0;j<x.size();j++){
			temp.push_back(x[j]);
			solve(ind+1, n, s, temp, ans, umap);
			temp.pop_back();
		}
	return;


}


vector<string> helper(string &str){

	vector<string> ans;
	int n = str.size();
    if(n==0) return ans;

	unordered_map<char, string>umap;
	umap['2'] = "abc";
	umap['3'] = "def";
	umap['4'] = "ghi";
	umap['5'] = "jkl";
	umap['6'] = "mno";
	umap['7'] = "pqrs";
	umap['8'] = "tuv";
	umap['9'] = "wxyz";



	int ind = 0;
	string temp = "";
	solve(ind, n, str, temp, ans, umap);
	return ans;
}



int main()
{
	string digits = "2";
	vector<string>ans = helper(digits);

	for(auto it : ans){
		deb(it);
	}

	return 0;
}