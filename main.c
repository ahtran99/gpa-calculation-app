/*
 * Alexander Tran
 * January 26, 2022,
 * Developing a GPA Calculation Application using array of structures and files in C
 */

#include <stdio.h>
#include <string.h>

#define MAX_COURSES 4

typedef struct course {
    char courseID[20];
    int credits;
    float grade;
} Course;

// Update a course grade in the list of course
void updateCourseGrade(Course courses[]);

// Find Maximum Grade. This is a recursive function and you need to implement
int max(int n1, int n2);

float findMaxGrade(Course courses[], int n);

// Display a list of courses taken by student
void display(Course courses[]);

// Compute the accumulative GPA for all courses
float gradePoints(float grade);

float computeGPA(Course courses[]);

// Save all courses and grades in an output file called "output.txt"
void saveCourses(char str[], Course courses[]);

int main() {
    // Declaring three variables, including name, selecting numbers and course struct
    char name[20];
    int choice;
    Course course[4];

    // Ask users to enter name
    printf("Enter your name: ");
    scanf("%s", name);

    // Prints welcome statements
    printf("Welcome %s\n", name);

    // Keep the menu using while loop
    while (choice != 6) {
        printf("---------------------------------\n");
        printf("Operations on Courses\n");
        printf("---------------------------------\n");
        printf("1.Update Course Grade\n");
        printf("2.Find Maximum Grade\n");
        printf("3.Display Courses\n");
        printf("4.Compute Accumulative GPA\n");
        printf("5.Save the courses to a File\n");
        printf("6.Exit\n");
        printf("Enter your choice\n", &choice);

        // Ask users to enter a number between 1-6
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Update Course Grade:\n");
                updateCourseGrade(course);
                break;
            case 2:
                printf("Maximum Grade = %f\n", findMaxGrade(course, MAX_COURSES));
                break;
            case 3:
                printf("Display Courses:\n");
                display(course);
                break;
            case 4:
                printf("Compute Accumulative GPA\n");
                printf("GPA = %f\n", computeGPA(course));
                break;
            case 5:
                printf("Saving Courses to the File\n");
                saveCourses("output.txt", course);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("INVALID INPUT\n");
                break;
        }
    }

    return 0;
}

// Update a course grade in the list of course
void updateCourseGrade(Course courses[]) {
    char search[10];
    float changeGrade;

    printf("Enter Course ID\n");
    scanf("%s", search);

    FILE *fp;
    fp = fopen("grades.txt", "r+");

    for (int i = 0; i < MAX_COURSES; i++) {
        fscanf(fp, "%s%d%f", courses[i].courseID, &courses[i].credits, &courses[i].grade);
        if (strcmp(search, courses[i].courseID) == 0) {
            printf("Enter Course Grade:\n");
            scanf("%d", &changeGrade);
        }
    }
    fclose(fp);
}

// Find Maximum Grade. This is a recursive function and you need to implement
int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

float findMaxGrade(Course courses[], int n) {
    if (n < 2)
        return courses[0].grade;
    return max(courses[n - 1].grade, findMaxGrade(courses, n - 1));
}

// Display a list of courses taken by student
void display(Course courses[]) {
    FILE *in_fp;
    in_fp = fopen("grades.txt", "r");
    for (int i = 0; i < MAX_COURSES; i++) {
        fscanf(in_fp, "%s%d%f", courses[i].courseID, &courses[i].credits, &courses[i].grade);
        printf("%-10s   %-10d   %-10f\n", courses[i].courseID, courses[i].credits, courses[i].grade);
    }
    fclose(in_fp);
}

// Compute the accumulative GPA for all courses
float gradePoints(float grade) {
    float gradeValue = 0;
    if (grade >= 90 && grade <= 100) {
        gradeValue = 4.0f;
    } else if (grade >= 85 || grade <= 89) {
        gradeValue = 3.8f;
    } else if (grade >= 80 || grade <= 84) {
        gradeValue = 3.6f;
    } else if (grade >= 75 || grade <= 79) {
        gradeValue = 3.3f;
    } else if (grade >= 70 || grade <= 74) {
        gradeValue = 3.0f;
    } else if (grade >= 65 || grade <= 69) {
        gradeValue = 2.5f;
    } else if (grade >= 60 || grade <= 64) {
        gradeValue = 2.0f;
    } else if (grade >= 55 || grade <= 59) {
        gradeValue = 1.5f;
    } else if (grade >= 50 || grade <= 54) {
        gradeValue = 1.0f;
    } else {
        gradeValue = 0.0f;
    }
    return gradeValue;
}

float computeGPA(Course courses[]) {
    float weightedCredVal;
    float totalCredits = 0;
    float totalWeightCredVal = 0;
    float totalGPA;
    for (int i = 0; i < MAX_COURSES; i++) {
        weightedCredVal = courses[i].credits * gradePoints(courses[i].grade);
        totalWeightCredVal += weightedCredVal;
    }
    for (int i = 0; i < MAX_COURSES; i++) {
        totalCredits += courses[i].credits;
    }
    totalGPA = totalWeightCredVal / totalCredits;
    return totalGPA;
}

// Save all courses and grades in an output file called "output.txt"
void saveCourses(char str[], Course courses[]) {
    FILE *in_fp, *out_fp;
    in_fp = fopen("grades.txt", "r");
    out_fp = fopen(str[10], "w");
    for (int i = 0; i < MAX_COURSES; ++i) {
        fscanf(in_fp, "%s%d%f", courses[i].courseID, &courses[i].credits, &courses[i].grade);
        fprintf(out_fp, "%-10s   %-10d   %-10f\n", courses[i].courseID, courses[i].credits, courses[i].grade);
    }
    fclose(in_fp);
    fclose(out_fp);
}