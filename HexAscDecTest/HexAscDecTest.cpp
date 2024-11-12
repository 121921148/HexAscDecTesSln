// HexAscDecTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  //标注输入输出
#include <fstream>   //读取二进制文件
#include<bitset>     //二进制输出

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int dwAscValue = 0;
	char chAscCharacter = '\0';
	int iBinaryOut = 0;

	cout<<"/** ASCII码字符、ASCII码值（十进制、十六进制、二进制）的对应关系演示：**/"<<endl<<endl;
	cout<<"/// 请输入一个(字符的)ASCII码值："<<endl;
	cout<<"/// "; cin>>dwAscValue;
	chAscCharacter = dwAscValue;
	cout<<"/// 码值"<<"\""<<dwAscValue<<"("<<hex<<dwAscValue<<"h,";
	//二进制输出
	iBinaryOut = dwAscValue;
	cout<<bitset<sizeof(int) * 8>(iBinaryOut)<<"b)";
	cout<<"\""<<"对应的ASCII码字符为："<<chAscCharacter<<endl<<endl;

	cout<<dec;  //恢复默认十进制输出


	cout<<"/// 请输入一个ASCII码字符："<<endl;
	cout<<"/// "; 
	cin>>chAscCharacter;
	dwAscValue = chAscCharacter;
	cout<<"/// ASCII码字符"<<"\""<<chAscCharacter<<"\""<<"对应的ASCII码值为："<<dwAscValue<<"("<<hex<<dwAscValue<<"h,";
	//二进制输出
	iBinaryOut = dwAscValue;
	cout<<bitset<sizeof(int) * 8>(iBinaryOut)<<"b)"<<endl<<endl;

	cout<<dec;  //恢复默认十进制输出

	cout<<"/** 二进制文件读写演示：**/"<<endl<<endl;
	ofstream ofs("./example.bin", std::ios::binary | std::ios::out);  //创建二进制文件

	//写二进制文件
	if (!ofs) //打开文件
	{
        std::cerr << "/// 无法打开文件" << std::endl;
    }
	else  //写操作
	{
		unsigned int dataToWrite = 0xFFFFFFFF;
		cout << "/// 写入：" << dataToWrite;
		cout << "(";
		cout << hex << dataToWrite << "h";
		cout << dec;
		cout <<",";
		cout << bitset<sizeof(unsigned int) * 8>((int)dataToWrite) << "b";  //bitset只能接受int形参吗？
		cout << ")" <<endl;
		cout <<endl;

		ofs.write(reinterpret_cast<const char*>(&dataToWrite), sizeof(dataToWrite));
		ofs.close();  //关闭文件释放资源
	}

	//读二进制文件
    std::ifstream ifs("./example.bin", std::ios::binary | std::ios::in);
    if (!ifs) 
	{
        std::cerr << "/// 无法打开文件" << std::endl;
    }
	else
	{
		unsigned int dataToRead;
		ifs.read(reinterpret_cast<char*>(&dataToRead), sizeof(dataToRead));
		std::cout << "/// 读取的数据: " << dataToRead << std::endl;
		cout << "/// 二进制表示：" << bitset<sizeof(unsigned int) * 8>((int)dataToRead)<<endl;
		cout << "/// 十六进制表示：" << hex << dataToRead << endl;
		cout <<dec;
		cout <<endl;

		ifs.close();
	}

	//命令行窗口保持
	system("pause");
    getchar();

	return 0;
}

