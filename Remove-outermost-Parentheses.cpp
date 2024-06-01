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

	int i=0;
	stack<char>st;
	int st_size = 0;
	string ans = "";
    bool added = false;
	while(i<n){

        added = false;

		if(s[i]=='('){
			st.push(s[i]);
			st_size++;	
		} 
		else if(s[i]==')'){
			if(st_size>1){
                ans.push_back(s[i]);
                added = true;
            } 
			st.pop();
			st_size--;	
		} 
		if(st_size!=0 && st_size!=1 && !added) ans.push_back(s[i]);
		i++;

	}
	return ans;

}


int main()
{

	string s = "(()(()))";
	string ans = solve(s);
	deb(ans);

	return 0;
}