#pragma once  //��ֹͷ�ļ��ظ�����
#include <iostream>  //�������������
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "headmaster.h"
#include "string.h"
#include <fstream>

#define FIFENAME "perFile.txt"
using namespace std; //ʹ�ñ�׼�������ռ�

class Manager {
public:
	// ���캯��
	Manager();

	//��������
	~Manager();

	//��ʾ�˵�
	void ShowMenu();

	//�˳�����ϵͳ
	void ExitSystem();

	//��¼�Ǽ�����
	int personNum;

	//��Ա����ָ��
	Person **PersonArray;

	//������Ա
	void Add_person();

	//�����ļ�
	void FileSave(int newSize);

	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool FileIsEmpty;

	//ͳ���ļ�����
	int get_PerNum();

	//��ʼ��Ա��
	void init_Person();

	//��ʾ��Ա
	void showPerson();

	//ɾ����Ա
	void delPerson();

	//�ж���Ա�Ƿ���� ������ڷ���ְ�����������е�λ�ã��������򷵻�-1
	int personIsExist(string name);

	//�޸��ļ�
	void modPerson();

	//����ļ�
	void cleanFile();
};

