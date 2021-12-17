#include <iostream>
using namespace std;
#include<cstring>
int countPalindromeSubstrings(char s[]) {
	int n= strlen(s);
    int count=0;
    for(int i=0;i<n;i++){// consider each elemnt for even or odd mid for palindrome
        int l=i,r=i;// consider for odd mid
        while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--,r++;
        }
        l=i,r=i+1;//consider for even mid
     while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--,r++;
        }
    }
    return count;
}
int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}

