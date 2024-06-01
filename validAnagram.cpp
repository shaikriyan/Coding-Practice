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

	vector<int>hash(256, 0);


	for(auto it : s){
		hash[it]++;
	}

	for(auto it : t){
		hash[it]--;
	}

	for(auto it : hash){
		if(it!=0) return false;
	}

	return true;

}



int main()
{
	string s = "anagram";
	string t = "nagaram";

	bool ans = solve(s, t);

	deb(ans);

	return 0;
}