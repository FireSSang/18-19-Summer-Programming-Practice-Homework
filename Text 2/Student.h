//
// Created by Wang Haoen on 2019/8/1.
//

#ifndef TEXT_2_STUDENT_H
#define TEXT_2_STUDENT_H

#include <bits/stdc++.h>

/**
 * 类 Student 的解释：
 * 本类中定义了学生的学号、姓名、总评成绩、绩点和所选科目数
 * 本类中使用结构体定义了学生需要记录的科目信息，包括学生所选科目名称、科目学分、科目成绩和科目绩点
 * 本类中使用STL中的容器vector存储科目信息
 * 本类中定义了如下函数，右侧标注了其主要功能
 * 在该类对应的.cpp文件中，对每个函数进行了详细的解释
 */

class Student
{
public:
    Student();                                      //无参构造函数
    Student(std::string, std::string, int);         //含参构造函数
    std::string get_ID();                           //读取学生学号
    void set_ID(std::string);                       //写入学生学号
    std::string get_name();                         //读取学生姓名
    void set_name(std::string);                     //写入学生姓名
    double get_total_score();                       //读取学生总评
    double get_total_credit();                      //读取学生学分
    double get_single_score(std::string);           //读取单科成绩
    void set_score(std::string, double, double);    //写入学生成绩
    void modify_score(std::string, double);         //修改学生成绩
    double calculate_GPA(double);                   //计算学生绩点
    double get_GPA();                               //读取学生绩点
    int get_rank();                                 //获取学生排名
    bool check_subject(std::string);                //查询是否已选


private:
    std::string ID;
    std::string name;
    double total_score;
    double total_credit;
    double GPA;
    int number_of_subjects;
    struct subject
    {
        std::string subject_name;
        double subject_credit;
        double subject_score;
        double subject_GPA;
    };
    std::vector<subject> list;
};


#endif //TEXT_2_STUDENT_H
