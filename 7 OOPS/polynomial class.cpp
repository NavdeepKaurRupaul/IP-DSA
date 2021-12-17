#include <vector>
#include <climits>
#include <iostream>
using namespace std;
class Polynomial {
      public:
    int *degCoeff;
    int capacity;
    //DEFAULT CONSTRUCTOR
     Polynomial(){
        capacity=5;
        degCoeff=new int[capacity]();
    }
    //COPY CONSTRUCTOR
    Polynomial(Polynomial const &p){
        int i;
        capacity=p.capacity;
        degCoeff=new int[capacity];
        for(i=0;i<capacity;i++){
            degCoeff[i]=p.degCoeff[i];
		}    
         delete []p.degCoeff;
    }
    //= OPERATOR OVERLOADING(COPY ASSIGNMENT OPERATOR)
    Polynomial operator= (Polynomial const &p){  	
        int i;
        capacity=p.capacity;
        degCoeff=new int[capacity]();
        for(i=0;i<capacity;i++){
        	degCoeff[i]=p.degCoeff[i];
        }	 
         delete []p.degCoeff;       
    }
     //SET COEFFICIENT FUNCTION
    //D INDEX NUMBER , C ELEMENT
    void setCoefficient(int d,int c) {
        int i,p;
        if(d<capacity){
        	degCoeff[d]=c;
		}           
        else {
            while(capacity<=d){         //IF D IS GREATER THAN CAPACITY THEN DOUBLE THE CAPACITY COPY ALL ELEMENYS AND PUT C IN DTH INDEX NUMBER
            p=capacity;
            capacity=p*2;
            int * deg=new int[capacity]();
            for(i=0;i<p;i++){
            deg[i]=degCoeff[i];	
			}           
            delete []degCoeff;  //DELETING PREVIOUS ARRAY
            degCoeff=deg;
            }
            degCoeff[d]=c;
            }
    }
    //+ OPERATOR OVERLOADING
    Polynomial operator+ (Polynomial const &p) const{
        int i;
        Polynomial p1;
         if(capacity<p.capacity){
            for(i=0;i<capacity;i++){
            	p1.setCoefficient(i,degCoeff[i]+p.degCoeff[i]);
			}           
            for(i=capacity;i<p.capacity;i++){
            	p1.setCoefficient(i,p.degCoeff[i]);
			}         
         }
        else   {        //IF CAPACTITY>P.CAPACITY
            for(i=0;i<p.capacity;i++){
            	p1.setCoefficient(i,degCoeff[i]+p.degCoeff[i]);
			}           
            for(i=p.capacity;i<capacity;i++){
         	    p1.setCoefficient(i,degCoeff[i]);
		 }        
        }       
          return p1;
    }
    //- OPERATOR OVERLOADING
    Polynomial operator-  (Polynomial const &p) const{
        int i;
        Polynomial p1;
         if(capacity<p.capacity){        	
           for(i=0;i<capacity;i++){
           	p1.setCoefficient(i,degCoeff[i]-p.degCoeff[i]);
		   }         
           for(i=capacity;i<p.capacity;i++){
           	p1.setCoefficient(i,-p.degCoeff[i]);
		   }         
         }
          else {
            for(i=0;i<p.capacity;i++){
            	p1.setCoefficient(i,degCoeff[i]-p.degCoeff[i]);
			}
         for(i=p.capacity;i<capacity;i++){
                p1.setCoefficient(i,degCoeff[i]);
            }
          }
               return p1;
    }
    //* OPERATOR OVERLOADING
    Polynomial operator* (Polynomial const &p) const {
          int i,j,k;
          Polynomial p1;  
        for(i=0;i<capacity;i++){  
            for(j=0;j<p.capacity;j++){
                k=degCoeff[i]*p.degCoeff[j];
                if(i+j<p1.capacity){
                p1.setCoefficient(i+j,p1.degCoeff[i+j]+k);
            }
                else{
                    p1.setCoefficient(i+j,k); 
				}
            }
        }
        return p1;
    }
     //PRINT FUNCTION
    void print() const {
          int i;
        for(i=0;i<capacity;i++){
            if(degCoeff[i]!=0)
            cout<<degCoeff[i]<<'x'<<i<<" ";
        }
    }
    
};
int main(){
    int count1,count2,choice;
    cin >> count1; 
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];  
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }  
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    } 
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    cin >> count2; 
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2]; 
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    } 
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }  
    cin >> choice; 
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }        
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }           
    }
    return 0;
}

