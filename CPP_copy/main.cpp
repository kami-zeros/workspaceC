
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


class Text {
public:
	//构造函数
	Text(const char* str) {
		//申请一块内存，保存此字符串
		m_size = strlen(str) + 1;
		m_buf = new char[m_size];
		strcpy(m_buf, str);
	}
	//拷贝构造函数
	Text(const Text& other) {
		m_size = other.m_size;
		m_buf = new char[m_size];
		strcpy(m_buf, other.m_buf);
	}

	~Text() {
		//释放此字符串
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

	//这里崩溃，因为copy是拷贝其数据，而不是拷贝其指针，所以在析构时
	//t1已经m_buf内存释放，t2.m_buf(指向同一块内存)在析构时已经被delete
	//Text t2(t1);

	//解决办法
	//添加copy构造函数

	system("pause");
}
