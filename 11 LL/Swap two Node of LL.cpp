//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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
node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    i=i+1;
    j=j+1;
    node *node1, *node2, *prev1, *prev2, *temp;
    int k;

    // Get the far position among both
    const int maxPos = (i > j) ? i : j;

   


    // Identify both nodes to swap
    k = 1;
    temp  = head;
    prev1 = NULL;
    prev2 = NULL;

    // Find nodes to swap
    while (temp != NULL && (k <= maxPos))
    {
        if (k == i - 1)
            prev1 = temp;
        if (k == i)
            node1 = temp;

        if (k == j- 1)
            prev2 = temp;
        if (k == j)
            node2 = temp;

        temp = temp->next;
        k++;
    }

    // If both nodes to swap are found.
    if (node1 != NULL && node2 != NULL)
    {
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->next = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->next = node1;

        // Swap node1 and node2 by swapping their 
        // next node links
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

    return head;
}

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}


