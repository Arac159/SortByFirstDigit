#include <stdio.h>
#include <stdlib.h>
int firstdigit(int a)
{
    if (a < 10)
    {
        return a;
    }
    else if (a < 100)
    {
        a = a / 10;
    }
    else if (a < 1000)
    {
        a = a / 100;
    }
    return a;
}


int main()
{
    //declaration
    int i, j;
    int temp;

    //open and read file
    FILE *myFile;
    myFile = fopen("Array.txt", "r");

    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit(0);
    }

    //allocate memory to array
    int numNumbers = 0;
    fscanf(myFile, "%d", &numNumbers);

    //insert numbers to array
    int* numberArray = malloc(numNumbers * sizeof(int));

    for (i = 0; i < numNumbers; i++)
    {
        fscanf(myFile, "%d,", &numberArray[i]);
    }

    //print initial arrary
    printf("The initial array is\n");
    for (i = 0; i < numNumbers; ++i)
    {
        printf("%d ", numberArray[i]);
    }

    //sort array by first digit
    for (i = 0; i < (numNumbers-1); ++i)
        {
            for (j = 0; j < (numNumbers-1); ++j)
            {
                if (firstdigit(numberArray[i+1]) < numberArray[i])
                {
                    temp = numberArray[i];
                    numberArray[i] = numberArray[i+1];
                    numberArray[i+1] = temp;
                }
            }
        }

    //print sorted array
    printf("\nThe array is\n");
    for (i = 0; i < numNumbers; ++i)
    {
        printf("%d ", numberArray[i]);
    }

    fclose(myFile);
    free(numberArray);
    
    return 0;
}
