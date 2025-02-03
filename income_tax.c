/*
#include<stdio.h>
void main()
{
    int calculate=1;
    printf("************ This is our calculator *************\n");
    
    while (calculate==1)
    {
    	 int a;
    	 printf("\nTo calculate income tax press 1 : ");
    	 scanf("%d",&a);
    	
    	if (a==1)
    	{
    		float input_income, tax;
        	printf("\nEnter your income: ");
        	scanf("%f", &input_income);
        	
        	if (input_income <= 250000)         // up to 250000 no tax
      {
          tax = 0;
      }
      else if (input_income > 250000 && input_income <= 500000)
      {
          tax = (input_income - 250000) * 0.1;         // 1% tax
      }
      else if (input_income > 500000 && input_income <= 1000000)
      {
          tax =  (input_income - 500000) * 0.2;     // 2% tax
      }
      else
      {
          tax =  (input_income - 1000000) * 0.3;   // 3% tax
      }
      printf("\nYour income tax is: %.2f\n", tax);
		}
		
		else if (a==-1)
		{
			printf("\nThank You!");
			break;
		}
		else
		{
			printf("\n-----------Wrong Input----------\n");
		}
    	printf("\nEnter -1 to exit.");
    	
	}
}
*/












#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct taxpayer {
    char name[50];
    int income;
    float tax;
};

void addRecord(struct taxpayer *p, int *count);
void listRecord(struct taxpayer *p, int count);
void searchRecord(struct taxpayer *p, int count);
void editRecord(struct taxpayer *p, int count);
void deleteRecord(struct taxpayer *p, int *count);

int main() {
    int choice, count = 0;
    struct taxpayer *p = malloc(sizeof(struct taxpayer));

    if (!p) {   // memory allocation failed
        printf("Memory allocation failed!");
        return 0;
    }

    do {
        printf("\n\nINCOME TAX CALCULATOR\n");
        printf("1. Add New Record\n");
        printf("2. List all Tax Payer along with income tax to be paid\n");
        printf("3. Search\n");
        printf("4. Edit\n");
        printf("5. Delete Record\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(p, &count);
                break;
            case 2:
                listRecord(p, count);
                break;
            case 3:
                searchRecord(p, count);
                break;
            case 4:
                editRecord(p, count);
                break;
            case 5:
                deleteRecord(p, &count);
                break;
            case 0:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice!");
        }
    } while (choice != 0);

    free(p);    // free the allocated memory
    return 0;
}

void addRecord(struct taxpayer *p, int *count) {
    printf("\nEnter taxpayer name: ");
    scanf("%s", (p + *count)->name);
    printf("Enter taxpayer income: ");
    scanf("%d", &(p + *count)->income);

    // calculate tax
    if ((p + *count)->income <= 500000)
        (p + *count)->tax = 0;
    else if ((p + *count)->income <= 1000000)
        (p + *count)->tax = (p + *count)->income * 0.2;
    else
        (p + *count)->tax = (p + *count)->income * 0.3;

    (*count)++;
}

void listRecord(struct taxpayer *p, int count) {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nTAX PAYER\tINCOME\tTAX\n");
    for (int i = 0; i < count; i++)
        printf("%s\t\t%d\t%.2f\n", (p + i)->name, (p + i)->income, (p + i)->tax);
}

void searchRecord(struct taxpayer *p, int count) {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    char name[50];
    printf("\nEnter taxpayer name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp((p + i)->name, name) == 0) {
            printf("\nTAX PAYER\tINCOME\tTAX\n");
            printf("%s\t\t%d\t%.2f\n", (p + i)->name, (p + i)->income, (p + i)->tax);
            return;
        }
    }

    printf("\nRecord not found!\n");
}

void editRecord(struct taxpayer *p, int count) {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    char name[50];
    printf("\nEnter taxpayer name to edit: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp((p + i)->name, name) == 0) {
            printf("\nEnter new income: ");
            scanf("%d", &(p + i)->income);

            // calculate new tax
            if ((p + i)->income <= 250000)
                (p + i)->tax = 0;
            else if ((p + i)->income <= 500000)
                (p + i)->tax = (p + i)->income * 0.05;
            else if((p+i)->income <=1000000)
                (p + i)->tax = (p + i)->income * 0.2;
            else
                (p + i)->tax = (p + i)->income * 0.3;

            printf("\nRecord updated successfully!\n");
            return;
        }
    }

    printf("\nRecord not found!\n");
}

void deleteRecord(struct taxpayer *p, int *count) {
    if (*count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    char name[50];
    printf("\nEnter taxpayer name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp((p + i)->name, name) == 0) {
            // shift all records from i+1 to end to the left by 1 position
            for (int j = i+1; j < *count; j++)
                *(p + j - 1) = *(p + j);

            (*count)--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }

    printf("\nRecord not found!\n");
}