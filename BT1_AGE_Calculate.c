/*---------------------------CALCULATE YOUR AGE---------------------------------
- This program require your birthday and it must be entered excatly by keyboard
- Then the program will calculate your age
------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

int TODAY = 16;
int THIS_MONTH = 10;
int THIS_YEAR = 2022;

bool CALENDAR_TypeCheck(int days, int months, int years)
{
    if(days > 31)
    {
        printf("You typed the invalid day: %d\n", days);
        return false;
    }
    else if(months > 12)
    {
        printf("You typed the invalid month: %d\n", months);
        return false;
    }
    else if(years > 2022)
    {
        printf("It is not yet %d\n", years);
        return false;
    }
    else return true;
}

bool CALENDAR_Check(int day, int month, int year)
{
    if(month == 2)
    {
        if(day > 29)
        {
            printf("Invalid day of February: %d-%d", day, month);
            return false;
        }else
        {
            if((year%400) == 0)
            {
                if(day>29)
                {
                    printf("Invalid day of February in %d (leap-year): %d-%d-%d", year, day, month, year);
                    return false;
                }else return true;
            }else
            {
                if(((year%4) && (year%100)) != 0)
                {
                    if(day>29)
                    {
                        printf("Invalid day of February in %d (leap-year): %d-%d-%d", year, day, month, year);
                        return false;
                    }else return true;
                }else
                {
                    if(day > 28)
                    {
                        printf("Invalid day of February in %d (non-leap year): %d-%d-%d", year, day, month, year);
                        return false;
                    }else return true;
                }
            }
        }
    }else
    {
        if(month == 4)
        {
            if(day > 30)
            {
                printf("April has 30 days maximum!!");
                return false;
            }else return true;
        }
        else if(month == 6)
        {
            if(day > 30)
            {
                printf("June has 30 days maximum!!");
                return false;
            }else return true;
        }
        else if(month == 9)
        {
            if(day > 30)
            {
                printf("September has 30 days maximum!!");
                return false;
            }else return true;
        }
        else if(month == 11)
        {
            if(day > 30)
            {
                printf("November has 30 days maximum!!");
                return false;
            }else return true;
        }else return true;
    }
}

int AGE_Calculate(int day, int month, int year)
{
    int age = THIS_YEAR-year;
    
    if(month < THIS_MONTH)
    {
        age -= 1;
    }
    else if(month == THIS_MONTH)
    {
        if(day < TODAY)
        {
            age -= 1;
        }
    }

    return age;

}

int main()
{
    int day=1, month=1, year=1;
    
    printf("Type your birthday");
    do
    {
        do
        {
            printf("\nDay: "); scanf("%d", &day);
        } while (CALENDAR_TypeCheck(day, month, year) == false);
        do
        {
            printf("Month: "); scanf("%d", &month);
        } while (CALENDAR_TypeCheck(day, month, year) == false);
        do
        {
            printf("Year: "); scanf("%d", &year);
        } while (CALENDAR_TypeCheck(day, month, year) == false);
    } while (CALENDAR_Check(day, month, year) == false);

    printf("\nYour Birthday: %d-%d-%d\n ", day, month, year);
    printf("Your age: %d", AGE_Calculate(day, month, year));

    return 0;
}

