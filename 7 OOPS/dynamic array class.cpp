#include<iostream>
using namespace std;
class dynamicarray{
	int * data;
	int capacity;
	int nextindex;
	public:
		dynamicarray(){
			data=new int[5];
			capacity=5;
			nextindex=0;
		}
		dynamicarray(dynamicarray const & d){
			this->data=new int[d.capacity];
			for(int i=0;i<d.nextindex;i++){
				this->data[i]=d.data[i];
			}
			this->nextindex=d.nextindex;
			this->capacity=d.capacity;
		}
		void operator==(dynamicarray const & d){
			this->data=new int[d.capacity];
			for(int i=0;i<d.nextindex;i++){
				this->data[i]=d.data[i];
			}
			this->nextindex=d.nextindex;
			this->capacity=d.capacity;
		}
		void add(int element){
			if(nextindex==capacity){
				int * newdata= new int[2*capacity];
				for(int i=0;i<nextindex;i++){
					newdata[i]=data[i];
				}
				delete [] data;
				data=newdata;
				capacity *=2;
			}
			data[nextindex]=element;
			nextindex++;
		}
		void add(int i,int element){
			if(i<nextindex){
				data[i]=element;
			}
			else if(i==nextindex){
				data[nextindex]=element;
				nextindex++;
			}
			else{
				return;
			}
		}
		void print(){
			for(int i=0;i<nextindex;i++){
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	dynamicarray d1;
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(60);
	d1.print();
	dynamicarray d2(d1);
	d1.add(1,105);
	d1.print();
	d2.print();
	dynamicarray d3;
	d3==d1;
	d1.add(0,105);
	d1.print();
	d3.print();
}
