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


void solve(int i, int j, int N, vector<vector<int>>&mat, 
	string &temp, vector<string>&ans){

	// Base condition
	if(i==N-1 && j==N-1){
		ans.push_back(temp);
		return;
	}

	int di[] = {1, 0, 0 , -1};
	int dj[] = {0, -1, 1, 0};
	string str = "DLRU";

	for(int k=0;k<4;k++){
		int ii = i + di[k];
		int jj = j + dj[k];

		if(ii>=0 && ii<N && jj>=0 && jj<N && mat[ii][jj]==1){
			mat[ii][jj] = 0;
			temp +=str[k];
			solve(ii,jj, N, mat, temp, ans);
			mat[ii][jj] = 1;
			temp.pop_back();
		}

	}



}


int main()
{
	
	int N = 4;

	vector<vector<int>>mat = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};

	string temp="";

	vector<string>ans;

	solve(0,0,N, mat, temp, ans);

	for(auto it : ans){
		cout<<it<<endl;
	}cout<<endl;


	return 0;
}