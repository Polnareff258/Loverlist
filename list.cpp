#include<iostream>
#include<string>
using namespace std;
#define max 1000
void  showmenu()
{
	cout << "这是一个约炮通讯录管理系统" << endl;
	cout << "1. Add an 炮友 to the list" << endl;
	cout << "2. find an 炮友" << endl;
	cout << "3. Display the list" << endl;
	cout << "4. Delete a 炮友" << endl;
	cout << "5. Change a 炮友" << endl;
	cout << "6. Exit" << endl;
	cout << "更多功能开发中，喵~"<< endl;
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
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name, address,xp;
		int age, length, phonenumber, sex;
		cout << "请输入姓名和地址" << endl;
		cin >> name >> address;
		c->num[c->size].name = name;//name 
		c->num[c->size].address = address;//address
		cout << "请输入年龄" << endl;
		cin >> age;
		c->num[c->size].age = age;//age
		cout << "请输入电话号码" << endl;
		cin >> phonenumber;
		c->num[c->size].phonenumber = phonenumber;
		cout << "请输入性别(女为0，男为1)" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				if (sex == 0)
				{
					cout << "请输入b深度";
					cin >> length;
					c->num[c->size].length = length;
				}
				else
				{
					cout << "请输入jb长度";
					cin >> length;
					c->num[c->size].length = length;
				}
				break;
			}
			cout << "输入错误，请重新输入,no LGPT here!You can't be a wallmat bag" << endl;
		}
		c->num[c->size].sex = sex;
		cout << "请输入性癖(如：SM, 百合, 萝莉, 正太, 巨乳等)";
			cin >> xp;
		c->num[c->size].xp;
		c->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
};
void showperson(book* c)
{
	if (c->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < c->size; i++)
		{
			cout << "姓名：" << c->num[i].name << "\t";
			cout << "地址：" << c->num[i].address << "\t";
			cout << "年龄：" << c->num[i].age << "\t";
			cout << "电话号码：" << c->num[i].phonenumber << "\t";
			cout << "xp是" << c->num[i].xp << "\t";
			if (c->num[i].sex == 0)
			{
				cout << "b的深度" << c->num[i].length << "\t";
			}
			else
			{
				cout << "JB的长度" << c->num[i].length << "\t";
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
			return i; //确认查有此人
		}
	}
	return -1;
};
void deleteperson(book* c)
{
	cout << "宝贝，要删除谁" << endl;
	string name;
	cin >> name;
	int res = checkperson(c, name);
	if (res == -1)
	{
		cout << "你他妈添加了吗就删除" << endl;
	}
	else
	{
		for (int i = res; i < c->size; i++)
		{
			c->num[i] = c->num[i + 1];
		}
		c->size--;
		cout << "See u again~" << endl << "今天敢删他，明天就敢删我，狗男人";
	}
};
void findperson(book* c)
{
	string name;
	cin >> name;
	int res=checkperson(c, name);
	if (res == -1)
	{
		cout << "你他妈添加了吗就找他，虚空约炮吗" << endl;
	}
	else
	{
		cout << c->num[res].name <<"\t";
		cout<< c->num[res].length << "\t";
		cout << c->num[res].address << "\t";
		cout << c->num[res].age << "\t";
		cout << c->num[res].phonenumber << "\t";
		cout << (c->num[res].sex==0?"母":"公") << "\t";
	}
	system("pause");
	system("cls");
}
void changeperson(book* c)
{
	cout << "输入要修改的炮友的姓名" << endl;
	string name;
	cin >> name;
	int res = checkperson(c, name);
	if (res == -1)
	{
		cout << "你他妈添加了吗就改" << endl;
	}
	else
	{
		int sel = 0;
		cout << "输入要修改的内容" << "\t";
		cout << "1.长度" << "\t";
		cout << "2.地址" << "\t";
		cout << "3.年龄" << "\t";
		cout << "4.电话号码" << "\t";
		cout << "5.性别" << "\t";
		cout << "6.性癖" << "\t";
		cout << "7.退出" << "\t";

		cin >> sel;
		string  address,xp;
		int age, length, phonenumber, sex;
		switch (sel)
		{
		case 1:
		{
			cout << "请输入长度" << endl;
			cin >> length;
			c->num[res].length = length;
		};
		break;
		case 2:
		{
			cout << "请输入地址" << endl;
			cin >> address;
			c->num[res].address = address;
		};
		break;
		case 3:
		{
			cout << "请输入年龄" << endl;
			cin >> age;
			c->num[res].age = age;
		};
		break;
		case 4:
		{
			cout << "请输入电话号码" << endl;
			cin >> phonenumber;
			c->num[res].phonenumber = phonenumber;
		};
		break;
		case 5:
		{
			cout << "请输入要修改的性别(女为0，男为1)" << endl;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 0)
				{
					c->num[res].sex = sex;
					break;
				}
				cout << "输入错误，请重新输入,no LGPT here!You can't be a wallmat bag" << endl;
			}
		}break;
		case 6:
		{
			cout << "请输入要修改的xp" << endl;
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
			cout << "无效的选项，请重新输入" << endl;
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
			cout << "输入要删除的炮友的姓名" << endl;
			cin >> name;
			if (checkperson(&c, name) == -1)
			{
				cout << "你他妈添加了吗就删除" << endl;
			}
			else
			{
				deleteperson(&c);
				cout << "See u again~" << endl << "今天敢删他，明天就敢删我，狗男人";
			}
			break;
		case 5:
			changeperson(&c);
			break;
		case 6:
			cout << "退出程序" << endl;
			return 0;
		default:
			cout << "无效的选项，请重新输入" << endl;
			break;
		}
	};
}
