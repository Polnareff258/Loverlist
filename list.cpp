#include<iostream>
#include<string>
using namespace std;
#define max 1000
void  showmenu()
{
	cout << "����һ��Լ��ͨѶ¼����ϵͳ" << endl;
	cout << "1. Add an ���� to the list" << endl;
	cout << "2. find an ����" << endl;
	cout << "3. Display the list" << endl;
	cout << "4. Delete a ����" << endl;
	cout << "5. Change a ����" << endl;
	cout << "6. Exit" << endl;
	cout << "���๦�ܿ����У���~"<< endl;
};
struct Person
{
	string name,address,xp;
	int age,phonenumber,length,sex;
};
struct book
{
	struct Person num[max];
	int size;
};
void addperson(book* c)
{
	if (c->size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name, address,xp;
		int age, length, phonenumber, sex;
		cout << "�����������͵�ַ" << endl;
		cin >> name >> address;
		c->num[c->size].name = name;//name 
		c->num[c->size].address = address;//address
		cout << "����������" << endl;
		cin >> age;
		c->num[c->size].age = age;//age
		cout << "������绰����" << endl;
		cin >> phonenumber;
		c->num[c->size].phonenumber = phonenumber;
		cout << "�������Ա�(ŮΪ0����Ϊ1)" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				if (sex == 0)
				{
					cout << "������b���";
					cin >> length;
					c->num[c->size].length = length;
				}
				else
				{
					cout << "������jb����";
					cin >> length;
					c->num[c->size].length = length;
				}
				break;
			}
			cout << "�����������������,no LGPT here!You can't be a wallmat bag" << endl;
		}
		c->num[c->size].sex = sex;
		cout << "���������(�磺SM, �ٺ�, ����, ��̫, �����)";
			cin >> xp;
		c->num[c->size].xp;
		c->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
};
void showperson(book* c)
{
	if (c->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < c->size; i++)
		{
			cout << "������" << c->num[i].name << "\t";
			cout << "��ַ��" << c->num[i].address << "\t";
			cout << "���䣺" << c->num[i].age << "\t";
			cout << "�绰���룺" << c->num[i].phonenumber << "\t";
			cout << "xp��" << c->num[i].xp << "\t";
			if (c->num[i].sex == 0)
			{
				cout << "b�����" << c->num[i].length << "\t";
			}
			else
			{
				cout << "JB�ĳ���" << c->num[i].length << "\t";
			}
		};
	}
		system("pause");
		system("cls");
};
int checkperson(book* c, const string& name)
{
	for (int i = 0; i < c->size; i++)
	{
		if (c->num[i].name == name)
		{
			return i; //ȷ�ϲ��д���
		}
	}
	return -1;
};
void deleteperson(book* c)
{
	cout << "������Ҫɾ��˭" << endl;
	string name;
	cin >> name;
	int res = checkperson(c, name);
	if (res == -1)
	{
		cout << "��������������ɾ��" << endl;
	}
	else
	{
		for (int i = res; i < c->size; i++)
		{
			c->num[i] = c->num[i + 1];
		}
		c->size--;
		cout << "See u again~" << endl << "�����ɾ��������͸�ɾ�ң�������";
	}
};
void findperson(book* c)
{
	string name;
	cin >> name;
	int res=checkperson(c, name);
	if (res == -1)
	{
		cout << "�����������������������Լ����" << endl;
	}
	else
	{
		cout << c->num[res].name <<"\t";
		cout<< c->num[res].length << "\t";
		cout << c->num[res].address << "\t";
		cout << c->num[res].age << "\t";
		cout << c->num[res].phonenumber << "\t";
		cout << (c->num[res].sex==0?"ĸ":"��") << "\t";
	}
	system("pause");
	system("cls");
}
void changeperson(book* c)
{
	cout << "����Ҫ�޸ĵ����ѵ�����" << endl;
	string name;
	cin >> name;
	int res = checkperson(c, name);
	if (res == -1)
	{
		cout << "�������������͸�" << endl;
	}
	else
	{
		int sel = 0;
		cout << "����Ҫ�޸ĵ�����" << "\t";
		cout << "1.����" << "\t";
		cout << "2.��ַ" << "\t";
		cout << "3.����" << "\t";
		cout << "4.�绰����" << "\t";
		cout << "5.�Ա�" << "\t";
		cout << "6.���" << "\t";
		cout << "7.�˳�" << "\t";

		cin >> sel;
		string  address,xp;
		int age, length, phonenumber, sex;
		switch (sel)
		{
		case 1:
		{
			cout << "�����볤��" << endl;
			cin >> length;
			c->num[res].length = length;
		};
		break;
		case 2:
		{
			cout << "�������ַ" << endl;
			cin >> address;
			c->num[res].address = address;
		};
		break;
		case 3:
		{
			cout << "����������" << endl;
			cin >> age;
			c->num[res].age = age;
		};
		break;
		case 4:
		{
			cout << "������绰����" << endl;
			cin >> phonenumber;
			c->num[res].phonenumber = phonenumber;
		};
		break;
		case 5:
		{
			cout << "������Ҫ�޸ĵ��Ա�(ŮΪ0����Ϊ1)" << endl;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 0)
				{
					c->num[res].sex = sex;
					break;
				}
				cout << "�����������������,no LGPT here!You can't be a wallmat bag" << endl;
			}
		}break;
		case 6:
		{
			cout << "������Ҫ�޸ĵ�xp" << endl;
			cin >> xp;
			c->num[res].xp = xp;
			break;
		}
		case 7:
		{
			system("pause");
			system("cls");
			break;
		}
		default:
			cout << "��Ч��ѡ�����������" << endl;
			break;
		}
	}
};

int main()
{
	book c;
	c.size = 0;
	int select = 0;
	string name; 
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&c);
			break;
		case 2:
			findperson(&c);
			break;
		case 3:
			showperson(&c);
			break;
		case 4:
			cout << "����Ҫɾ�������ѵ�����" << endl;
			cin >> name;
			if (checkperson(&c, name) == -1)
			{
				cout << "��������������ɾ��" << endl;
			}
			else
			{
				deleteperson(&c);
				cout << "See u again~" << endl << "�����ɾ��������͸�ɾ�ң�������";
			}
			break;
		case 5:
			changeperson(&c);
			break;
		case 6:
			cout << "�˳�����" << endl;
			return 0;
		default:
			cout << "��Ч��ѡ�����������" << endl;
			break;
		}
	};
}
