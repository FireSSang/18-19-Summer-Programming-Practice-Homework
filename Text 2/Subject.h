//
// Created by Wang Haoen on 2019/8/1.
//

#ifndef TEXT_2_SUBJECT_H
#define TEXT_2_SUBJECT_H

#include <bits/stdc++.h>

class Subject
{
    Subject();                                                  //�޲ι��캯��
    Subject(std::string, double);                               //���ι��캯��
    void set_subject_name(std::string);                         //д���Ŀ����
    std::string get_subject_name();                             //��ȡ��Ŀ����
    void set_subject_credit(double);                            //д���Ŀѧ��
    double get_subject_credit();                                //��ȡ��Ŀѧ��
    double get_average_score();                                 //��ȡƽ���ɼ�
    int get_number_of_student();                                //��ȡѧ������
    void set_student_score(std::string, std::string, double);   //¼��ѧ���ɼ�
    void calculate_average_score();                             //����ƽ���ɼ�
    double calculate_GPA(double);                               //����ѧ������

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
