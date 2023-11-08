#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// helper function
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

        if (strcmp(input_filename, "FitnessData_2023.csv") == 0) // ChatGPT: "How to compare strings in C"
        {
            // file_open
            char filename[] = "FitnessData_2023.csv";
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

            FITNESS_DATA fitness_data_array[200];

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
            printf("Error: Could not find or open the file.\n");
        }
        main();
        break;

        


    case 'B':
        printf("Total records: %d\n", num_of_records);
        main();
        break;

    case 'C':
        main();
        break;

    case 'Q':
        main();
        return 0;

    default:
        printf("Invalid choice. Try again.\n");
    }
}





