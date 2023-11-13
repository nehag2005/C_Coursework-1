#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FITNESS_DATA fitness_data_array[200];

// Complete the main function
int main()
{

    char line[buffer_size];
    char filename[buffer_size];

    int num_of_records = 0;
    char choice;
    int max = 0;
    int max_index = 0;
    int i;
    int min;
    int min_index = 0;
    float sum = 0;
    float average;

    while (1)
    {
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n')
            ;

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("Input filename: ");
            char input_filename[100];
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", input_filename);

            FILE *file = open_file(input_filename, "r");

            while (fgets(line, buffer_size, file) != NULL)
            {
                // Tokenize the line to get date, time, and steps
                char date[11]; // // Week 3, Bootcamp 2, Session 2 codes, functions-ex.c
                char time[6];
                char steps[8];
                tokeniseRecord(line, ",", date, time, steps);

                strcpy(fitness_data_array[num_of_records].date, date); // ChatGPT "How to store records in a typedef structure"
                strcpy(fitness_data_array[num_of_records].time, time);
                fitness_data_array[num_of_records].steps = atoi(steps);

                num_of_records++;
            }

            fclose(file);
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", num_of_records);
            break;

        case 'C':
        case 'c':
            min = fitness_data_array[0].steps;
            for (i = 0; i < num_of_records; i++)
            {
                if (fitness_data_array[i].steps <= min)
                {
                    min = fitness_data_array[i].steps;
                    min_index = i;
                }
            }
            printf("Fewest steps: %s %s\n", fitness_data_array[min_index].date, fitness_data_array[min_index].time);
            break;

        case 'D':
        case 'd':
            for (i = 0; i < num_of_records; i++)
            {
                if (fitness_data_array[i].steps >= max)
                {
                    max = fitness_data_array[i].steps;
                    max_index = i;
                }
            }
            printf("Largest steps: %s %s\n", fitness_data_array[max_index].date, fitness_data_array[max_index].time);
            break;

        case 'E':
        case 'e':
            sum = 0;

            for (i = 0; i < num_of_records; i++)
            {
                sum += fitness_data_array[i].steps;
            }
            printf("%f/n", sum);
            float average = sum / num_of_records;
            printf("Mean step count: %.2f\n", average); // round
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice.Try again.\n");
            break;
        }
    }
}
