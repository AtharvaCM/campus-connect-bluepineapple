// Program that converts number to words in American counting system.

#include <iostream>
#include <string.h>
#include <string>

std::string RESULT; // to store the RESULTult string

void convertToWords(std::string numString)
{
    const char *digits_1[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine",
                                " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen",
                                " Seventeen", " Eighteen", " Nineteen"};
    const char *digits_2[11] = {"",
                                " Ten",
                                " Twenty",
                                " Thirty",
                                " Fourty",
                                " Fifty",
                                " Sixty",
                                " Seventy",
                                " Eighty",
                                " Ninety",
                                " Hundred"};

    int len = numString.length();
    // convert the numString to int
    int numInt = std::stoi(numString);

    if (len == 3)
    {
        // check if all the digits are 0s
        if (numString == "000")
            return;
        RESULT.insert(0, digits_1[numInt % 10]);           // units place
        RESULT.insert(0, digits_2[((numInt % 100) / 10)]); // ten's place
        RESULT.insert(0, " Hundred");
        RESULT.insert(0, digits_1[numInt / 100]); // hundred's place
    }
    else if (len == 2)
    {
        RESULT.insert(0, digits_1[numInt % 10]);           // units place
        RESULT.insert(0, digits_2[((numInt % 100) / 10)]); // ten's place
    }
    else if (len == 1)
    {
        if (numInt % 10 == 0)
            RESULT.insert(0, " Zero");
        else
            RESULT.insert(0, digits_1[numInt % 10]); // units place
    }
    else
    {
        printf("\nInvalid length\n");
        exit(1);
    }
    std::cout << RESULT << std::endl;
}

int main()
{
    const char *suffix[] = {"", " THOUSAND", " MILLION", " BILLION", " TRILLION", " QUADRILLION", " QUINTRILLION", " SEXTILLION",
                            " SEPTILIION", " OCTILLION", " NONILLION", " DECILLION"};
    // store the number in a string
    std::string numString;
    std::cout << "\nEnter the number to convert: ";
    std::cin >> numString;
    std::string splitString;
    int len;
    int loop_counter = 0;

    len = numString.length();

    if (len % 3 == 0)
        loop_counter++;
    for (loop_counter; loop_counter <= (len / 3); loop_counter++)
    {
        // copy 3 digits into a string buffer
        std::cout << "numstr = " << numString << std::endl;
        if (numString.length() > 3)
            splitString = numString.substr(numString.length() - 3);
        else
            splitString = numString;
        std::cout << "split = " << splitString << std::endl;

        // add the appropriate suffix
        if (splitString != "000")
        {
            if (len % 3 == 0)
                RESULT.insert(0, suffix[loop_counter - 1]); // coz we incremented the counter earlier
            else
                RESULT.insert(0, suffix[loop_counter]);
        }

        // function to convert (maxlen 3) digits to words
        convertToWords(splitString);

        // truncate the string
        if (numString.length() > 3)
            numString.erase(numString.length() - 3);
    }

    // print the result
    std::cout << RESULT << std::endl;

    return 0;
}