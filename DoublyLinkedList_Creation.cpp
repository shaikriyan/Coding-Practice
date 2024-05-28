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
	Node* prev;
	int data;
	Node* next;

	Node(int data1=0,Node* prev1=nullptr, Node* next1=nullptr){
		prev = prev1;
		data = data1;
		next = next1;
	}

};


Node* array2DLL(vector<int>&nums){

	Node *head = nullptr, *temp = nullptr; 
	for(auto it : nums){
		if(head==nullptr){
			head = new Node(it);
			temp = head;
		}else{
			temp->next = new Node(it);
			temp = temp->next;
		}
	}
	return head;
}

void printDLL(Node* head){

	Node* temp = head;
	while(temp){
		cout<<temp->data<<" <=> ";
		temp = temp->next;
	}
	cout<<endl;
	return;

}

int getCount(Node* head){

	Node* temp = head;
	int cnt = 0;
	while(temp){
		cnt++;
		temp = temp->next;
	}
	return cnt;

}


Node* insertAtBegining(Node* head, int data){

	if(head==nullptr) return new Node(data);
	Node* temp = new Node(data);
	temp->next = head;
	head->prev = temp;
	head = temp;

	return head;
}


Node* insertAtEnd(Node* head, int data){

	Node* temp = head;
	while(temp->next!=nullptr){
		temp = temp->next;
	}
	Node* last = new Node(data);
	temp->next = last;
	last->prev = temp;
	return head;
}

Node* insertAtPos(Node* head, int pos, int data){

	if(head==nullptr && pos==0) return new Node(data);

	int len = getCount(head);

	if(pos==0){
		// Insert at begining logic.
		return insertAtBegining(head, data);
	}
	else if(pos>0 && pos<len){
		// Insert at pos [any middle node]
		int cnt = 0;
		Node* temp = head;
		while(temp){
			cnt++;
			if(cnt-1 == pos) break;
			temp = temp->next;
		}

		Node* newNode = new Node(data);
		newNode->next = temp->next;
		temp->next->prev = newNode;
		temp->next = newNode;
		newNode->prev = temp;	


	}
	else if(pos==len){
		//Insert at end.
		return insertAtEnd(head, data);
	}

 return head;

}



Node* deleteAtBegining(Node* head){

	if(head==nullptr || head->next==nullptr) return nullptr;

	Node* temp = head;
	head = temp->next;
	head->prev = nullptr;
	temp->next = nullptr;

	return temp; 
}

Node* deleteAtEnd(Node* head){

	Node* temp = head;
	while(temp->next){
		temp = temp->next;
	}

	Node* last = temp->prev;
	last->next = nullptr;
	temp->prev = nullptr;

	return head;

}


Node* deleteAtPos(Node* head, int pos){

	int len = getCount(head);

	if(pos==1){
		//delete the first node
		return deleteAtBegining(head);
	}
	else if(pos ==len){
		//  delete the last node.
		return deleteAtEnd(head);
	}
	else{

		int cnt = 0;
		Node* temp = head;
		while(temp){
			cnt++;
			if(cnt==pos) break;
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->next ==nullptr;
		temp->prev ==nullptr;

	}



return head;


}

Node* reverseDLL(Node* head){

	if(head==nullptr || head->next==nullptr) return head;

	Node *left=nullptr, *right= nullptr, *curr = head;

	while(curr){

		right = curr->next;
		curr->next = left;
		curr->prev = right;
		left = curr;
		curr = right;
	}

	return left;

}




int main()
{

	vector<int>nums = {2,2,10,8,4,2,5,2};
	Node* head = array2DLL(nums);
	// int len = getCount(head);
	// deb(len);
	printDLL(head);

	head = reverseDLL(head);
	printDLL(head);
	
	
	return 0;
}