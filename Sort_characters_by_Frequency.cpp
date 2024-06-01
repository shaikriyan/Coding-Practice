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

string solve(string &s){

	int n = s.length();
	if(n==0) return s;

	// deb(n);

	// sort the string
	sort(s.begin(), s.end());

	// deb(s);

	vector<string>hash(n+1, "");

	int j=0;
	for(int i=0;i<n;i++){

		if(s[i]!=s[j]){
			int cnt = i-j;
			hash[cnt]+=s[j];
			j = i;
		}
	}

	int cnt = n-j;
	hash[cnt]+=s[j];
	j = n;


	// deb(hash);

	string ans = "";

	for(int i=n;i>=0;i--){
		string temp = hash[i];
		if(temp.size()>0){
			for(auto it : temp){
				for(int k=0;k<i;k++){
					ans+=it;
				}
			}
		}
	}

	return ans;

}


string solve2(string &s){

	int n = s.size();
	if(n==0) return s;



	// char, freq
	unordered_map<char, int>umap;

	for(auto it : s){
		umap[it]++;
	}


	vector<string>hash(n+1, "");

	for(auto it : umap){
		hash[it.second] += (it.first);
	}

	string ans = "";

	for(int i=n;i>=0;i--){
		string temp = hash[i];
		if(temp.size()>0){
			for(auto it : temp){
				for(int k=0;k<i;k++){
					ans+=it;
				}
			}
		}
	}

	return ans;




}



int main()
{

	// string s = "tree";
	string s = "Aabb";

	string ans = solve(s);
	string ans2 = solve2(s);
	deb(ans);
	deb(ans2);

	return 0;
}