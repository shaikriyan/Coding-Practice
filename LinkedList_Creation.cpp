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
public :

	int data;
	Node* next;
	
	Node(int data1=0, Node* next1=nullptr){
		data = data1;
		next = next1;
	}

};


Node* array2LL(vector<int>&nums){

	int n = nums.size();
	Node* head = nullptr;
	Node* temp = NULL;
	for(int i=0;i<n;i++){
		if(i==0){
			head = new Node(nums[i]);
			temp = head;
		}
		else{
			temp->next = new Node(nums[i]);
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
}

Node* insertAtBegining(Node* head, int x){
	if(head==nullptr) return new Node(x);
	return new Node(x, head);
}

Node* insertAtEnd(Node* head, int x){
	if(head==NULL) return new Node(x);

	Node* temp = head;
	while(temp->next!=nullptr){
		temp = temp->next;
	}
	temp->next = new Node(x);
	return head;
}


int getCount(Node *head){
	int len = 0;
	if(head==NULL) return len;
	Node* temp = head;
	while(temp){
		len++;
		temp = temp->next;
	}
	return len;
}


bool searchKey(Node* head, int n, int key){

	if(n==0) return false;
	Node *temp = head;
	while(n){
		if(temp->data==key) return true;
		temp= temp->next;
		n--;
	}

	return false;
}

// This is the Leet code sum.
/*void deleteNode(Node* node){

       ListNode* temp = node;
        ListNode* prev = NULL;
        while(temp->next!=nullptr){
            temp->val = temp->next->val;
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
       	return;
}*/



int main()
{

	// Node* temp1 = new Node(1);
	// Node* temp2 = new Node(2);
	// Node* temp3 = new Node(3);
	// Node* temp4 = new Node(4);
	
	// temp1->next = temp2;
	// temp2->next = temp3;
	// temp3->next = temp4;
	
	// Node* tmp = temp1;
	// while(tmp){
	// 	cout<<tmp->val<<" ->";
	// 	tmp = tmp->next;
	// }
	// cout<<endl;

	vector<int> nums = {1,2,3,4,5};
	Node* head = array2LL(nums);
	printLL(head);

	head = insertAtBegining(head, 0);
	head = insertAtBegining(head, 100);
	printLL(head);

	head = insertAtEnd(head, 3000);
	printLL(head);

	int len = getCount(head);
	deb(len);

	bool status = searchKey(head, len, 1000);
	deb(status);

	status = searchKey(head, len, 3000);
	deb(status);



	return 0;
}