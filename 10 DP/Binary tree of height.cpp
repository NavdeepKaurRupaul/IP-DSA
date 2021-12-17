int binaryTreesOfHeight(int h){
	init *a=new int[h+1];
	if(h==0){
		return 1;
	}
	if(h==1){
		return 1;
	}
	a[0]=1;
	a[1]=1;
	int mod=(int)(pow(10,9))+7;
	for(int i=2;i<=h;i++){
		long temp=(long)(a[i-1])*a[i-1];
		temp=temp%mod;
		long temp1=2*(long)(a[i-1])*a[i-2];
		temp1=temp1%mod;
		a[i]=(temp+temp1)%mod:
	}
	int ans=a[h];
	delete[ ]a;
	return ans;
}
