#include<iostream>
using namespace std;
template<typename T>
class QueueUsingArray{
	T * data;
	int nextindex;
	int firstindex;
	int size;
	int capacity;
	public:
		QueueUsingArray(int totalsize){
			data=new T[totalsize];
			nextindex=0;
			size=0;
			firstindex=-1;
			capacity=totalsize;
		}
		int getsize(){
			return size;
		}
		bool isEmpty(){
			return size==0;
		}
		void enqueue(T element){
			if(size==capacity){
				cout<<"Queue Full!"<<endl;
				return;
			}
			data[nextindex]=element;
			nextindex=(nextindex+1)%capacity;
			if(firstindex==-1){
				firstindex=0;
			}
			size++;
		}
		T dequeue(){
			if(size==0){
				cout<<"Queue Empty!"<<endl;
				return 0;
			}
			T a= data[firstindex];
			firstindex=(firstindex+1)%capacity;
			size--;
			if(size==0){
				firstindex=-1;
				nextindex=0;
			}
			return a;
		}
		T front(){
			if(firstindex==-1){
				cout<<"Queue Empty!"<<endl;
				return 0;
			}
			return data[firstindex];
		}
};
int main(){
	QueueUsingArray<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getsize()<<endl;
	cout<<q.isEmpty()<<endl;
}
