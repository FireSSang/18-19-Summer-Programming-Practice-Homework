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
    rank = 0;
    number_of_subject = 0;
}

Student::Student(std::string newID, std::string newName, int newNumber)
{
    ID = newID;
    name = newName;
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    rank = 0;
    number_of_subject = newNumber;
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
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            return list[i].subject_score;
        }
    }
}

void Student::set_score(std::string subjectName, double credit, double newScore)
{
    number_of_subject++;
    total_credit += credit;
    subject subj;
    subj.subject_name = subjectName;
    subj.subject_credit = credit;
    subj.subject_score = newScore;
    subj.subject_GPA = calculate_single_GPA(subj.subject_score);
    list.push_back(subj);
    calculate_total_GPA();
    calculate_total_score();
    sort(list.begin(), list.begin() + list.size(), sort_with_credit);
}

void Student::modify_score(std::string subjectName, double newScore)
{
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            list[i].subject_score = newScore;
            list[i].subject_GPA = calculate_single_GPA(list[i].subject_score);
            break;
        }
    }
    calculate_total_GPA();
    calculate_total_score();
}

void Student::delete_score(std::string subjectName)
{
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            total_credit -= list[i].subject_credit;
            list.erase(list.begin() + i);
            break;
        }
    }
    number_of_subject--;
    calculate_total_GPA();
    calculate_total_score();
}

double Student::get_GPA()
{
    return GPA;
}

void Student::set_rank(int newRank)
{
    rank = newRank;
}

int Student::get_rank()
{
    return rank;
}

int Student::get_number_of_subject()
{
    return number_of_subject;
}


/**
 * 按一定格式输出学生的各项信息，包括以下方面：
 * 年级排名 姓名 学号 加权成绩 GPA 总学分 选课数目
 * 输出学生所选科目数量 n
 * 以下 n 行，输出每科目信息
 * 包括科目名称、科目学分、科目成绩、科目GPA
 */
void Student::show_subject()
{
    std::cout << std::left;
    std::cout << "年级排名：" << rank << std::endl;
    std::cout << "学生学号：" << ID << std::endl;
    std::cout << "学生姓名：" << name << std::endl;
    std::cout << "加权成绩：" << std::fixed << std::setprecision(1) << total_score << std::endl;
    std::cout << "  GPA  ：" << std::fixed << std::setprecision(1) << GPA << std::endl;
    std::cout << "总修学分：" << std::fixed << std::setprecision(1) << total_credit << std::endl;
    std::cout << "选课数量：" << number_of_subject << std::endl;
    std::cout << std::setw(22) << "科目名称 " << std::setw(7) << "学分 " << std::setw(7) << "成绩 " << std::setw(7) << "GPA " << std::endl;
    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << std::left;
        std::cout << std::setw(20) << list[i].subject_name << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << list[i].subject_credit << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << list[i].subject_score << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << list[i].subject_GPA << std::endl;
    }
    std::cout << std::endl;
}

/**
 * 检测该学生是否已经录入某一科目信息
 * 已录入返回true，否则返回false
 */
bool Student::check_subject(std::string subjectName)
{
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
            return true;
    }
    return false;
}

////private

/**
 * 计算单科成绩GPA
 * 采用天津大学GPA计算方式
 */
double Student::calculate_single_GPA(double singleScore)
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

/**
 * 计算总GPA
 * 总GPA计算方式：（单科GPA * 单科学分）（求和） / 总学分
 */
double Student::calculate_total_GPA()
{
    double total_weighted_GPA = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        total_weighted_GPA += list[i].subject_GPA * list[i].subject_credit;
    }
    GPA = total_weighted_GPA / total_credit;
}

/**
 * 计算加权成绩
 * 加权成绩计算方式：（单科成绩 * 单科学分）（求和） / 总学分
 */
double Student::calculate_total_score()
{
    double total_weighted_score = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        total_weighted_score += list[i].subject_score * list[i].subject_credit;
    }
    total_score = total_weighted_score / total_credit;
}

/**
 * 比较函数
 * 在添加科目信息后对科目的vector按学分降序重新排序
 */
bool Student::sort_with_credit(Student::subject a, Student::subject b)
{
    return a.subject_credit > b.subject_credit;
}




