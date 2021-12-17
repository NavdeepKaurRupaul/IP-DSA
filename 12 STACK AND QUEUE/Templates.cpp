#include<iostream>
using namespace std;
template<typename T, typename V>
class Pair{
	T x;
	V y;
	public:
		void setX(T x){
			this->x=x;
		}
		void setY(V y){
			this->y=y;
		}
		T getX(){
			return x;
		}
		V getY(){
			return y;
		}
};
int main(){
	Pair<Pair<int,int>,int> p;
	Pair<int,int>pp;
	pp.setX(1);
	pp.setY(2);
	p.setY(3);
	p.setX(pp);
	cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY()<<endl;
}
