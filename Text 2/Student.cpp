//
// Created by Wang Haoen on 2019/8/1.
//

#include <bits/stdc++.h>
#include "Student.h"

/**
 * �޲εĹ��캯��
 */
Student::Student()
{
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    rank = 0;
    number_of_subject = 0;
}

/**
 * ���εĹ��캯��
 * ����һ��ѧ��Ϊ newID �� ����Ϊ newName ��ѧ��
 */
Student::Student(std::string newID, std::string newName)
{
    ID = newID;
    name = newName;
    total_score = 0;
    total_credit = 0;
    GPA = 0;
    rank = 0;
    number_of_subject = 0;
}

/**
 * ����ѧ��ѧ��
 */
std::string Student::get_ID()
{
    return ID;
}

/**
 * ����ѧ������
 */
std::string Student::get_name()
{
    return name;
}

/**
 * ���ؼ�Ȩ�ɼ�
 */
double Student::get_total_score()
{
    return total_score;
}

/**
 * ������ѧ��
 */
double Student::get_total_credit()
{
    return total_credit;
}

/**
 * Ϊ��ѧ�����һ���µĿ�Ŀ
 * ��Ŀ����Ϊ subjectName
 * ��Ŀѧ��Ϊ credit
 * ��Ŀ�ɼ�Ϊ newScore
 * �����ɺ���� GPA �ͼ�Ȩ�ɼ�
 * ���Կ�Ŀ�� sort_with_credit() ����
 */
void Student::set_score(std::string subjectName, double credit, double newScore)
{
    number_of_subject++;
    total_credit += credit;
    subject subj;
    subj.subject_name = subjectName;
    subj.subject_credit = credit;
    subj.subject_score = newScore;
    subj.subject_GPA = calculate_single_GPA(subj.subject_score);
    list.push_back(subj);
    calculate_total_GPA();
    calculate_total_score();
    sort(list.begin(), list.begin() + list.size(), sort_with_credit);//����
}

/**
 * ���� GPA
 */
double Student::get_GPA()
{
    return GPA;
}

/**
 * ��ѧ���꼶������¼Ϊ newRank
 */
void Student::set_rank(int newRank)
{
    rank = newRank;
}

/**
 * �����꼶����
 */
int Student::get_rank()
{
    return rank;
}

/**
 * ����ѡ����Ŀ
 */
int Student::get_number_of_subject()
{
    return number_of_subject;
}

/**
 * �޸Ŀ�Ŀ�ɼ�
 * ��Ŀ����Ϊ subjectName
 * �³ɼ�Ϊ newScore
 * ���㱾��Ŀ GPA
 * �޸���ɺ���� GPA �ͼ�Ȩ�ɼ�
 * ����������Ϊ��Ŀѧ��δ����
 */
void Student::modify_score(std::string subjectName, double newScore)
{
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            list[i].subject_score = newScore;
            list[i].subject_GPA = calculate_single_GPA(list[i].subject_score);
            break;
        }
    }
    calculate_total_GPA();
    calculate_total_score();
}

/**
 * ɾ����Ŀ�ɼ�
 * �޸���ɺ���� GPA �ͼ�Ȩ�ɼ�
 * ����������Ϊɾ��ǰ��������
 */
void Student::delete_score(std::string subjectName)
{
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
        {
            total_credit -= list[i].subject_credit;
            list.erase(list.begin() + i);
            break;
        }
    }
    number_of_subject--;
    calculate_total_GPA();
    calculate_total_score();
}

/**
 * ��һ����ʽ���ѧ���ĸ�����Ϣ���������·��棺
 * �꼶���� ���� ѧ�� ��Ȩ�ɼ� GPA ��ѧ�� ѡ����Ŀ
 * ���ѧ����ѡ��Ŀ���� n
 * ���� n �У����ÿ��Ŀ��Ϣ
 * ������Ŀ���ơ���Ŀѧ�֡���Ŀ�ɼ�����ĿGPA
 */
