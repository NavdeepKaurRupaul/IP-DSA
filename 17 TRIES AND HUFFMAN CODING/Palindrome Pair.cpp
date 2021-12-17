#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <vector>

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    

    #include<vector>
#include<string>





bool checkWordForPalindrome(string word){
	int startindex=0;
	int endindex= word.length()-1;
	while(startindex<endindex){
		if(word[startindex]!=word[endindex]){
			return false;
		}
		startindex+=1;
		endindex-=1;
	}
	return true;
}

bool checkReamainingBranchesInTrie(TrieNode * root,string word){
	if(root->isTerminal){
		if(checkWordForPalindrome(word)){
			return true;
		}
	}
	for(int i=0;i<26;i++){
		TrieNode * childNode=root->children[i];
		if(childNode==NULL){
			continue;
		}
		string fwd =word+childNode->data;
		if(checkReamainingBranchesInTrie(childNode,fwd)){
			return true;
		}
	}
	return false;
}

bool doespairExistfor(TrieNode *root, string word,int startindex){
	if(word.length()==0){
		return true;
	}
	if(startindex==word.length()){
		if(root->isTerminal){
			return true;
		}
		return checkReamainingBranchesInTrie(root,"");
	}
	int charIndex=word[startindex]-'a';
	TrieNode * correspondingChild =root->children[charIndex];
	if(correspondingChild==NULL){
		if(root->isTerminal){
			return checkWordForPalindrome(word.substr(startindex));
		}
		return false;
	}
	return doespairExistfor(correspondingChild,word,(startindex+1));
}
bool isPalindromePair(TrieNode *root, vector<string> words){
	if(words.size()==0){
		return false;
	}
	for(int i=0;i<words.size();i++){
		if (doespairExistfor(root,words[i],0)){
			return true;
		}
	}
	return false;
}
string reverseWord(string word){
	string reverse="";
	for(int i=word.length()-1;i>=0;i--){
		reverse+=word[i];
	}
	return reverse;
}
bool isPalindromePair(vector<string> words){
		for(int i=0;i<words.size();i++){
			this->add(reverseWord(words[i]));
		}
		return isPalindromePair(this->root,words);
}
};

int main()
{
	Trie t;
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> words[i];
	}
	bool ans = t.isPalindromePair(words);

	if (ans)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
