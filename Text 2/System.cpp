//
// Created by Wang Haoen on 2019/8/2.
//

#include <bits/stdc++.h>
#include "System.h"

/**
 * 系统初始化
 * 启动程序时自动执行
 * 从本地文件中读取信息并写入内存，以便进行操作
 */
void System::system_initialization()
{
    std::cout << "系统正在初始化，请稍候..." << std::endl;
    std::ifstream in("data.txt");
    std::string student_ID, student_name;
    int number_of_subject;
    std::string subject_name;
    double subject_credit, subject_score;
    while (in.peek() != EOF)
    {
        in >> student_ID >> student_name;
        in >> number_of_subject;
        Student new_student(student_ID, student_name);
        for (int i = 0; i < number_of_subject; ++i)
        {
            in >> subject_name;
            in >> subject_credit >> subject_score;
            new_student.set_score(subject_name, subject_credit, subject_score);
            int index_of_subject = find_by_subject_name(subject_name);
            if (index_of_subject == -1)//新的科目
            {
                Subject new_subject(subject_name, subject_credit);
                new_subject.set_student_score(student_ID, student_name, subject_score);
                subj.push_back(new_subject);//加入到vector中
            }
            else
            {
                subj[index_of_subject].set_student_score(student_ID, student_name, subject_score);
            }
        }
        if (number_of_subject != 0)//解决文件读取最后一行的异常现象
            stud.push_back(new_student);
        number_of_subject = 0;
    }
    in.close();
    std::cout << "系统初始化完成！" << std::endl;
}

/**
 * 退出系统
 * 关闭程序前自动执行
 * 将内存中存储的信息保存到本地文件中，以便下次打开时进行操作
 */
void System::system_exit()
{
    std::cout << "系统正在保存数据，请稍候..." << std::endl;
    std::ofstream out("data.txt");
    out.clear();//清空重写
    std::string subject_name;
    double subject_credit, subject_score;
    for (int i = 0; i < stud.size(); ++i)
    {
        out << stud[i].get_ID() << " " << stud[i].get_name() << " ";
        out << stud[i].get_number_of_subject() << std::endl;
        for (int j = 0; j < stud[i].get_number_of_subject(); ++j)
        {
            stud[i].get_subject(j, subject_name, subject_credit, subject_score);//因为list的内容是private部分，无法直接访问
            out << subject_name << " ";
            out << subject_credit << " " << subject_score << std::endl;
        }
    }
    out.close();
    std::cout << "数据保存成功！" << std::endl;
    std::cout << "期待您的下次使用！" << std::endl;
}

/**
 * 导航界面
 * 指引用户选择操作
 * 根据用户输入的不同字符选择对应的操作
 * 在这个函数下调用其他函数实现分类
 */
void System::guide_interface()
{
    while (true)
    {
        std::cout << "您可以输入序号进行以下操作：" << std::endl;
        std::cout << "1. 输入学生成绩" << std::endl;
        std::cout << "2. 修改学生成绩" << std::endl;
        std::cout << "3. 删除学生成绩" << std::endl;
        std::cout << "4. 查询学生信息" << std::endl;
        std::cout << "5. 查询单科信息" << std::endl;
        std::cout << "6. 查看成绩总览" << std::endl;
        std::cout << "7. 查看年级排名" << std::endl;
        std::cout << "0. 安全退出系统" << std::endl;
        std::cout << "提示：建议您安全退出，强制终止程序可能会导致数据丢失。" << std::endl;
        std::string operation;
        std::cin >> operation;
        if (operation.length() != 1)
        {
            error_interface();
            return;
        }
        else
        {
            char op;
            op = operation[0];
            switch ((int)(op - '0'))
            {
                case 1: input_interface();break;
                case 2: modify_interface();break;
                case 3: delete_interface();break;
                case 4: query_interface();break;
                case 5: query_subject();break;
                case 6: output_all_subject();break;
                case 7: output_total_ranking();break;
                case 0: return;
                default: error_interface();break;
            }
        }
    }
}

/**
 * 输入学生成绩界面
 * 该函数下有三种操作：
 * 1. 添加一名新的学生，并选择是否录入成绩
 *    若该学生已经存在，则报错
 * 2. 输入学生学号，并为他添加一门新的成绩信息
 *    若该学生不存在，则报错
 * 3. 输入学生姓名，并为他添加一门新的成绩信息
 *    若重名，则报错
 *    若该学生不存在，则报错
 */
