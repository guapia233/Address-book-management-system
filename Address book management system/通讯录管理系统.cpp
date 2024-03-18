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
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
void addPerson(addressBook *abs) {
	if (abs->cnt >= MAX) {
		cout << "通讯录已满，添加失败！" << endl;
		return;
	}
	string name;
	cout << endl << "请输入联系人的姓名：";
	cin >> name;
	abs->a[abs->cnt].name = name;
	string gender;
	cout << endl << "请输入联系人的性别：";
	cin >> gender;
	abs->a[abs->cnt].gender = gender;
	int age;
	cout << endl << "请输入联系人的年龄：";
	cin >> age;
	abs->a[abs->cnt].age = age;
	string number;
	cout << endl << "请输入联系人的电话：";
	cin >> number;
	abs->a[abs->cnt].number = number;
	string address;
	cout << endl << "请输入联系人的地址：";
	cin >> address;
	abs->a[abs->cnt].address = address;
	abs->cnt++;
	cout << endl << "添加成功!" << endl;
	system("pause");
	system("cls");	
}
void showPerson(addressBook* abs) {
	cout << "您的通讯录共有";
	cout << abs->cnt;
	cout << "人:" << endl;
	for (int i = 0; i < abs->cnt; i++) {
		cout << i + 1;
		cout << ".";
		cout << "姓名：" << abs->a[i].name << "\t";
		cout << "性别：" << abs->a[i].gender << "\t";
		cout << "年龄：" << abs->a[i].age << "\t";
		cout << "电话：" << abs->a[i].number << "\t";
		cout << "住址：" << abs->a[i].address << endl;
	}
	system("pause");
	system("cls"); 
}

void deletePerson(addressBook *abs) {
	cout << "请输入您要删除的联系人的姓名:";
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
		cout << endl << "此联系人不存在！" << endl;
	}
	else {
		for (int i = p; i < abs->cnt; i++) {
			abs->a[i] = abs->a[i + 1];
		}
		abs->cnt--;
		cout << endl << "此联系人已删除！" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(addressBook* abs) {
	cout << "请输入您要查找的联系人的姓名:";
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
		cout << endl << "此联系人不存在！" << endl;
	}
	else {
		cout << "姓名：" << abs->a[p].name << "\t";
		cout << "性别：" << abs->a[p].gender << "\t";
		cout << "年龄：" << abs->a[p].age << "\t";
		cout << "电话：" << abs->a[p].number << "\t";
		cout << "住址：" << abs->a[p].address << endl;
	}
	system("pause");
	system("cls");
}

void editPerson(addressBook* abs) {
	cout << "请输入您要修改的联系人的姓名:";
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
		cout << endl << "此联系人不存在！" << endl;
	}
	else {
		int flag1;
		cout << endl << "请输入修改后的性别（若此项无需修改，请按0跳过，否则请按1）：";
		cin >> flag1;
		if (flag1) {
			string gender;
			cin >> gender;
			abs->a[p].gender = gender;
		}
		int flag2;
		cout << endl << "请输入修改后的年龄（若此项无需修改，请按0跳过，否则请按1）：";
		cin >> flag2;
		if (flag2) {
			int age;
			cin >> age;
			abs->a[p].age = age;
		}
		int flag3;
		cout << endl << "请输入修改后的电话（若此项无需修改，请按0跳过，否则请按1）：";
		cin >> flag3;
		if (flag3) {
			string number;
			cin >> number;
			abs->a[p].number = number;	
		}
		int flag4;
		cout << endl << "请输入修改后的地址（若此项无需修改，请按0跳过，否则请按1）：";
		cin >> flag4;
		if (flag4) {
			string address;
			cin >> address;
			abs->a[p].address = address;
		}
		cout << endl << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(addressBook* abs) {
	abs->cnt = 0;
	cout << endl << "清空成功！" << endl;
	system("pause");
	system("cls");
}

int main() {
	addressBook abs;
	abs.cnt = 0;
	int select = 0;
	while (true) {
		showMenu();
		cout << "请输入您要执行的功能数字：";
		cin >> select;
		switch (select) {
		case 1: 
			addPerson(&abs);
			break; //添加联系人
		case 2: 
			showPerson(&abs);
			break; //显示联系人
		case 3: 
			deletePerson(&abs);
			break; //删除联系人
		case 4: 
			findPerson(&abs);
			break; //查找联系人
		case 5: 
			editPerson(&abs);
			break; //修改联系人
		case 6: 
			clearPerson(&abs);
			break; //清空联系人
		case 0: 
			cout << "欢迎下次使用！" << endl; 
			return 0;
			break; //退出通讯录
		default: break;
		}
	}
	system("pause");
	return 0;
}