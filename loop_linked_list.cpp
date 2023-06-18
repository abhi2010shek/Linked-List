#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int val){
			data=val;
			next=NULL;
		}
};
void insert(node* &head, int val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void insert_at_head(node* &head, int val){
	node* n=new node(val);
	n->next=head;
	head=n;
}
void display(node* head){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
bool search(node* head, int key){
	node*temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}
void delete_head(node*&head){
	node*todelete=head;
	head=head->next;
	delete todelete;
}
void delete_node(node*&head, int val){
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		delete_head(head);
		return;
	}
	node*temp=head;
	while(temp->next->data!=val){
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
    delete todelete;
}
node * recurrsive_reverse(node*&head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* newnode=recurrsive_reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newnode;
}
node* change_node_in_position(node*&head, int k){
	node*pre=NULL;
	node*curr=head;
	node*nex;
	int c=0;
	while(curr!=NULL && c<k){
		nex=curr->next;
		curr->next=pre;
		
		pre=curr;
		curr=nex;
		c++;
	}
	if(nex!=NULL){
	head->next = change_node_in_position(nex,k);
    }
    return pre;
}
void make_loop(node*&head,int pos){
	node*temp=head;
	node*starnode;
	int c=0;
	while(temp->next!=NULL){
		if(c==pos){
			starnode=temp;
		}
		temp=temp->next;
		c++;
	}
	temp->next=starnode;
}
bool detect_loop(node*&head){
	node*slow=head;
	node*fast=head;
	node*temp=head;
	while(fast->next!=NULL || fast!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			return true;
		}
	}
	return false;
}
void delete_loop(node*&head){
	node*slow=head;
	node*fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);
	
	fast=head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}
int main(){
	node*head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	insert(head,6);
	//insert_at_head(head,4);
	//delete_node(head,3);
	//delete_head(head);
	//node * n1=recurrsive_reverse(head);
	//change_node_in_position(head,3);
	make_loop(head,4);
	delete_loop(head);
	cout<<detect_loop(head);
	display(head);
	//cout<<search(head,2);
	return 0;
}
