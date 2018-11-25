#include<stdio.h>

int main()
{
	int c,first,last,middle,n,srch,a[10];
	
	printf("Enter the no of elements\n");
	scanf("%d", &n);
	
	printf("Enter the sorted %d integers\n",n);
	
	for(c=0; c<n; c++)
		scanf("%d", &a[c]);
		
	printf("Enter the no to be searched\n");
	scanf("%d", &srch);
	
	first=0;
	last=n-1;
	middle=(first+last)/2;
	
	while(first <= last)
	{
		if(a[middle]<srch)
			first=middle+1;
		
		else if(a[middle]==srch)
		{
			printf("%d found at location %d\n",srch,middle+1);
			break;
		}
		
		else
			last=middle-1;
		
		middle=(first+last)/2;
	}	
	
	if(first>last)
		printf("The no %d is not found",srch);
	
}
