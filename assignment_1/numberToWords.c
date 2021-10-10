// Program that converts number to words in American counting system.

#include <stdio.h>
#include <stdlib.h> // atoi()
#include <string.h>

char RESULT[1024]; // to store the result string

void convertToWords(char *numString)
{
    char *digits_1[20] = {"", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine",
                          " eleven", " twelve", " thirteen", " fourteen", " fifteen", " sixteen",
                          " seventeen", " eighteen", " nineteen"};
    char *digits_2[11] = {"",
                          " ten",
                          " twenty",
                          " thirty",
                          " fourty",
                          " fifty",
                          " sixty",
                          " seventy",
                          " eighty",
                          " ninety",
                          " hundred"};
    char res[1024] = "";

    int len = strlen(numString);
    // convert the numString to int
    int numInt = atoi(numString);

    if (len == 3)
    {
        strcat(res, digits_1[numInt / 100]); // hundred's place
        strcat(res, " Hundred");
        strcat(res, digits_2[((numInt % 100) / 10)]); // ten's place
        strcat(res, digits_1[numInt % 10]);           // units place
    }
    else if (len == 2)
    {
        strcat(res, digits_2[((numInt % 100) / 10)]); // ten's place
        strcat(res, digits_1[numInt % 10]);           // units place
    }
    else if (len == 1)
    {
        if (numInt % 10 == 0)
            strcat(res, " Zero");
        else
            strcat(res, digits_1[numInt % 10]); // units place
    }
    else
    {
        printf("\nInvalid length\n");
        exit(1);
    }
    printf("\nres = %s\n", res);
}

int main()
{
    // store the number in a string
    char number[100];
    char numString[4] = "2156";
    int len;

    len = strlen(numString);
    for (int i = 0; i < (len % 3) + 1; i++)
    {
        // split the string

        convertToWords(numString);
    }

    // function to convert (maxlen 3) digits to words
    convertToWords(numString);

    return 0;
}