//
// Created by Wang Haoen on 2019/8/2.
//

#include <bits/stdc++.h>
#include "System.h"

/**
 * ϵͳ��ʼ��
 * ��������ʱ�Զ�ִ��
 * �ӱ����ļ��ж�ȡ��Ϣ��д���ڴ棬�Ա���в���
 */
void System::system_initialization()
{
    std::cout << "ϵͳ���ڳ�ʼ�������Ժ�..." << std::endl;


    std::cout << "ϵͳ��ʼ����ɣ�" << std::endl;
}

/**
 * �˳�ϵͳ
 * �رճ���ǰ�Զ�ִ��
 * ���ڴ��д洢����Ϣ���浽�����ļ��У��Ա��´δ�ʱ���в���
 */
void System::system_exit()
{
    std::cout << "ϵͳ���ڱ������ݣ����Ժ�..." << std::endl;



    std::cout << "���ݱ���ɹ���" << std::endl;
    std::cout << "�ڴ������´�ʹ�ã�" << std::endl;
}

/**
 * �������
 * �����û�����Ĳ�ͬ�ַ�ѡ���Ӧ�Ĳ���
 * ����������µ�����������ʵ�ַ���
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
                case 2: modify_data();break;
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
 * ��������
 * ָ���û�ѡ�����
 */
void System::guide_interface()
{
    std::cout << "������������Ž������²�����" << std::endl;
    std::cout << "1. ����ѧ���ɼ�" << std::endl;
    std::cout << "2. �޸�ѧ���ɼ�" << std::endl;
    std::cout << "3. ɾ��ѧ���ɼ�" << std::endl;
    std::cout << "4. ��ѯѧ����Ϣ" << std::endl;
    std::cout << "5. ��ѯ������Ϣ" << std::endl;
    std::cout << "6. �鿴�ɼ�����" << std::endl;
    std::cout << "7. �鿴�꼶����" << std::endl;
    std::cout << "0. ��ȫ�˳�ϵͳ" << std::endl;
    std::cout << "��ʾ����������ȫ�˳���ǿ����ֹ������ܻᵼ�����ݶ�ʧ��" << std::endl;
    classification();
}

/**
 * ����ѧ���ɼ�����
 * �ú����������ֲ�����
 * 1. ���һ���µ�ѧ������ѡ���Ƿ�¼��ɼ�
 *    ����ѧ���Ѿ����ڣ���ᱨ��
 * 2. ����ѧ����������Ϊ�����һ���µĳɼ���Ϣ
 *    ����ѧ�������ڣ���ѯ���Ƿ��½�������Ϣ����¼��ɼ�
 * 3. ����ѧ��ѧ�ţ���Ϊ�����һ���µĳɼ���Ϣ
 *    ����ѧ�������ڣ���ѯ���Ƿ��½�������Ϣ����¼��ɼ�
 */
