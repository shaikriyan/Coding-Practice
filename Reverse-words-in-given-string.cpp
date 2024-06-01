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

	stack<string>st;

	int i=0;
	string temp = "";
	while(i<s.size()){

		if(s[i]==' '){
			if(temp.size()>0) st.push(temp);
			temp = "";
		}
		else{
			temp = temp + s[i];
		}

		i++;


	}

	if(temp.size()>0) st.push(temp);

	string ans = "";

	while(!st.empty()){
		ans +=st.top();
		st.pop();
		if(!st.empty()) ans +=" ";
	}

	return ans;

}


int main()
{
	string s = "the sky is blue";
	string ans = solve(s);

	deb(ans);

	return 0;
}