void System::input_interface()
{
    while (true)
    {
        std::cout << "您可以输入序号进行以下操作：" << std::endl;
        std::cout << "1. 建立新的学生档案" << std::endl;
        std::cout << "2. 输入学生学号以添加成绩" << std::endl;
        std::cout << "3. 输入学生姓名以添加成绩" << std::endl;
        std::cout << "0. 返回上一级" << std::endl;
        std::string operation;
        std::cin >> operation;
        if (operation.length() != 1)
        {
            error_interface();
            continue;
        }
        else
        {
            char op;
            op = operation[0];
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1: add_data();break;
                case 2:
                {
                    std::cout << "请输入学生学号：" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    input_data(index_of_student);
                    break;
                }
                case 3:
                {
                    std::cout << "请输入学生姓名：" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "这个姓名存在重名学生，请通过输入学号方式进行添加！" << std::endl;
                        break;
                    }
                    input_data(index_of_student);
                    break;
                }
                case 0: return;
                default: error_interface();break;
            }
        }
    }

}

/**
 * 修改学生成绩界面
 * 该函数下有两种操作：
 * 1. 输入学生学号，输入待修改的科目名称和新成绩并修改
 *    若该学生不存在，则会报错并返回上一级
 *    若要修改的科目不存在，则会报错并返回上一级
 * 2. 输入学生姓名，输入待修改的科目名称和新成绩并修改
 *    若该学生不存在，则会报错并返回上一级
 *    若重名，则报错
 *    若要修改的科目不存在，则会报错并返回上一级
 */
void System::modify_interface()
{
    while (true)
    {
        std::cout << "您可以输入序号进行以下操作：" << std::endl;
        std::cout << "1. 输入学生学号以修改成绩" << std::endl;
        std::cout << "2. 输入学生姓名以修改成绩" << std::endl;
        std::cout << "0. 返回上一级" << std::endl;
        std::string operation;
        std::cin >> operation;
        if (operation.length() != 1)
        {
            error_interface();
            continue;
        }
        else
        {
            char op;
            op = operation[0];
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1:
                {
                    std::cout << "请输入学生学号：" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    modify_data(index_of_student);
                    break;
                }
                case 2:
                {
                    std::cout << "请输入学生姓名：" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "这个姓名存在重名学生，请通过输入学号方式进行修改！" << std::endl;
                        break;
                    }
                    modify_data(index_of_student);
                    break;
                }
                case 0: return;
                default: error_interface();break;
            }
        }
    }
}

/**
 * 删除学生成绩界面
 * 该函数下有两种操作：
 * 1. 输入学生学号，输入待删除的科目名称并删除
 *    若该学生不存在，则会报错并返回上一级
 *    若要删除的科目不存在，则会报错并返回上一级
 * 2. 输入学生姓名，输入待删除的科目名称并删除
 *    若该学生不存在，则会报错并返回上一级
 *    若重名，则报错
 *    若要删除的科目不存在，则会报错并返回上一级
 */
void System::delete_interface()
{
    while (true)
    {
        std::cout << "您可以输入序号进行以下操作：" << std::endl;
        std::cout << "1. 输入学生学号以删除成绩" << std::endl;
        std::cout << "2. 输入学生姓名以删除成绩" << std::endl;
        std::cout << "0. 返回上一级" << std::endl;
        std::string operation;
        std::cin >> operation;
        if (operation.length() != 1)
        {
            error_interface();
            continue;
        }
        else
        {
            char op;
            op = operation[0];
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1:
                {
                    std::cout << "请输入学生学号：" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    delete_data(index_of_student);
                    break;
                }
                case 2:
                {
                    std::cout << "请输入学生姓名：" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "这个姓名存在重名学生，请通过输入学号方式进行删除！" << std::endl;
                        break;
                    }
                    delete_data(index_of_student);
                    break;
                }
                case 0: return;
                default: error_interface();break;
            }
        }
    }
}
/**
 * 查询学生信息界面
 * 输入学生学号或姓名
 * 若该学生不存在，则会报错并返回上一级
 * 若重名，则报错
 */
