#pragma once
#include <iostream>
#include <String>
#include "person.h"
using namespace std;

class Headmaster :public Person {
public:
    //���캯��
	Headmaster(int ID,string name,string schoolName,string schoolAim );

	//��ʾ������Ϣ
	virtual void showInfo();
};