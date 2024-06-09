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

stack<int> solve(stack<int> &st){

	if(st.size()==0) return st; 
	stack<int>ans;
	int topped = st.top();
	st.pop();
	ans = solve(st);
	stack<int>temp;
	while(!ans.empty() && ans.top()<topped){
		temp.push(ans.top());
		ans.pop();
	}

	ans.push(topped);

	while(!temp.empty()){
		ans.push(temp.top());
		temp.pop();
	}

	return ans;

}


stack<int> reverseStack(stack<int> &st){

	if(st.empty()) return st;

	int topped = st.top();
	st.pop();

	stack<int> ans = reverseStack(st);

	stack<int> temp;

	while(!ans.empty()){
		temp.push(ans.top());
		ans.pop();
	}

	ans.push(topped);

	while(!temp.empty()){
		ans.push(temp.top());
		temp.pop();
	}

	return ans;
}





int main()
{

	stack<int>s;
	s.push(11);
	s.push(2);
	s.push(32);
	s.push(3);
	s.push(41);

	deb(s);
	// stack<int> ans = solve(s);
	// deb(ans);

	stack<int> ans = reverseStack(s);
	deb(ans);

	return 0;
}