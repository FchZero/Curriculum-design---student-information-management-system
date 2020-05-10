#include<iostream>
#include<fstream>
#include<iomanip>
#include<string> 
#include<windows.h>
using namespace std;
const int MAX_STUDENT_NUM = 5;
void Exit();//退出函数
class Student
{
public:
	void inputId();//输入学号 
	void inputName();// 输入姓名 
	void inputSex();//输入性别
	void math();
	void english();
	void clanguage();
	int getId();// 获得学号
	static void heading()//输出成绩标题
	{
		cout << setw(10) << "学号" << setw(10) << "姓名" << setw(10) <<"性别"<<setw(10)<< "数学" << setw(10) << "英语" << setw(10) << "C++" << endl;
	}
	void output();//输出成绩信息 
	double CalTatalMark();//计算总评成绩
private:
	int id;//学号
	char name[20]; //姓名
	char sex[20];//性别
	double mathscore;
	double englishscore;
	double clanguagescore;
};
void Student::inputId()
{
	cout << "请输入学号：";
	cin >> id;

}
void Student::inputName()
{
	cin.ignore(80, '\n');
	cout << "请输入姓名：";
	cin.getline(name, 20);
}

void Student::inputSex()
{
	cout << "请输入性别：";
	cin.getline(sex, 20);
}
void Student::math()
{
	cout << "请输入数学成绩（0-100之间）：";
	cin >> mathscore;
	while (mathscore < 0 || mathscore>100)
	{
		cout << "输入错误，成绩应该在0到100之间！" << endl;
		cout << "请输入平时成绩（0-100之间）：";
		cin >> mathscore;
	}
}
void Student::english()
{
	cout << "请输入英语考试成绩（0-100之间）：";
	cin >> englishscore;
	while (englishscore < 0 || englishscore>100)
	{
		cout << "输入错误，成绩应该在0到100之间！" << endl;
		cout << "请输入期末考试成绩（0-100之间）：";
		cin >> englishscore;
	}
}
void Student::clanguage()
{
	cout << "请输入C++考试成绩（0-100之间）：";
	cin >> clanguagescore;
	while (clanguagescore < 0 || clanguagescore>100)
	{
		cout << "输入错误，成绩应该在0到100之间！" << endl;
		cout << "请输入期末考试成绩（0-100之间）：";
		cin >> englishscore;
	}
}
int Student::getId()
{
	return id;
}

void Student::output()
{
	cout << setw(10) << id << setw(10) << name << setw(10) << sex <<setiosflags(ios::fixed) << setprecision(1) << setw(10) << mathscore << setw(10) << englishscore << setw(10) << clanguagescore << endl;
}

double Student::CalTatalMark()
{
	return (mathscore + englishscore + clanguagescore) / 3;
}

