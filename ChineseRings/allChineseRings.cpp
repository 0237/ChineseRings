/***************************************
* 功能：拆解&安装九连环
* 介绍：输入九连环当前状态（9位01串表示）
*      输出此时九连环的解法和装法以及相应步数
*      0表示环在轴下
*      1表示环在轴上
*
* 支持九连环全部状态的解法和装法
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

int Ring::s_nCnt = 0;    //计数  

Ring::Ring(string s)
{
	stRing = s;
	for (int i = 0;i < 9;i++)
	{
		if (s[i] == '1')nDownRingNum = i + 1;
		if (s[i] == '0')nUpRingNum = i + 1;
	}
}

void Ring::UpRing(int n)  //Upring是DownRing的逆过程.  
{
	//if (n > 1 && stRing[n - 1] == '1')n--;//如果当环在轴上，则后移一位。
	//while (n >= 1 && stRing[n - 1] == '1')n--;
	if (n > 0)
	{
		if (n > 1 && stRing[n - 2] == '0') UpRing(n - 1);//更改
		if (n > 2) DownRing(n - 2);
		if (stRing[n - 1] == '0')
		{
			stRing[n - 1] = '1';
			++s_nCnt;
			cout << "上第" << n << "环" << endl;
		}
		//if (n > 1 && stRing[n - 2] == '0')n++;//如果下一个环不在轴上，则后移一位
		if (n > 1 && stRing[n - 2] == '0') UpRing(n - 1);//
		if (n > 2) UpRing(n - 2);//原有的
		//if (n > 1) UpRing(n - 1);//试验
		//if (n > 1 && stRing[n - 1] == '1') DownRing(n - 1);//
	}
}

void Ring::DownRing(int n)
{
	//if (n > 1 && stRing[n - 1] == '0')n--;//如果当前环在轴下，则前移一位
	while (n >= 1 && stRing[n - 1] == '0')n--;
	if (n > 0)
	{
		if (n > 1 && stRing[n - 2] == '0') UpRing(n - 1);//
		if (n > 2) DownRing(n - 2);
		//if (stRing[n - 1] == '1')
		//{
			stRing[n - 1] = '0';
			++s_nCnt;
			cout << "下第" << n << "环" << endl;
		//}
		//if (n > 1 && stRing[n - 2] == '0')n--;//如果下一个环在轴上，则前移一位
		if (n > 2) UpRing(n - 2);
		if (n > 1) DownRing(n - 1);
	}
}

void Ring::startDownRing()
{
	cout << "拆解九连环:" << stRing << endl;
	DownRing(nDownRingNum);
	cout << "拆解完毕" << endl;
}

void Ring::startUpRing()
{
	cout << "安装九连环:" << stRing << endl;
	UpRing(nUpRingNum);
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
	string s;
	cin >> s;
	Ring dring(s);
	dring.startDownRing();
	dring.totalCnt();
	dring.setUpZero();      //置为0  

	Ring uring(s);
	uring.startUpRing();
	uring.totalCnt();
	uring.setUpZero();

	return 0;
}