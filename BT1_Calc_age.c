/*---------------------------CALCULATE YOUR AGE---------------------------------
- This program require your birthday and it must be typed excatly by keyboard
- Then the program will calculate the age of you
------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

bool check(uint16_t d, uint16_t mth, uint16_t y){
    if(d >31){
        printf("You typed the invalid day: %d\n", d);
        return false;
    }
    else if (mth >12){
        printf("You typed the invalid month: %d\n", mth);
        return false;
    }
    else if(y>2022){
        printf("It is not yet %d\n", y);
        return false;
    }
    else return true;
}

uint16_t calculate_age(uint16_t d, uint16_t mth, uint16_t y ){
    uint16_t today=16, months=10, years=2022, age;
    age = years-y;
    if(mth <=months){
        age-- ;
    };

    return age;

}

int main(){
    uint16_t day=1, month=1, year=1;
    printf("Type your birthday");
    do
    {
        printf("\nDay: "); scanf("%d", &day);
        //check(day, month, year);
    } while (check(day, month, year) ==false);
    do
    {
        printf("Month: "); scanf("%d", &month);
        //check(day, month, year);
    } while (check(day, month, year) ==false);
    do
    {
        printf("Year: "); scanf("%d", &year);
        //check(day, month, year);
    } while (check(day, month, year) ==false);

    printf("Your age: %d", calculate_age(day, month, year));

    return 0;
}
