/***************************************
* ���ܣ����&��װn����
* ���ܣ���������n
*      ���n�����Ľⷨ��װ���Լ���Ӧ����
* 
* ��֧�ֻ�ȫ��������ʱ���ºͻ�ȫ��������ʱװ��
****************************************/

#include<iostream>   

using namespace std;

class Ring
{
public:
	Ring(int n) :nRingNum(n) {}
	void UpRing(int n);
	void DownRing(int n);
	void startDownRing();
	void startUpRing();
	void totalCnt();
	void setUpZero();
private:
	int nRingNum;
	static int s_nCnt;
};

int Ring::s_nCnt = 0;    //����  

void Ring::UpRing(int n)  //Upring��DownRing�������.  
{
	if (n != 0)
	{
		++s_nCnt;
		if (n > 1) UpRing(n - 1);
		if (n > 2) DownRing(n - 2);
		cout << "�ϵ�" << n << "��" << endl;
		if (n > 2) UpRing(n - 2);
	}
}

void Ring::DownRing(int n)
{
	if (n != 0)
	{
		++s_nCnt;
		if (n > 2) DownRing(n - 2);
		cout << "�µ�" << n << "��" << endl;
		if (n > 2) UpRing(n - 2);
		if (n > 1) DownRing(n - 1);
	}
}

void Ring::startDownRing()
{
	cout << "���" << nRingNum << "��������!" << endl;
	DownRing(nRingNum);
	cout << "������" << endl;
}

void Ring::startUpRing()
{
	cout << "��װ" << nRingNum << "��������!" << endl;
	UpRing(nRingNum);
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
	int n;
	cin >> n;
	Ring ring(n);
	ring.startDownRing();
	ring.totalCnt();
	ring.setUpZero();      //��Ϊ0  

	ring.startUpRing();
	ring.totalCnt();
	ring.setUpZero();

	return 0;
}