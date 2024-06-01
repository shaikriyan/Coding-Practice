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

int solve(string &s){

	int n = s.size();

	unordered_map<char, int>umap;

	int l=0, r=0;
	int len = 0;

	while(r<n){

		if(umap.find(s[r])==umap.end() || umap[s[r]] < l){
			umap[s[r]] = r;
			len = max(len, r-l+1);
		}
		else{
			// it is present 
			l = umap[s[r]] + 1;
			umap[s[r]] = r;
			len = max(len, r-l+1);
		}

		r++;
	}
	return len;

}



int main()
{

	string s = "abba";
	// ans = 2;

	int ans = solve(s);

	cout<<ans<<endl;


	return 0;
}