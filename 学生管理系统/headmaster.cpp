#include <iostream>
#include "headmaster.h"
using namespace std;

//���캯��
Headmaster::Headmaster(int  ID,string name, string schoolName, string schoolAim) {
	this->ID = ID;
	this->name = name;
	this->message = schoolAim;
	this->message2= schoolName;
};

//��ʾ������Ϣ
void Headmaster::showInfo() {
	cout << "\n***********************************"
		 << "\n**\tУ�����:" << this->ID
		 << "\n**\tУ������:" << this->name
		 << "\n**\tѧУ����:" << this->message2
		 << "\n**\tѧУ����:" << this->message
		 << "\n***********************************" << endl;
};