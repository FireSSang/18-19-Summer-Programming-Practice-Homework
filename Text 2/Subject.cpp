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

/**
 * 添加学生信息到该科目下
 * 添加结束后统计平均分
 */
void Subject::set_student_score(std::string studentID, std::string studentName, double studentScore)
{
    number_of_student++;
    student stud;
    stud.student_ID = studentID;
    stud.student_name = studentName;
    stud.student_score = studentScore;
    stud.student_GPA = calculate_GPA(stud.student_score);
    list.push_back(stud);
    calculate_average_score();
    sort(list.begin(), list.begin() + list.size(), sort_with_score);
}

/**
 * 修改某一学生
 * 考虑到学号的唯一性，此处采用学号修改
 */
void Subject::modify_score(std::string studentID, double studentScore)
{
    for (int i = 0; i < list.size(); ++i)
    {
        if (list[i].student_ID == studentID)
        {
            list[i].student_score = studentScore;
            break;
        }
    }
    calculate_average_score();
    sort(list.begin(), list.begin() + list.size(), sort_with_score);
}

/**
 * 删除某一学生
 * 考虑到学号的唯一性，此处采用学号删除
 */
void Subject::delete_student(std::string studentID)
{
    for (int i = 0; i < list.size(); ++i)
    {
        if (list[i].student_ID == studentID)
        {
            list.erase(list.begin() + i);
            break;
        }
    }
    number_of_student--;
    calculate_average_score();
}

/**
 * 按一定格式输出科目信息
 * 科目信息包括科目名称、科目学分、平均成绩、选课人数
 * 输出选课人数 n
 * 以下 n 行，输出每个学生信息
 * 包括排名、学生学号、学生姓名、学生成绩、学生GPA
 */
void Subject::show_information()
{
    std::cout << std::left;
    std::cout << "科目名称：" << name << std::endl;
    std::cout << "科目学分：" << std::fixed << std::setprecision(1) << credit << std::endl;
    std::cout << "平均成绩：" << std::fixed << std::setprecision(2) << average_score << std::endl;
    std::cout << "选课人数：" << number_of_student << std::endl;
    std::cout << std::setw(6) << "排名" << " " << std::setw(16) << " " << "学号" << std::setw(16) << "姓名" << " " << std::setw(6) << "成绩" << " " << std::setw(6) << "GPA " << std::endl;
    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << std::left;
        std::cout << std::setw(6) << i+1 << " ";
        std::cout << std::setw(16) << list[i].student_ID << " ";
        std::cout << std::setw(16) << list[i].student_name << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << list[i].student_score << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << list[i].student_GPA << std::endl;
    }
    std::cout << std::endl;
}




////private

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

/**
 * 计算GPA
 * 采用天津大学GPA计算方式
 */
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



/**
 * 比较函数
 * 在添加学生信息后对学生的vector按成绩降序重新排序
 */
bool Subject::sort_with_score(student a, student b)
{
    return a.student_score > b.student_score;
}
