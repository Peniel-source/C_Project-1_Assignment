#include <stdio.h>

/*define maximum number of routes*/
#define R 100

/*prototypes*/
int find_total(int arr[], int num);
float calculate_avg(int arr[], int num);
int calculate_longest(int arr[], int num);
int above_limit(int arr[], int num, int limit);
int sum_distance(int arr[], int num);

int main()
{
    /*variables*/
    int distances[R];
    int n;
    int i;
    float average;
    int count, limit, total, longest, r_total;

    /*get the number of routes*/
    printf("Enter the number of routes: ");
    /*store it in n but check if scanf returns 1. this is to ensure the user enters a number*/
    if (scanf("%d", &n) != 1) {
        printf("Invalid. please enter a number\n");
        return 1;
    }
    /*n must be greater than 0 and should not be more than the maximum number of routes*/
    if (n < 1 || n > R) {
        printf("Invalid. number of routes must be between 1 and %d\n", R);
        return 1;
    }

    /*read the distances and handle errors*/
    for (i = 0; i < n; i++) {
        printf("Distance for route %d: ", i + 1);
        if (scanf("%d", &distances[i]) != 1) {
            printf("Invalid. Enter a number\n");
            return 1;
        }
        if (distances[i] <= 0) {
            printf("Error. distance must be greater than zero\n");
            return 1;
        }
    }

    /*get and read the limit from the user. and handle invalid inputs*/
    printf("Enter the distance limit: ");
    if (scanf("%d", &limit) != 1) {
        printf("Invalid. Enter a number\n");
        return 1;
    }
    if (limit < 0) {
        printf("Invalid. Limit cannot be negative.\n");
        return 1;
    }

    /*call the functions*/
    total = find_total(distances, n);
    average = calculate_avg(distances, n);
    longest = calculate_longest(distances, n);
    count = above_limit(distances, n, limit);
    r_total = sum_distance(distances, n);

    /*display the report*/
    printf("\n====DELIVERY DISTANCE ANALYSIS=====\n");
    printf("\nTotal distance: %d km\n", total);
    printf("Average distance: %.2f km\n", average);
    printf("Longest route: %d km\n", longest);
    printf("Routes above %d km: %d\n", limit, count);
    printf("\nRecursive sum: %d km\n", r_total);   
}

int find_total(int arr[], int num) {
    int total = 0;
    int i;
    for (i = 0; i < num; i++) {
        total += arr[i];
    }
    return total;
}

float calculate_avg(int arr[], int num) {
    if (num == 0) {
        return 0.0f;
    }
    /*I'm resuing find_total here, but I'm casting it to float for average outcomes*/
    return (float)find_total(arr, num) / num; 
}

int calculate_longest(int arr[], int num) {
    if (num <= 0) {
        return 0;
    }
    int longest = arr[0];
    int i;
    for (i = 1; i < num; i++) {
        if (arr[i] > longest) {
            longest = arr[i];
        }
    }
    return longest;
}

int above_limit(int arr[], int num, int limit) {
    int count = 0;
    int i;
    for (i = 0; i < num; i++) {
        if (arr[i] > limit) {
            count++;
        }
    }
    return count;
}

int sum_distance(int arr[], int num) {
    if (num == 0) {
        return 0;
    }
    /*recursion*/
    return arr[num - 1] + sum_distance(arr, num - 1);
}