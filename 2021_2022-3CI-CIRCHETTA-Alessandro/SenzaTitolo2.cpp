#include <stdio.h>

main ()
{
	int n1, n2, n3, n4, uteroinaffitto;
	
	printf("Inserire 4 numeri: ");
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	scanf("%d", &n4);
	
	uteroinaffitto = n1;
	
	if (n1 > n2)
	uteroinaffitto = n2;	
	else
	{
	
		if (n2 > n3)
		uteroinaffitto = n3;
		else
		{
	
			if (uteroinaffitto > n4)
			uteroinaffitto = n4;
		}
	}
	
	printf("Il valore più piccolo e': %d", n4);
	
	return 0;
}
