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

bool isPalindrome(string &s){
	int n = s.size();
	for(int i=0;i<(n/2);i++){
		if(s[i]!=s[n-1-i]) return false;
	}
	return true;
}


string solve(string &s){

	int n = s.size();
	if(isPalindrome(s)) return s;



	string ans = "";
	ans +=s[0];

	int j = 0;

	while(j<n){

		int cnt = 1;
		int i = j-1, k = j+1;

		while(i>=0 && k<n){
			if(s[i]==s[k]){
				cnt+=2;
				if(i-1<0 || k+1>=n || s[i-1]!=s[k+1]){
					if(cnt > ans.size()){
						ans = s.substr(i, k-i+1);
					}
				break;
				}	
			}else{
				break;
			}

			i--;
			k++;

		} 


		j++;


	}
	j=0;
	while(j<n){

		int cnt = 0;
		int i = j-1, k = j;

		while(i>=0 && k<n){
			if(s[i]==s[k]){
				cnt+=2;
				if(i-1<0 || k+1>=n || s[i-1]!=s[k+1]){
					if(cnt > ans.size()){
						ans = s.substr(i, k-i+1);
					}
				break;
				}	
			}else{
				break;
			}

			i--;
			k++;

		} 


		j++;


	}


	return ans;


}



int main()
{
	string s = "babad";
	// string s = "cbbd";
	string ans = solve(s);

	deb(ans);

	return 0;
}