#include <stdio.h>
#include <conio.h>
int main()
{
    int a[50], i, n, pos, ele, item, choice;
       clrscr();
    printf("Enter the size of the array:");
    scanf("%d", &n);
    if (n > 50)
     {
	printf("Size exceeds limit (50). Exiting");
	return;
    }

   printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
     {
	scanf("%d", &a[i]);
     }

    while (1)
    {
	printf("\nMenu:\n");
	printf("1. Insert Element at Beginning\n");
	printf("2. Insert Element at Given Position\n");
	printf("3. Insert Element at End\n");
	printf("4. Delete Element from Beginning\n");
	printf("5. Delete Element from Given Position\n");
	printf("6. Delete Element from End\n");
	printf("7. Exit\n");

	printf("Select your choice:");
	scanf("%d", &choice);

	switch (choice)
	{
	    case 1:
		if (n >= 50)
		{
		    printf("Array is full! Cannot insert.\n");
		    break;
		}
		printf("Enter the element to insert at the beginning:");
		scanf("%d", &ele);
		for (i = n; i > 0; i--)
		{
		    a[i] = a[i-1];
		}
		a[0] = ele;
		n++;
		printf("Array after insertion: ");
		for (i = 0; i < n; i++)
		{
		    printf("%d\t", a[i]);
		}
		printf("\n");
		break;

	    case 2:
		if (n >= 50)
		{
		    printf("Array is full! Cannot insert.\n");
		    break;
		}
		printf("Enter the position (0 to %d):", n);
		scanf("%d", &pos);
		if (pos < 0 || pos > n)
		{
		    printf("Invalid position!\n");
		    break;
		}
		printf("Enter the element to insert:");
		scanf("%d", &ele);
		for (i = n; i > pos; i--)
		{
		    a[i] = a[i-1];
		}
		a[pos] = ele;
		n++;
		printf("Array after insertion:");
		for (i = 0; i < n; i++)
		{
		    printf("%d\t", a[i]);
		}
		printf("\n");
		break;

	    case 3:
	       if (n >= 50)
		 {
		    printf("Array is full! Cannot insert.\n");
		    break;
		 }
		printf("Enter the element to insert at the end:");
		scanf("%d", &ele);
		a[n] = ele;
		n++;
		printf("Array after insertion:");
		for (i = 0; i < n; i++)
		{
		    printf("%d\t", a[i]);
		}
		printf("\n");
		break;

	    case 4:
		if (n == 0)
		 {
		    printf("Array is empty! Cannot delete.\n");
		    break;
		 }
		printf("Element deleted: %d\n", a[0]);
		for (i = 0; i < n-1; i++)
		 {
		    a[i] = a[i + 1];
		 }
		n--;
		printf("Array after deletion:");
		for (i = 0; i < n; i++)
		{
		    printf("%d\t", a[i]);
		}
		printf("\n");
		break;

	    case 5:
		if (n == 0)
		 {
		    printf("Array is empty! Cannot delete.\n");
		    break;
		 }
		printf("Enter the position (0 to %d) to delete: ", n - 1);
		scanf("%d", &pos);
		if (pos < 0 || pos >= n)
		{
		    printf("Invalid position!\n");
		    break;
		}
		printf("Element deleted: %d\n", a[pos]);
		for (i= pos; i < n - 1; i++)
		 {
		    a[i] = a[i + 1];
		 }
		n--;
		printf("Array after deletion:");
		for (i = 0; i < n; i++)
		{
		    printf("%d\t", a[i]);
		}
		printf("\n");
		break;

	    case 6:
		if (n == 0)
		 {
		    printf("Array is empty! Cannot delete.\n");
		    break;
		 }
		printf("Element deleted: %d\n", a[n-1]);
		n--;
		printf("Array after deletion:");
		for (i = 0; i < n; i++)
		 {
		    printf("%d\t", a[i]);
		 }
		printf("\n");
		break;

	    case 7:
		printf("Exiting program...\n");
		return 0;

	    default:
		printf("Invalid choice! Please try again.\n");
	}
    }
    getch();
}


