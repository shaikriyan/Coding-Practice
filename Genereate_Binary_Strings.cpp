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


void solve(int K, string &temp, vector<string> &ans){

	if(temp.size()==K){
		ans.push_back(temp);
		return;
	} 

	temp.push_back('0');
	solve(K, temp, ans);
	temp.pop_back();

	if(temp[temp.size()-1]!='1'){
		temp.push_back('1');
		solve(K, temp, ans);
		temp.pop_back();
	}

	return;

}

int main()
{

	int K = 3;
	vector<string>strs;
	string temp = "";
	solve(K, temp, strs);

	for(auto it : strs){
		deb(it);
	}

	return 0;
}