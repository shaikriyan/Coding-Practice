#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}

template<typename T>
void print(vector<T> v){
	cout<<"[ ";
	for(int i=0;i<v.size();i++){
		print(v[i]);
		cout<<" ";
	}
	cout<<"]";
}



class Node{

public:
	int data;
	Node *next;

	Node(int data1, Node* next1){
		data = data1;
		next = next1;
	}

	Node(int data1){
		data = data1;
		next = nullptr;
	}

};

Node* arrayToLinkedList(vector<int> &nums){

	Node *head = NULL,*temp = NULL;

	for(auto it: nums){
		if(head==NULL){
			head  = new Node(it);
			temp = head;
		}
		else{
			temp->next = new Node(it);
			temp = temp->next;
		}
	}

	return head;
}


void printList(Node* head){

	if(head==NULL){
		cout<<"[]"<<endl;
		return;
	}

	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
}

int lengthOfLinkedList(Node* head){
	Node* temp = head;

	int cnt = 0;
	while(temp){
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

Node* insertAtBegining(Node* head, int val){
	if(head==NULL) return new Node(val);

	Node* temp = new Node(val);
	temp->next = head;
	head = temp;

	return head;
}

Node* insertAtEnd(Node* head , int val){

	if(head==NULL){
		return new Node(val);
	}


	Node* temp = head;
	while(temp->next !=NULL){
		temp = temp->next;
	}

	temp->next = new Node(val);

	return head;

}

Node* insertAtPos(Node* head, int val, int pos){
	if(head==NULL && pos==1) return new Node(val);
	if(head==NULL && pos!=1) return head;


	// if pos == 1: first position to insert
	if(pos==1){
		Node* x = new Node(val);
		x->next = head;
		head = x;
		return head;
	}
	else{
		// pos 2, 3, 4, 5....

		Node* prev = NULL;
		Node* temp = head;
		int cnt = 0;
		while(temp!=NULL){
			cnt++;

			if(cnt==pos){
				Node* x = new Node(val);
				x->next = temp;
				prev->next = x;
				break;
			}


			prev = temp;
			temp = temp->next; 
		}


	}

	return head;

}

// deletion part is yet to be implemented.....
// similar to insertion part..



int main()
{
	vector<int>nums = {1,2,3,4,5};

	Node* head = arrayToLinkedList(nums);

	// int len = lengthOfLinkedList(head);
	// cout<<"len : "<<len<<endl;



	// head = insertAtBegining(head, 100);
	// head = insertAtBegining(head, 200);
	// head = insertAtBegining(nullptr, 500);


	// head = insertAtEnd(head, 10);
	// head = insertAtEnd(head, 20);
	// head = insertAtEnd(NULL, 30);


	// head = insertAtPos(head, 800, 1);
	// head = insertAtPos(head, 800, 5);
	// head = insertAtPos(head, 800, 2);

	// head = insertAtPos(head, 800, 6);









	printList(head);

	return 0;
}