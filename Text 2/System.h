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

    //����
    void guide_interface() override;
    void input_interface() override;
    void modify_interface() override;
    void delete_interface() override;
    void query_interface() override;
    void error_interface() override;

    //��ѯ����ز���
    void output_total_ranking() override;

    //���롢�޸ļ���ز���
    void add_data() override;
    void input_data(int) override;
    void modify_data(int) override;
    void delete_data(int) override;
    void query_student(int) override;
    void query_subject() override;
    void output_all_subject() override;

    //��λ������
    int find_by_student_ID(std::string student_ID) override;
    int find_by_student_name(std::string student_name) override;
    int find_by_subject_name(std::string subject_name) override;
    bool is_duplicate_names(std::string student_name) override;





private:
    std::vector<Student> stud;
    std::vector<Subject> subj;

    static bool sort_with_total_score(Student, Student);

};

#endif //TEXT_2_SYSTEM_H
