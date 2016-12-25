/***************************************
* 功能：拆解&安装n连环
* 介绍：输入数字n
*      输出n连环的解法和装法以及相应步数
* 
* 仅支持环全部在轴上时解下和环全部在轴下时装上
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

int Ring::s_nCnt = 0;    //计数  

void Ring::UpRing(int n)  //Upring是DownRing的逆过程.  
{
	if (n != 0)
	{
		++s_nCnt;
		if (n > 1) UpRing(n - 1);
		if (n > 2) DownRing(n - 2);
		cout << "上第" << n << "环" << endl;
		if (n > 2) UpRing(n - 2);
	}
}

void Ring::DownRing(int n)
{
	if (n != 0)
	{
		++s_nCnt;
		if (n > 2) DownRing(n - 2);
		cout << "下第" << n << "环" << endl;
		if (n > 2) UpRing(n - 2);
		if (n > 1) DownRing(n - 1);
	}
}

void Ring::startDownRing()
{
	cout << "拆解" << nRingNum << "连环操作!" << endl;
	DownRing(nRingNum);
	cout << "拆解完毕" << endl;
}

void Ring::startUpRing()
{
	cout << "安装" << nRingNum << "连环操作!" << endl;
	UpRing(nRingNum);
	cout << "安装完毕" << endl;
}

void Ring::totalCnt()
{
	cout << "共累计上、下环" << s_nCnt << "次!" << endl << endl;
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
	ring.setUpZero();      //置为0  

	ring.startUpRing();
	ring.totalCnt();
	ring.setUpZero();

	return 0;
}