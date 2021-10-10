// Program that converts number to words in American counting system.

#include <stdio.h>
#include <stdlib.h> // atoi()
#include <string.h>

char RESULT[1024]; // to store the RESULTult string

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

    int len = strlen(numString);
    // convert the numString to int
    int numInt = atoi(numString);

    if (len == 3)
    {
        strcat(RESULT, digits_1[numInt / 100]); // hundred's place
        strcat(RESULT, " Hundred");
        strcat(RESULT, digits_2[((numInt % 100) / 10)]); // ten's place
        strcat(RESULT, digits_1[numInt % 10]);           // units place
    }
    else if (len == 2)
    {
        strcat(RESULT, digits_2[((numInt % 100) / 10)]); // ten's place
        strcat(RESULT, digits_1[numInt % 10]);           // units place
    }
    else if (len == 1)
    {
        if (numInt % 10 == 0)
            strcat(RESULT, " Zero");
        else
            strcat(RESULT, digits_1[numInt % 10]); // units place
    }
    else
    {
        printf("\nInvalid length\n");
        exit(1);
    }
    // printf("\nRESULT = %s\n", RESULT);
}

int main()
{
    // store the number in a string
    char *suffix[] = {"", "THOUSAND", "MILLION", "BILLION", "TRILLION", "QUADRILLION", "QUINTRILLION", "SEXTILLION",
                      "SEPTILIION", "OCTILLION", "NONILLION", "DECILLION"};
    char numString[10] = "2100156";
    char splitString[4];
    int len;

    len = strlen(numString);
    for (int i = 0; i <= (len / 3); i++)
    {
        // copy 3 digits into a string buffer
        // strncpy(splitString, numString + (len - 3), 3);
        strcpy(splitString, numString[len - 3]);
        // function to convert (maxlen 3) digits to words
        convertToWords(splitString);
        // add the appropriate suffix
        strcat(RESULT, suffix[i]);
        // truncate the string
        numString[len - 3] = "\0";
    }
    // convertToWords(numString);
    printf("\nRESULT = %s\n", RESULT);

    return 0;
}