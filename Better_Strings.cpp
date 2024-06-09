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


void solve(int ind, int n , string &s, string &temp, unordered_set<string>&ans){

	if(ind>=n){
		ans.insert(temp);
		return;
	}

	temp.push_back(s[ind]);
	solve(ind+1, n, s, temp, ans);
	temp.pop_back();
	solve(ind+1, n, s, temp, ans);
	return;

}






int main()
{

	string s1 = "gfg";
	string temp1 = "";
	unordered_set<string>ans1;

	solve(0, s1.size(), s1, temp1, ans1);
	// deb(ans1);


	string s2 = "ggg";
	string temp2 = "";
	unordered_set<string>ans2;

	solve(0, s2.size(), s2, temp2, ans2);
	// deb(ans2);

	int n1 = ans1.size();
	int n2 = ans2.size();

	string ans = (n1>=n2) ? s1 : s2;
	deb(ans);



	return 0;
}