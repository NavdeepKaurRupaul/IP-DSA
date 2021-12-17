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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}
BinaryTreeNode<int>* buildTreeHelp(int *preorder, int *inorder, int preStart, int preEnd, int inStart, int inEnd){
    int rootelement = preorder[preStart];
	int rootindex = 0;
    if(inStart>inEnd){
    	return NULL;
	}
        
	for(int i =inStart;i<=inEnd; i++){
		if(inorder[i]==rootelement){
			rootindex=i;
		}
		
	}
	int inorderLeftEnd = rootindex-1;
	int inorderLeftStart = inStart;
    int preorderLeftStart=preStart+1;
	int preorderRightEnd = preEnd;
	int inorderRightEnd = inEnd;
	int inorderRightStart = rootindex+1;
    int preorderLeftEnd = inorderLeftEnd-inorderLeftStart+preorderLeftStart;	
    int preorderRightStart = preorderLeftEnd+1;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootelement);
	root->right=buildTreeHelp(preorder, inorder, preorderRightStart, preorderRightEnd, inorderRightStart, inorderRightEnd);
    root-> left=buildTreeHelp(preorder, inorder, preorderLeftStart, preorderLeftEnd, inorderLeftStart, inorderLeftEnd);
	return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
    return buildTreeHelp(preorder, inorder,0 ,preLength-1, 0, inLength-1);
}
int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>pre[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}

