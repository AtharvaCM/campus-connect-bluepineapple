// Program to find total occurennces of each digit (0-9) using funtion.
// Tue, Oct 5 2021

#include <iostream>
#include <string>

int main()
{
    // input the number as a string
    std::string number;
    std::cout << "Enter the number: ";
    std::cin >> number;

    // init all the counters with 0
    int digits[10] = {0};

    // iterate over the characters in number
    for (int i = 0; i < number.length(); i++)
    {
        char c = number[i];
        int index = c - '0'; // char('0') stands for int(49) in ASCII.
        digits[index]++;     // increment the counter
    }

    // print
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << ": " << digits[i] << std::endl;
    }

    return 0;
}