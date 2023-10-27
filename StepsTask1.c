#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Outputs: date character array; time character array; steps character array
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

    FITNESS_DATA fitness_data_array[200];

int main() {
    
    // Open the file
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open the file");
        return 1;
    }

    int char_buffer_per_line = 100;
    char line[char_buffer_per_line];
    int num_of_records = 0;


   

    // Read the file
    while (fgets(line, char_buffer_per_line, file) != NULL) {


        // Tokenize the line to get date, time, and steps
        char date[11];                                            // // Week 3, Bootcamp 2, Session 2 codes, functions-ex.c
        char time[6];
        char steps[8];
        tokeniseRecord(line, ",", date, time, steps);


       

       if (num_of_records < 3) {                              // First three rows, < 3 as it terminates at 3 
        printf("%s/%s/%s", date, time, steps);
       }


       strcpy(fitness_data_array[num_of_records].date, date);   //ChatGPT "How to store records in a typedef structure"
       strcpy(fitness_data_array[num_of_records].time, time);
       fitness_data_array[num_of_records].steps = atoi(steps);
                                        
       
        num_of_records++;
    }

    

    // Print the number of records
    printf("Number of records: %d\n", num_of_records);

    // Close the file
    fclose(file);

    return 0;
}


