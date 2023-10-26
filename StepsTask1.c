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
        char date[11];
        char time[6];
        char steps[8];
        tokeniseRecord(line, ",", date, time, steps);

        int steps_as_integer = atoi(steps);    // turns steps from string to integer
       
        num_of_records++;
    }

    // Print the number of records
    printf("Number of records: %d\n", num_of_records);

    // Close the file
    fclose(file);

    return 0;
}


// resize array 
// print rows
// git commit push error
// unseen file 
