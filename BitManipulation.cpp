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

int decToBin(int num){
	string s = "";
	string ns = "";
	vector<pair<int,int>>pr;
	long long int ans = 0;
	for(int i=31;i>=0;i--){
		int x = (num & (1<<i)) ? 1 : 0;
		s+=(to_string(x));
		ns+=(to_string(x^0^1));
		ans = ans*10 + x;
		pr.push_back({i, x});
	}
	// deb(s);
	// deb(ns);


	// deb(pr);
	// cout<<"[ "<<endl;
	// for(auto it : pr){
	// 	cout<<it.first<<" : "<<it.second<<endl;
	// }
	// cout<<"]"<<endl;

	return ans;
}

bool getIthBit(int &num, int i){
	// if 1<=i<=32
	// return (num & (1<<i-1));
	return (num & (1<<i));
}


int setIthBit(int &num, int i){
	return (num | (1<<i));
}

int toggleIthBit(int &num, int i){
	return (num ^ (1<<i));
}

int clearIthBit(int &num, int i){
	return (num & ~(1<<i));
}

int countOfSetBits(int num){

	long long ans = 0;
	while(num){
		if(num&1) ans++;
		num = num>>1;
	}

	return ans;

}


int main()
{

	// int num = 74;
	// int binNum = decToBin(num);
	// deb(num);
	// deb(binNum);


	// int IthBitStatus = getIthBit(num, 4);
	// deb(IthBitStatus);

	// cout<<endl;
	// num = setIthBit(num, 0);
	// deb(num);
	// binNum = decToBin(num);
	// deb(binNum);


	// cout<<endl;
	// num = toggleIthBit(num, 0);
	// deb(num);
	// binNum = decToBin(num);
	// deb(binNum);


	// cout<<endl;
	// num = clearIthBit(num, 6);
	// deb(num);
	// binNum = decToBin(num);
	// deb(binNum);

	int num = 75;
	int cnt = countOfSetBits(num);
	int binNum = decToBin(num);
	deb(binNum);
	deb(cnt);





	return 0;
}