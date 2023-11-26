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

    char date[11]; // // Week 3, Bootcamp 2, Session 2 codes, functions-ex.c
    char time[6];
    char steps[8];
    

    while (fgets(line, buffer_size, file) != NULL)
    {
        // Tokenize the line to get date, time, and steps
        tokeniseRecord(line, ",", date, time, steps);

        strcpy(fitness_data_array[num_of_records].date, date); // ChatGPT "How to store records in a typedef structure"
        strcpy(fitness_data_array[num_of_records].time, time);
        fitness_data_array[num_of_records].steps = atoi(steps);

        if (date[0] == '\0' || time[0] == '\0'|| atoi(steps) == 0)
        {
            printf("Error: Invalid file\n");
            exit(1);
        }
    

        num_of_records++;
    }

    int max_steps = 0;
    char temp_time[10];

    for (int i = 0; i < num_of_records; i++) // loop through array elements
    {
        for (int j = i + 1; j < num_of_records; j++) // loop through array elements from index 1
        {
            if (fitness_data_array[i].steps < fitness_data_array[j].steps) // https://www.geeksforgeeks.org/c-program-to-sort-the-elements-of-an-array-in-descending-order/
            {
                max_steps = fitness_data_array[i].steps;
                fitness_data_array[i].steps = fitness_data_array[j].steps;
                fitness_data_array[j].steps = max_steps;
                
                strcpy(temp_time, fitness_data_array[i].time);
                strcpy(fitness_data_array[i].time, fitness_data_array[j].time);
                strcpy(fitness_data_array[j].time, temp_time);
                
            }
        }
    }
    
    char tsv_file[200];
    sprintf(tsv_file, "%s.tsv", input_filename);               
    FILE *file2 = fopen(tsv_file, "w");
    if (file2 == NULL) {
        perror("Error: invalid file\n");
        return 1;
    }

    for (int i = 0; i < num_of_records; i++)
    {
        fprintf(file2, "%s\t%s\t%d\n", fitness_data_array[i].date, fitness_data_array[i].time, fitness_data_array[i].steps);
    }

    fclose(file);
    fclose(file2);

    printf("Data sorted and written to %s\n", tsv_file);
    return 0;
}