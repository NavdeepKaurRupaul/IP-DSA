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

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
int length(Node *head) {
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
    	count++;
    	temp=temp->next;
	}
	return count;
}

void printIthNode(Node *head, int i) {
    int lengthLL=length(head);
    if(i>=lengthLL){
    	return;
	}
	else{
		Node *temp=head;
		int count=0;
		while(count<i && temp->data!=NULL){
			count++;
			temp=temp->next;
		}
        cout<<temp->data<<endl;
		}
	}
int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    printIthNode(head, pos);
    return 0;
}


