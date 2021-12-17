#include<iostream>
#include<climits>
using namespace std;
class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;	
	public :
	StackUsingArray() {
		data = new int[4];
		nextIndex = 0;
		capacity = 4;
	}
	
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		/*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
		*/
		return nextIndex == 0;
	}

	void push(int element) {
		if(nextIndex == capacity) {
			int * newdata = new int[2*capacity];
			for(int i=0;i<capacity;i++){
				newdata[i]=data[i];
			}
			delete [] data;
			data=newdata;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	int pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex - 1];
	}
};
int main(){
	StackUsingArray s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	
	cout<<s.pop()<<endl;
	
	cout<<s.top()<<endl;
	
	cout<<s.isEmpty()<<endl;
	
	cout<<s.size()<<endl;
	
}
