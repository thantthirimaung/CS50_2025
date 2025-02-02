#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_index(int letters, int words, int sentences);
void print_grade(int index);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int idx = compute_index(num_letters, num_words, num_sentences);

    // Print the grade level
    print_grade(idx);
}

int count_letters(string text)
{
    int l = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
    }
    return l;
}

int count_words(string text)
{
    int w = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || isspace(text[i - 1])) && isalpha(text[i]))
        {
            w++;
        }
    }
    return w;
}

int count_sentences(string text)
{
    int s = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {

            s++;
        }
    }

    return s;
}

int compute_index(int letters, int words, int sentences)
{
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int indx = round(0.0588 * L - 0.296 * S - 15.8);
    return indx;
}

void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
