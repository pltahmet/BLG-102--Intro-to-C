#include <stdio.h>
#include <stdlib.h>

int checkDate(int year, int month, int day);
int whichDay(int year, int month, int day);
int howManyDay(int year, int month, int day, int valueOfSameDay, int endYear);


int main(){

    int enteredYear, enteredMonth, enteredDay, enteredEndYear;
    int valueOfDay, numberDay;

    printf("Enter date [year month day]: ");
    scanf("%d %d %d", &enteredYear, &enteredMonth, &enteredDay);
    
    
    if(!checkDate(enteredYear, enteredMonth, enteredDay)){
        printf("Invalid date.\n");
        return 1;
    }

    printf("Enter end year: ");
    scanf("%d", &enteredEndYear);
    
    valueOfDay = whichDay(enteredYear, enteredMonth, enteredDay);
        
    switch (valueOfDay){
    case 0:
        printf("It's a Saturday.\n");
        break;
    case 1:
        printf("It's a Sunday.\n");
        break;
    case 2:
        printf("It's a Monday.\n");
        break;
    case 3:
        printf("It's a Tuesday.\n");
        break;
    case 4:
        printf("It's a Wednesday.\n");
        break;
    case 5:
        printf("It's a Thursday.\n");
        break;
    case 6:
        printf("It's a Friday.\n");
        break;
    default:
        break;
    }

    numberDay = howManyDay(enteredYear, enteredMonth, enteredDay, valueOfDay, enteredEndYear);
    printf("Same day-and-month on same weekday between %d and %d: %d\n", enteredYear + 1, enteredEndYear, numberDay);

    return 0;
}

int checkDate(int year, int month, int day){
    if(month < 1 || month > 12){
        return 0;
    }
    else if(day < 1 || day > 31){
        return 0;
    }
    else if(month == 2 && (day < 1 || day > 28)){
        return 0;
    }
    else if(day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)){
        return 0;
    }
    return 1;
}

int whichDay(int year, int month, int day){
    int q, m, j, k, result;
    
    if(month == 1 || month == 2){
        month += 12;
        year -= 1;
    }

    q = day;
    m = month;
    j = year / 100;
    k = year % 100;

    result = (q + (13 * (m + 1) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    return result;
}

int howManyDay(int year, int month, int day, int valueOfSameDay, int endYear){    
    int howMany = 0, i;

    for(i = year + 1; i <= endYear; i++){
        if(valueOfSameDay == whichDay(i, month, day)){
            howMany += 1;
        }
    }
    return howMany;
}