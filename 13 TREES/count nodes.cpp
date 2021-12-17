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
int countnode(TreeNode<int>* root) {
    int ans=1;
    for(int i=0;i<root->children.size();i++){
    	ans+=countnode(root->children[i]);
	}
	return ans;
}
void printLevelWise(TreeNode<int>* root) {
    //cout<<root->data<<":";
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
    	TreeNode<int>* front=pending.front();
    	pending.pop();
    	cout<<front->data<<":";
    	for(int i=0;i<front->children.size();i++){
    		if(i+1==front->children.size()){
    			cout<<front->children[i]->data;
			}
			else{
				cout<<front->children[i]->data<<",";
			}
    		pending.push(front->children[i]);
		}
		cout<<endl;
	}
}

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

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    //printLevelWise(root);
    cout<<countnode(root);
}