void System::query_interface()
{
    while (true)
    {
        std::cout << "您可以输入序号进行以下操作：" << std::endl;
        std::cout << "1. 输入学生学号以查询信息" << std::endl;
        std::cout << "2. 输入学生姓名以查询信息" << std::endl;
        std::cout << "0. 返回上一级" << std::endl;
        std::string operation;
        std::cin >> operation;
        if (operation.length() != 1)
        {
            error_interface();
            continue;
        }
        else
        {
            char op;
            op = operation[0];
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1:
                {
                    std::cout << "请输入学生学号：" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    query_student(index_of_student);
                    break;
                }
                case 2:
                {
                    std::cout << "请输入学生姓名：" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "这个姓名存在重名学生，请通过输入学号方式进行查询！" << std::endl;
                        break;
                    }
                    query_student(index_of_student);
                    break;
                }
                case 0: return;
                default: error_interface();break;
            }
        }
    }
}

/**
 * 错误界面
 * 用户进行了错误的操作后跳转到该界面，指引用户返回正确的操作
 */
void System::error_interface()
{
    std::cout << "您的操作无效！" << std::endl;
    std::cout << "按任意键返回上一级..." << std::endl;
    std::string s;
    std::cin >> s;
}

/**
 * 建立新的学生信息
 * 考虑到名字的多样性，本函数录入学生信息时不检查重名现象
 * 如果输入的学号已经存在，将会报错
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分依课程而定，不做检测
 * 如果将要录入的课程已经被记录，则会报错并提示用户去修改界面修改
 */
void System::add_data()
{
    std::cout << "请按照以下提示输入学生信息以建立档案：" << std::endl;
    std::string newName, newID;
    std::cout << "请输入学号：";
    std::cin >> newID;
    if (find_by_student_ID(newID) != -1)
    {
        std::cout << "已存在学号为" << newID << "的学生！" << std::endl;
        error_interface();
        return;
    }
    std::cout << "请输入姓名：";
    std::cin >> newName;
    Student newStudent(newID, newName);

    std::cout << "请按照以下提示输入该生成绩信息：" << std::endl;
    while (true)
    {
        std::cout << "请输入科目名称（输入0以结束操作并返回上一级）：" << std::endl;
        std::string subject_name;
        double subject_credit, subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            stud.push_back(newStudent);
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//排序
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            std::cout << "添加学生信息结束！" << std::endl;
            return;
        }
        if (newStudent.check_subject(subject_name))//检测是否已经录入此科目
        {
            std::cout << "该科目成绩已录入，无法重复录入！" << std::endl;
            error_interface();
            continue;
        }
        std::cout << "请输入科目学分和学生成绩：" << std::endl;
        std::cin >> subject_credit >> subject_score;
        if (subject_score < 0 || subject_score > 100)
        {
            std::cout << "无效的成绩！请重新输入！" << std::endl;
            continue;
        }
        newStudent.set_score(subject_name, subject_credit, subject_score);
        int index_of_subject = find_by_subject_name(subject_name);
        if (index_of_subject == -1)//新的科目
        {
            Subject new_subject(subject_name, subject_credit);
            new_subject.set_student_score(newID, newName, subject_score);
            subj.push_back(new_subject);//加入到vector中
        }
        else
        {
            subj[index_of_subject].set_student_score(newID, newName, subject_score);
        }
        std::cout << "添加科目信息成功！" << std::endl;
    }
}

/**
 * 添加学生成绩
 * 如果待添加信息的学生不存在，则报错并返回上一级
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分依课程而定，不做检测
 * 如果将要录入的课程已经被记录，则报错
 */
