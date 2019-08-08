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
 * 本类中使用 STL 中的容器 vector 存储科目信息
 * 本类中定义了如下函数，右侧标注了其主要功能
 * 在该类对应的.cpp文件中，对每个函数进行了详细的解释
 */
class Student
{
public:
    Student();                                              //无参构造函数
    Student(std::string, std::string);                      //含参构造函数
    std::string get_ID();                                   //读取学生学号
    std::string get_name();                                 //读取学生姓名
    double get_total_score();                               //读取学生加权
    double get_total_credit();                              //读取学生学分
    void set_score(std::string, double, double);            //写入学生成绩
    double get_GPA();                                       //读取学生绩点
    void set_rank(int);                                     //写入学生排名
    int get_rank();                                         //获取学生排名
    int get_number_of_subject();                            //获取选课数量
    void modify_score(std::string, double);                 //修改学生成绩
    void delete_score(std::string);                         //删除学生成绩
    void show_information();                                //展示科目信息
    bool check_subject(std::string);                        //查询是否已选

    void get_subject(int, std::string&, double&, double&);  //保存文件函数

private:
    std::string ID;
    std::string name;
    double total_score;
    double total_credit;
    double GPA;
    int rank;
    int number_of_subject;
    struct subject
    {
        std::string subject_name;
        double subject_credit;
        double subject_score;
        double subject_GPA;
    };
    std::vector<subject> list;

    static double calculate_single_GPA(double);            //计算单科绩点
    double calculate_total_GPA();                          //计算学生绩点
    double calculate_total_score();                        //计算学生加权
    static bool sort_with_credit(subject, subject);        //比较函数，将科目按学分降序排序
};

#endif //TEXT_2_STUDENT_H
