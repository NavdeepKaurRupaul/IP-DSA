#include <iostream>
using namespace std;
long maxPathSum(int ar1[], int ar2[], int m, int n){
    int i=0;
    int j=0;
    long maxsum=0;
    long sum1=0;
    long sum2=0;
    while(i<m && j<n){
    	if(ar1[i]<ar2[j]){
    		sum1= sum1+ar1[i];
    		i++;
		}
		else if(ar1[i]>ar2[j]){
			sum2=sum2+ar2[j];
			j++;
		}
		else if(ar1[i]==ar2[j]){
			sum1=sum1+ar1[i];
			sum2=sum2+ar2[j];
			i++;
			j++;
			if(sum1>sum2){
				maxsum=maxsum+sum1;
			}
			else{
				maxsum=maxsum+sum2;
			}
			sum1=0;
			sum2=0;
		}
	}
	while(i<m){
		sum1=sum1+ar1[i];
		i++;
	}
	while(j<n){
		sum2=sum2+ar2[j];
		j++;
	}
	/*if(sum1 !=0){
		maxsum=maxsum+sum1;
	}
	else{
	    maxsum=maxsum+sum2;
    }
    
    //without intersection
    sum1=0;
    sum2=0;
    for(int i=0;i<m;i++){
    	sum1=sum1+ar1[i];
	}
	for(int i=0;i<n;i++){
		sum2=sum2+ar2[i];
	}
	int max=0;
	if(sum1>sum2){
		max=sum1;
	}
	else{
		max=sum2;
	}
	if(maxsum<max){
		maxsum=max;
	}*/
    maxsum = maxsum+max(sum1,sum2);
    
	return maxsum;
}

int main() {
    int *a,*b,m,n,i;
    cin>>m;
    a=new int[m];
    for(i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    b=new int[n];
    for(i=0;i<n;i++)
        cin>>b[i];
    long ans = maxPathSum(a,b,m, n);
    cout << ans << endl;
    delete a;
    delete b;
    return 0;
}
