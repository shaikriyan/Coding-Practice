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

	unordered_map<char, int>umap = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

	int i = n-1;
	int j = n-1;
	int ans = 0;

	while(i>=0){

		if(s[i]==s[j]){
			i--;
		}
		else{
			int len = j - i;
			if(umap[s[i]] > umap[s[j]]){
				ans += (umap[s[j]] * len);
				j = i;
			}	
			else {
				// six constraints scenario mentioned in the question

				// All the roman patterns will be valid patters 
				ans += ((umap[s[j]] * len) - umap[s[i]]);
				i--;
				j = i;
			}
		}
	

	}

	if(j>=0){
		int len = j - i;
		ans += (umap[s[j]]*len);
	}

	return ans;



}



int main()
{

	// string s = "LVIII";
	// string s = "MCMXCIV";
	string s = "IV";
	int ans = solve(s);
	deb(ans);

	return 0;
}