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


// void solve(int ind, int n, string& s){
// 	if(ind==n){
// 		cout<<s<<endl;
// 		return;
// 	}


// 	for(int i=ind;i<n;i++){
// 		char c = s[i];
// 		char d = s[ind];

// 		s[ind] = c;
// 		s[i] = d;
// 		solve(ind+1, n, s);
// 		s[ind] = d;
// 		s[i] = c;
		
// 	}

// }

bool isSafe(int r, int c, int n, vector<vector<int>>&temp){

	int i = r;
	int j = c;

	while(i>=0){
		if(temp[i][j]==1) return false;
		i--;
	}

	i = r;
	j = c;

	while(i>=0 && j>=0){

		if(temp[i][j]==1) return false;

		i--;
		j--;
	}


	i = r;
	j = c;

	while(i>=0 && j<n){
		if(temp[i][j]==1) return false;

		i--;
		j++;
	}

	return true;

}



void solve(int r, int N, vector<vector<int>>&temp, 
	vector<vector<vector<int>>>&ans,
	vector<int>&dj, vector<int>&dr, vector<int>&dl){


	if(r>=N){
		ans.push_back(temp);
		return;
	}

	// for(int j=0;j<N;j++){
	// 	if(isSafe(r, j, N, temp)){
	// 		temp[r][j] = 1;
	// 		solve(r+1, N, temp, ans);
	// 		temp[r][j] = 0;
	// 	}
	// }



	for(int j=0;j<N;j++){
		if(dj[j]!=1 && dr[r+j]!=1 && dl[N-r+j]!=1){
			dj[j] = 1;
			dr[r+j] = 1;
			dl[N-r+j] = 1;
			temp[r][j] = 1;
			solve(r+1, N, temp, ans,dj, dr, dl);
			temp[r][j] = 0;
			dj[j] = 0;
			dr[r+j] = 0;
			dl[N-r+j] = 0;
		}
	}

}


int main()
{



	int N = 4;
	vector<vector<int>>temp(N, vector<int>(N, 0));
	vector<vector<vector<int>>>ans;

	vector<int>dj(N, 0);
	vector<int>dr(2*N-2, 0);
	vector<int>dl(2*N+1, 0);




	solve(0, N, temp, ans, dj, dr, dl);




	for(auto it: ans){
		for(auto it1: it){
			for(auto it2: it1){
				cout<<it2<<" ";
			}cout<<endl;
		}cout<<endl;
	}


	
	// string s = "abc";
	// solve(0, s.size(), s);

	return 0;
}