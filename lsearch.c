#include<stdio.h>

int main()
{
	int a[10],i,n,srch,c,b=0;

	printf("Enter the number of elements in an array\n");
	scanf("%d", &n);

	printf("Enter the elements of array\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Enter the no to be searched\n");
	scanf("%d", &srch);

	for(i=0; i<n; i++)
	{
		if(a[i]==srch)
		{
			printf("\nThe position is %d",i);
			b++;
		}
		continue;
	}
	printf("\nThe no of times the number is found is %d\n",b);
}
