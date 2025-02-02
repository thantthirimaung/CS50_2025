#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string convert_to_cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");

    string ciphertext = convert_to_cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
}

string convert_to_cipher(string plaintext, int key)
{
    key = key % 26;
    int n = strlen(plaintext);
    for (int i = 0; i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        }
    }
    return plaintext;
}