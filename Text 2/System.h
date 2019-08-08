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
    //初始化及安全退出
    void system_initialization() override;
    void system_exit() override;

    //界面
    void guide_interface() override;
    void input_interface() override;
    void modify_interface() override;
    void delete_interface() override;
    void query_interface() override;
    void error_interface() override;

    //查询及相关操作
    void output_total_ranking() override;

    //输入、修改及相关操作
    void add_data() override;
    void input_data(int) override;
    void modify_data(int) override;
    void delete_data(int) override;
    void query_student(int) override;
    void query_subject() override;
    void output_all_subject() override;

    //定位及查重
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
