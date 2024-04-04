#include<stdio.h>
#include<string.h>

struct CourseRecord
{
    char fst_name[20];
    char lst_name[20];
    int roll_no;
    char department[20];
    int course_code;
    int marks[3];
} record;

int calculateAverageTestMarks(struct CourseRecord record) {
    int totalMarks = 0;
    for (int i = 0; i < 3; i++) {
        totalMarks += record.marks[i];
    }
    return totalMarks / 3; // Integer division
}

int Pass(struct CourseRecord record) {
    int averageMarks = calculateAverageTestMarks(record);
    if (averageMarks >= 35) {
        return 1; // Pass
    } else {
        return 0; // Fail
    }
}

int main() {
    strcpy(record.fst_name, "Ajay");
    strcpy(record.lst_name, "Matasugur");
    record.roll_no = 2301001;
    strcpy(record.department, "Civil");
    record.course_code = 1234;
    record.marks[0] = 34;
    record.marks[1] = 67;
    record.marks[2] = 56;

    printf("Students name: %s %s\n",record.fst_name,record.lst_name);
    printf("Roll no. : %d\n",record.roll_no);
    printf("Students department: %s\n",record.department);
    printf("Course code: %d\n",record.course_code);
    int averageMarks = calculateAverageTestMarks(record);
    printf("\nAverage Test Marks: %d\n", averageMarks);
    if (Pass(record)) {
        printf("Student passed the test\n");
    } else {
        printf("Student failed the test\n");
    }

    return 0;
}


