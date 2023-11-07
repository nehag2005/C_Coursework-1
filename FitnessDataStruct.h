#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}



FILE *file_open(char *filename, char *mode)
{
	FILE *file = fopen(filename, mode);
	if (file == NULL)
	{
		printf("Error");
		exit(1);
	}

	return file;
}


int file_read(FILE *filename, FITNESS_DATA *records)
{
	int char_buffer_per_line = 100;
    char line[char_buffer_per_line];
    int num_of_records = 0;
	FITNESS_DATA fitness_data_array[200];

    while (fgets(line, char_buffer_per_line, filename) != NULL)
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

#endif // FITNESS_DATA_STRUCT_