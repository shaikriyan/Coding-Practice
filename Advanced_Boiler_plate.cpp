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



int main()
{

	vector<int> nums  = {223,23,4,23,4,2,5,23,4,2};
	deb(nums);

	vector<pair<int,int>> vec_pr= {{1,2},{2,3},{3,4}};
	deb(vec_pr); 

	set<int>stt(nums.begin(), nums.end());
	deb(stt);

	set<pair<int,int>>st_pr(vec_pr.begin(), vec_pr.end());
	deb(st_pr);


	stack<int>st;
	st.push(1);
	st.push(3);
	st.push(2);
	deb(st);

	stack< pair<int, int> > stt_pr;
	stt_pr.push({2,3});
	stt_pr.push({1,6});
	stt_pr.push({6,5});
	deb(stt_pr);





	return 0;
}