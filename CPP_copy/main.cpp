
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


class Text {
public:
	//���캯��
	Text(const char* str) {
		//����һ���ڴ棬������ַ���
		m_size = strlen(str) + 1;
		m_buf = new char[m_size];
		strcpy(m_buf, str);
	}
	//�������캯��
	Text(const Text& other) {
		m_size = other.m_size;
		m_buf = new char[m_size];
		strcpy(m_buf, other.m_buf);
	}

	~Text() {
		//�ͷŴ��ַ���
		delete[] m_buf;
	}

	const char* GetText() {
		return m_buf;
	}
private:
	int m_size;
	char* m_buf;
};

void main() {
	Text t1("hello world");
	printf("t1:%s\n", t1.GetText());

	//�����������Ϊcopy�ǿ��������ݣ������ǿ�����ָ�룬����������ʱ
	//t1�Ѿ�m_buf�ڴ��ͷţ�t2.m_buf(ָ��ͬһ���ڴ�)������ʱ�Ѿ���delete
	//Text t2(t1);

	//����취
	//���copy���캯��

	system("pause");
}
