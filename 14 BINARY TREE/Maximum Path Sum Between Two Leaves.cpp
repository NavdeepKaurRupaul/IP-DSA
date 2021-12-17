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
int maxPathSumUtil(BinaryTreeNode<int> *root, int &res) {  
    if (root==NULL) {
		return 0; 
	}
    if (!root->left && !root->right) {
    	return root->data;
	}
    int ls = maxPathSumUtil(root->left, res); 
    int rs = maxPathSumUtil(root->right, res); 
    if (root->left && root->right) {  
        res = max(res, ls + rs + root->data);
        return max(ls, rs) + root->data; 
    } 
    return (!root->left)? rs + root->data: ls + root->data; 
} 
#include<climits>
long long int maximumSumLeafpath(BinaryTreeNode<int> *root){
   int res = INT_MIN; 
    maxPathSumUtil(root, res); 
    return res;    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << maximumSumLeafpath(root) << endl;
}

