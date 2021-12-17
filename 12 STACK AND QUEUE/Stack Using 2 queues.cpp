#include <iostream>
using namespace std;
#include<queue>
template<typename T>
class stack {
	public:
    queue<T> q1, q2; 
    int curr_size; 
    Stack() { 
        curr_size = 0; 
    } 
  
    T pop() 
    { 
        if (q1.empty()) 
            return; 
  
        // Leave one element in q1 and 
        // push others in q2. 
        while (q1.size() != 1) { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
        T a= q1.front();
        // Pop the only left element 
        // from q1 
        q1.pop(); 
        curr_size--; 
  
        // swap the names of two queues 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
        return a;
    } 
  
    void push(T x) 
    { 
        q1.push(x); 
        curr_size++; 
    } 
  
    T top() 
    { 
        if (q1.empty()) 
            return -1; 
  
        while (q1.size() != 1) { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        // last pushed element 
        T temp = q1.front(); 
  
        // to empty the auxiliary queue after 
        // last operation 
        q1.pop(); 
  
        // push last element to q2 
        q2.push(temp); 
  
        // swap the two queues names 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
        return temp; 
    } 
  
    int getSize() 
    { 
        return curr_size; 
    } 
};

int main(){
    stack<int> s;
    int choice, input;
    
    while(true){
        
        cin>>choice;
        
        switch(choice){
            case 1:
                cin >> input;
                s.push(input);
                break;
            case 2:
                cout << s.pop() << "\n";
                break;
            case 3:
                cout << s.top() << "\n";
                break;
            case 4 :
                cout << s.getSize() << endl;
                break;
            case 5 : // Test
                while(!s.q1 -> empty()) {
                    cout << s.q1 -> front() << " ";
                    s.q1 -> pop();
                }
                return 0;
            default:
                return 0;
                break;
        }
    }
}

