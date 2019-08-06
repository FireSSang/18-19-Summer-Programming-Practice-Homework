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

    //分类操作
    void classification() override;

    //界面
    void guide_interface() override;
    void input_interface() override;
    void modify_interface() override;
    //void query_interface() override;
    void error_interface() override;

    //查询及相关操作
    void query_student() override;
    void query_subject() override;
    void output_all_subject() override;
    void output_total_ranking() override;

    //定位
    int find_by_student_ID(std::string student_ID) override;
    int find_by_student_name(std::string student_name) override;
    int find_by_subject_name(std::string subject_name) override;

    //判断重名
    bool is_duplicate_names(std::string student_name) override;

    //输入、修改及相关操作
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
