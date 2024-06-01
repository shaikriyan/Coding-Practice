#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}

template<typename T>
void print(vector<T> v){
	cout<<"[ ";
	for(int i=0;i<v.size();i++){
		print(v[i]);
		cout<<" ";
	}
	cout<<"]";
}

bool solve(string &s, string &t){

	if(s.size() != t.size()) return false;

	unordered_map<char, char>umap;
	int n = s.size();

	for(int i =0;i<n;i++){

		if(umap.find(s[i])!=umap.end()){
			if(umap[s[i]] != t[i]) return false;
		}
		else{
			umap[s[i]] = t[i];
		}

	}

	return true;




}


int main()
{

	string s = "badc";
	string t = "baba";

	bool ans = solve(s, t) & solve(t, s);
	deb(ans);


	return 0;
}