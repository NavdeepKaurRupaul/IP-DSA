#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL){
    	return;
	}
	queue<BinaryTreeNode<int> *>pending;
	pending.push(root);
	while(! pending.empty()){
		BinaryTreeNode<int> * front=pending.front();
		pending.pop();
		cout<<front->data<<":";
		if(front->left != NULL){
			cout<<"L:"<<front->left->data<<",";
			pending.push(front->left);
		}
		if(front->left == NULL){
			cout<<"L:-1,";
		}
		if(front->right != NULL){
			cout<<"R:"<<front->right->data;
			pending.push(front->right);
		}
		if(front->right == NULL){
			cout<<"R:-1";
		}
		cout<<endl;
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}

