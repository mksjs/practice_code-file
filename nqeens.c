#include<stdio.h>
#include<stdlib.h>
int x[100];
int place(int k,int i){
	for(int j=1;j<=(k-1);j++){
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k))){
			return 0;
		}
	}
	return 1;
}
void nqeen(int k,int n){
	for(int i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n){
				for(i=1;i<=n;i++){
					printf("%d ",x[i]);
				}
				printf("\n");
			}
			else 
				nqeen(k+1,n);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	nqeen(1,n);
return 0;
}

