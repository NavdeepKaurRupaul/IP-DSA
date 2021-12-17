/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include<iostream>
using namespace std;
#include<stack>
int prec(char c) { 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}
#include<cstring>
#include<string>
#include<cmath>
float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}
int isOperator(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;    //character is an operator
   return -1;   //not an operator
}
int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   //character is an operand
   return -1;   //not an operand
}
float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a); //find b^a
   else
      return INT_MIN; //return negative infinity
}
float postfixEval(string postfix) {
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      //read elements and perform postfix evaluation
      if(isOperator(*it) != -1) {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }else if(isOperand(*it) > 0) {
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}
void evaluatePostfix(char s[]) {
    stack<char> st; 
    st.push('N'); 
    int l = strlen(s); 
    string ns; 
    for(int i = 0; i < l; i++) { 
        // If the scanned character is an operand, add it to output string. 
        if(s[i] >= '0' && s[i] <= '9') 
        ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(')  
        st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered. 
        else if(s[i] == ')') { 
            while(st.top() != 'N' && st.top() != '(') { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){ 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    }   
    cout << ns << endl;
	cout<< postfixEval(ns)<<endl;
}

int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}