void Student::show_information()
{
    std::cout << std::left;
    std::cout << "�꼶������" << rank << std::endl;
    std::cout << "ѧ��ѧ�ţ�" << ID << std::endl;
    std::cout << "ѧ��������" << name << std::endl;
    std::cout << "��Ȩ�ɼ���" << std::fixed << std::setprecision(1) << total_score << std::endl;
    std::cout << " G P A ��" << std::fixed << std::setprecision(1) << GPA << std::endl;
    std::cout << "����ѧ�֣�" << std::fixed << std::setprecision(1) << total_credit << std::endl;
    std::cout << "ѡ��������" << number_of_subject << std::endl;
    std::cout << std::setw(20) << "��Ŀ����" << " " << std::setw(6) << "ѧ��" << " " << std::setw(6) << "�ɼ�" << " " << std::setw(6) << "GPA " << std::endl;
    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << std::left;
        std::cout << std::setw(20) << list[i].subject_name << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(2) << list[i].subject_credit << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(2) << list[i].subject_score << " ";
        std::cout << std::setw(6) << std::fixed << std::setprecision(1) << list[i].subject_GPA << std::endl;
    }
    std::cout << std::endl;
}

/**
 * ����ѧ���Ƿ��Ѿ�¼��ĳһ��Ŀ��Ϣ
 * ��¼�뷵��true�����򷵻�false
 */
bool Student::check_subject(std::string subjectName)
{
    for (int i = 0; i < number_of_subject; ++i)
    {
        if (list[i].subject_name == subjectName)
            return true;
    }
    return false;
}

/**
 * index �ǿ�Ŀ�������� 0 �� number_of_subject-1
 * ���屾������ԭ���ǣ������� list Ϊ˽�г�Ա�����ڲ��������ܱ� System �к���ֱ�ӵ��ã����屾������ͨ�����ô��ݷ�ʽ�ش���Ϣ
 */
void Student::get_subject(int index, std::string& subjectName, double& subjectCredit, double& subjectScore)
{
    subjectName = list[index].subject_name;
    subjectCredit = list[index].subject_credit;
    subjectScore = list[index].subject_score;
}

////private

/**
 * ���㵥�Ƴɼ�GPA
 * ��������ѧGPA���㷽ʽ
 */
double Student::calculate_single_GPA(double singleScore)
{
    double cred = 0;
    if (singleScore >= 90)
        cred = 4.0;
    else if (singleScore >= 85)
        cred = 3.7;
    else if (singleScore >= 82)
        cred = 3.3;
    else if (singleScore >= 78)
        cred = 3.0;
    else if (singleScore >= 75)
        cred = 2.7;
    else if (singleScore >= 72)
        cred = 2.3;
    else if (singleScore >= 68)
        cred = 2.0;
    else if (singleScore >= 64)
        cred = 1.5;
    else if (singleScore >= 60)
        cred = 1.0;
    else
        cred = 0;
    return cred;
}

/**
 * ������GPA
 * ��GPA���㷽ʽ��������GPA * ����ѧ�֣�����ͣ� / ��ѧ��
 */
double Student::calculate_total_GPA()
{
    double total_weighted_GPA = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        total_weighted_GPA += list[i].subject_GPA * list[i].subject_credit;
    }
    GPA = total_weighted_GPA / total_credit;
}

/**
 * �����Ȩ�ɼ�
 * ��Ȩ�ɼ����㷽ʽ�������Ƴɼ� * ����ѧ�֣�����ͣ� / ��ѧ��
 */
double Student::calculate_total_score()
{
    double total_weighted_score = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        total_weighted_score += list[i].subject_score * list[i].subject_credit;
    }
    total_score = total_weighted_score / total_credit;
}

/**
 * �ȽϺ���
 * ����ӿ�Ŀ��Ϣ��Կ�Ŀ��vector��ѧ�ֽ�����������
 */
bool Student::sort_with_credit(Student::subject a, Student::subject b)
{
    return a.subject_credit > b.subject_credit;
}