void System::input_data(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "该学生不存在！" << std::endl;
        error_interface();
        return;
    }
    while (true)
    {
        std::cout << "请输入科目名称（输入0以结束操作并返回上一级）：" << std::endl;
        std::string subject_name;
        double subject_credit, subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "添加信息结束！" << std::endl;
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//排序
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            return;
        }
        if (stud[index_of_student].check_subject(subject_name))//检测是否已经录入此科目
        {
            std::cout << "该科目成绩已录入，无法重复录入！" << std::endl;
            error_interface();
            continue;
        }
        std::cout << "请输入科目学分和学生成绩：" << std::endl;
        std::cin >> subject_credit >> subject_score;
        if (subject_score < 0 || subject_score > 100)
        {
            std::cout << "无效的成绩！请重新输入！" << std::endl;
            continue;
        }
        stud[index_of_student].set_score(subject_name, subject_credit, subject_score);
        int index_of_subject = find_by_subject_name(subject_name);
        if (index_of_subject == -1)//新的科目
        {
            Subject new_subject(subject_name, subject_credit);
            new_subject.set_student_score(stud[index_of_student].get_ID(), stud[index_of_student].get_name(), subject_score);
            subj.push_back(new_subject);//加入到vector中
        }
        else
        {
            subj[index_of_subject].set_student_score(stud[index_of_student].get_ID(), stud[index_of_student].get_name(), subject_score);
        }
        std::cout << "添加科目信息成功！" << std::endl;
    }
}

/**
 * 修改学生成绩
 * 如果该学生不存在，则报错并返回上一级
 * 如果输入的科目不存在，则报错并返回上一级
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分不支持修改
 */
void System::modify_data(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "该学生不存在！" << std::endl;
        error_interface();
        return;
    }
    while (true)
    {
        std::cout << "请输入科目名称（输入0以结束操作并返回上一级）：" << std::endl;
        std::string subject_name;
        double subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "修改成绩结束！" << std::endl;
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//排序
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            return;
        }
        if (!stud[index_of_student].check_subject(subject_name))//检测是否已经录入此科目
        {
            std::cout << "该科目不存在，无法修改！" << std::endl;
            error_interface();
            continue;
        }
        std::cout << "请输入新的学生成绩：" << std::endl;
        std::cin >> subject_score;
        if (subject_score < 0 || subject_score > 100)
        {
            std::cout << "无效的成绩！请重新输入！" << std::endl;
            continue;
        }
        stud[index_of_student].modify_score(subject_name, subject_score);
        int index_of_subject = find_by_subject_name(subject_name);
        subj[index_of_subject].modify_score(stud[index_of_student].get_ID(), subject_score);
        std::cout << "修改成绩成功！" << std::endl;
    }
}

/**
 * 删除学生成绩
 * 如果该学生不存在，则报错并返回上一级
 * 如果待删除的科目不存在，则报错并返回上一级
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分不支持修改
 */
void System::delete_data(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "该学生不存在！" << std::endl;
        error_interface();
        return;
    }
    while (true)
    {
        std::cout << "请输入科目名称（输入0以结束操作并返回上一级）：" << std::endl;
        std::string subject_name;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "删除信息结束！" << std::endl;
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//排序
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            return;
        }
        if (!stud[index_of_student].check_subject(subject_name))//检测是否已经录入此科目
        {
            std::cout << "该科目不存在，无法删除！" << std::endl;
            error_interface();
            continue;
        }
        stud[index_of_student].delete_score(subject_name);
        int index_of_subject = find_by_subject_name(subject_name);
        subj[index_of_subject].delete_student(stud[index_of_student].get_ID());
        std::cout << "删除成绩成功！" << std::endl;
    }
}

/**
 * 按一定格式输出学生的各项信息，包括以下方面：
 * 年级排名 姓名 学号 加权成绩 GPA 总学分 选课数目
 * 然后按科目学分降序依次展示各科目信息，包括以下方面：
 * 科目名称 科目学分 科目成绩 科目GPA
 */
void System::query_student(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "该学生不存在！" << std::endl;
        error_interface();
        return;
    }
    stud[index_of_student].show_information();
}

/**
 * 查询科目界面（操作）（因为不涉及两种查询方式 所以就写这一个函数了）
 * 输入科目名称后，按一定格式输出科目信息
 * 科目信息包括科目名称、科目学分、平均成绩、选课人数
 * 如果待查询的科目不存在，则会报错
 * 然后按照成绩降序（排名升序）输出学生名单和信息`
 * 学生信息包括包括排名、学生学号、学生姓名、学生成绩、学生GPA
 */
void System::query_subject()
{
    while (true)
    {
        std::cout << "请输入科目名称（输入0以结束操作并返回上一级）：" << std::endl;
        std::string subject_name;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "查询科目信息结束！" << std::endl;
            return;
        }
        int index_of_subject = find_by_subject_name(subject_name);
        if (index_of_subject == -1)//检测是否已经录入此科目
        {
            std::cout << "该科目不存在！" << std::endl;
            error_interface();
            continue;
        }
        subj[index_of_subject].show_information();
    }
}

