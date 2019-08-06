//
// Created by Wang Haoen on 2019/8/2.
//

#ifndef TEXT_2_SYSTEM_H
#define TEXT_2_SYSTEM_H

#include <bits/stdc++.h>
#include "Method.h"
#include "Student.h"
#include "Subject.h"

class System : Method
{
public:
    //��ʼ������ȫ�˳�
    void system_initialization() override;
    void system_exit() override;

    //�������
    void classification() override;

    //����
    void guide_interface() override;
    void input_interface() override;
    void modify_interface() override;
    //void query_interface() override;
    void error_interface() override;

    //��ѯ����ز���
    void query_student() override;
    void query_subject() override;
    void output_all_subject() override;
    void output_total_ranking() override;

    //��λ
    int find_by_student_ID(std::string student_ID) override;
    int find_by_student_name(std::string student_name) override;
    int find_by_subject_name(std::string subject_name) override;

    //�ж�����
    bool is_duplicate_names(std::string student_name) override;

    //���롢�޸ļ���ز���
    void add_data() override;
    void input_by_ID() override;
    void input_by_name() override;
    int check_exist() override;
    void modify_by_ID() override;
    void modify_by_name() override;
    void delete_data() override;




private:
    std::vector<Student> stud;
    std::vector<Subject> subj;

};

#endif //TEXT_2_SYSTEM_H
