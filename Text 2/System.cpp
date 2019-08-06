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



    std::cout << "数据保存成功！" << std::endl;
    std::cout << "期待您的下次使用！" << std::endl;
}

/**
 * 分类操作
 * 根据用户输入的不同字符选择对应的操作
 * 在这个函数下调用其他函数实现分类
 */
void System::classification()
{
    std::string operation;
    while (std::cin >> operation)
    {
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
                case 3: delete_data();break;
                case 4: query_student();break;
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
 * 导航界面
 * 指引用户选择操作
 */
void System::guide_interface()
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
    classification();
}

/**
 * 输入学生成绩界面
 * 该函数下有三种操作：
 * 1. 添加一名新的学生，并选择是否录入成绩
 *    若该学生已经存在，则会报错
 * 2. 输入学生姓名，并为他添加一门新的成绩信息
 *    若该学生不存在，则询问是否新建该生信息并且录入成绩
 * 3. 输入学生学号，并为他添加一门新的成绩信息
 *    若该学生不存在，则询问是否新建该生信息并且录入成绩
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
            switch ((int)(op - '0'))
            {
                case 1: add_data();break;
                case 2: input_by_ID();break;
                case 3: input_by_name();break;
                case 0: return;
                default: error_interface();break;
            }
        }
    }

}

/**
 * 修改学生成绩界面
 * 该函数下有两种操作：
 * 1. 输入学生姓名，输入待修改的科目名称和新成绩并修改
 *    若该学生不存在，则会报错并返回上一级
 *    若要修改的科目不存在，则会报错并返回上一级
 * 2. 输入学生学号，输入待修改的科目名称和新成绩并修改
 *    若该学生不存在，则会报错并返回上一级
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
            switch ((int)(op - '0'))
            {
                case 1: modify_by_ID();break;
                case 2: modify_by_name();break;
                case 0: return;
                default: error_interface();break;
            }
        }
    }

}

/**
 * 查询界面
 * 在该界面下进一步选择查询方式
 */
/*void System::query_interface()
{

}*/

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

void System::query_student()
{

}


void System::query_subject()
{

}

void System::output_all_subject()
{

}

void System::output_total_ranking()
{

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


/**
 * 建立新的学生信息
 * 考虑到名字的多样性，本函数不检查重名现象
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
    Student newStudent(newID, newName, 0);

    std::cout << "请按照以下提示输入该生成绩信息：" << std::endl;
    while (true)
    {
        std::cout << "请输入科目名称（输入0以结束操作并返回上一级）：" << std::endl;
        std::string subject_name;
        double subject_credit, subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "添加信息结束！" << std::endl;
            return;
        }
        if (newStudent.check_subject(subject_name))//检测是否已经录入此科目
        {
            std::cout << "该科目成绩已录入，无法重复录入！" << std::endl;
            error_interface();
            /*std::cout << "原成绩为：" << newStudent.get_single_score(subject_name) << std::endl;
            std::cout << "输入\"1\"以继续操作，录入新成绩以覆盖原成绩" << std::endl;
            std::cout << "输入其他字符取消本次操作，继续输入科目" << std::endl;
            std::string operation;
            std::cin >> operation;
            if (operation == "1")
            {
                std::cout << "操作继续！" << std::endl;
                std::cout << "请输入学生成绩：" << std::endl;
                std::cin >> subject_score;
                newStudent.modify_score(subject_name, subject_score);//在学生档案下修改成绩
                int index_of_subject = find_by_subject_name(subject_name);
                subj[index_of_subject].modify_by_ID(newID, subject_score);//在科目下修改该学生成绩
                std::cout << "修改成绩成功！" << std::endl;
            }
            else
            {
                std::cout << "操作取消！" << std::endl;
            }*/
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
        stud.push_back(newStudent);
        std::cout << "添加科目信息成功！" << std::endl;
    }
}

/**
 * 通过输入学生学号添加学生成绩
 * 如果输入的学号不存在，则报错并返回上一级
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分依课程而定，不做检测
 * 如果将要录入的课程已经被记录，则会报错并提示用户去修改界面修改
 */
