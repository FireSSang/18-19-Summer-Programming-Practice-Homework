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
            if (index_of_subject == -1)//�µĿ�Ŀ
            {
                Subject new_subject(subject_name, subject_credit);
                new_subject.set_student_score(student_ID, student_name, subject_score);
                subj.push_back(new_subject);//���뵽vector��
            }
            else
            {
                subj[index_of_subject].set_student_score(student_ID, student_name, subject_score);
            }
        }
        if (number_of_subject != 0)//����ļ���ȡ���һ�е��쳣����
            stud.push_back(new_student);
        number_of_subject = 0;
    }
    in.close();
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
    std::ofstream out("data.txt");
    out.clear();//�����д
    std::string subject_name;
    double subject_credit, subject_score;
    for (int i = 0; i < stud.size(); ++i)
    {
        out << stud[i].get_ID() << " " << stud[i].get_name() << " ";
        out << stud[i].get_number_of_subject() << std::endl;
        for (int j = 0; j < stud[i].get_number_of_subject(); ++j)
        {
            stud[i].get_subject(j, subject_name, subject_credit, subject_score);//��Ϊlist��������private���֣��޷�ֱ�ӷ���
            out << subject_name << " ";
            out << subject_credit << " " << subject_score << std::endl;
        }
    }
    out.close();
    std::cout << "���ݱ���ɹ���" << std::endl;
    std::cout << "�ڴ������´�ʹ�ã�" << std::endl;
}

/**
 * ��������
 * ָ���û�ѡ�����
 * �����û�����Ĳ�ͬ�ַ�ѡ���Ӧ�Ĳ���
 * ����������µ�����������ʵ�ַ���
 */
