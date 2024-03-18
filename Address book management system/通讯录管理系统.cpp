#include<iostream>
using namespace std;
#define MAX 1000

struct person {
	string name;
	string gender;
	int age;
	string number;
	string address;
};
struct addressBook {
	struct person a[MAX];
	int cnt;
};
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
void addPerson(addressBook *abs) {
	if (abs->cnt >= MAX) {
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
		return;
	}
	string name;
	cout << endl << "��������ϵ�˵�������";
	cin >> name;
	abs->a[abs->cnt].name = name;
	string gender;
	cout << endl << "��������ϵ�˵��Ա�";
	cin >> gender;
	abs->a[abs->cnt].gender = gender;
	int age;
	cout << endl << "��������ϵ�˵����䣺";
	cin >> age;
	abs->a[abs->cnt].age = age;
	string number;
	cout << endl << "��������ϵ�˵ĵ绰��";
	cin >> number;
	abs->a[abs->cnt].number = number;
	string address;
	cout << endl << "��������ϵ�˵ĵ�ַ��";
	cin >> address;
	abs->a[abs->cnt].address = address;
	abs->cnt++;
	cout << endl << "��ӳɹ�!" << endl;
	system("pause");
	system("cls");	
}
void showPerson(addressBook* abs) {
	cout << "����ͨѶ¼����";
	cout << abs->cnt;
	cout << "��:" << endl;
	for (int i = 0; i < abs->cnt; i++) {
		cout << i + 1;
		cout << ".";
		cout << "������" << abs->a[i].name << "\t";
		cout << "�Ա�" << abs->a[i].gender << "\t";
		cout << "���䣺" << abs->a[i].age << "\t";
		cout << "�绰��" << abs->a[i].number << "\t";
		cout << "סַ��" << abs->a[i].address << endl;
	}
	system("pause");
	system("cls"); 
}

void deletePerson(addressBook *abs) {
	cout << "��������Ҫɾ������ϵ�˵�����:";
	string name;
	cin >> name;
	int p = -1;
	for (int i = 0; i < abs->cnt; i++) {
		if (abs->a[i].name == name) {
			p = i;
			break;
		} 
	}
	if (p < 0) {
		cout << endl << "����ϵ�˲����ڣ�" << endl;
	}
	else {
		for (int i = p; i < abs->cnt; i++) {
			abs->a[i] = abs->a[i + 1];
		}
		abs->cnt--;
		cout << endl << "����ϵ����ɾ����" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(addressBook* abs) {
	cout << "��������Ҫ���ҵ���ϵ�˵�����:";
	string name;
	cin >> name;
	int p = -1;
	for (int i = 0; i < abs->cnt; i++) {
		if (abs->a[i].name == name) {
			p = i;
			break;
		}
	}
	if (p < 0) {
		cout << endl << "����ϵ�˲����ڣ�" << endl;
	}
	else {
		cout << "������" << abs->a[p].name << "\t";
		cout << "�Ա�" << abs->a[p].gender << "\t";
		cout << "���䣺" << abs->a[p].age << "\t";
		cout << "�绰��" << abs->a[p].number << "\t";
		cout << "סַ��" << abs->a[p].address << endl;
	}
	system("pause");
	system("cls");
}

void editPerson(addressBook* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�˵�����:";
	string name;
	cin >> name;

	int p = -1;
	for (int i = 0; i < abs->cnt; i++) {
		if (abs->a[i].name == name) {
			p = i;
			break;
		}
	}
	if (p < 0) {
		cout << endl << "����ϵ�˲����ڣ�" << endl;
	}
	else {
		int flag1;
		cout << endl << "�������޸ĺ���Ա������������޸ģ��밴0�����������밴1����";
		cin >> flag1;
		if (flag1) {
			string gender;
			cin >> gender;
			abs->a[p].gender = gender;
		}
		int flag2;
		cout << endl << "�������޸ĺ�����䣨�����������޸ģ��밴0�����������밴1����";
		cin >> flag2;
		if (flag2) {
			int age;
			cin >> age;
			abs->a[p].age = age;
		}
		int flag3;
		cout << endl << "�������޸ĺ�ĵ绰�������������޸ģ��밴0�����������밴1����";
		cin >> flag3;
		if (flag3) {
			string number;
			cin >> number;
			abs->a[p].number = number;	
		}
		int flag4;
		cout << endl << "�������޸ĺ�ĵ�ַ�������������޸ģ��밴0�����������밴1����";
		cin >> flag4;
		if (flag4) {
			string address;
			cin >> address;
			abs->a[p].address = address;
		}
		cout << endl << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(addressBook* abs) {
	abs->cnt = 0;
	cout << endl << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

int main() {
	addressBook abs;
	abs.cnt = 0;
	int select = 0;
	while (true) {
		showMenu();
		cout << "��������Ҫִ�еĹ������֣�";
		cin >> select;
		switch (select) {
		case 1: 
			addPerson(&abs);
			break; //�����ϵ��
		case 2: 
			showPerson(&abs);
			break; //��ʾ��ϵ��
		case 3: 
			deletePerson(&abs);
			break; //ɾ����ϵ��
		case 4: 
			findPerson(&abs);
			break; //������ϵ��
		case 5: 
			editPerson(&abs);
			break; //�޸���ϵ��
		case 6: 
			clearPerson(&abs);
			break; //�����ϵ��
		case 0: 
			cout << "��ӭ�´�ʹ�ã�" << endl; 
			return 0;
			break; //�˳�ͨѶ¼
		default: break;
		}
	}
	system("pause");
	return 0;
}