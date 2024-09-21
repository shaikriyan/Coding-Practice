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



class MyStack{

private:

	int arr[1000];
	int top;

public:

	MyStack(){
		top = -1;
	}


	int pop(){
		if(top<0) return -1;
		return arr[top--];
	}

	void push(int x){
		arr[++top] = x; 
	}

	int size(){
		int temp = top;
		int cnt = 0;
		while(temp>=0){
			cnt++;
			temp--;
		}
		return cnt;
	}

	bool empty(){
		return (top!=-1);
	}

	void printStack(){
		int temp = top;
		while(temp>=0){
			cout<<arr[temp]<<" ";
			temp--;
		}
		cout<<endl;
	return;
	}
};

bool isValid(string s){

	int n = s.size();
	stack<char>st;

	int i=0;
	unordered_map<char, char>umap;
	umap['(']=')';
	umap['[']=']';
	umap['{']='}';

	while(i<n){

		if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
			st.push(s[i]);
		}
		else if(s[i]==')' || s[i]==']' || s[i]=='}'){
			char poppedChar = st.top();
			if(umap[poppedChar]!=s[i]) return false;
			else st.pop();
		}
		i++;

	}

	if(!st.empty()) return false;
	return true;

}





int main()
{

	// MyStack *myStack = new MyStack();

	// for(int i=1;i<=10;i++){
	// 	myStack->push(i);

	// 	if(i%4==0) myStack->pop();
	// }

	// myStack->printStack();


	// (*myStack).push(2000);
	// (*myStack).printStack();

	// delete myStack;




	return 0;
}