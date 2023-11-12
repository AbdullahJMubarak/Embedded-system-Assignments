#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CLASSES 3
#define NUM_STUDENTS 10
#define TOTAL_GRADE 100
#define PASSING_GRADE 50

int main() {
    int classes[NUM_CLASSES][NUM_STUDENTS];
    int passed = 0, failed = 0;
    int highest_grade = 0, lowest_grade = TOTAL_GRADE;
    int total_grades = 0;

    
    srand(time(0));

  
    for (int class_num = 0; class_num < NUM_CLASSES; class_num++) {
        printf("Class %d grades:\n", class_num + 1);
        for (int student = 0; student < NUM_STUDENTS; student++) {
            classes[class_num][student] = rand() % (TOTAL_GRADE + 1);
            printf("Student %d: %d\n", student + 1, classes[class_num][student]);

           
            total_grades += classes[class_num][student];
            if (classes[class_num][student] >= PASSING_GRADE) {
                passed++;
            } else {
                failed++;
            }

            if (classes[class_num][student] > highest_grade) {
                highest_grade = classes[class_num][student];
            }

            if (classes[class_num][student] < lowest_grade) {
                lowest_grade = classes[class_num][student];
            }
        }
        printf("\n");
    }


    float average_grade = (float)total_grades / (NUM_CLASSES * NUM_STUDENTS);


    printf("Statistics:\n");
    printf("Number of Passed Students: %d\n", passed);
    printf("Number of Failed Students: %d\n", failed);
    printf("Highest Grade: %d\n", highest_grade);
    printf("Lowest Grade: %d\n", lowest_grade);
    printf("Average Grade: %.2f\n", average_grade);

    return 0;
}
