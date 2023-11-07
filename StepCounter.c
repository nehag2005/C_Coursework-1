#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"


// Complete the main function
int main()
{

    while (1) // infinite while loop
    {
        // printing menu options
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");

        char choice;
        printf("Enter choice: "); // user input
        scanf("%c", &choice);

        // Clear the input buffer                //ChatGPT: "In C, how to allow more time for user input when using a infinite while loop?"
        while (getchar() != '\n');

        switch (choice)
        {
        case 'A':
            printf("Input filename: ");
            char input_filename[100];
            scanf("%s", input_filename);
            if (strcmp(input_filename, "FitnessData_2023.csv") == 0)              // ChatGPT: "How to compare strings in C"
            {
                file_open("FitnessData_2023.csv", "r");
                printf("File successfully loaded.\n");
            }
            else
            {
                printf("Error: Could not find or open the file.\n");
            }
            break;

        case 'B':
            break;

        case 'C':
            break;

        case 'D':
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
