#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

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
Node* deleteNode(Node*head, int i){
	Node*temp=head;
	int count=0;
    if(head==NULL){
        return head;
    }
	else if(i==0){
		head=head->next;
		return head;
	}
	else {
        while(temp!= NULL && count<i-1){
		temp=temp->next;
		count++;
	}
	if(temp!= NULL && temp->next != NULL){
		temp->next=temp->next->next;
	}
    }
	return head;
}}
void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}


