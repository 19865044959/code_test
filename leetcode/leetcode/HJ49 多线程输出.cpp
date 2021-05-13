/*
������������4���̺߳�1���������ַ����顣�߳�1�Ĺ��ܾ������������A���߳�2�Ĺ��ܾ������ַ����B���߳�3�Ĺ��ܾ������������C���߳�4�Ĺ��ܾ������������D��Ҫ��˳�������鸳ֵABCDABCDABCD��ABCD�ĸ������̺߳���1�Ĳ���ָ����[ע��C����ѡ�ֿ�ʹ��WINDOWS SDK�⺯��]
�ӿ�˵����
void init();  //��ʼ������
void Release(); //��Դ�ͷź���
unsignedint__stdcall ThreadFun1(PVOID pM)  ; //�̺߳���1������һ��int���͵�ָ��[ȡֵ��Χ��1 �C 250������������֤]�����ڳ�ʼ�����A��������Դ��Ҫ�߳��ͷ�
unsignedint__stdcall ThreadFun2(PVOID pM)  ;//�̺߳���2���޲�������
unsignedint__stdcall ThreadFun3(PVOID pM)  ;//�̺߳���3���޲�������
Unsigned int __stdcall ThreadFunc4(PVOID pM);//�̺߳���4���޲�������
char  g_write[1032]; //�߳�1,2,3,4��˳��������鸳ֵ�����ÿ��������Ƿ�Խ�磬����������֤
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

string g_write;
mutex mtx;
bool stop = false;

void thread_fun1(int num) {
    while (num) {
        if (mtx.try_lock()) {
            int len = g_write.length();
            if (len % 4 == 0) {
                g_write += 'A';
                num--;
            }
            mtx.unlock();
        }
    }
    stop = true;
}

void thread_fun2() {
    while (1) {
        if (mtx.try_lock()) {
            int len = g_write.length();
            if (stop && len % 4 == 0) {
                mtx.unlock();
                return;
            }
            if (len % 4 == 1) {
                g_write += 'B';
            }
            mtx.unlock();
        }
    }
}
void thread_fun3() {
    while (1) {
        if (mtx.try_lock()) {
            int len = g_write.length();
            if (stop && len % 4 == 0) {
                mtx.unlock();
                return;
            }
            if (len % 4 == 2) {
                g_write += 'C';
            }
            mtx.unlock();
        }
    }
}
void thread_fun4() {
    while (1) {
        if (mtx.try_lock()) {
            int len = g_write.length();
            if (stop && len % 4 == 0) {
                mtx.unlock();
                return;
            }
            if (len % 4 == 3) {
                g_write += 'D';
            }
            mtx.unlock();
        }
    }
}
int main() {
    int in;
    while (cin >> in) {
        thread t1(thread_fun1, in);
        thread t2(thread_fun2);
        thread t3(thread_fun3);
        thread t4(thread_fun4);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        cout << g_write.c_str() << endl;
        g_write.clear();
        stop = false;
    }
    return 0;
}