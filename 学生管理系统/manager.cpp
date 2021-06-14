#include "Manager.h"

// ��ʾ�˵�
void Manager::ShowMenu() {
	cout << "***********************************" << endl;
	cout << "**									" << endl;
	cout << "**       ��ӭʹ��ѧУ����ϵͳ��    " << endl;
	cout << "**									" << endl;
	cout << "**          1.��ʾ��Ա��Ϣ         " << endl;
	cout << "**          2.������Ա��Ϣ			" << endl;
	cout << "**          3.ɾ����У��Ա			" << endl;
	cout << "**          4.�޸���Ա��Ϣ			" << endl;
	cout << "**          5.�˳�����ϵͳ			" << endl;
	cout << "**          6.��������ĵ�			" << endl;
	cout << "**									" << endl;
	cout << "***********************************" << endl;
	cout << endl;
}

// 1.��ʾ��Ա
void Manager::showPerson() {
	// �ж��ļ��Ƿ�Ϊ��
	if (this->FileIsEmpty) {
		cout << "***********************************" << endl;
		cout << "**   ����û�У���ô��ʾ����" << endl;
		cout << "***********************************" << endl;
	}
	else {
		// ���ö�̬���ó���ӿ�
		for (int i = 0; i < this->personNum; i++) {
			this->PersonArray[i]->showInfo();
		}
	}

	//�����������
	system("pause");
	system("cls");
}

