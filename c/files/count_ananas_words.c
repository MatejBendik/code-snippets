#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char arr[2000];
    int count = 0;

    if (argv[1] == NULL || file == NULL)
    {
        printf("Error: File not found");
        return 0;
    }

    // read all the file and store it to the array arr
    for (int d = 0; (arr[d] = fgetc(file)) != EOF; d++)
    {
    }
    fclose(file);

    // loop through the arr
    for (int d = 0; arr[d] != '\0'; d++)
    {
        // turn all the letters to lower case
        if (arr[d] >= 'A' && arr[d] <= 'Z')
        {
            arr[d] = arr[d] + 32;
        }
        // remove all the spaces and new lines from the array
        if (arr[d] == ' ' || arr[d] == '\n')
        {
            for (int j = d; arr[j] != '\0'; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }

    // count word ananas in the array arr
    for (int d = 0; arr[d] != '\0'; d++)
    {
        if (arr[d] == 'a' && arr[d + 1] == 'n' && arr[d + 2] == 'a' && arr[d + 3] == 
'n' && arr[d + 4] == 'a' && arr[d + 5] == 's')
        {
            count++;
        }
    }

    // turn count to char type and store it to the same file
    char c = count + '0';

    int first_num = (count / 10) + '0';
    int second_num = (count % 10) + '0';

    file = fopen(argv[1], "w");

    // if count is more than 9, print the first number and then the second number
    if (count > 9)
    {
        fputc(first_num, file);
        fputc(second_num, file);
    }
    else
        fputc(c, file);

    fclose(file);
}
