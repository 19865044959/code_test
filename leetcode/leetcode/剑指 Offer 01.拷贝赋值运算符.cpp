/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������1����ֵ���������
// ��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������

/*
    ֪ʶ�㣺
    һ��������ֵ���������Ҫע��4�����飺
        1. �����β�һ����const ������& a�����������ã����������ʵ������Ч�ʵ���
        2. ����ֵһ���� ������&���������ã�����������ֵ
        3. �Ƿ��ͷ�ʵ�����е��ڴ�
        4. �жϴ���Ĳ����뵱ǰʵ���ǲ���ͬһ��ʵ��
*/
#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);  //���캯��
    CMyString(const CMyString& str); //�������캯��
    ~CMyString(void); //��������

    CMyString& operator = (const CMyString& str); //������ֵ�����

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if (pData == nullptr) {
        m_pData = new char[1]; //���ﲻ��˵��ʱ����һ��������������Ҫnew����Ϊ��ʱ��������if{}���ֱ�ӱ�������
        m_pData[0] = '\0';
    }
    else {
        //1�����ȿ���һ�����µĿռ䣬�ÿռ��ڶѿռ��ڣ��´���Ҫ��deleteɾ��
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy_s(m_pData, length + 1, pData); //������ʹ��strcpy������strcpy_s�����ң�strcpy_s��copy��new�ĳ�Աʱ����Ҫ��3������������

        //2���������˼��m_pData��pDataָ��ͬһ�����ݣ�û�дﵽ���Ƶ�Ҫ��
        //m_pData = pData;
    }
}

CMyString::CMyString(const CMyString& str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy_s(m_pData, length + 1, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMyString& CMyString::operator = (const CMyString& str)
{
    if (this == &str) return *this;
    else {
        delete[] m_pData;
        m_pData = nullptr;

        int length = strlen(str.m_pData);
        m_pData = new char[length + 1];
        strcpy_s(m_pData, length + 1, str.m_pData);

        return *this;
    }
}

void CMyString::Print()
{
    printf("%s", m_pData);
}

// ====================���Դ���====================
void Test1()
{
    printf("Test1 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// ��ֵ���Լ�
void Test2()
{
    printf("Test2 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// ������ֵ
void Test3()
{
    printf("Test3 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

//���Կ������캯��
void Test4()
{
    printf("Test4 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    CMyString str2(str1);

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}

