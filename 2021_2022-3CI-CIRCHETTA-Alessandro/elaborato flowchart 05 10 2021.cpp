#include <stdio.h>


int main()
{
    int N1, N2;

	printf("Scrivere il PRIMO numero: ");
	scanf("%d", &N1);
	
	printf("Scrivere il SECONDO numero: ");
	scanf("%d", &N2);
	
	if (N1 > N2)
	{
		printf("%d \n", N2);
		printf("%d", N1);
	}
	else
	{
		printf("%d \n", N1);	
		printf("%d", N2);
	}
	
	return 0;
}

