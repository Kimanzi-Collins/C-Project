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