/***************************************
* ���ܣ����&��װ������
* ���ܣ������������ǰ״̬��9λ01����ʾ��
*      �����ʱ�������Ľⷨ��װ���Լ���Ӧ����
*      0��ʾ��������
*      1��ʾ��������
*
* ֧�־�����ȫ��״̬�Ľⷨ��װ��
****************************************/

#include <iostream>   
#include <string>

using namespace std;

class Ring
{
public:
	Ring(string s);
	void UpRing(int n);
	void DownRing(int n);
	void startDownRing();
	void startUpRing();
	void totalCnt();
	void setUpZero();
private:
	int nDownRingNum;
	int nUpRingNum;
	static int s_nCnt;
	string stRing;
};

int Ring::s_nCnt = 0;    //����  

Ring::Ring(string s)
{
	stRing = s;
	for (int i = 0;i < 9;i++)
	{
		if (s[i] == '1')nDownRingNum = i + 1;
		if (s[i] == '0')nUpRingNum = i + 1;
	}
}

void Ring::UpRing(int n)  //Upring��DownRing�������.  
{
	if (n > 0)
	{
		if (n > 1 && stRing[n - 2] == '0') UpRing(n - 1);
		if (n > 2) DownRing(n - 2);
		if (stRing[n - 1] == '0')
		{
			stRing[n - 1] = '1';
			++s_nCnt;
			cout << "�ϵ�" << n << "��" << endl;
		}
		if (n > 1 && stRing[n - 2] == '0') UpRing(n - 1);
		if (n > 2) UpRing(n - 2);
	}
}

void Ring::DownRing(int n)
{
	while (n >= 1 && stRing[n - 1] == '0')n--;
	if (n > 0)
	{
		if (n > 1 && stRing[n - 2] == '0') UpRing(n - 1);//
		if (n > 2) DownRing(n - 2);

		stRing[n - 1] = '0';
		++s_nCnt;
		cout << "�µ�" << n << "��" << endl;

		if (n > 2) UpRing(n - 2);
		if (n > 1) DownRing(n - 1);
	}
}

void Ring::startDownRing()
{
	cout << "��������:" << stRing << endl;
	DownRing(nDownRingNum);
	cout << "������" << endl;
}

void Ring::startUpRing()
{
	cout << "��װ������:" << stRing << endl;
	UpRing(nUpRingNum);
	cout << "��װ���" << endl;
}

void Ring::totalCnt()
{
	cout << "���ۼ��ϡ��»�" << s_nCnt << "��!" << endl << endl;
}

void Ring::setUpZero()
{
	Ring::s_nCnt = 0;
}

int main()
{
	string s;
	cin >> s;
	Ring dring(s);
	dring.startDownRing();
	dring.totalCnt();
	dring.setUpZero();      //��Ϊ0  

	Ring uring(s);
	uring.startUpRing();
	uring.totalCnt();
	uring.setUpZero();

	return 0;
}