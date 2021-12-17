#include<iostream>
using namespace std;
class vehicle{
	private:
		int maxspeed;
	protected:
		int numtyres;
	public:
		string color;
	vehicle(){
		cout<<"V constructor"<<endl;
	}
	vehicle(int x){
		cout<<"V parameterised constructor"<<endl;
	}
	~vehicle(){
		cout<<"V destructor"<<endl;
	}
};
class car: public vehicle{
	public:
		int numgears;
	car(){
		cout<<"C constructor"<<endl;
	}
	car(int x):vehicle(x){
		cout<<"C parameterised constructor"<<endl;
	}	
	~car(){
		cout<<"C destructor"<<endl;
	}
};
int main(){
	vehicle v;
	car c;
	car c1(6);
}
