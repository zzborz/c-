#include<iostream>
using namespace std;
//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
#define MAX 1000
//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];//��ϵ������
	int m_Size;//ͨѶ¼��ǰ����
};
//�˵�����
void showMenu()
{
	cout << "************" << endl;
	cout << "******1�������ϵ��******" << endl;
	cout << "******2����ʾ��ϵ��******" << endl;
	cout << "******3��ɾ����ϵ��******" << endl;
	cout << "******4��������ϵ��******" << endl;
	cout << "******5���޸���ϵ��******" << endl;
	cout << "******6�������ϵ��******" << endl;
	cout << "******7���˳���ϵ��******" << endl;
	cout << "************" << endl;
}
//�����ϵ��
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size==MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�����" << endl;
		return;
	}
	else
	{
		//�����ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex==1||sex==2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "��������,��������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "������סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//���������
		system("cls");//����

	}
}
//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼����
	if (abs->m_Size==0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";//�հ˸��ַ�
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰: " << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name==name)
		{
			return i;
		}
	}
	return -1;
}
//ɾ��ָ����ϵ��
void deletPerson(Addressbooks* abs) 
{
	string name;
	cout << "������Ҫɾ������ϵ��" << endl;
	cin >> name;
	int ret = isExist(abs, name);
		if (ret != -1)
		{

			for (int i = ret; i < abs->m_Size; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
			cout << "ɾ����ϵ�˳ɹ�" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "���޴���" << endl;
		}
}
//������ϵ��
void findPreson(Addressbooks* abs)
{
	cout << "��������Ҫ��ѯ����ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret!=-1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";//�հ˸��ַ�
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "δ�ҵ���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret!=-1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "��������,��������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "������סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��
	abs.m_Size = 0;
	int select;
	//�˵���Ӷ
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletPerson(&abs);
			break;
		/*{
			cout << "������ɾ����ϵ�˵�����"<<endl;
			string name;
			cin >> name;
			if (isExist(&abs,name)==-1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����"<<endl;
			}
			

			break;
		}*/
		//��ѯ��
		case 4://4��������ϵ��
			findPreson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");  
	return 0;

}