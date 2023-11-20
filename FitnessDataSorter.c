#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Define the struct for the fitness data
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps)
{
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL)
    {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL)
        {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL)
            {
                *steps = atoi(ptr);
            }
        }
    }
}

int main()
{
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
}