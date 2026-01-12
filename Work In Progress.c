//GitHub Repository Link: https://github.com/Kimanzi-Collins/C-Project
//Project Title: Smart Exam Revision Planner
//Read Project Documentation in README.md file in the repository
//Group Members:
//SCS3/2490/2025
//SCS3/9999/2025
//SCS3/2589/2025
//SCS3/150356/2025
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int calculateDaysLeft(int day, int month, int year){
    time_t now = time(NULL);
    struct tm today = *localtime(&now);
    struct tm exam = {0};
    exam.tm_mday = day;
    exam.tm_mon = month - 1;
    exam.tm_year = year - 1900;

    double seconds = difftime(mktime(&exam), mktime(&today));
    return (int)(seconds / (60 * 60 * 24));
}

void generateStudyTechnique(int difficultyLevel, int daysLeft, char studyTechnique[]){
    srand(time(NULL) + rand());
    const char *tips[] = {NULL};

    if (difficultyLevel == 3 && daysLeft <= 5) {
        const char *hardTips[] = {
            "Use active recall and timed practice.",
            "Focus on weak areas and revise daily.",
            "Study in short, intense sessions."
        };
        strcpy(studyTechnique, hardTips[rand() % 3]);
        printf("Study Tip: %s\n", studyTechnique);
    }
    else if (difficultyLevel == 2) {
        const char *mediumTips[] = {
            "Summarize notes and review regularly.",
            "Use flashcards for key concepts.",
            "Teach the topic to someone else."
        };
        strcpy(studyTechnique, mediumTips[rand() % 3]);
        printf("Study Tip: %s\n", studyTechnique);
    }
    else {
        const char *easyTips[] = {
            "Light revision and concept review.",
            "Practice a few questions daily.",
            "Maintain a steady study pace."
        };
        strcpy(studyTechnique, easyTips[rand() % 3]);
        printf("Study Tip: %s\n", studyTechnique);
    }    

}

struct Student{
    char name[50];
    char RegNo[20];
    char Course[50];
};

struct Subject{
    char subjectName[50];
    int difficultyLevel;
    int day;
    int month;
    int year;
    int DaysLeft;
    char studyTechnique[100];
};

void AddSubject(){
    struct Student student;
    struct Subject sub[100];
    int n, i;
    printf("---------------------------------------------------------------\n");
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", student.name);
    printf("Enter Registration Number: ");  
    scanf(" %[^\n]s", student.RegNo);
    printf("Enter Course Name: ");
    scanf(" %[^\n]s", student.Course);
    printf("Enter number of subjects to log: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter details for Subject %d:\n", i + 1);
        printf("Subject Name: ");
        scanf(" %[^\n]s", sub[i].subjectName);
        printf("Difficulty Level (1-Low, 2-Medium, 3-High): ");
        scanf("%d", &sub[i].difficultyLevel);
        printf("Exam Date (DD MM YYYY): ");
        scanf("%d %d %d", &sub[i].day, &sub[i].month, &sub[i].year);
        printf("Days Left for Exam: ");
        sub[i].DaysLeft = calculateDaysLeft(sub[i].day, sub[i].month, sub[i].year);
        printf("%d\n", sub[i].DaysLeft);
        generateStudyTechnique(sub[i].difficultyLevel, sub[i].DaysLeft, sub[i].studyTechnique);
    }
    FILE *fp;
    char filename[60];
    sprintf(filename, "%s.txt", student.name);
    fp = fopen(filename, "a");
    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "Student Name: %s\n", student.name);   
    fprintf(fp, "Registration Number: %s\n", student.RegNo);
    fprintf(fp, "Course Name: %s\n", student.Course);  
    for(i = 0; i < n; i++){
        fprintf(fp, "----------------------------------------\n");
        fprintf(fp, "Subject %d:\n", i + 1);
        fprintf(fp, "Subject Name: %s\n", sub[i].subjectName);
        fprintf(fp, "Difficulty Level: %d\n", sub[i].difficultyLevel);
        fprintf(fp, "Exam Date: %02d/%02d/%04d\n", sub[i].day, sub[i].month, sub[i].year);
        fprintf(fp, "Days Left for Exam: %d\n", sub[i].DaysLeft);
        fprintf(fp, "%s\n", sub[i].studyTechnique);
        fprintf(fp, "----------------------------------------\n");
    }
    fclose(fp);
    FILE *fpointer;
    char filee[60];
    sprintf(filee, "%s_priority.txt", student.name);
    fpointer = fopen(filee, "a");
    if(fpointer == NULL){
        printf("Error opening file!\n");
        return;
    }
    fprintf(fpointer, "Student Name: %s\n", student.name);   
    fprintf(fpointer, "Registration Number: %s\n", student.RegNo);
    fprintf(fpointer, "Course Name: %s\n", student.Course);
    for(i = 0; i < n; i++){
        if(sub[i].difficultyLevel == 3 || sub[i].DaysLeft <= 5){
            fprintf(fpointer, "----------------------------------------\n");
            fprintf(fpointer, "Subject %d:\n", i + 1);
            fprintf(fpointer, "Subject Name: %s\n", sub[i].subjectName);
            fprintf(fpointer, "Difficulty Level: %d\n", sub[i].difficultyLevel);
            fprintf(fpointer, "Exam Date: %02d/%02d/%04d\n", sub[i].day, sub[i].month, sub[i].year);
            fprintf(fpointer, "Days Left for Exam: %d\n", sub[i].DaysLeft);
            fprintf(fpointer, "%s\n", sub[i].studyTechnique);
            fprintf(fpointer, "----------------------------------------\n");
        }
    }
    fclose(fpointer);
}
