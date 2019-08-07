//
// Created by Wang Haoen on 2019/8/2.
//

#ifndef TEXT_2_METHOD_H
#define TEXT_2_METHOD_H

#include <bits/stdc++.h>

class Method
{
public:
    //初始化及退出
    virtual void system_initialization() = 0;
    virtual void system_exit() = 0;

    //分类操作
    virtual void classification() = 0;

    //界面
    virtual void guide_interface() = 0;
    virtual void input_interface() = 0;
    virtual void modify_interface() = 0;
    virtual void delete_interface() = 0;
    //virtual void query_interface() = 0;
    virtual void error_interface() = 0;

    //查询及相关操作
    virtual void query_student() = 0;
    virtual void query_subject() = 0;
    virtual void output_all_subject() = 0;
    virtual void output_total_ranking() = 0;

    //定位
    virtual int find_by_student_ID(std::string) = 0;
    virtual int find_by_student_name(std::string) = 0;
    virtual int find_by_subject_name(std::string) = 0;
    virtual bool is_duplicate_names(std::string) = 0;

    //输入、修改及相关操作
    virtual void add_data() = 0;
    virtual void input_data(int) = 0;
    virtual void modify_data(int)= 0;
    virtual void delete_data(int) = 0;

    //计算加权分数
    //double calculatine_weighted_scores();
};

#endif //TEXT_2_METHOD_H
