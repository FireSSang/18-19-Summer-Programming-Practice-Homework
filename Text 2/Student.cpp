//
// Created by Wang Haoen on 2019/8/1.
//

#include <bits/stdc++.h>
#include "Student.h"

/**
 * 无参的构造函数
 */
Student::Student()
{
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    rank = 0;
    number_of_subject = 0;
}

/**
 * 含参的构造函数
 * 创建一个学号为 newID ， 姓名为 newName 的学生
 */
Student::Student(std::string newID, std::string newName)
{
    ID = newID;
    name = newName;
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    rank = 0;
    number_of_subject = 0;
}

/**
 * 返回学生学号
 */
std::string Student::get_ID()
{
    return ID;
}

/**
 * 返回学生姓名
 */
std::string Student::get_name()
{
    return name;
}

/**
 * 返回加权成绩
 */
double Student::get_total_score()
{
    return total_score;
}

/**
 * 返回总学分
 */
double Student::get_total_credit()
{
    return total_credit;
}

/**
 * 为该学生添加一门新的科目
 * 科目名称为 subjectName
 * 科目学分为 credit
 * 科目成绩为 newScore
 * 添加完成后计算 GPA 和加权成绩
 * 并对科目按 sort_with_credit() 排序
 */
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
    sort(list.begin(), list.begin() + list.size(), sort_with_credit);//排序
}

/**
 * 返回 GPA
 */
double Student::get_GPA()
{
    return GPA;
}

/**
 * 将学生年级排名记录为 newRank
 */
void Student::set_rank(int newRank)
{
    rank = newRank;
}

/**
 * 返回年级排名
 */
int Student::get_rank()
{
    return rank;
}

/**
 * 返回选课数目
 */
int Student::get_number_of_subject()
{
    return number_of_subject;
}

/**
 * 修改科目成绩
 * 科目名称为 subjectName
 * 新成绩为 newScore
 * 计算本科目 GPA
 * 修改完成后计算 GPA 和加权成绩
 * 无需排序，因为科目学分未更改
 */
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

/**
 * 删除科目成绩
 * 修改完成后计算 GPA 和加权成绩
 * 无需排序，因为删除前序列有序
 */
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

/**
 * 按一定格式输出学生的各项信息，包括以下方面：
 * 年级排名 姓名 学号 加权成绩 GPA 总学分 选课数目
 * 输出学生所选科目数量 n
 * 以下 n 行，输出每科目信息
 * 包括科目名称、科目学分、科目成绩、科目GPA
 */
void Student::show_information()
{
    std::cout << std::left;
    std::cout << "年级排名：" << rank << std::endl;
    std::cout << "学生学号：" << ID << std::endl;
    std::cout << "学生姓名：" << name << std::endl;
    std::cout << "加权成绩：" << std::fixed << std::setprecision(1) << total_score << std::endl;
    std::cout << " G P A ：" << std::fixed << std::setprecision(1) << GPA << std::endl;
    std::cout << "总修学分：" << std::fixed << std::setprecision(1) << total_credit << std::endl;
    std::cout << "选课数量：" << number_of_subject << std::endl;
    std::cout << std::setw(20) << "科目名称" << " " << std::setw(6) << "学分" << " " << std::setw(6) << "成绩" << " " << std::setw(6) << "GPA " << std::endl;
    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << std::left;
        std::cout << std::setw(20) << list[i].subject_name << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(2) << list[i].subject_credit << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(2) << list[i].subject_score << " ";
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

/**
 * index 是科目索引，从 0 到 number_of_subject-1
 * 定义本函数的原因是：该类下 list 为私有成员，其内部参数不能被 System 中函数直接调用，定义本函数以通过引用传递方式回传信息
 */
void Student::get_subject(int index, std::string& subjectName, double& subjectCredit, double& subjectScore)
{
    subjectName = list[index].subject_name;
    subjectCredit = list[index].subject_credit;
    subjectScore = list[index].subject_score;
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