void System::guide_interface()
{
    while (true)
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
 * ����ѧ���ɼ�����
 * �ú����������ֲ�����
 * 1. ���һ���µ�ѧ������ѡ���Ƿ�¼��ɼ�
 *    ����ѧ���Ѿ����ڣ��򱨴�
 * 2. ����ѧ��ѧ�ţ���Ϊ�����һ���µĳɼ���Ϣ
 *    ����ѧ�������ڣ��򱨴�
 * 3. ����ѧ����������Ϊ�����һ���µĳɼ���Ϣ
 *    ���������򱨴�
 *    ����ѧ�������ڣ��򱨴�
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
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1: add_data();break;
                case 2:
                {
                    std::cout << "������ѧ��ѧ�ţ�" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    input_data(index_of_student);
                    break;
                }
                case 3:
                {
                    std::cout << "������ѧ��������" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "���������������ѧ������ͨ������ѧ�ŷ�ʽ������ӣ�" << std::endl;
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
 * �޸�ѧ���ɼ�����
 * �ú����������ֲ�����
 * 1. ����ѧ��ѧ�ţ�������޸ĵĿ�Ŀ���ƺ��³ɼ����޸�
 *    ����ѧ�������ڣ���ᱨ��������һ��
 *    ��Ҫ�޸ĵĿ�Ŀ�����ڣ���ᱨ��������һ��
 * 2. ����ѧ��������������޸ĵĿ�Ŀ���ƺ��³ɼ����޸�
 *    ����ѧ�������ڣ���ᱨ��������һ��
 *    ���������򱨴�
 *    ��Ҫ�޸ĵĿ�Ŀ�����ڣ���ᱨ��������һ��
 */
void System::modify_interface()
{
    while (true)
    {
        std::cout << "������������Ž������²�����" << std::endl;
        std::cout << "1. ����ѧ��ѧ�����޸ĳɼ�" << std::endl;
        std::cout << "2. ����ѧ���������޸ĳɼ�" << std::endl;
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
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1:
                {
                    std::cout << "������ѧ��ѧ�ţ�" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    modify_data(index_of_student);
                    break;
                }
                case 2:
                {
                    std::cout << "������ѧ��������" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "���������������ѧ������ͨ������ѧ�ŷ�ʽ�����޸ģ�" << std::endl;
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
 * ɾ��ѧ���ɼ�����
 * �ú����������ֲ�����
 * 1. ����ѧ��ѧ�ţ������ɾ���Ŀ�Ŀ���Ʋ�ɾ��
 *    ����ѧ�������ڣ���ᱨ��������һ��
 *    ��Ҫɾ���Ŀ�Ŀ�����ڣ���ᱨ��������һ��
 * 2. ����ѧ�������������ɾ���Ŀ�Ŀ���Ʋ�ɾ��
 *    ����ѧ�������ڣ���ᱨ��������һ��
 *    ���������򱨴�
 *    ��Ҫɾ���Ŀ�Ŀ�����ڣ���ᱨ��������һ��
 */
void System::delete_interface()
{
    while (true)
    {
        std::cout << "������������Ž������²�����" << std::endl;
        std::cout << "1. ����ѧ��ѧ����ɾ���ɼ�" << std::endl;
        std::cout << "2. ����ѧ��������ɾ���ɼ�" << std::endl;
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
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1:
                {
                    std::cout << "������ѧ��ѧ�ţ�" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    delete_data(index_of_student);
                    break;
                }
                case 2:
                {
                    std::cout << "������ѧ��������" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "���������������ѧ������ͨ������ѧ�ŷ�ʽ����ɾ����" << std::endl;
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
 * ��ѯѧ����Ϣ����
 * ����ѧ��ѧ�Ż�����
 * ����ѧ�������ڣ���ᱨ��������һ��
 * ���������򱨴�
 */
void System::query_interface()
{
    while (true)
    {
        std::cout << "������������Ž������²�����" << std::endl;
        std::cout << "1. ����ѧ��ѧ���Բ�ѯ��Ϣ" << std::endl;
        std::cout << "2. ����ѧ�������Բ�ѯ��Ϣ" << std::endl;
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
            int index_of_student;
            switch ((int)(op - '0'))
            {
                case 1:
                {
                    std::cout << "������ѧ��ѧ�ţ�" << std::endl;
                    std::string newStudentID;
                    std::cin >> newStudentID;
                    index_of_student = find_by_student_ID(newStudentID);
                    query_student(index_of_student);
                    break;
                }
                case 2:
                {
                    std::cout << "������ѧ��������" << std::endl;
                    std::string newStudentName;
                    std::cin >> newStudentName;
                    index_of_student = find_by_student_name(newStudentName);
                    if (is_duplicate_names(newStudentName))
                    {
                        std::cout << "���������������ѧ������ͨ������ѧ�ŷ�ʽ���в�ѯ��" << std::endl;
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

/**
 * �����µ�ѧ����Ϣ
 * ���ǵ����ֵĶ����ԣ�������¼��ѧ����Ϣʱ�������������
 * ��������ѧ���Ѿ����ڣ����ᱨ��
 * ѧ�Ƴɼ�����Ч��ΧΪ 0~100, ������Ч��Χ���ᱨ��
 * ѧ�����γ̶������������
 * �����Ҫ¼��Ŀγ��Ѿ�����¼����ᱨ����ʾ�û�ȥ�޸Ľ����޸�
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
    Student newStudent(newID, newName);

    std::cout << "�밴��������ʾ��������ɼ���Ϣ��" << std::endl;
    while (true)
    {
        std::cout << "�������Ŀ���ƣ�����0�Խ���������������һ������" << std::endl;
        std::string subject_name;
        double subject_credit, subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            stud.push_back(newStudent);
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//����
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            std::cout << "���ѧ����Ϣ������" << std::endl;
            return;
        }
        if (newStudent.check_subject(subject_name))//����Ƿ��Ѿ�¼��˿�Ŀ
        {
            std::cout << "�ÿ�Ŀ�ɼ���¼�룬�޷��ظ�¼�룡" << std::endl;
            error_interface();
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
        int index_of_subject = find_by_subject_name(subject_name);
        if (index_of_subject == -1)//�µĿ�Ŀ
        {
            Subject new_subject(subject_name, subject_credit);
            new_subject.set_student_score(newID, newName, subject_score);
            subj.push_back(new_subject);//���뵽vector��
        }
        else
        {
            subj[index_of_subject].set_student_score(newID, newName, subject_score);
        }
        std::cout << "��ӿ�Ŀ��Ϣ�ɹ���" << std::endl;
    }
}

/**
 * ���ѧ���ɼ�
 * ����������Ϣ��ѧ�������ڣ��򱨴�������һ��
 * ѧ�Ƴɼ�����Ч��ΧΪ 0~100, ������Ч��Χ���ᱨ��
 * ѧ�����γ̶������������
 * �����Ҫ¼��Ŀγ��Ѿ�����¼���򱨴�
 */
void System::input_data(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "��ѧ�������ڣ�" << std::endl;
        error_interface();
        return;
    }
    while (true)
    {
        std::cout << "�������Ŀ���ƣ�����0�Խ���������������һ������" << std::endl;
        std::string subject_name;
        double subject_credit, subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "�����Ϣ������" << std::endl;
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//����
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            return;
        }
        if (stud[index_of_student].check_subject(subject_name))//����Ƿ��Ѿ�¼��˿�Ŀ
        {
            std::cout << "�ÿ�Ŀ�ɼ���¼�룬�޷��ظ�¼�룡" << std::endl;
            error_interface();
            continue;
        }
        std::cout << "�������Ŀѧ�ֺ�ѧ���ɼ���" << std::endl;
        std::cin >> subject_credit >> subject_score;
        if (subject_score < 0 || subject_score > 100)
        {
            std::cout << "��Ч�ĳɼ������������룡" << std::endl;
            continue;
        }
        stud[index_of_student].set_score(subject_name, subject_credit, subject_score);
        int index_of_subject = find_by_subject_name(subject_name);
        if (index_of_subject == -1)//�µĿ�Ŀ
        {
            Subject new_subject(subject_name, subject_credit);
            new_subject.set_student_score(stud[index_of_student].get_ID(), stud[index_of_student].get_name(), subject_score);
            subj.push_back(new_subject);//���뵽vector��
        }
        else
        {
            subj[index_of_subject].set_student_score(stud[index_of_student].get_ID(), stud[index_of_student].get_name(), subject_score);
        }
        std::cout << "��ӿ�Ŀ��Ϣ�ɹ���" << std::endl;
    }
}

/**
 * �޸�ѧ���ɼ�
 * �����ѧ�������ڣ��򱨴�������һ��
 * �������Ŀ�Ŀ�����ڣ��򱨴�������һ��
 * ѧ�Ƴɼ�����Ч��ΧΪ 0~100, ������Ч��Χ���ᱨ��
 * ѧ�ֲ�֧���޸�
 */
void System::modify_data(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "��ѧ�������ڣ�" << std::endl;
        error_interface();
        return;
    }
    while (true)
    {
        std::cout << "�������Ŀ���ƣ�����0�Խ���������������һ������" << std::endl;
        std::string subject_name;
        double subject_score;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "�޸ĳɼ�������" << std::endl;
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//����
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            return;
        }
        if (!stud[index_of_student].check_subject(subject_name))//����Ƿ��Ѿ�¼��˿�Ŀ
        {
            std::cout << "�ÿ�Ŀ�����ڣ��޷��޸ģ�" << std::endl;
            error_interface();
            continue;
        }
        std::cout << "�������µ�ѧ���ɼ���" << std::endl;
        std::cin >> subject_score;
        if (subject_score < 0 || subject_score > 100)
        {
            std::cout << "��Ч�ĳɼ������������룡" << std::endl;
            continue;
        }
        stud[index_of_student].modify_score(subject_name, subject_score);
        int index_of_subject = find_by_subject_name(subject_name);
        subj[index_of_subject].modify_score(stud[index_of_student].get_ID(), subject_score);
        std::cout << "�޸ĳɼ��ɹ���" << std::endl;
    }
}

/**
 * ɾ��ѧ���ɼ�
 * �����ѧ�������ڣ��򱨴�������һ��
 * �����ɾ���Ŀ�Ŀ�����ڣ��򱨴�������һ��
 * ѧ�Ƴɼ�����Ч��ΧΪ 0~100, ������Ч��Χ���ᱨ��
 * ѧ�ֲ�֧���޸�
 */
void System::delete_data(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "��ѧ�������ڣ�" << std::endl;
        error_interface();
        return;
    }
    while (true)
    {
        std::cout << "�������Ŀ���ƣ�����0�Խ���������������һ������" << std::endl;
        std::string subject_name;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "ɾ����Ϣ������" << std::endl;
            sort(stud.begin(), stud.begin() + stud.size(), sort_with_total_score);//����
            sort(subj.begin(), subj.begin() + subj.size(), sort_with_credit);
            for (int i = 0; i < stud.size(); ++i)
            {
                stud[i].set_rank(i+1);
            }
            return;
        }
        if (!stud[index_of_student].check_subject(subject_name))//����Ƿ��Ѿ�¼��˿�Ŀ
        {
            std::cout << "�ÿ�Ŀ�����ڣ��޷�ɾ����" << std::endl;
            error_interface();
            continue;
        }
        stud[index_of_student].delete_score(subject_name);
        int index_of_subject = find_by_subject_name(subject_name);
        subj[index_of_subject].delete_student(stud[index_of_student].get_ID());
        std::cout << "ɾ���ɼ��ɹ���" << std::endl;
    }
}

/**
 * ��һ����ʽ���ѧ���ĸ�����Ϣ���������·��棺
 * �꼶���� ���� ѧ�� ��Ȩ�ɼ� GPA ��ѧ�� ѡ����Ŀ
 * Ȼ�󰴿�Ŀѧ�ֽ�������չʾ����Ŀ��Ϣ���������·��棺
 * ��Ŀ���� ��Ŀѧ�� ��Ŀ�ɼ� ��ĿGPA
 */
void System::query_student(int index_of_student)
{
    if (index_of_student == -1)
    {
        std::cout << "��ѧ�������ڣ�" << std::endl;
        error_interface();
        return;
    }
    stud[index_of_student].show_information();
}

/**
 * ��ѯ��Ŀ���棨����������Ϊ���漰���ֲ�ѯ��ʽ ���Ծ�д��һ�������ˣ�
 * �����Ŀ���ƺ󣬰�һ����ʽ�����Ŀ��Ϣ
 * ��Ŀ��Ϣ������Ŀ���ơ���Ŀѧ�֡�ƽ���ɼ���ѡ������
 * �������ѯ�Ŀ�Ŀ�����ڣ���ᱨ��
 * Ȼ���ճɼ����������������ѧ����������Ϣ`
 * ѧ����Ϣ��������������ѧ��ѧ�š�ѧ��������ѧ���ɼ���ѧ��GPA
 */
void System::query_subject()
{
    while (true)
    {
        std::cout << "�������Ŀ���ƣ�����0�Խ���������������һ������" << std::endl;
        std::string subject_name;
        std::cin >> subject_name;
        if (subject_name == "0")
        {
            std::cout << "��ѯ��Ŀ��Ϣ������" << std::endl;
            return;
        }
        int index_of_subject = find_by_subject_name(subject_name);
        if (index_of_subject == -1)//����Ƿ��Ѿ�¼��˿�Ŀ
        {
            std::cout << "�ÿ�Ŀ�����ڣ�" << std::endl;
            error_interface();
            continue;
        }
        subj[index_of_subject].show_information();
    }
}

/**
 * չʾȫ����Ŀ��Ϣ
 * ��ѧ�ֽ���չʾ
 * ����չʾ��ʽ�μ� Subject ���µ� show_information() ������ע��
 */
void System::output_all_subject()
{
    std::cout << "�ɼ��������£�" << std::endl << std::endl;
    for (int i = 0; i < subj.size(); ++i)
    {
        subj[i].show_information();
    }
}

/**
 * ����꼶����
 * ���꼶������������
 * ��Ϣ������
 * ���� ID ���� ��Ȩ�ɼ� GPA
 */
void System::output_total_ranking()
{
    std::cout << "�꼶�������£�" << std::endl << std::endl;
    std::cout << std::setw(6) << "���� " << std::setw(18) << "ѧ�� " << std::setw(18) << "���� " << std::setw(7) << "�ɼ� " << std::setw(7) << "GPA " << std::endl;
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
 * ��ѧ�Ų���ѧ��
 * ��ѧ���Ѿ�¼�룬�򷵻�����vector�е��±�
 * �������ڣ��򷵻�-1
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
 * ����������ѧ��
 * ��ʱ�Ѿ�ȷ��������������������ʵ���ڿ��е����ӣ�
 * ��ѧ���Ѿ�¼�룬�򷵻�����vector�е��±�
 * �������ڣ��򷵻�-1
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
 * ���ҿ�Ŀ
 * ����Ŀ�Ѿ����ڣ��򷵻�����vector�е��±�
 * �������ڣ��򷵻�-1
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

////private

/**
 * �ȽϺ��������ڶ�ѧ����������
 * ����Ȩ�ɼ��������У���Ȩ�ɼ�һ�㲻����ͬ��
 * ��Ȩ�ɼ���ͬʱ��GPA��������
 * GPA��ͬʱ����ѧ�ֽ�������
 * ����ѧ����ͬʱ��ѡ������������
 * ѡ������ͬʱ��ѧ����������
 * ѧ���ܲ�����ͬ��
 * Ҫ�����г��Ȳ�ͬ��ѧ��...����д���� ˭��д˭д��
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
 * �ȽϺ��������ڶ�ѧ�ƽ�������
 * ��ѧ�ֽ�������
 * ѧ����ͬ��ѡ��������������
 */
bool System::sort_with_credit(Subject a, Subject b)
{
    if (a.get_subject_credit() == b.get_subject_credit())
        return a.get_number_of_student() > b.get_number_of_student();
    return a.get_subject_credit() > b.get_subject_credit();
}
