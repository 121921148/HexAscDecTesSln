// HexAscDecTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>  //��ע�������
#include <fstream>   //��ȡ�������ļ�
#include<bitset>     //���������

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int dwAscValue = 0;
	char chAscCharacter = '\0';
	int iBinaryOut = 0;

	cout<<"/** ASCII���ַ���ASCII��ֵ��ʮ���ơ�ʮ�����ơ������ƣ��Ķ�Ӧ��ϵ��ʾ��**/"<<endl<<endl;
	cout<<"/// ������һ��(�ַ���)ASCII��ֵ��"<<endl;
	cout<<"/// "; cin>>dwAscValue;
	chAscCharacter = dwAscValue;
	cout<<"/// ��ֵ"<<"\""<<dwAscValue<<"("<<hex<<dwAscValue<<"h,";
	//���������
	iBinaryOut = dwAscValue;
	cout<<bitset<sizeof(int) * 8>(iBinaryOut)<<"b)";
	cout<<"\""<<"��Ӧ��ASCII���ַ�Ϊ��"<<chAscCharacter<<endl<<endl;

	cout<<dec;  //�ָ�Ĭ��ʮ�������


	cout<<"/// ������һ��ASCII���ַ���"<<endl;
	cout<<"/// "; 
	cin>>chAscCharacter;
	dwAscValue = chAscCharacter;
	cout<<"/// ASCII���ַ�"<<"\""<<chAscCharacter<<"\""<<"��Ӧ��ASCII��ֵΪ��"<<dwAscValue<<"("<<hex<<dwAscValue<<"h,";
	//���������
	iBinaryOut = dwAscValue;
	cout<<bitset<sizeof(int) * 8>(iBinaryOut)<<"b)"<<endl<<endl;

	cout<<dec;  //�ָ�Ĭ��ʮ�������

	cout<<"/** �������ļ���д��ʾ��**/"<<endl<<endl;
	ofstream ofs("./example.bin", std::ios::binary | std::ios::out);  //�����������ļ�

	//д�������ļ�
	if (!ofs) //���ļ�
	{
        std::cerr << "/// �޷����ļ�" << std::endl;
    }
	else  //д����
	{
		unsigned int dataToWrite = 0xFFFFFFFF;
		cout << "/// д�룺" << dataToWrite;
		cout << "(";
		cout << hex << dataToWrite << "h";
		cout << dec;
		cout <<",";
		cout << bitset<sizeof(unsigned int) * 8>((int)dataToWrite) << "b";  //bitsetֻ�ܽ���int�β���
		cout << ")" <<endl;
		cout <<endl;

		ofs.write(reinterpret_cast<const char*>(&dataToWrite), sizeof(dataToWrite));
		ofs.close();  //�ر��ļ��ͷ���Դ
	}

	//���������ļ�
    std::ifstream ifs("./example.bin", std::ios::binary | std::ios::in);
    if (!ifs) 
	{
        std::cerr << "/// �޷����ļ�" << std::endl;
    }
	else
	{
		unsigned int dataToRead;
		ifs.read(reinterpret_cast<char*>(&dataToRead), sizeof(dataToRead));
		std::cout << "/// ��ȡ������: " << dataToRead << std::endl;
		cout << "/// �����Ʊ�ʾ��" << bitset<sizeof(unsigned int) * 8>((int)dataToRead)<<endl;
		cout << "/// ʮ�����Ʊ�ʾ��" << hex << dataToRead << endl;
		cout <<dec;
		cout <<endl;

		ifs.close();
	}

	//�����д��ڱ���
	system("pause");
    getchar();

	return 0;
}

