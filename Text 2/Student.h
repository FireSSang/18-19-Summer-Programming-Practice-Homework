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
 * ������ʹ�� STL �е����� vector �洢��Ŀ��Ϣ
 * �����ж��������º������Ҳ��ע������Ҫ����
 * �ڸ����Ӧ��.cpp�ļ��У���ÿ��������������ϸ�Ľ���
 */
class Student
{
public:
    Student();                                              //�޲ι��캯��
    Student(std::string, std::string);                      //���ι��캯��
    std::string get_ID();                                   //��ȡѧ��ѧ��
    std::string get_name();                                 //��ȡѧ������
    double get_total_score();                               //��ȡѧ����Ȩ
    double get_total_credit();                              //��ȡѧ��ѧ��
    void set_score(std::string, double, double);            //д��ѧ���ɼ�
    double get_GPA();                                       //��ȡѧ������
    void set_rank(int);                                     //д��ѧ������
    int get_rank();                                         //��ȡѧ������
    int get_number_of_subject();                            //��ȡѡ������
    void modify_score(std::string, double);                 //�޸�ѧ���ɼ�
    void delete_score(std::string);                         //ɾ��ѧ���ɼ�
    void show_information();                                //չʾ��Ŀ��Ϣ
    bool check_subject(std::string);                        //��ѯ�Ƿ���ѡ

    void get_subject(int, std::string&, double&, double&);  //�����ļ�����

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

    static double calculate_single_GPA(double);            //���㵥�Ƽ���
    double calculate_total_GPA();                          //����ѧ������
    double calculate_total_score();                        //����ѧ����Ȩ
    static bool sort_with_credit(subject, subject);        //�ȽϺ���������Ŀ��ѧ�ֽ�������
};

#endif //TEXT_2_STUDENT_H