/**
 * 展示全部科目信息
 * 按学分降序展示
 * 具体展示各式参见 Subject 类下的 show_information() 函数的注释
 */
void System::output_all_subject()
{
    std::cout << "成绩总览如下：" << std::endl << std::endl;
    for (int i = 0; i < subj.size(); ++i)
    {
        subj[i].show_information();
    }
}

/**
 * 输出年级排名
 * 按年级排名升序排列
 * 信息包括：
 * 排名 ID 姓名 加权成绩 GPA
 */
void System::output_total_ranking()
{
    std::cout << "年级排名如下：" << std::endl << std::endl;
    std::cout << std::setw(6) << "排名 " << std::setw(18) << "学号 " << std::setw(18) << "姓名 " << std::setw(7) << "成绩 " << std::setw(7) << "GPA " << std::endl;
    for (int i = 0; i < stud.size(); ++i)
    {
        std::cout << std::left;
        std::cout << std::setw(5) << stud[i].get_rank() << " ";
        std::cout << std::setw(16) << stud[i].get_ID() << " ";
        std::cout << std::setw(16) << stud[i].get_name() << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << stud[i].get_total_score() << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << stud[i].get_GPA() << std::endl;
    }
    std::cout << std::endl;
}

/**
 * 按学号查找学生
 * 若学生已经录入，则返回其在vector中的下标
 * 若不存在，则返回-1
 */
int System::find_by_student_ID(std::string student_ID)
{
    for (int i = 0; i < stud.size(); ++i)
    {
        if (stud[i].get_ID() == student_ID)
            return i;
    }
    return -1;
}

/**
 * 按姓名查找学生
 * 此时已经确保不会出现重名情况（其实现在看有点冗杂）
 * 若学生已经录入，则返回其在vector中的下标
 * 若不存在，则返回-1
 */
int System::find_by_student_name(std::string student_name)
{
    for (int i = 0; i < stud.size(); ++i)
    {
        if (stud[i].get_name() == student_name)
            return i;
    }
    return -1;
}

/**
 * 查找科目
 * 若科目已经存在，则返回其在vector中的下标
 * 若不存在，则返回-1
 */
int System::find_by_subject_name(std::string subject_name)
{
    for (int i = 0; i < subj.size(); ++i)
    {
        if (subj[i].get_subject_name() == subject_name)
            return i;
    }
    return -1;
}

/**
 * 查询是否存在重名的学生
 * 若存在，返回true，否则返回false
 */
bool System::is_duplicate_names(std::string student_name)
{
    int count_this_name = 0;
    for (int i = 0; i < stud.size(); ++i)
    {
        if (stud[i].get_name() == student_name)
            count_this_name++;
    }
    return count_this_name > 1;
}

////private

/**
 * 比较函数，用于对学生进行排序
 * 按加权成绩降序排列（加权成绩一般不会相同）
 * 加权成绩相同时按GPA降序排列
 * GPA相同时总修学分降序排列
 * 总修学分相同时按选课数降序排列
 * 选课数相同时按学号升序排列
 * 学号总不能相同了
 * 要是真有长度不同的学号...这我写不了 谁能写谁写吧
 */
bool System::sort_with_total_score(Student a, Student b)
{
    if (a.get_total_score() == b.get_total_score())
    {
        if (a.get_GPA() == b.get_GPA())
        {
            if (a.get_total_credit() == b.get_total_credit())
            {
                if (a.get_number_of_subject() == b.get_number_of_subject())
                {
                    return a.get_ID() < b.get_ID();
                }
                return a.get_number_of_subject() > b.get_number_of_subject();
            }
            return a.get_total_credit() > b.get_total_credit();
        }
        return a.get_GPA() > b.get_GPA();
    }
    return a.get_total_score() > b.get_total_score();
}

/**
 * 比较函数，用于对学科进行排序
 * 按学分降序排序
 * 学分相同则按选课人数降序排序
 */
bool System::sort_with_credit(Subject a, Subject b)
{
    if (a.get_subject_credit() == b.get_subject_credit())
        return a.get_number_of_student() > b.get_number_of_student();
    return a.get_subject_credit() > b.get_subject_credit();
}