//录入或插入学生信息 
void Input(Student stu[], int &num)
{
	int i = 0; //人数
	string str;//用来判断是否继续输入的字符串
	char exit;//判断是否继续使用系统
	if (num == 0)
	{
		while (true)
		{
			stu[i].inputId();
			for (int j = 0; j < num; j++)
			{
				if (stu[i].getId() == stu[j].getId())
				{
					cout << "学号不允许重复，该学号已经存在！\n";
					stu[i].inputId();
				}
			}
			stu[i].inputName();
			stu[i].inputSex();
			stu[i].math();
			stu[i].english();
			stu[i].clanguage();
			stu[i].CalTatalMark();
			i++;
			num = i;
			cout << "继续输入学生数据请按y或Y：";
			cin >> str;
			if (i == MAX_STUDENT_NUM)
			{
				cout << "人数已达到" << MAX_STUDENT_NUM << "人上限，无法再输入！\n";
				break;
			}
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}

	else //插入学生信息 
	{
		if (num == MAX_STUDENT_NUM)
		{
			cout << "人数已达到" << MAX_STUDENT_NUM << "人上限，无法再插入！\n";
		}
		else
		{
			i = num;//当前数组元素个数
			while (true)
			{
				stu[i].inputId();
				for (int j = 0; j < num; j++)
				{
					if (stu[i].getId() == stu[j].getId())
					{
						cout << "学号不允许重复，该学号已经存在！\n";
						stu[i].inputId();
					}
				}
				stu[i].inputName();
				stu[i].inputSex();
				stu[i].math();
				stu[i].english();
				stu[i].clanguage();
				i++;
				num = i;
				cout << "继续输入学生数据请按y或Y：";
				cin >> str;
				if (i == MAX_STUDENT_NUM)
				{
					cout << "人数已达到" << MAX_STUDENT_NUM << "人上限，无法再输入！\n";
					break;
				}
				if (str == "y" || str == "Y")
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << "是否继续使用本系统?(Y/N)" << endl;
	do
	{
		(cin >> exit).get();
		if (exit == 'N')
		{
			Exit();
		}
		else
			if (exit == 'Y')
			{
				system("CLS");
			}
			else
				cout << "\aPlease enter a correct charactor." << endl;
	} while (exit != 'Y'&&exit != 'N');
}
//输出显示成绩信息 
void Output(Student stu[], int num)
{
	char exit;//判断是否继续使用系统
	if (num != 0)
	{
		stu[0].heading();//学生信息标题
		for (int i = 0; i < num; i++)
		{
			stu[i].output();
		}
	}
	else
	{
		cout << "暂无成绩信息，请选择1=录入学生信息" << endl;
	}
	cout << "是否继续使用本系统?(Y/N)" << endl;
	do
	{
		(cin >> exit).get();
		if (exit == 'N')
		{
			Exit();
		}
		else
			if (exit == 'Y')
			{
				system("CLS");
			}
			else
				cout << "\aPlease enter a correct charactor." << endl;
	} while (exit != 'Y'&&exit != 'N');
}
//根据总评排序 
void Order(Student stu[], int num)
{
	char exit;//判断是否继续使用系统
	if (num != 0)
	{
		int i, j, k;
		int m;//升降序判断
		Student temp;
		cout << "升序请输入1，降序请输入2" << endl;
		cin >> m;
		while (m != 1 && m != 2)
		{
			cout << "您的输入不合法，请重新输入" << endl;
			cin >> m;
		}
		switch (m)
		{
		case 1:
			{
			 for (i = 0; i < num; i++)
			 {
				for (j = 0; j < num - i - 1; j++)
				{
					if (stu[j].CalTatalMark() > stu[j + 1].CalTatalMark())
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			 }
			 stu[0].heading();//学生信息标题
			 for (k = 0; k < num; k++)
			 {
			 	stu[k].output();
			 }
			 cout << endl;
			 break;
			}
		case 2:
		 {
			for (i = 0; i < num; i++)
			{
				for (j = 0; j < num - i - 1; j++)
				{
					if (stu[j].CalTatalMark() < stu[j + 1].CalTatalMark())
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			stu[0].heading();//学生信息标题
			for (k = 0; k < num; k++)
			{
				stu[k].output();
			}
			cout << endl;
			break;
		 }
		}
	}
	else
	{
		cout << "暂无成绩信息，请选择1=录入学生信息" << endl;
	}
	cout << "是否继续使用本系统?(Y/N)" << endl;
	do
	{
		(cin >> exit).get();
		if (exit == 'N')
		{
			Exit();
		}
		else
			if (exit == 'Y')
			{
				system("CLS");
			}
			else
				cout << "\aPlease enter a correct charactor." << endl;
	} while (exit != 'Y'&&exit != 'N');
}

//查找学生信息 
void Search(Student stu[], int num)
{
	char exit;//判断是否继续使用系统
	int id;
	string str;//用来判断是否继续输入的字符串
	while (true)
	{
		cout << "请输入您要查找的学号：";
		cin >> id;
		int flag = 0;
		if (id >= 1 && id <= 10000000000)
		{
			for (int i = 0; i < num; i++)
			{
				if (stu[i].getId() == id)
				{
					flag++;
				}
			}
			if (flag == 0)
			{
				cout << "没有该学生信息！" << endl;
			}
			else
			{
				stu[0].heading();//学生信息标题
				for (int i = 0; i < num; i++)
				{
					if (stu[i].getId() == id)
					{
						stu[i].output();
					}
				}
			}
			cout << "继续查找请按y或Y：";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "输入有误，请重新输入\n " << endl;
			cout << "继续查找请按y或Y：";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	cout << "是否继续使用本系统?(Y/N)" << endl;
	do
	{
		(cin >> exit).get();
		if (exit == 'N')
		{
			Exit();
		}
		else
			if (exit == 'Y')
			{
				system("CLS");
			}
			else
				cout << "\aPlease enter a correct charactor." << endl;
	} while (exit != 'Y'&&exit != 'N');
}

void Delete(Student stu[], int &num)
{
	char exit;//判断是否继续使用系统
	int id;
	string str;//用来判断是否继续输入的字符串
	while (true)
	{
		cout << "请输入要删除学生的学号：";
		cin >> id;
		int flag = 0;//用来统计删除后剩余的数组元素个数
		Student a[100];
		if (id >= 1 && id <= 10000000000)
		{
			for (int i = 0; i < num; i++)
			{
				if (stu[i].getId() != id)
				{
					a[flag] = stu[i];
					flag++;
				}
			}
			if (flag == num)
			{
				cout << "没有该学号学生！" << endl;
			}
			else
			{
				num = flag;
				for (int k = 0; k < num; k++)
				{
					stu[k] = a[k];
				}
				cout << id << "号学生信息删除成功！" << endl;
			}
			cout << "继续删除其他学生请按y或Y：";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "输入学号有误，请重新输入学号！\n";
			cout << "继续删除其他学生请按y或Y：";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	cout << "是否继续使用本系统?(Y/N)" << endl;
	do
	{
		(cin >> exit).get();
		if (exit == 'N')
		{
			Exit();
		}
		else
			if (exit == 'Y')
			{
				system("CLS");
			}
			else
				cout << "\aPlease enter a correct charactor." << endl;
	} while (exit != 'Y'&&exit != 'N');
}

//统计人数 
void Statis(Student stu[], int num)
{
	char exit;//判断是否继续使用系统
	int	i, a[5] = { 0 };
	for (i = 0; i < num; i++)
	{
		if (stu[i].CalTatalMark() >= 90 && stu[i].CalTatalMark() <= 100)
		{
			a[0] += 1;
		}
		else if (stu[i].CalTatalMark() >= 80 && stu[i].CalTatalMark() < 90)
		{
			a[1] += 1;
		}
		else if (stu[i].CalTatalMark() >= 70 && stu[i].CalTatalMark() < 80)
		{
			a[2] += 1;
		}
		else if (stu[i].CalTatalMark() >= 60 && stu[i].CalTatalMark() < 70)
		{
			a[3] += 1;
		}
		else
		{
			a[4] += 1;
		}
	}
	cout << "     100~90    89~80    79~70    69~60     <60" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << setw(9) << a[i];
	}
	cout << endl;
	cout << "是否继续使用本系统?(Y/N)" << endl;
	do
	{
		(cin >> exit).get();
		if (exit == 'N')
		{
			Exit();
		}
		else
			if (exit == 'Y')
			{
				system("CLS");
			}
			else
				cout << "\aPlease enter a correct charactor." << endl;
	} while (exit != 'Y'&&exit != 'N');
}

//主菜单 
void Menu()
{
	cout << "                                =================================================\n";
	cout << "                                =              欢迎使用成绩管理系统             =\n";
	cout << "                                =                   1=录入学生                  =\n";
	cout << "                                =                   2=显示信息                  =\n";
	cout << "                                =                   3=排序总评                  =\n";
	cout << "                                =                   4=查找学生                  =\n";
	cout << "                                =                   5=插入学生                  =\n";
	cout << "                                =                   6=删除学生                  =\n";
	cout << "                                =                   7=统计人数                  =\n";
	cout << "                                =                   0=退出                      =\n";
	cout << "                                =================================================\n";
	cout << "                                                    请选择:";
}

int main()
{
	cout << "                          请不要进行非正常关闭，退出时请用0进行退出，避免学生信息无法保存"<<endl<<endl<<endl;
	system("color 3F");
	int currentN = 0;
	Student stu[MAX_STUDENT_NUM];
	/*从文件读数据 */
	ifstream filein("students.txt", ios::binary);
	if (filein)
	{
		filein.read((char*)&currentN, sizeof(currentN));
		for (int i = 0; i < currentN; i++)
		{
			filein.read((char*)&stu[i], sizeof(stu[i]));
		}
	}
	filein.close();
	string a;//用来判断菜单选择,用string 
	Menu();
	while (cin >> a)
	{

		if (a == "1")
		{
			cout << "您选择了录入学生" << endl;
			Input(stu, currentN);//输入
			Menu();
		}
		else if (a == "2")
		{
			cout << "您选择了显示信息" << endl;
			Output(stu, currentN);//输出成绩信息
			Menu();
		}
		else if (a == "3")
		{
			cout << "您选择了排序总评" << endl;
			Order(stu, currentN);
			Menu();
		}
		else if (a == "4")
		{
			cout << "您选择了查找学生" << endl;
			Search(stu, currentN);
			Menu();
		}
		else if (a == "5")
		{
			cout << "您选择了插入学生" << endl;
			Input(stu, currentN);
			Menu();
		}
		else if (a == "6")
		{
			cout << "您选择了删除学生" << endl;
			Delete(stu, currentN);
			Menu();
		}
		else if (a == "7")
		{
			cout << "您选择了统计人数" << endl;
			Statis(stu, currentN);
			Menu();
		}
		else if (a == "0")
		{
			/*往文件写入数据*/
			ofstream fileout("students.txt", ios::binary);
			if (!fileout)
			{
				cout << "文件不能被打开！" << endl;
				return 0;
			}
			fileout.write((char*)&currentN, sizeof(currentN));
			for (int i = 0; i < currentN; i++)
			{
				fileout.write((char*)&stu[i], sizeof(stu[i]));
			}
			fileout.close();
			Exit();
			return 0;
		}
		else
		{
			cout << "输入非法，请重新输入！" << endl;
			Menu();
		}

	}
	return 0;
}

void Exit()
{
	using namespace std;
	system("CLS");
	system("color 0A");
	cout << "感谢您的使用！ " << endl;
	cout << "系统将在3秒后退出" << endl;
	Sleep(3000);
	exit(0);
}