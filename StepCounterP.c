#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStructP.h"


void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// actual code

int num_of_records = 0;
char choice;
int max = 0;
int max_index = 0;
int j;
int i;
int k;
int min_index = 0;
int min;
int sum = 0;

FITNESS_DATA fitness_data_array[200];

// Complete the main function
int main()
{
    choice = menu();
    switch (choice)
    {
    case 'A':
        printf("Input filename: ");
        char input_filename[100];
        scanf("%s", input_filename);

        if (strcmp(input_filename, "f.csv") == 0) // ChatGPT: "How to compare strings in C"
        {
            // file_open
            char filename[] = "f.csv";
            FILE *file = fopen(filename, "r");
            if (file == NULL)
            {
                perror("Unable to open the file");
                return 1;
            }
            printf("File successfully loaded.\n");

            // read file
            int char_buffer_per_line = 100;
            char line[char_buffer_per_line];

            while (fgets(line, char_buffer_per_line, file) != NULL)
            {
                num_of_records++;
                // Tokenize the line to get date, time, and steps
                char date[11]; // // Week 3, Bootcamp 2, Session 2 codes, functions-ex.c
                char time[6];
                char steps[8];
                tokeniseRecord(line, ",", date, time, steps);

                strcpy(fitness_data_array[num_of_records].date, date); // ChatGPT "How to store records in a typedef structure"
                strcpy(fitness_data_array[num_of_records].time, time);
                fitness_data_array[num_of_records].steps = atoi(steps);
            }
        }
        else
        {
            printf("Error: Could not open file.\n");
            return 0;
        }
        main();
        break;

    case 'B':
        printf("Total records: %d\n", num_of_records);
        main();
        break;

    case 'C':
        min = fitness_data_array[0].steps;
        for (i = 0; i < num_of_records; i++)
        {
            if (fitness_data_array[i].steps < min)
            {
                min = fitness_data_array[i].steps;
                min_index = i;
            }
        }
        printf("Fewest steps: %s %s\n", fitness_data_array[min_index].date, fitness_data_array[min_index].time);
        main();
        break;

    case 'D':
        for (j = 0; j < num_of_records; j++)
        {
            if (fitness_data_array[j].steps > max)
            {
                max = fitness_data_array[j].steps;
                max_index = j;
            }
        }
        printf("Largest steps: %s %s\n", fitness_data_array[max_index].date, fitness_data_array[max_index].time);
        main();
        break;

    case 'E':
        for (k = 0; k <= num_of_records; k++)
        {
            sum += fitness_data_array[k].steps;
        }
        printf("%d\n", sum);
        //float average = sum / num_of_records;
        //printf("Mean step count: %.2f\n", average
        main();
        break;

    case 'F':
        



       // printf("Longest period start: %s %s");
        //printf("Longest period end: %s %s");
        main();
        break;

    case 'Q':
        return 0;

    default:
        printf("Invalid choice. Try again.\n");
        main();
    }
}
