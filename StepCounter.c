#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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

void option_A()
{
    char input_filename[100];
    printf("Input filename: ");
    scanf("%s", input_filename);
}

int option_B()
{
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    int char_buffer_per_line = 100;
    char line[char_buffer_per_line];
    int num_of_records = 0;

    while (fgets(line, char_buffer_per_line, file) != NULL)
    {
        num_of_records++;
    }
    printf("Total records: %d\n", num_of_records);
    fclose(file);
}

FITNESS_DATA fitness_data_array[200];        //add typedef to array

char option_C() {
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    int char_buffer_per_line = 100;
    char line[char_buffer_per_line];
    char fewest_steps;
    int num_of_records = 0;

    while (fgets(line, char_buffer_per_line, file) != NULL)
    {
        num_of_records++;
        // Tokenize the line to get date, time, and steps
        char date[11];                                            // // Week 3, Bootcamp 2, Session 2 codes, functions-ex.c
        char time[6];
        char steps[8];
        tokeniseRecord(line, ",", date, time, steps);
       
       strcpy(fitness_data_array[num_of_records].date, date);   //ChatGPT "How to store records in a typedef structure"
       strcpy(fitness_data_array[num_of_records].time, time);
       fitness_data_array[num_of_records].steps = atoi(steps);

    }

    for(int i=0; i<num_of_records; i++) 
    {

    
    printf("Fewest steps: %s %s", fitness_data_array[i].date, fitness_data_array[i].time);
    }
    fclose(file);
}

// Complete the main function
int main()
{

    while (1)                       // infinite while loop
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
            option_A(); break;

        case 'B':
            option_B(); break; 

        case 'C':
            option_C(); break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
