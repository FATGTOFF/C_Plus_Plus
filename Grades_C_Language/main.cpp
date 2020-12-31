#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char choice = ' ';
    int *p_GradesArr = NULL;
    int percentage = 0;
    int numOfGrades = 0;

    /*Stop the loop to quit the program when the user presser q*/
    while (choice != 'q')
    {

        printf("----------Enter Grade Percentage (0-100)----------\n");
        printf("Add Grade Percent (0-100)(a) \n");
        printf("Quit / Finish(q) \n");
        (void)scanf("%c", &choice);

        /*
          Ask the user how many grades he/she wishes to enter. Allocate
          the memory according to the chosen number of grades. Ensure the
          memory is allocated before inputing the grades. Once the grades
          are inputted, print the grades to the user and free the allocated
          memory for future use.
        */
        if ('a' == choice)
        {
            printf("How many grades will you enter? ");
            (void)scanf("%d", &numOfGrades);

            p_GradesArr = (int*)malloc(numOfGrades * sizeof(int));

            if (NULL == p_GradesArr)
            {
                printf("Memory not allocated.\n");
                exit(0);
            }
            else
            {
                for (int count = 0; count < numOfGrades; count++)
                {
                    printf("Enter grade: ");
                    (void)scanf("%d", &percentage);

                    while (percentage < 0 || percentage > 100)
                    {
                        printf("Your grade is not between 0 and 100\n");
                        printf("Enter grade: ");
                        (void)scanf("%d", &percentage);
                    }

                    p_GradesArr[count] = percentage;
                }
            }

            printf("Grades are:\n");
            for (int count = 0; count < numOfGrades; count++)
            {
                printf("%d\n", p_GradesArr[count]);
            }

            free(p_GradesArr);
        }

        else if ('q' == choice)
        {
            break;
        }

        else
        {
            printf("Your choice is not correct\n");
        }

        (void)getchar();
    }
 
    return 0;
}
