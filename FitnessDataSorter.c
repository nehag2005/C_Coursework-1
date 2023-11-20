#include "FitnessDataStruct.h"

FITNESS_DATA fitness_data_array[200];
int num_of_records = 0;

int main()
{
    char line[buffer_size];
    char filename[buffer_size];
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

        if (fitness_data_array[0].date[0] == '\0' || fitness_data_array[0].time[0] == '\0' || fitness_data_array[0].steps[0] = 0)
        {
            printf("Error: Invalid file\n");
            return 1; 
        }

        num_of_records++;
    }

    for (int i=0; i < num_of_records; i++)           //loop through array elements
    {
        for (int j= i+1; j < num_of_records; j++)               // loop through array elements from index 1 
        {
            if (fitness_data_array[i].steps < fitness_data_array[j].steps)          // https://www.geeksforgeeks.org/c-program-to-sort-the-elements-of-an-array-in-descending-order/
            {
                int max_steps = fitness_data_array[i].steps;
                fitness_data_array[i].steps = fitness_data_array[j].steps;
                fitness_data_array[j].steps = max_steps;
            }
        }
    }

    FILE *file2 = fopen("FitnessData_2023.csv.tsv", "w");


    for (int i = 0; i < num_of_records; i++) { 
        fprintf(file2, "%s\t%s\t%d\n", fitness_data_array[i].date, fitness_data_array[i].time, fitness_data_array[i].steps); 
    } 

    fclose(file);
    fclose(file2);
    return 0; 
}