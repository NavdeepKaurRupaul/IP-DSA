#include <cmath>
#include <iostream>
#include<unordered_map>
using namespace std;
int makeAnagram(char str1[], char str2[]){
    unordered_map <char,int> m;
    for(int i=0;str1[i]!='\0';i++){
        if(!m.count(str1[i])){
        	m[str1[i]]=1;
		}   
        else{
        	m[str1[i]]+=1;
		}  
    }
    int ans=0;
    for(int i =0;str2[i]!='\0';i++){
        if(m.count(str2[i])){
            if(m[str2[i]]==0){
                ans=ans+1;
                continue;
            }
            m[str2[i]]-=1;
            }
        else{
            ans=ans+1;
        }
    }
    unordered_map<char,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        ans=ans+it->second;
    }
    return ans;
}


int main() {
    char str1[10010], str2[10010];
    cin>>str1;
    cin>>str2;
    
    cout << makeAnagram(str1,str2) << endl;
	
}

