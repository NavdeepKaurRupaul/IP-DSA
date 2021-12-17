//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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
node* kReverse(node*head,int n){
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
    while (current != NULL && count < n )  {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
    if (next != NULL)  
    head->next = kReverse(next, n);  
    return prev;  
} 
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}

