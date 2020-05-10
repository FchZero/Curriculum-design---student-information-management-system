#include<iostream>
#include<fstream>
#include<iomanip>
#include<string> 
#include<windows.h>
using namespace std;
const int MAX_STUDENT_NUM = 5;
void Exit();//�˳�����
class Student
{
public:
	void inputId();//����ѧ�� 
	void inputName();// �������� 
	void inputSex();//�����Ա�
	void math();
	void english();
	void clanguage();
	int getId();// ���ѧ��
	static void heading()//����ɼ�����
	{
		cout << setw(10) << "ѧ��" << setw(10) << "����" << setw(10) <<"�Ա�"<<setw(10)<< "��ѧ" << setw(10) << "Ӣ��" << setw(10) << "C++" << endl;
	}
	void output();//����ɼ���Ϣ 
	double CalTatalMark();//���������ɼ�
private:
	int id;//ѧ��
	char name[20]; //����
	char sex[20];//�Ա�
	double mathscore;
	double englishscore;
	double clanguagescore;
};
void Student::inputId()
{
	cout << "������ѧ�ţ�";
	cin >> id;

}
void Student::inputName()
{
	cin.ignore(80, '\n');
	cout << "������������";
	cin.getline(name, 20);
}

void Student::inputSex()
{
	cout << "�������Ա�";
	cin.getline(sex, 20);
}
void Student::math()
{
	cout << "��������ѧ�ɼ���0-100֮�䣩��";
	cin >> mathscore;
	while (mathscore < 0 || mathscore>100)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "������ƽʱ�ɼ���0-100֮�䣩��";
		cin >> mathscore;
	}
}
void Student::english()
{
	cout << "������Ӣ�￼�Գɼ���0-100֮�䣩��";
	cin >> englishscore;
	while (englishscore < 0 || englishscore>100)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "��������ĩ���Գɼ���0-100֮�䣩��";
		cin >> englishscore;
	}
}
void Student::clanguage()
{
	cout << "������C++���Գɼ���0-100֮�䣩��";
	cin >> clanguagescore;
	while (clanguagescore < 0 || clanguagescore>100)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "��������ĩ���Գɼ���0-100֮�䣩��";
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

//¼������ѧ����Ϣ 
void Input(Student stu[], int &num)
{
	int i = 0; //����
	string str;//�����ж��Ƿ����������ַ���
	char exit;//�ж��Ƿ����ʹ��ϵͳ
	if (num == 0)
	{
		while (true)
		{
			stu[i].inputId();
			for (int j = 0; j < num; j++)
			{
				if (stu[i].getId() == stu[j].getId())
				{
					cout << "ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�\n";
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
			cout << "��������ѧ�������밴y��Y��";
			cin >> str;
			if (i == MAX_STUDENT_NUM)
			{
				cout << "�����Ѵﵽ" << MAX_STUDENT_NUM << "�����ޣ��޷������룡\n";
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

	else //����ѧ����Ϣ 
	{
		if (num == MAX_STUDENT_NUM)
		{
			cout << "�����Ѵﵽ" << MAX_STUDENT_NUM << "�����ޣ��޷��ٲ��룡\n";
		}
		else
		{
			i = num;//��ǰ����Ԫ�ظ���
			while (true)
			{
				stu[i].inputId();
				for (int j = 0; j < num; j++)
				{
					if (stu[i].getId() == stu[j].getId())
					{
						cout << "ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�\n";
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
				cout << "��������ѧ�������밴y��Y��";
				cin >> str;
				if (i == MAX_STUDENT_NUM)
				{
					cout << "�����Ѵﵽ" << MAX_STUDENT_NUM << "�����ޣ��޷������룡\n";
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
	cout << "�Ƿ����ʹ�ñ�ϵͳ?(Y/N)" << endl;
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
//�����ʾ�ɼ���Ϣ 
void Output(Student stu[], int num)
{
	char exit;//�ж��Ƿ����ʹ��ϵͳ
	if (num != 0)
	{
		stu[0].heading();//ѧ����Ϣ����
		for (int i = 0; i < num; i++)
		{
			stu[i].output();
		}
	}
	else
	{
		cout << "���޳ɼ���Ϣ����ѡ��1=¼��ѧ����Ϣ" << endl;
	}
	cout << "�Ƿ����ʹ�ñ�ϵͳ?(Y/N)" << endl;
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
//������������ 
void Order(Student stu[], int num)
{
	char exit;//�ж��Ƿ����ʹ��ϵͳ
	if (num != 0)
	{
		int i, j, k;
		int m;//�������ж�
		Student temp;
		cout << "����������1������������2" << endl;
		cin >> m;
		while (m != 1 && m != 2)
		{
			cout << "�������벻�Ϸ�������������" << endl;
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
			 stu[0].heading();//ѧ����Ϣ����
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
			stu[0].heading();//ѧ����Ϣ����
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
		cout << "���޳ɼ���Ϣ����ѡ��1=¼��ѧ����Ϣ" << endl;
	}
	cout << "�Ƿ����ʹ�ñ�ϵͳ?(Y/N)" << endl;
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

//����ѧ����Ϣ 
void Search(Student stu[], int num)
{
	char exit;//�ж��Ƿ����ʹ��ϵͳ
	int id;
	string str;//�����ж��Ƿ����������ַ���
	while (true)
	{
		cout << "��������Ҫ���ҵ�ѧ�ţ�";
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
				cout << "û�и�ѧ����Ϣ��" << endl;
			}
			else
			{
				stu[0].heading();//ѧ����Ϣ����
				for (int i = 0; i < num; i++)
				{
					if (stu[i].getId() == id)
					{
						stu[i].output();
					}
				}
			}
			cout << "���������밴y��Y��";
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
			cout << "������������������\n " << endl;
			cout << "���������밴y��Y��";
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
	cout << "�Ƿ����ʹ�ñ�ϵͳ?(Y/N)" << endl;
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
	char exit;//�ж��Ƿ����ʹ��ϵͳ
	int id;
	string str;//�����ж��Ƿ����������ַ���
	while (true)
	{
		cout << "������Ҫɾ��ѧ����ѧ�ţ�";
		cin >> id;
		int flag = 0;//����ͳ��ɾ����ʣ�������Ԫ�ظ���
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
				cout << "û�и�ѧ��ѧ����" << endl;
			}
			else
			{
				num = flag;
				for (int k = 0; k < num; k++)
				{
					stu[k] = a[k];
				}
				cout << id << "��ѧ����Ϣɾ���ɹ���" << endl;
			}
			cout << "����ɾ������ѧ���밴y��Y��";
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
			cout << "����ѧ����������������ѧ�ţ�\n";
			cout << "����ɾ������ѧ���밴y��Y��";
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
	cout << "�Ƿ����ʹ�ñ�ϵͳ?(Y/N)" << endl;
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

//ͳ������ 
void Statis(Student stu[], int num)
{
	char exit;//�ж��Ƿ����ʹ��ϵͳ
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
	cout << "�Ƿ����ʹ�ñ�ϵͳ?(Y/N)" << endl;
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

//���˵� 
void Menu()
{
	cout << "                                =================================================\n";
	cout << "                                =              ��ӭʹ�óɼ�����ϵͳ             =\n";
	cout << "                                =                   1=¼��ѧ��                  =\n";
	cout << "                                =                   2=��ʾ��Ϣ                  =\n";
	cout << "                                =                   3=��������                  =\n";
	cout << "                                =                   4=����ѧ��                  =\n";
	cout << "                                =                   5=����ѧ��                  =\n";
	cout << "                                =                   6=ɾ��ѧ��                  =\n";
	cout << "                                =                   7=ͳ������                  =\n";
	cout << "                                =                   0=�˳�                      =\n";
	cout << "                                =================================================\n";
	cout << "                                                    ��ѡ��:";
}

int main()
{
	cout << "                          �벻Ҫ���з������رգ��˳�ʱ����0�����˳�������ѧ����Ϣ�޷�����"<<endl<<endl<<endl;
	system("color 3F");
	int currentN = 0;
	Student stu[MAX_STUDENT_NUM];
	/*���ļ������� */
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
	string a;//�����жϲ˵�ѡ��,��string 
	Menu();
	while (cin >> a)
	{

		if (a == "1")
		{
			cout << "��ѡ����¼��ѧ��" << endl;
			Input(stu, currentN);//����
			Menu();
		}
		else if (a == "2")
		{
			cout << "��ѡ������ʾ��Ϣ" << endl;
			Output(stu, currentN);//����ɼ���Ϣ
			Menu();
		}
		else if (a == "3")
		{
			cout << "��ѡ������������" << endl;
			Order(stu, currentN);
			Menu();
		}
		else if (a == "4")
		{
			cout << "��ѡ���˲���ѧ��" << endl;
			Search(stu, currentN);
			Menu();
		}
		else if (a == "5")
		{
			cout << "��ѡ���˲���ѧ��" << endl;
			Input(stu, currentN);
			Menu();
		}
		else if (a == "6")
		{
			cout << "��ѡ����ɾ��ѧ��" << endl;
			Delete(stu, currentN);
			Menu();
		}
		else if (a == "7")
		{
			cout << "��ѡ����ͳ������" << endl;
			Statis(stu, currentN);
			Menu();
		}
		else if (a == "0")
		{
			/*���ļ�д������*/
			ofstream fileout("students.txt", ios::binary);
			if (!fileout)
			{
				cout << "�ļ����ܱ��򿪣�" << endl;
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
			cout << "����Ƿ������������룡" << endl;
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
	cout << "��л����ʹ�ã� " << endl;
	cout << "ϵͳ����3����˳�" << endl;
	Sleep(3000);
	exit(0);
}