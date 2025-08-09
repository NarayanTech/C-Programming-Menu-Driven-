#include<stdio.h>
#include<conio.h>
void main() {
    int i, j, a[10], temp, n, min, ele, flag, beg, mid, Choice, end, loc;
    clrscr();
    while (1) {
	printf("\n====================================\n");
	printf("                MENU                   \n");
	printf("1. BUBBLE SORTING\n");
	printf("2. SELECTION SORTING\n");
	printf("3. INSERTION SORTING\n");
	printf("4. LINEAR SEARCH\n");
	printf("5. BINARY SEARCH\n");
	printf("6. EXIT\n");
	printf("=====================================\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d",&Choice);
	switch (Choice)
	 {
	    case 1:
		printf("ENTER THE SIZE OF AN ARRAY: ");
		scanf("%d",&n);
		printf("ENTER THE ELEMENTS OF THE ARRAY: ");
		for (i = 0; i < n; i++)
		    scanf("%d",&a[i]);

		for (i = 0; i < n - 1; i++)
		    for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) {
			    temp = a[j];
			    a[j] = a[j + 1];
			    a[j + 1] = temp;
			}

		printf("\n Array after sorting:\n");
		for (i = 0; i < n; i++)
		    printf("%d\t",a[i]);
		break;

	    case 2:
		printf("ENTER THE SIZE OF AN ARRAY: ");
		scanf("%d",&n);
		printf("ENTER THE ELEMENTS OF THE ARRAY: ");
		for (i = 0; i < n; i++)
		    scanf("%d",&a[i]);

		for (i = 0; i < n - 1; i++) {
		    min = i;
		    for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
			    min = j;

		    if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		    }
		}

		printf("\nArray after Sorting:\n");
		for (i = 0; i < n; i++)
		    printf("%d\t",a[i]);
		break;

	    case 3:
		printf("ENTER THE SIZE OF AN ARRAY: ");
		scanf("%d",&n);
		printf("ENTER THE ELEMENTS OF THE ARRAY: ");
		for (i = 0; i < n; i++)
		    scanf("%d",&a[i]);

		for (i = 1; i < n; i++) {
		    temp = a[i];
		    j = i - 1;
		    while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		    }
		    a[j + 1] = temp;
		}

		printf("\nArray after Sorting:\n");
		for (i = 0; i < n; i++)
		    printf("%d\t",a[i]);
		break;

	    case 4:
		printf("ENTER THE SIZE OF AN ARRAY: ");
		scanf("%d", &n);
		printf("ENTER THE ELEMENTS OF THE ARRAY: ");
		for (i = 0; i < n; i++)
		    scanf("%d" ,&a[i]);

		printf("ENTER THE SEARCH ELEMENT: ");
		scanf("%d" ,&ele);
		flag = 0;

		for (i = 0; i < n; i++)
		    if (a[i] == ele) {
			flag = 1;
			break;
		    }

		if (flag == 1)
		    printf("Element %d is found at location %d", ele, i);
		else
		    printf("Element %d is not found", ele);
		break;

	    case 5:
		printf("ENTER THE SIZE OF AN ARRAY: ");
		scanf("%d",&n);
		printf("ENTER THE ELEMENTS OF THE ARRAY IN  SORTED ORDER : ");
		for (i = 0; i < n; i++)
		    scanf("%d" ,&a[i]);

		printf("ENTER THE SEARCH ELEMENT: ");
		scanf("%d" ,&ele);
		beg = 0;
		end = n - 1;
		loc = -1;


		while (beg <= end) {
		    mid = (beg + end) / 2;
		    if (a[mid] == ele) {
			loc = mid;
			break;
		    } else if (ele < a[mid])
			end = mid - 1;
		    else
			beg = mid + 1;
		}

		if (loc >= 0)
		    printf("Element %d is found at location %d", ele, loc);
		else
		    printf("Element %d is not found", ele);
		break;

	    case 6:
		printf("Exiting program...\n");
		return(0);

	default:
		printf("Invalid Choice! Try again.\n");
	}
    }
    getch();
}