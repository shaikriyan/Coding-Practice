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
	if(n==0) return 0;

	stack<char>st;

	int i=0;
	int ans = 0;
	int st_size = 0;

	while(i<n){

		if(s[i]=='('){
			st.push(s[i]);
			st_size++;
			ans = max(ans, st_size);
		}
		else if(s[i]==')'){
			st.pop();
			st_size--;
		}

		i++;

	}

	return ans;

}





int main()
{

	// string s = "(1+(2*3)+((8)/4))+1";
	string s = "()(())((()()))";
	int depth = solve(s);
	deb(depth);


	return 0;
}