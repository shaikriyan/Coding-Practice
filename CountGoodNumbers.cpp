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




long long myPow(long long x, long long n){

	if(n==1) return x;
	long long mod = 1000000007; 


	// we will check n is odd or even.

	long long m = (n&1) ? ((n-1)/2) : (n/2);

	long long ans = myPow(((x*x)%mod), m);

	if(n&1) ans = ans * x;

	return ans%mod;

}




long long countGoodNumbersHelper(long long n){

	if(n==1) return 5;

	long long mod = 1000000007; 
	long long m = n/2;

	if(n%2==0){
		//even scenario [odds = even]
		return ((myPow(5, m) % mod) * (myPow(4, m) % mod))%mod;

	}else{
		// odd scenario [odds = n/2 , even = odd + 1]
		return ((myPow(5, m+1) % mod) * (myPow(4, m) % mod))%mod;
	}

	return -1;
}





// This was giving me the stack overflow condition.
// long long countGoodNumbers(long long n){

// 	// base condition
// 	if(n==1) return 5;

// 	int ind = n-1;
// 	long long ans = 1;

// 	if(ind&1) ans =  4 * countGoodNumbers(n-1);
// 	else ans = 5 * countGoodNumbers(n-1);

// 	return ans%(1000000000 + 7);
// }


int main()
{

	// long long n = 4;
	long long n = 806166225460393;
	int ans = countGoodNumbersHelper(n);
	deb(ans);

	return 0;
}