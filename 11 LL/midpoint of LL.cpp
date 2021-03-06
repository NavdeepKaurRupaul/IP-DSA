//Find midpoint of a Linked List
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
int length(node* head){
	node* temp= head;
	int count=0;
	while(temp!= NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
node* midpoint_linkedlist(node *head)
{
    int x=length(head);
    node* slow = head;
    	node* fast = head->next;
    if(x%2 !=0){
    	while(fast != NULL){
    		slow=slow->next;
    		fast=fast->next->next;
		}
	}
	else{
    	while(fast->next != NULL){
    		slow=slow->next;
    		fast=fast->next->next;
		}
	}
	return slow;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}