void System::input_interface()
{
    while (true)
    {
        std::cout << "������������Ž������²�����" << std::endl;
        std::cout << "1. �����µ�ѧ������" << std::endl;
        std::cout << "2. ����ѧ��ѧ������ӳɼ�" << std::endl;
        std::cout << "3. ����ѧ����������ӳɼ�" << std::endl;
        std::cout << "0. ������һ��" << std::endl;
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
 * ��ѯ����
 * �ڸý����½�һ��ѡ���ѯ��ʽ
 */
/*void System::query_interface()
{

}*/

/**
 * �������
 * �û������˴���Ĳ�������ת���ý��棬ָ���û�������ȷ�Ĳ���
 */
void System::error_interface()
{
    std::cout << "���Ĳ�����Ч��" << std::endl;
    std::cout << "�������������һ��..." << std::endl;
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
 * ��ѧ�Ų���ѧ��
 * ��ѧ���Ѿ�¼�룬�򷵻�����vector�е��±�
 * �������ڣ��򷵻�-1
 */
int System::find_by_student_ID(std::string student_ID)
{
    return 0;
}

int System::find_by_student_name(std::string student_name)
{
    return 0;
}

int System::find_by_subject_name(std::string subject_name)
{
    return 0;
}

/**
 * ��ѯ�Ƿ����������ѧ��
 * �����ڣ�����true�����򷵻�false
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
 * �����µ�ѧ����Ϣ
 * ���ǵ����ֵĶ����ԣ��������������������
 * ��������ѧ���Ѿ����ڣ����ᱨ��
 * ѧ�Ƴɼ�����Ч��ΧΪ 0~100, ������Ч��Χ���ᱨ��
 * ѧ�����γ̶������������
 * �����Ҫ¼��Ŀγ��Ѿ�����¼������ʾ�û��Ƿ���������Ը���ԭ�ɼ�
 */
void System::add_data()
{
    std::cout << "�밴��������ʾ����ѧ����Ϣ�Խ���������" << std::endl;
    std::string newName, newID;
    std::cout << "������ѧ�ţ�";
    std::cin >> newID;
    if (find_by_student_ID(newID) != -1)
    {
        std::cout << "�Ѵ���ѧ��Ϊ" << newID << "��ѧ����" << std::endl;
        error_interface();
        return;
    }
    std::cout << "������������";
    std::cin >> newName;
    Student newStudent(newID, newName, 0);

    std::cout << "�밴��������ʾ��������ɼ���Ϣ��" << std::endl;
    while (true)
    {
        std::cout << "�������Ŀ���ƣ�����0����ֹ���룩��" << std::endl;
        std::string subject_name;
        double subject_credit;
        double subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "�����Ϣ������" << std::endl;
            return;
        }
        if (newStudent.check_subject(subject_name))
        {
            std::cout << "�ÿ�Ŀ�ɼ���¼�룬�ظ�¼�뽫����ԭ�ɼ���" << std::endl;
            std::cout << "ԭ�ɼ�Ϊ��" << newStudent.get_single_score(subject_name) << std::endl;
            std::cout << "����\"1\"�Լ���������¼���³ɼ��Ը���ԭ�ɼ�" << std::endl;
            std::cout << "���������ַ�ȡ�����β��������������Ŀ" << std::endl;
            std::string operation;
            std::cin >> operation;
            if (operation == "1")
            {
                std::cout << "����������" << std::endl;
                std::cout << "������ѧ���ɼ���" << std::endl;
                std::cin >> subject_score;
                newStudent.modify_score(subject_name, subject_score);
                std::cout << "�޸ĳɼ��ɹ���" << std::endl;
            }
            else
            {
                std::cout << "����ȡ����" << std::endl;
            }
            continue;
        }
        std::cout << "�������Ŀѧ�ֺ�ѧ���ɼ���" << std::endl;
        std::cin >> subject_credit >> subject_score;
        if (subject_score < 0 || subject_score > 100)
        {
            std::cout << "��Ч�ĳɼ������������룡" << std::endl;
            continue;
        }
        newStudent.set_score(subject_name, subject_credit, subject_score);
        std::cout << "��ӿ�Ŀ��Ϣ�ɹ���" << std::endl;
    }
}

/**
 * ͨ������ѧ��ѧ�Ÿ���ѧ���ɼ�
 * ������޸ĵ�ѧ�Ų����ڣ��򱨴�������һ��
 */
void System::input_by_ID()
{
    std::cout << "������ѧ��ѧ�ţ�" << std::endl;
    std::string newStudentID;
    std::cin >> newStudentID;
    int index_of_student = find_by_student_ID(newStudentID);
    if (index_of_student == -1)
    {
        std::cout << "ѧ��Ϊ" << newStudentID << "��ѧ�������ڣ�" << std::endl;
        error_interface();
        return;
    }
    std::cout << "������Ҫ�޸ĵĿ�Ŀ���Ƽ��ɼ���" << std::endl;
    std::string subject_name;
    double subject_score;
    std::cin >> subject_name >> subject_score;
    stud[index_of_student].modify_score(subject_name, subject_score);
    std::cout << "�޸ĳɼ��ɹ���" << std::endl;
}

/**
 * ͨ������ѧ����������ѧ���ɼ�
 * ������޸ĵ����������ڣ��򱨴�������һ��
 * �����������ѧ��������ת������ѧ���޸ĳɼ�
 */
void System::input_by_name()
{
    std::cout << "������ѧ��������" << std::endl;
    std::string newStudentName;
    std::cin >> newStudentName;
    int index_of_student = find_by_student_ID(newStudentName);
    if (index_of_student == -1)
    {
        std::cout << "����Ϊ" << newStudentName << "��ѧ�������ڣ�" << std::endl;
        error_interface();
        return;
    }
    if (is_duplicate_names(newStudentName))
    {
        std::cout << "���������������ѧ������ͨ������ѧ�ŷ�ʽ�����޸ģ�" << std::endl;
        input_by_ID();
        return;
    }
    std::cout << "������Ҫ�޸ĵĿ�Ŀ���Ƽ��ɼ���" << std::endl;
    std::string subject_name;
    double subject_score;
    std::cin >> subject_name >> subject_score;
    stud[index_of_student].modify_score(subject_name, subject_score);
    std::cout << "�޸ĳɼ��ɹ���" << std::endl;
}

int System::check_exist()
{
    return 0;
}

void System::modify_data()
{

}

void System::delete_data()
{

}