// 2.������Ա
void Manager::Add_person() {
	int AddNum = 0;   //��¼�û����������
	cout << endl;
	cout << "***********************************" << endl;
	cout << "���ѣ�������������Ҫ��Ӷ����ˣ�����ѧ������ʦ��У����:" << endl;
	cin >> AddNum;

	//��ʽ��������ʵ������
	string content1;
	string content2;
	string content3;

	//�ж���ֵ�Ƿ�����
	if (AddNum > 0) {
		//��̬��չ����

		//���㿪���¿ռ��С
		int newSize = this->personNum + AddNum;

		//�����¿ռ�
		Person** newSpace = new Person * [newSize];

		//��ԭ���ռ�����ݣ��������¿ռ���
		if (this->PersonArray != NULL) {
			for (int i = 0; i < this->personNum; i++) {
				newSpace[i] = this->PersonArray[i];
			}
		}

		//�������������
		for (int i = 0; i < AddNum; i++) {
			int select; //��ݵ�ѡ��
			cout << "***********************************" << endl;
			cout << "����������ӵĵ�" << i + 1 << "����Ա" << endl;
			cout << "��ѡ����Ա�����:" << endl;
			cout << " 1.ѧ��" << endl;
			cout << " 2.��ʦ" << endl;
			cout << " 3.У��" << endl;
			cin >> select;
			while (select != 1 && select != 2 && select != 3) {
				cout << "�ֵܣ����ǲ�����Ū�ҵĸ��飿" << endl;
				cout << "��������ѡ��:" << endl;
				cin >> select;
			}

			Person* person = NULL;
			switch (select) {
			case 1:	   cout << "������λѧ��Ժϵ�ǣ�" << endl;
				cin >> content2;
				cout << "������λѧ���༶�ǣ�" << endl;
				cin >> content3;
				cout << "������λѧ�������ǣ�" << endl;
				cin >> content1;
				person = new Student(1, content1, content2, content3);  //���ٶ���
				break;
			case 2:	   cout << "������λ��ʦ�γ��ǣ�" << endl;
				cin >> content2;
				cout << "������λ��ʦ�����ǣ�" << endl;
				cin >> content1;
				cout << "������λ��ʦ���������ǣ�" << endl;
				cin >> content3;
				person = new Teacher(2, content1, content2, content3);
				break;
			case 3:	   cout << "������λУ�������ǣ�" << endl;
				cin >> content1;
				cout << "������λУ�������ѧУ�ǣ�" << endl;
				cin >> content2;
				cout << "������λУ����ѧУ��չ�����ǣ�" << endl;
				cin >> content3;
				person = new Headmaster(3, content1, content2, content3);
				break;
			default:   break;
			}
			//���浽����
			newSpace[this->personNum + i] = person;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->PersonArray;

		//�����¿ռ��ָ��
		this->PersonArray = newSpace;

		//�������ݵ��ļ���
		this->FileSave(newSize);

		//�����µ���Ա����
		this->personNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << AddNum << "����Ա����" << endl;

		system("pause");
		system("cls");

	}
	else {
		cout << "�ֵܣ����ǲ�����ƭ�ҵĸ��飿" << endl;
	}
	cout << "***********************************" << endl;
	cout << endl;
}

// 3.ɾ����Ա
void Manager::delPerson() {
	if (this->FileIsEmpty) {
		cout << "***********************************" << endl;
		cout << "**      �ļ���Ϊ�գ�ɾ���ϣ���" << endl;
		cout << "***********************************" << endl;
	}
	else {
		cout << "***********************************" << endl;
		// ������Ա��������ɾ��
		cout << "��������Ҫɾ����Ա������: ";
		string name;
		cin >> name;
		int index = this->personIsExist(name);

		if (index != -1) {  //˵����Ա���ڣ�����Ҫɾ��
			//����ǰ��
			for (int i = index; i < this->personNum - 1; i++) {
				this->PersonArray[i] = this->PersonArray[i + 1];
			}
			this->personNum--;  // ���������м�¼����Ա����

			//����ͬ�����µ��ļ���
			this->FileSave(-1);
			cout << "ɾ���ɹ����������" << endl;
		}
		else {
			cout << "     ɾ���ϣ�����ľ�У���" << endl;
		}
		cout << "***********************************" << endl;

	}
	system("pause");
	system("cls");
}

// 4.�޸��ļ�
void Manager::modPerson() {
	if (this->FileIsEmpty) {
		cout << "***********************************" << endl;
		cout << "**      �ļ���Ϊ�գ�ɾ���ϣ���" << endl;
		cout << "***********************************" << endl;
	}
	else {
		cout << "***********************************" << endl;
		int ID;  //�����Ա��ID
		string name; //����޸��˵�����
		cout << "�������޸���Ա������:";
		cin >> name;

		int index = this->personIsExist(name);
		if (index != -1) {
			cout << "��ѡ����Ա�����:" << endl;
			cout << " 1.ѧ��" << endl;
			cout << " 2.��ʦ" << endl;
			cout << " 3.У��" << endl;
			cin >> ID;
			while (ID != 1 && ID != 2 && ID != 3) {
				cout << "�ֵܣ����ǲ�����Ū�ҵĸ��飿" << endl;
				cout << "��������ѡ��:" << endl;
				cin >> ID;
			}
			ID = this->PersonArray[index]->ID;
			delete this->PersonArray[index];

			string newMessage="";  //����޸��˵���Ϣ
			string newMessage2=""; //����޸��˵���Ϣ2

			Person* person = NULL;
			switch (ID) {
			case 1:	   cout << "������λѧ��Ժϵ�ǣ�" << endl;
					   cin >> newMessage;
					   cout << "������λѧ���༶�ǣ�" << endl;
				  	   cin >> newMessage2;
					   cout << "������λѧ�������ǣ�" << endl;
					   cin >> name;
					   person = new Student(1, name, newMessage, newMessage2);  //���ٶ���
					   break;
			case 2:	   cout << "������λ��ʦ�γ��ǣ�" << endl;
					   cin >> newMessage;
					   cout << "������λ��ʦ�����ǣ�" << endl;
					   cin >> newMessage2;
					   cout << "������λ��ʦ�����ǣ�" << endl;
					   cin >> name;
					   person = new Teacher(2, name, newMessage, newMessage2);
					   break;
			case 3:	   cout << "������λУ�������ѧУ�ǣ�" << endl;
					   cin >> newMessage;
					   cout << "������λУ����ѧУ��չ�����ǣ�" << endl;
				  	   cin >> newMessage2;
					   cout << "������λУ�������ǣ�" << endl;
					   cin >> name;
					   person = new Headmaster(3, name, newMessage, newMessage2);
					   break;
			default:   break;
			}
			//�������ݵ�������
			this->PersonArray[index] = person;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->FileSave(-1);
		}
		else {
			cout << "�ֵܣ����޴��ˣ���" << endl;
		}
		cout << "***********************************" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}

// 5.�˳�����ϵͳ
void Manager::ExitSystem() {
	cout << endl;
	cout << "***********************************" << endl;
	cout << "**    ������ڣ��ֵ��ǣ�" << endl;
	cout << "***********************************" << endl;
	cout << endl;
	system("pause");
	exit(0);
}

// 6.����ļ�
void Manager::cleanFile() {
	cout << "***********************************" << endl;
	cout << "**\tȷ������ļ����ݣ�" << endl;
	cout << "**\t1.ȷ��" << endl;
	cout << "**\t2.����" << endl;

	int select;
	cin >> select;
	while (select != 1 && select != 2) {
		cout << "Are you really ?" << endl;
		cin >> select;
	}
	if (select == 1) {
		// ��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(FIFENAME, ios::trunc);
		ofs.close();
		for (int i = 0; i < this->personNum; i++){
			if (this->PersonArray[i] != NULL) {
				delete this->PersonArray[i];
			}
		}
		this->personNum = 0;
		delete[] this->PersonArray;
		this->PersonArray = NULL;
		this->FileIsEmpty = true;
		cout << "����ɾ���" << endl;
	}
	cout << "***********************************" << endl;
	system("pause");
	system("cls");
}

// �����ļ�
void  Manager::FileSave(int newSize) {
	ofstream ofs;

	if (newSize == -1) {
		ofs.open(FIFENAME, ios::out);   //������ķ�ʽ���ļ� --д�ļ�

		//��ÿ���˵�����д�뵽�ļ���
		for (int i = 0; i < this->personNum; i++) {
			ofs << this->PersonArray[i]->ID << " "
				<< this->PersonArray[i]->name << " "
				<< this->PersonArray[i]->message << " "
				<< this->PersonArray[i]->message2 << endl;
		}
	}
	else {
		ofs.open(FIFENAME, ios::app);   //������ķ�ʽ���ļ� --д�ļ�

		//��ÿ���˵�����д�뵽�ļ���
		for (int i = this->personNum; i < newSize; i++) {
			ofs << this->PersonArray[i]->ID << " "
				<< this->PersonArray[i]->name << " "
				<< this->PersonArray[i]->message << " "
				<< this->PersonArray[i]->message2 << endl;
		}
	}
	cout << "�����ļ��ɹ���" << endl;

	//�ر��ļ���
	ofs.close();
}

// ͳ���ļ�����
int Manager::get_PerNum() {
	ifstream ifs;
	ifs.open(FIFENAME,ios::in);

	int ID;
	string name;
	string message;
	string message2;

	int num = 0;

	while (ifs >> ID && ifs >> name && ifs >> message && ifs >> message2) {
		//��¼����
		num++;
	}

	ifs.close();
	return num; 
}

// ��ʼ����Ա
void Manager::init_Person() {
	ifstream ifs;
	ifs.open(FIFENAME, ios::in);

	int index = 0; //�±�
	int ID;
	string name;
	string message;
	string message2;
	
	while (ifs >> ID && ifs >> name && ifs >> message && ifs >> message2) {
		Person* person = NULL;
		if (ID == 1) {   //ѧ��
			person = new Student(ID, name, message, message2);
		}
		else if (ID == 2) {   //��ʦ
			person = new Teacher(ID, name, message, message2);
		}
		else {    //У��
			person = new Headmaster(ID, name, message, message2);
		}
		this->PersonArray[index] = person;
		index++;
	}

	// �ر��ļ�
	ifs.close();
}

//�ж���Ա�Ƿ���� ������ڷ���ְ�����������е�λ�ã��������򷵻�-1
int Manager::personIsExist(string name) {
	int index = -1;
	for (int i = 0; i < this->personNum; i++) {
		if (this->PersonArray[i]->name == name) {
			index = i;
			break;
		}
	}
	return index;
}

Manager::Manager() {
	ifstream ifs;
	ifs.open(FIFENAME,ios::in);

	// 1.�ļ������ڵ����
	if (!ifs.is_open()) {
		cout << "***********************************" << endl;
		cout << "**           �ļ�������" << endl;
		cout << "***********************************" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->personNum = 0;
		//��ʼ������ָ��
		this->PersonArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 2.�ļ����ڣ�����û�м�¼�����
	char ch;
	ifs >> ch;  // ��ȡ���ļ�txt��һ���ֽ�����
	if (ifs.eof()) {    // eofΪ�ļ�txt��ĩβ��־
		cout << "***********************************" << endl;
		cout << "**           �ļ�Ϊ��" << endl;
		cout << "***********************************" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->personNum = 0;
		//��ʼ������ָ��
		this->PersonArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	// 3.�ļ����ڣ����Ҽ�¼���ݵ����
	int num = this->get_PerNum();
	cout << "***********************************" << endl;
	cout << "**\t�Ѿ����" << num << "����Ա��" << endl;
	cout << "***********************************" << endl;
	this->personNum = num;
	//���ٿռ�
	this->PersonArray = new Person * [num];
	//���ļ��е����ݴ洢��������
	this->init_Person();


	//���Դ���
	/*
	for (int i = 0; i < num; i++) {
		cout << "**      " ;
		switch (this->PersonArray[i]->ID) {
		case 1: cout << "ѧ�����:" << this->PersonArray[i]->ID << " * "
				     << "ѧ������:" << this->PersonArray[i]->name << " * "
					 << "ѧ��Ժϵ:" << this->PersonArray[i]->message << " * "
					 << "ѧ���༶:" << this->PersonArray[i]->message2 << endl;
				cout << "**" << endl;
				break;
		case 2: cout << "��ʦ���:" << this->PersonArray[i]->ID << " * "
			         << "��ʦ����:" << this->PersonArray[i]->name << " * "
					 << "��ʦ�γ�:" << this->PersonArray[i]->message << " * "
					 << "��ʦ����:" << this->PersonArray[i]->message2 << endl;
			    cout << "**" << endl;
				break;
		case 3: cout << "У�����:" << this->PersonArray[i]->ID << " * "
					 << "У������:" << this->PersonArray[i]->name << " * "
					 << "�����ѧУ:" << this->PersonArray[i]->message << " * "
					 << "ѧУ�ķ���:" << this->PersonArray[i]->message2 << endl;
			    cout << "**" << endl;
				break;
		}
		
	}
	cout << "*********************************************************************************************" << endl;
	*/
};

Manager::~Manager() {
	if (this->PersonArray != NULL) {
		delete[] this->PersonArray;
		this->PersonArray = NULL;
	}
};