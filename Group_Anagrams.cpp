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

bool checkAnagrams(string &s, string &t){

	if(s.size() != t.size()) return false;
	int n = s.size();
	vector<int>hash(26, 0);
	for(auto it : s) hash[it-'a']++;
	for(auto it : t) hash[it-'a']--;
	for(auto it : hash) if(it) return false;
	return true;
}


vector<vector<string>> solve(vector<string>&strs){

	int n = strs.size();
	vector<vector<string>>ans;
	if(n==0) return ans;

	vector<bool>vis(n, 0);

	for(int i=0;i<n;i++){

		vector<string> temp;
		if(!vis[i]){
			 temp.push_back(strs[i]);
			 vis[i] = true;
		}

		for(int j=i+1;j<n;j++){
			if(!vis[j] && checkAnagrams(strs[i], strs[j])){
				temp.push_back(strs[j]);
				vis[j] = true;
			}
		}

		if(temp.size()) ans.push_back(temp);
	}

	return ans;

}

int main()
{

	// vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	vector<string> strs = {""};
	vector<vector<string>> ans = solve(strs);

	for(auto it : ans){
		deb(it);
	}

	// string s = "eat";
	// string t = "tan";
	// bool check = checkAnagrams(s,t);
	// deb(check);

	return 0;
}