#include <cs50.h>
#include <stdio.h>

bool check_luhn(long long card_number);
int count_digits(long long number);
bool starts_with(long long number, int target, int length);

int main(void)
{
    long long card_number = get_long("Number: ");
    int digits = count_digits(card_number);
    bool valid = check_luhn(card_number);

    if ((starts_with(card_number, 34, 2) || starts_with(card_number, 37, 2)) && digits == 15 && valid)
    {
        printf("AMEX\n");
    }
    else if ((starts_with(card_number, 51, 2) || starts_with(card_number, 52, 2) || starts_with(card_number, 53, 2) ||
              starts_with(card_number, 54, 2) || starts_with(card_number, 55, 2)) &&
             digits == 16 && valid)
    {
        printf("MASTERCARD\n");
    }
    else if (starts_with(card_number, 4, 1) && (digits == 13 || digits == 16) && valid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_luhn(long long card_number)
{
    int sum = 0;
    bool alternate = false;
    while (card_number > 0)
    {
        int digit = card_number % 10;
        if (alternate)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                digit = digit - 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        card_number /= 10;
    }
    return (sum % 10) == 0;
}

int count_digits(long long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

bool starts_with(long long number, int target, int length)
{
    long long divisor = 1;
    for (int i = 0; i < length - 1; i++)
    {
        divisor *= 10;
    }

    while (number / divisor >= 10)
    {
        number /= 10;
    }
    return number == target;
}
