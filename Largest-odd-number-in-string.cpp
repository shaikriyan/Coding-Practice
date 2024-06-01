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

	int n = s.size();
	string ans = "";
	int i= n-1;
	while(i>=0){

		int x = s[i] - '0';
		if(x&1){
			ans = s.substr(0, i+1);
			break;
		}

		i--;
	}
	return ans;

}

int main()
{

	string s = "35427";
	string ans = solve(s);
	deb(ans);

	return 0;
}