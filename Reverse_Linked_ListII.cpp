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


class Node{

public:
	int data;
	Node* next;

	Node(int data1=0, Node* next1=nullptr){
		data = data1;
		next = next1;
	}

};


Node* array2LL(vector<int>&nums){

	int n = nums.size();
	if(n==0) return nullptr;

	Node *head=nullptr, *temp=nullptr;

	for(auto it : nums){
		if(head==nullptr){
			head = new Node(it);
			temp = head;
		}
		else{
			temp->next = new Node(it);
			temp = temp->next;
		}
	}

	return head;


}


void printLL(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<endl;
	return;
}


Node* reverseLL(Node* head){

	if(head==nullptr || head->next ==nullptr) return head;
	Node *left = nullptr, *curr = head, *right = nullptr;

	while(curr){
		right = curr->next;
		curr->next = left;
		left = curr;
		curr = right;
	}

	return left;

}


Node* solve(Node* head, int left, int right){


	Node* edgeHead = new Node(INT_MAX);
	Node* edgeTail = new Node(INT_MAX);
	edgeHead->next = head;
	Node* temp = edgeHead;
	while(temp->next)
		temp = temp->next;
	temp->next = edgeTail;


	int cnt = 0;
	temp = edgeHead;
	Node *mainLeft = nullptr, *mainRight = nullptr;



	while(temp){

		cnt++;
		if(cnt==left) mainLeft = temp;
		if(cnt-1==right){
		 	mainRight = temp->next;
		 	temp->next = nullptr;
		 	break;
		}

		temp = temp->next;
	}

	




	Node* curr = mainLeft->next;
	mainLeft->next = nullptr;

	curr = reverseLL(curr);

	mainLeft->next = curr;

	temp = curr;

	while(temp->next){
		temp = temp->next;
	}
	
	if(mainRight->data!=INT_MAX)
		temp->next = mainRight;


	temp = mainRight;
	while(temp->next){
		curr = temp;
		temp = temp->next;
	}

	curr->next = nullptr;

	return edgeHead->next;

}






int main()
{

	vector<int> nums = {1,2,3,4,5};
	Node* head = array2LL(nums);
	printLL(head);


	head = solve(head, 1,5);
	printLL(head);





	return 0;
}