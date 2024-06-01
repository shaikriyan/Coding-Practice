#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}

template<typename T>
void print(vector<T> v){ cout<<"[ "; for(int i=0;i<v.size();i++){ print(v[i]); cout<<" "; } cout<<"]"; }

template<typename T, typename V>
void print(pair<T,V> pr){ cout<<"{ "; print(pr.first); cout<<" : "; print(pr.second); cout<<" },"; }

template<typename T>
void print(set<T> v){ cout<<"[ "; for(auto it :v){ print(it);cout<<" "; } cout<<"]"; }

template<typename K, typename V>
void print(unordered_map<K, V> umap){ cout<<"{ "; for(auto it : umap){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }

template<typename K, typename V>
void print(map<K, V> mp){ cout<<"{ "; for(auto it : mp){ cout<<"{ "; print(it.first); cout<<" : "; print(it.second); cout<<" }, "; } cout<<"}"; }


int main()
{

	return 0;
}