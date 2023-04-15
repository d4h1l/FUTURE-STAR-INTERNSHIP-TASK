#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void Sort(int *arr, int n)          // Array sorting function
{
    for(int i = 0; i < n-1; i++) 
    { 
       for(int j = 0; j < n-i-1; j++) 
       {  
           if(arr[j] > arr[j+1]) 
           {           
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
           }
        }
    }
}

float Coeff(int *arr1, int *arr2, int n)            // Coefficient calculation function
{
    int i = 0;
    float c = 0.0f;
    while (i < n)           // We find the relations of the elements and add up the values of the relations
    {
        if (arr1[i] < arr2[i])
        {
            c = c + (((float)arr2[i])/arr1[i]);
            i = i + 1;
        }

        else if (arr1[i] > arr2[i])
        {
            c = c + (((float)arr1[i])/arr2[i]);
            i = i + 1;
        }

        else if (arr1[i] == arr2[i])
        {
            i = i + 1;
        }              
    }

    return c;
}

void Manual_Input(int *arr1, int *arr2, int n)          // Function for manual entry of elements
{
    while (1)
    {
        bool flag1 = true;

        printf("Enter the elements of the first array:\n");
        
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &arr1[i]);          // We enter positive integers in the first array
            if (arr1[i] <= 0)
            {
                printf("Incorrect input!\n");
                flag1 = false;
                break;
            }
        }

        if (flag1 == true)
        {
            break;
        }
    }

    while (1)
    {
        bool flag2 = true;

        printf("Enter the elements of the second array:\n");
        
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &arr2[i]);          // We enter positive integers in the second array
            if (arr2[i] == 0)
            {
                printf("Incorrect input!\n");
                flag2 = false;
                break;
            }
        }

        if (flag2 == true)
        {
            break;
        }
    }

    printf("\na = ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\nb = ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr2[i]);
    }
}

void Auto_Input(int *arr1, int *arr2, int n)        // Function for automatic entry of elements
{
    printf("Generated arrays:\n");
    
    printf("a = ");
    for (int i = 0; i < n; i++) 
    {
        arr1[i] = (rand()%100) + 1;
        printf("%d ", arr1[i]);
    }

    printf("\nb = ");
    for (int i = 0; i < n; i++) 
    {
        arr2[i] = (rand()%100) + 1;
        printf("%d ", arr2[i]);
    }
}

int main()
{
    int n, value;

    while (1)
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);            // Specify the number of elements not exceeding 1000

        if (n <= 1000)
        {
            break;
        }

        else
        {
            printf("The number exceeds 1000\n");
        }
    }

    int a[n];
    int b[n];

    while (1)
    {
        printf("Manual input (1) or Auto (0)? Enter a number: ");
        scanf("%d", &value);            // Choosing the input method

        switch (value)
        {
        case 1:
            Manual_Input(a, b, n);
            break;
        case 0:
            Auto_Input(a, b, n);
            break;
        default:
            printf("Incorrect input!\n");
            break;
        }

        if ((value == 1) || (value == 0))
        {
            break;
        }
    }

    Sort(a, n);
    Sort(b, n);

    printf("\n\nCoefficient = %.2f", Coeff(a, b, n));       // Coefficient value

    printf("\n\n");

    return 0;
}
