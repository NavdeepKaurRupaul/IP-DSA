#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
    	if(next) 
	    delete next;
    }
};
Node* swapEveryPair(Node *head) {
    //write your code here
    Node* temp = head; 
  
    /* Traverse further only if  
    there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL) { 
        /* Swap data of node with  
           its next node's data */
        swap(temp->data, 
             temp->next->data); 
  
        /* Move temp by 2 for the next pair */
        temp = temp->next->next; 
    } 
    return head;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node*temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* head = takeinput();
    head = swapEveryPair(head);
    print(head);
    delete head;
    return 0;
}


