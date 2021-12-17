#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

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
void reverse(Node* head)
{
	 Node* prev = NULL;
	 Node* current = head;
	 Node* next;

	// traverse the list
	while (current)
	{
		// tricky: note the next node
		next = current->next;

		// fix the current node
		current->next = prev;

		// advance the two pointers
		prev = current;
		current = next;
	}

	// fix the head pointer to point to the new front
	head = prev;
}
Node* NextLargeNumber(Node *head){
    // empty list
	if (head == NULL)
		return 0;

	// reverse the linked list
	reverse(head);

	// initialize carry with given digit
	int carry = digit;

	// traverse the reversed list
	struct Node* curr = *head;
	while (carry)
	{
		// get sum of current node and carry
		int sum = curr->data + carry;

		// update value of the current node with the single-digit sum
		curr->data = sum % 10;

		// set carry for the next node
		carry = sum / 10;

		// break if current node is the last node
		if (curr->next == NULL)
			break;

		// move to the next node
		curr = curr->next;
	}

	// add a new node at the end of linked list if there is any carry left
	if (carry)
		curr->next = newNode(carry);

	// reverse the list again to restore the original order
	reverse(head);
}
int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}




