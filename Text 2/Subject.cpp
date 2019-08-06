//
// Created by Wang Haoen on 2019/8/1.
//

#include <bits/stdc++.h>
#include "Subject.h"

Subject::Subject()
{
    credit = 0;
    average_score = 0;
    number_of_student = 0;
}

Subject::Subject(std::string newName, double newCredit)
{
    name = newName;
    credit = newCredit;
    average_score = 0;
    number_of_student = 0;
}

void Subject::set_subject_name(std::string newName)
{
    name = newName;
}

std::string Subject::get_subject_name()
{
    return name;
}

void Subject::set_subject_credit(double newCredit)
{
    credit = newCredit;
}

double Subject::get_subject_credit()
{
    return credit;
}

double Subject::get_average_score()
{
    return average_score;
}

int Subject::get_number_of_student()
{
    return number_of_student;
}

void Subject::set_student_score(std::string studentName, std::string studentID, double studentScore)
{
    number_of_student++;
    student stud;
    stud.student_name = studentName;
    stud.student_ID = studentID;
    stud.student_score = studentScore;
    stud.student_GPA = calculate_GPA(stud.student_score);
    list.push_back(stud);
}

/**
 * 计算本科目平均分
 */
void Subject::calculate_average_score()
{
    double total_score = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        total_score += list[i].student_score;
    }
    average_score = total_score / number_of_student;
}

double Subject::calculate_GPA(double singleScore)
{
    double cred = 0;
    if (singleScore >= 90)
        cred = 4.0;
    else if (singleScore >= 85)
        cred = 3.7;
    else if (singleScore >= 82)
        cred = 3.3;
    else if (singleScore >= 78)
        cred = 3.0;
    else if (singleScore >= 75)
        cred = 2.7;
    else if (singleScore >= 72)
        cred = 2.3;
    else if (singleScore >= 68)
        cred = 2.0;
    else if (singleScore >= 64)
        cred = 1.5;
    else if (singleScore >= 60)
        cred = 1.0;
    else
        cred = 0;
    return cred;
}



