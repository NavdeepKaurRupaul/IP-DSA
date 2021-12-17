#include<iostream>
using namespace std;
class student{
	int age;
	public:
		int rollno;
		student(){
			cout<<"constructor1 called"<<endl;
		}
		student(int age){
			this->age=age;
			cout<<"constructor2 called"<<endl;
		}
		student(int age, int rollno){
			cout<<"constructor3 called"<<endl;
			this->age=age;
			this->rollno=rollno;
		}
		int getvalue(){
			return age;
		}
		void setage(int age){
			this->age=age;
		}
		void display(){
			cout<<age<<" "<<rollno<<endl;
		}
		~student(){
			cout<<"destructor called"<<endl;
		}
};
int main(){
	student s1;
	student * s2= new student;
	s1.setage(21);
	s1.rollno=105;
	student s3(16);
	student s5(s1);
	s5.display();
	s3.rollno=12;
	s1.display();
	(*s2).display();
	cout<<(*s2).getvalue()<<endl;
	student s4(21,1055);
	s4.display();
	delete s2; //to delete dynamic object delete is used....then destructor is called for dynamic object;
}
