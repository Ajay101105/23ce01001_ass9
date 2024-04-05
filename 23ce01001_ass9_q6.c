#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 100
#define MAX_RECORDS 100

struct StudentRecord {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float percentage;
};

struct StudentRecord database[MAX_RECORDS];

int numRecords = 0;

void insert(char *name, int rollNumber, float percentage) {
    strcpy(database[numRecords].name, name);
    database[numRecords].rollNumber = rollNumber;
    database[numRecords].percentage = percentage;
    numRecords++;
}

void sortName() {
    struct StudentRecord temp;
    for (int i = 0; i < numRecords - 1; i++) {
        for (int j = i + 1; j < numRecords; j++) {
            if (strcmp(database[i].name, database[j].name) > 0) {
                temp = database[i];
                database[i] = database[j];
                database[j] = temp;
            }
        }
    }
}

void findOne(char *prefix) {
    int prefixLength = strlen(prefix);
    for (int i = 0; i < numRecords; i++) {
        int match = 1;
        for (int j = 0; j < prefixLength; j++) {
            if (database[i].name[j] != prefix[j]) {
                match = 0;
                break;
            }
        }
        if (match==1) {
            printf("Found: %s (Roll Number: %d, Percentage: %.2f)\n", database[i].name, database[i].rollNumber, database[i].percentage);
            return;
        }
    }
    printf("No record found with name starting with '%s'\n", prefix);
}

float calculateMean() {
    float sum = 0;
    for (int i = 0; i < numRecords; i++) {
        sum += database[i].percentage;
    }
    return sum / numRecords;
}

float calculateStandardDeviation(float mean) {
    float variance = 0;
    for (int i = 0; i < numRecords; i++) {
        variance += pow(database[i].percentage - mean, 2);
    }
    return sqrt(variance / numRecords);
}

void specs() {
    printf("Number of records: %d\n", numRecords);

    if (numRecords == 0) {
        printf("No records to show.\n");
        return;
    }

    float highest = database[0].percentage, lowest = database[0].percentage;
    for (int i = 1; i < numRecords; i++) {
        if (database[i].percentage > highest)
            highest = database[i].percentage;
        if (database[i].percentage < lowest)
            lowest = database[i].percentage;
    }
    printf("Highest percentage: %.2f\n", highest);
    printf("Lowest percentage: %.2f\n", lowest);

    float mean = calculateMean();
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", calculateStandardDeviation(mean));
}

void delete(int rollNumber) {
    int i, found = 0;
    for (i = 0; i < numRecords; i++) {
        if (database[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }

    if (found==1) {
        for (; i < numRecords - 1; i++) {
            database[i] = database[i + 1];
        }
        numRecords--;
        printf("Record with roll number %d deleted successfully.\n", rollNumber);
    } else {
        printf("Record with roll number %d not found.\n", rollNumber);
    }
}

int main() {
    int choice = 0;
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float percentage;
    char prefix[MAX_NAME_LENGTH];

    while (choice != 5) {
        printf("\n1. Insert record\n");
        printf("2. Find record by name prefix\n");
        printf("3. Show specifications\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter roll number: ");
                scanf("%d", &rollNumber);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                insert(name, rollNumber, percentage);
                sortName(); // Sort after insertion
                break;
            case 2:
                printf("Enter name prefix: ");
                scanf("%s", prefix);
                findOne(prefix);
                break;
            case 3:
                specs();
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                delete(rollNumber);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
