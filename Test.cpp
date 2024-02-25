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
	Node* next;

	Node(int d1, Node* next1=nullptr){
		data = d1;
		next = next1;
	}
};

Node* array2LL(vector<int>&nums){

	Node* head = NULL;
	Node* temp = head;
	for(auto it : nums){
		if(head==NULL){
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


void printList(Node* temp){
	while(temp!=nullptr){
		cout<<temp->data<<"->";
		temp = temp->next;
	}cout<<endl;
}


Node* removeAllOccurancesOfAKey(Node* head, int key){

	if(head==NULL || (head->next==nullptr && head->data==key))
		return NULL;


	Node* temp = head;
	Node* prev = NULL;

	while(temp!=nullptr){

		if(head->data==key){
			head = head->next;
			temp = head;
			continue;
		}

		if(temp->data==key){
			prev->next = temp->next;
			temp->next = nullptr;
			delete temp;
			temp = prev;
		}

		prev = temp;
		temp = temp->next;
	}

	return head;

}


Node* deleteDuplicates(Node* head){

	if(head==NULL || head->next==NULL) return head;

	Node* temp = head;

	while(temp!=NULL){

		if(temp->next!=NULL){
			if(temp->data == temp->next->data){
				temp->next = temp->next->next;
				continue;
			}
		}

		temp = temp->next;
	}

	return head;

}

Node* MergeLL(Node* head1, Node* head2){

	if(head1==NULL) return head2;
	else if(head2==NULL) return head1;

	Node* ans = new Node(-1);
	Node* t = ans;

	Node* t1 = head1;
	Node* t2 = head2;

	while(t1!=nullptr && t2!=nullptr){
		if(t1->data <= t2->data){
			t->next = t1;
			t = t->next;
			t1= t1->next;
		}
		else if(t2->data < t1->data){
			t->next = t2;
			t = t->next;
			t2 = t2->next;
		}
	}

	while(t1){
		t->next = t1;
		t = t->next;
		t1 = t1->next;
	}

	while(t2){
		t->next = t2;
		t = t->next;
		t2 = t2->next;
	}

	return ans->next;



}


Node* rotateRightByK(Node* head, int k){

	if(head==NULL) return head;

	Node* temp = head;
	int cnt = 0;
	while(temp){
		cnt++;
		temp = temp->next;
	}

	k = k%cnt;

	if(k==0) return head;
	temp =head;
	int bp = cnt - k;
	Node* tail = NULL, *newHead = nullptr;
	cnt = 0;
	while(temp->next!=nullptr){
		cnt++;

		if(cnt==bp){
			tail = temp;
			newHead = temp->next;
		}
		temp = temp->next;
	}

	temp->next = head;
	tail->next = nullptr;
	return newHead;

}


Node* MergeSortLL(Node* head){

	if(head==NULL || head->next==NULL) return head;

	Node *slow=head, *fast=head;

	while(fast->next!=nullptr && fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	Node *head1 = head;
	Node *head2 = slow->next;
	slow->next = nullptr;


	head1 = MergeSortLL(head1);
	head2 = MergeSortLL(head2);

	head = MergeLL(head1, head2);
	return head;

}



Node* sortLL(Node* head){
	if(head==NULL || head->next==NULL) return head;
	 head = MergeSortLL(head);
	 return head;
}




int main()
{
	// vector<int>nums = {5,5,4,2,1,3,5,6,8,4};
	vector<int>nums = {1,2,3,4,5};
	// vector<int>nums = {1,1,1,2,2,3};

	Node *head = array2LL(nums);

	printList(head);

	// head = deleteDuplicates(head);


	// head = sortLL(head);
	head = rotateRightByK(head, 2);

	printList(head);
	// int key = 5;

	// head = removeAllOccurancesOfAKey(head, key);

	// printList(head);


	return 0;
}