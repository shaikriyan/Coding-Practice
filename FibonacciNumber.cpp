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




int solve(int n, vector<long long>&dp){
	// base condition
	int MOD = (1e9)+7;
	if(n<=1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n] = (((solve(n-1, dp) % MOD) + (solve(n-2, dp) % MOD)) % MOD);
}



long long int topDown(int n) {

    // n+1 --> +1 is for 0 index.
	vector<long long>dp(n+1, -1);
	solve(n, dp);
	dp[0] = 0;
	dp[1] = 1;
	deb(dp);
	return dp[n];
}



long long int bottomUp(int n) {
  	vector<long long>dp(n+1, -1);
  	dp[0] = 0;
  	dp[1] = 1;
  	int MOD = 1e9+7;
  	for(int i=2;i<n+1;i++){
  		dp[i] = (((dp[i-1]%MOD )+ (dp[i-2]%MOD))%MOD);
  	}
    return dp[n];
}

long long bestSolution(int n){

	if(n<=1) return n;
	long long prev2 = 0;
	long long prev = 1;
	int M = 1e9+7;

	for(int i=2;i<n+1;i++){
		int currSum = (((prev2%M) + (prev%M))%M);
		prev2 = prev;
		prev = currSum;
	}


	return prev;

}




int main()
{
	int n = 6;

	int ans = topDown(n); // T.C = O(N), S.C = O(N) + O(N)[Auxillary Space + dp array];
	int bottomUpAns = bottomUp(n); // T.C = O(N) , S.C =  O(N)[dp array]
	deb(bottomUpAns);
	deb(ans);

	ans = bestSolution(n);
	deb(ans);

	return 0;
}