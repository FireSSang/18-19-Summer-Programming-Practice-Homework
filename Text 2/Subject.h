//
// Created by Wang Haoen on 2019/8/1.
//

#ifndef TEXT_2_SUBJECT_H
#define TEXT_2_SUBJECT_H

#include <bits/stdc++.h>

/**
 * �� Subject �Ľ��ͣ�
 * �����ж����˿�Ŀ�����ơ�ѧ�֡�ƽ���ɼ���ѡ������
 * ������ʹ�ýṹ�嶨����ѡ���˸�ѧ��ѧ������Ϣ������ѧ��ѧ�š�ѧ��������ѧ���ɼ���ѧ������
 * ������ʹ�� STL �е����� vector �洢ѧ����Ϣ
 * �����ж��������º������Ҳ��ע������Ҫ����
 * �ڸ����Ӧ��.cpp�ļ��У���ÿ��������������ϸ�Ľ���
 */
class Subject
{
public:
    Subject();                                                  //�޲ι��캯��
    Subject(std::string, double);                               //���ι��캯��
    std::string get_subject_name();                             //��ȡ��Ŀ����
    double get_subject_credit();                                //��ȡ��Ŀѧ��
    int get_number_of_student();                                //��ȡѧ������
    void set_student_score(std::string, std::string, double);   //¼��ѧ���ɼ�
    void modify_score(std::string, double);                     //�޸�ѧ���ɼ�
    void delete_student(std::string);                           //ɾ��ѧ���ɼ�
    void show_information();                                    //չʾѧ����Ϣ

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

    void calculate_average_score();                             //����ƽ���ɼ�
    static double calculate_GPA(double);                        //����ѧ������
    static bool sort_with_score(student a, student b);          //�ȽϺ�������ѧ�����ɼ���������
};

#endif //TEXT_2_SUBJECT_H
