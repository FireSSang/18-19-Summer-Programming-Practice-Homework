//
// Created by Wang Haoen on 2019/8/1.
//

#ifndef TEXT_2_SUBJECT_H
#define TEXT_2_SUBJECT_H

#include <bits/stdc++.h>

class Subject
{
    Subject();                                                  //无参构造函数
    Subject(std::string, double);                               //含参构造函数
    void set_subject_name(std::string);                         //写入科目名称
    std::string get_subject_name();                             //获取科目名称
    void set_subject_credit(double);                            //写入科目学分
    double get_subject_credit();                                //获取科目学分
    double get_average_score();                                 //获取平均成绩
    int get_number_of_student();                                //获取学生人数
    void set_student_score(std::string, std::string, double);   //录入学生成绩
    void calculate_average_score();                             //计算平均成绩
    double calculate_GPA(double);                               //计算学生绩点

private:
    std::string name;
    double credit;
    double average_score;
    int number_of_student;
    struct student
    {
        std::string student_name;
        std::string student_ID;
        double student_score;
        double student_GPA;
    };
    std::vector<student> list;
};

#endif //TEXT_2_SUBJECT_H
