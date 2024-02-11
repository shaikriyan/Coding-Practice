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

bool isPalindrom(string s){
	int i=0;
	int j = s.size()-1;

	while(i<=j){
		if(s[i]!=s[j]) return false;
		i++;
		j--;
	}

	return true;

}

void solve(int ind, int n, string &s, vector<string>&temp, 
	vector<vector<string>>&ans){

	if(ind==n){
		ans.push_back(temp);
		return;
	}


	for(int i=ind;i<n;i++){
		string r = s.substr(ind, i+1-ind);
		if(isPalindrom(r)){
			temp.push_back(r);
			solve(i+1,n, s, temp, ans);
			temp.pop_back();
		}
	}


	return;

}

int main()
{
	
	string s = "aab";

	// cout<<isPalindrom(s)<<endl;
	// cout<<isPalindrom("madam")<<endl;

	vector<string> temp;
	vector<vector<string>>ans;

	solve(0, s.size(), s, temp, ans);

	for(auto it : ans){
		for(auto it1: it){
			cout<<it1<<" ";
		}cout<<endl;
	}cout<<endl;

	return 0;
}