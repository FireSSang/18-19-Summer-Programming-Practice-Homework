//
// Created by Wang Haoen on 2019/8/1.
//

#include <bits/stdc++.h>
#include "Student.h"

Student::Student()
{
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    number_of_subjects = 0;
}

Student::Student(std::string newID, std::string newName, int newNumber)
{
    ID = newID;
    name = newName;
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    number_of_subjects = newNumber;
}

std::string Student::get_ID()
{
    return ID;
}

void Student::set_ID(std::string newID)
{
    ID = newID;
}

std::string Student::get_name()
{
    return name;
}

void Student::set_name(std::string newName)
{
    name = newName;
}

double Student::get_total_score()
{
    return total_score;
}

double Student::get_total_credit()
{
    return total_credit;
}

double Student::get_single_score(std::string subjectName)
{
    for (int i = 0; i < number_of_subjects; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            return list[i].subject_score;
        }
    }
}

void Student::set_score(std::string subjectName, double credit, double newScore)
{
    number_of_subjects++;
    total_credit += credit;
    subject subj;
    subj.subject_name = subjectName;
    subj.subject_credit = credit;
    subj.subject_score = newScore;
    subj.subject_GPA = calculate_GPA(subj.subject_score);
    list.push_back(subj);
}

void Student::modify_score(std::string subjectName, double newScore)
{
    for (int i = 0; i < number_of_subjects; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            list[i].subject_score = newScore;
            list[i].subject_GPA = calculate_GPA(list[i].subject_score);
            //TODO
            return;
        }
    }
}


double Student::calculate_GPA(double singleScore)
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

double Student::get_GPA()
{
    return GPA;
}

int Student::get_rank()
{
    return 0;
}

bool Student::check_subject(std::string subjectName)
{
    for (int i = 0; i < number_of_subjects; ++i)
    {
        if (list[i].subject_name == subjectName)
            return true;
    }
    return false;
}



