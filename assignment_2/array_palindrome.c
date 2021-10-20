// Program that checks if an array of chars is a palindrome or not
#include <stdio.h>
#include <string.h>

void is_palindrome(char word[])
{
    int len = strlen(word);
    int flag = 1;

    for (int i = 0; i < (len / 2); i++)
    {
        if (word[i] != word[len - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
        printf("\n%s is not a palindrome.\n", word);
    else
        printf("\n%s is a palindrome.\n", word);
}

int main()
{
    char input[50];

    printf("\nEnter the word: ");
    scanf("%s", input);

    is_palindrome(input);

    return 0;
}