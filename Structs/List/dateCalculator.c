#include <stdio.h>
/* Struct - List 2 - Exercise 6 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year) {
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) {
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (isLeapYear(year) == 1)) {
        daysPerMonth[month-1] = 29;
    }
    return daysPerMonth[month-1];
}

int getRemainingDaysInMonth(Date date) {
    int remainingDays = 0;
    if (date.day != getDaysInMonth(date.month, date.year)) {
        remainingDays += getDaysInMonth(date.month, date.year) - date.day;
    }
    return remainingDays;
}

int calculateDaysBetweenDates(Date startDate, Date endDate) {
    Date tempDate;
    int yearsDiff = 0, monthsDiff = 0;
    
    if (startDate.year > endDate.year || 
        (startDate.year == endDate.year && startDate.month > endDate.month) ||
        (startDate.year == endDate.year && startDate.month == endDate.month && startDate.day > endDate.day)) {
        tempDate = startDate;
        startDate = endDate;
        endDate = tempDate;
    }
    
    yearsDiff = endDate.year - startDate.year;
    
    if (yearsDiff != 0) {
        monthsDiff = yearsDiff * 12;
    }
    monthsDiff = (monthsDiff - startDate.month) + endDate.month;
    
    int totalDays = 0;
    totalDays += getRemainingDaysInMonth(startDate);
    
    if (!(startDate.year == endDate.year && startDate.month == endDate.month)) {
        totalDays += getRemainingDaysInMonth(endDate);
    }
    
    int currentYear = startDate.year;
    int intermediateMonthsDays = 0;
    
    for (int i = startDate.month + 1; i <= startDate.month + monthsDiff - 1; i++) {
        int currentMonth = ((i - 1) % 12) + 1;
        if (currentMonth == 1 && i != startDate.month + 1) {
            currentYear++;
        }
        intermediateMonthsDays += getDaysInMonth(currentMonth, currentYear);
    }
    
    totalDays += intermediateMonthsDays;
    return totalDays;
}

void runTestCases() {
    Date date1 = {1, 1, 2023};
    Date date2 = {31, 12, 2023};
    printf("Test 1: Days between 01/01/2023 and 31/12/2023: ");
    printf("%d days\n", calculateDaysBetweenDates(date1, date2));
    
    Date date3 = {1, 1, 2024};
    Date date4 = {29, 2, 2024};
    printf("Test 2: Days between 01/01/2024 and 29/02/2024: ");
    printf("%d days\n", calculateDaysBetweenDates(date3, date4));
}

void getUserDates() {
    Date startDate, endDate;
    
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &startDate.day, &startDate.month, &startDate.year);
    
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &endDate.day, &endDate.month, &endDate.year);
    
    int daysDifference = calculateDaysBetweenDates(startDate, endDate);
    printf("Days between dates: %d days\n", daysDifference);
}

int main() {
    int userOption;
    
    do {
        printf("\nDate Calculator\n");
        printf("1. Run test cases\n");
        printf("2. Calculate days between two dates\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userOption);
        
        switch(userOption) {
            case 1:
                runTestCases();
                break;
            case 2:
                getUserDates();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(userOption != 0);
    
    return 0;
}