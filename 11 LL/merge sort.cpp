//merge sort recursive
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
node* mergeTwoLLs(node* h1, node* h2) 
{ 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->data < h2->data) { 
        h1->next = mergeTwoLLs(h1->next, h2); 
        return h1; 
    } 
    else { 
        h2->next = mergeTwoLLs(h1, h2->next); 
        return h2; 
    } 
}
node* midpoint_linkedlist(node *head)
{
	node * slow=head;
	node * fast= head->next;
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *temp=head;
    if(temp!= NULL){
    	while(fast!= NULL && fast->next!=NULL){
    		slow=slow->next;
    		fast = fast->next->next;
		}
        node * temp=slow->next;
        slow->next=NULL;
		return temp;
}
}

node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    node * mid=midpoint_linkedlist(head);
    node * head3=mergeSort(head);
    node * head4=mergeSort(mid);
    mergeTwoLLs(head3,head4);
}
int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}