void System::input_by_ID()
{
    std::cout << "请输入学生学号：" << std::endl;
    std::string newStudentID;
    std::cin >> newStudentID;
    int index_of_student = find_by_student_ID(newStudentID);
    if (index_of_student == -1)
    {
        std::cout << "学号为" << newStudentID << "的学生不存在！" << std::endl;
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
 * 通过输入学生姓名添加学生成绩
 * 如果输入的姓名不存在，则报错并返回上一级
 * 如果存在重名学生，则跳转到输入学号修改成绩
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分依课程而定，不做检测
 * 如果将要录入的课程已经被记录，则会报错并提示用户去修改界面修改
 */
void System::input_by_name()
{
    std::cout << "请输入学生姓名：" << std::endl;
    std::string newStudentName;
    std::cin >> newStudentName;
    int index_of_student = find_by_student_ID(newStudentName);
    if (index_of_student == -1)
    {
        std::cout << "姓名为" << newStudentName << "的学生不存在！" << std::endl;
        error_interface();
        return;
    }
    if (is_duplicate_names(newStudentName))
    {
        std::cout << "这个姓名存在重名学生，请通过输入学号方式进行添加！" << std::endl;
        input_by_ID();
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
            new_subject.set_student_score(stud[index_of_student].get_ID(), stud[index_of_student].get_name(),
                                          subject_score);
            subj.push_back(new_subject);//加入到vector中
        }else
        {
            subj[index_of_subject].set_student_score(stud[index_of_student].get_ID(), stud[index_of_student].get_name(),
                                                     subject_score);
        }
        std::cout << "添加科目信息成功！" << std::endl;




        /*std::cout << "请输入要修改的科目名称及成绩：" << std::endl;
        std::string subject_name;
        double subject_score;
        std::cin >> subject_name >> subject_score;
        if (!stud[index_of_student].check_subject(subject_name))//检测是否已经录入此科目
        {
            std::cout << "该生尚未录入该科目，无法修改！" << std::endl;
            error_interface();
            return;
        }
        stud[index_of_student].modify_score(subject_name, subject_score);
        int index_of_subject = find_by_subject_name(subject_name);
        subj[index_of_subject].modify_by_Name(newStudentName, subject_score);
        std::cout << "修改成绩成功！" << std::endl;*/
    }
}

int System::check_exist()
{
    return 0;
}

/**
 * 通过输入学生学号修改学生成绩
 * 如果输入的学号不存在，则报错并返回上一级
 * 如果输入的科目不存在，则报错并返回上一级
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分不支持修改
 */
void System::modify_by_ID()
{
    std::cout << "请输入学生姓名：" << std::endl;
    std::string newStudentName;
    std::cin >> newStudentName;
    int index_of_student = find_by_student_ID(newStudentName);
    if (index_of_student == -1)
    {
        std::cout << "姓名为" << newStudentName << "的学生不存在！" << std::endl;
        error_interface();
        return;
    }
    if (is_duplicate_names(newStudentName))
    {
        std::cout << "这个姓名存在重名学生，请通过输入学号方式进行添加！" << std::endl;
        input_by_ID();
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
            std::cout << "添加信息结束！" << std::endl;
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
        subj[index_of_subject].modify_by_ID(stud[index_of_student].get_ID(), subject_score);
        std::cout << "修改成绩成功！" << std::endl;
    }
}

/**
 * 通过输入学生姓名修改学生成绩
 * 如果输入的姓名不存在，则报错并返回上一级
 * 如果存在重名学生，则跳转到输入学号修改成绩
 * 如果输入的科目不存在，则报错并提示用户去添加界面添加科目
 * 学科成绩的有效范围为 0~100, 超出有效范围将会报错
 * 学分不支持修改
 */
void System::modify_by_name()
{
    std::cout << "请输入学生学号：" << std::endl;
    std::string newStudentID;
    std::cin >> newStudentID;
    int index_of_student = find_by_student_ID(newStudentID);
    if (index_of_student == -1)
    {
        std::cout << "学号为" << newStudentID << "的学生不存在！" << std::endl;
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
            std::cout << "添加信息结束！" << std::endl;
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
        subj[index_of_subject].modify_by_name(stud[index_of_student].get_name(), subject_score);
        std::cout << "修改成绩成功！" << std::endl;
    }
}

void System::delete_data()
{

}

