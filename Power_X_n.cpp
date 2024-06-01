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

// This was throwing TLE.
double myPow(double x, int n){
	long double ans = 1;
	int dn = abs(n);
	for(int i=0;i<dn;i++){
		ans *=x;
	}
	return (n>0) ? ans : (1/ans); 
}

double solve(double x, int n){

	if(n==1) return x;
	int m = (n&1) ? ((n-1)/2) : (n/2);
	double ans =  solve(x*x, m);
	if(n&1) ans = ans * x;
	return ans;
}


double myPow2(double x, int n){
	long double ans = 1;
	int dn = abs(n);
	ans = solve(x, dn);
	return (n>0) ? ans : (1/ans); 
}







int main()
{

	double x = 2.0000;
	int n = 10;




	double ans = myPow2(x,n);
	deb(ans);

	return 0;
}