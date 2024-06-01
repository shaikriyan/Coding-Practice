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

bool solve(string &s, string &goal){

	if(s.size()!=goal.size()) return false;


	int n = s.size();

	// no of times the second str is rotated
	int gap = -1;


	for(int i=0;i<n;i++){
		if(s[0]==goal[i] && s[1]==goal[(i+1)%n] && s[n-1]==goal[(i-1+n)%n]){
			gap = i;
			break;
		}
	}

	if(gap== -1) return false;


	for(int i=0;i<n;i++){

		int ind = i + gap;
		ind = ind%n;

		if(s[i]!=goal[ind]) return false;

	}

	return true;

}



int main()
{

	string s = "bbbacddceeb";
	string goal = "ceebbbbacdd";

	bool ans = solve(s, goal);
	deb(ans);
	return 0;
}