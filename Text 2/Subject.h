//
// Created by Wang Haoen on 2019/8/1.
//

#ifndef TEXT_2_SUBJECT_H
#define TEXT_2_SUBJECT_H

#include <bits/stdc++.h>

/**
 * 类 Subject 的解释：
 * 本类中定义了科目的名称、学分、平均成绩和选课人数
 * 本类中使用结构体定义了选修了该学科学生的信息，包括学生学号、学生姓名、学生成绩和学生绩点
 * 本类中使用 STL 中的容器 vector 存储学生信息
 * 本类中定义了如下函数，右侧标注了其主要功能
 * 在该类对应的.cpp文件中，对每个函数进行了详细的解释
 */
class Subject
{
public:
    Subject();                                                  //无参构造函数
    Subject(std::string, double);                               //含参构造函数
    std::string get_subject_name();                             //获取科目名称
    double get_subject_credit();                                //获取科目学分
    int get_number_of_student();                                //获取学生人数
    void set_student_score(std::string, std::string, double);   //录入学生成绩
    void modify_score(std::string, double);                     //修改学生成绩
    void delete_student(std::string);                           //删除学生成绩
    void show_information();                                    //展示学生信息

private:
    std::string name;
    double credit;
    double average_score;
    int number_of_student;
    struct student
    {
        std::string student_ID;
        std::string student_name;
        double student_score;
        double student_GPA;
    };
    std::vector<student> list;

    void calculate_average_score();                             //计算平均成绩
    static double calculate_GPA(double);                        //计算学生绩点
    static bool sort_with_score(student a, student b);          //比较函数，将学生按成绩降序排序
};

#endif //TEXT_2_SUBJECT_H
