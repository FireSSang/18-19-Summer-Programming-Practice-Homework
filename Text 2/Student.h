//
// Created by Wang Haoen on 2019/8/1.
//

#ifndef TEXT_2_STUDENT_H
#define TEXT_2_STUDENT_H

#include <bits/stdc++.h>

/**
 * �� Student �Ľ��ͣ�
 * �����ж�����ѧ����ѧ�š������������ɼ����������ѡ��Ŀ��
 * ������ʹ�ýṹ�嶨����ѧ����Ҫ��¼�Ŀ�Ŀ��Ϣ������ѧ����ѡ��Ŀ���ơ���Ŀѧ�֡���Ŀ�ɼ��Ϳ�Ŀ����
 * ������ʹ��STL�е�����vector�洢��Ŀ��Ϣ
 * �����ж��������º������Ҳ��ע������Ҫ����
 * �ڸ����Ӧ��.cpp�ļ��У���ÿ��������������ϸ�Ľ���
 */

class Student
{
public:
    Student();                                      //�޲ι��캯��
    Student(std::string, std::string, int);         //���ι��캯��
    std::string get_ID();                           //��ȡѧ��ѧ��
    void set_ID(std::string);                       //д��ѧ��ѧ��
    std::string get_name();                         //��ȡѧ������
    void set_name(std::string);                     //д��ѧ������
    double get_total_score();                       //��ȡѧ������
    double get_total_credit();                      //��ȡѧ��ѧ��
    double get_single_score(std::string);           //��ȡ���Ƴɼ�
    void set_score(std::string, double, double);    //д��ѧ���ɼ�
    void modify_score(std::string, double);         //�޸�ѧ���ɼ�
    double calculate_GPA(double);                   //����ѧ������
    double get_GPA();                               //��ȡѧ������
    int get_rank();                                 //��ȡѧ������
    bool check_subject(std::string);                //��ѯ�Ƿ���ѡ


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
