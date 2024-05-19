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
string findCommonPrefix(string &a, string &b){

	string ans = "";
	int size = min(a.size(), b.size());

	for(int i=0;i<size;i++){
		if(a[i]==b[i]) ans +=a[i];
		else break;
	}

	return ans;
}


string solve(vector<string> &str){

	int n = str.size();

	string ans = str[0];

	for(int i=1;i<n;i++){
		ans = findCommonPrefix(ans, str[i]);
	}

	return ans;


}


int main()
{
	// vector<string> str = {"flower","flow","flight"};
	vector<string> str = {"dog","racecar","car"};
	string ans = solve(str);

	deb(ans);

	return 0;
}