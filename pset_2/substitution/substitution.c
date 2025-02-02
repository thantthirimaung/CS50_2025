#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checking_letters(string key);
char convert_character(char ch, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!checking_letters(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", convert_character(plaintext[i], key));
    }
    printf("\n");
}

bool checking_letters(string key)
{
    int n = strlen(key);
    if (n != 26)
    {
        return false;
    }

    int seen[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int idx = toupper(key[i]) - 'A';
        if (seen[idx] > 0)
        {
            return false;
        }
        seen[idx]++;
    }
    return true;
}

char convert_character(char ch, string key)
{
    if (isalpha(ch))
    {
        int idx = toupper(ch) - 'A';
        if (isupper(ch))
        {
            return toupper(key[idx]);
        }
        else
        {
            return tolower(key[idx]);
        }
    }
    return ch;
}
