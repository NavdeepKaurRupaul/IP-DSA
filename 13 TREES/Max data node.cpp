#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};
#include <queue>
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    queue<TreeNode<int>*>a;
    a.push(root);
    TreeNode<int>* front;
    TreeNode<int>* maxNode=root;
    while(! a.empty()){
    	front=a.front();
    	a.pop();
        if(maxNode->data<front->data){
            maxNode=front;
        }
    	for(int i=0;i<front->children.size();i++){
    		a.push(front->children[i]);
		}
	}
	return maxNode;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);
    if(root != NULL) {
       	cout << ans -> data;
    }
}

