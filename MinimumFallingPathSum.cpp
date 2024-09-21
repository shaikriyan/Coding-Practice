#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}
template<typename T, typename V> void print(pair<T,V> pr){ cout<<"{ "; print(pr.first); cout<<" : "; print(pr.second); cout<<" },"; }
template<typename T> void print(vector<T> v){ cout<<"[ "; for(auto it : v){ print(it); cout<<" "; } cout<<"]"; }
template<typename T> void print(set<T> v){ cout<<"[ "; for(auto it :v){ print(it);cout<<" "; } cout<<"]"; }
template<typename K, typename V> void print(unordered_map<K, V> umap){ cout<<"{ "; for(auto it : umap){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename K, typename V> void print(map<K, V> mp){ cout<<"{ "; for(auto it : mp){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename T> void print(stack<T> st){ cout<<"[ "; while(!st.empty()){ print(st.top());cout<<" "; st.pop(); } cout<<"]"; }



int solve(int r, int c, int n, vector<vector<int>>&matrix, vector<vector<int>>&dp){

	if(r==n-1) return matrix[r][c];

	if(dp[r][c]!=-1) return dp[r][c];

	// I have 3 options to expore

	int left = INT_MAX;
	int down = INT_MAX;
	int right = INT_MAX;



	if(c-1>=0) left = solve(r+1, c-1, n, matrix, dp);

	if(c+1<=n-1) right = solve(r+1, c+1, n, matrix,dp);

	down = solve(r+1, c, n, matrix,dp);

	return dp[r][c] = matrix[r][c] + min(down , min(left, right));

}


int solveTabulation(vector<vector<int>>&matrix){

	int n = matrix.size();
	vector<vector<int>>dp(n, vector<int>(n, -1));

	for(int i=0;i<n;i++){
		dp[n-1][i] = matrix[n-1][i];
	}



	for(int r=n-2;r>=0;r--){
		for(int c= 0;c<n;c++){

	int left = INT_MAX;
	int down = INT_MAX;
	int right = INT_MAX;



	if(c-1>=0) left = dp[r+1][c-1];

	if(c+1<=n-1) right = dp[r+1][c+1];

	down = dp[r+1][c];

	dp[r][c] = matrix[r][c] + min(down , min(left, right));
 
		}
	}

	int ans = INT_MAX;
	for(int i=0;i<n;i++){
		ans = min(ans , dp[0][i]);
	}

	return ans;

}





int main()
{

	vector<vector<int>>matrix = {{2,1,3},{6,5,4},{7,8,9}};
	int n = matrix.size();
	

	int ans = INT_MAX;
		vector<vector<int>>dp(n, vector<int>(n, -1));
	for(int col=0; col<n; col++){
		ans = min(ans, solve(0,col, n, matrix, dp));
	}

	deb(ans);


	ans = solveTabulation(matrix);
	deb(ans);

	return 0;
}