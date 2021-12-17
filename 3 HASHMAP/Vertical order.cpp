#include<iostream>
#include <queue>
#include<cmath>
using namespace std;
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
BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
    cin >> data;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            current -> left = left;
            pendingNodes.push(left);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            current -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
void findMinMax(BinaryTreeNode<int> *node, int *min, int *max, int hd) { 
    // Base case 
    if (node == NULL) return; 
  
    // Update min and max 
    if (hd < *min)  *min = hd; 
    else if (hd > *max) *max = hd; 
  
    // Recur for left and right subtrees 
    findMinMax(node->left, min, max, hd-1); 
    findMinMax(node->right, min, max, hd+1); 
}
void printVerticalLine(BinaryTreeNode<int> *node, int line_no, int hd) { 
    // Base case 
    if (node == NULL) return; 
  
    // If this node is on the given line number 
    if (hd == line_no) 
        cout << node->data << " "; 
  
    // Recur for left and right subtrees 
    printVerticalLine(node->left, line_no, hd-1); 
    printVerticalLine(node->right, line_no, hd+1); 
} 	
void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root) {	 
	// Find min and max distances with resepect to root 
    int min = 0, max = 0; 
    findMinMax(root, &min, &max, 0); 
  
    // Iterate through all possible vertical lines starting 
    // from the leftmost line and print nodes line by line 
    for (int line_no = min; line_no <= max; line_no++) { 
        printVerticalLine(root, line_no, 0); 
        cout << endl; 
    } 
}
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeVerticalOrder(root);
    return 0;
}

