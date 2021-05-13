/*
问题描述：有4个线程和1个公共的字符数组。线程1的功能就是向数组输出A，线程2的功能就是向字符输出B，线程3的功能就是向数组输出C，线程4的功能就是向数组输出D。要求按顺序向数组赋值ABCDABCDABCD，ABCD的个数由线程函数1的参数指定。[注：C语言选手可使用WINDOWS SDK库函数]
接口说明：
void init();  //初始化函数
void Release(); //资源释放函数
unsignedint__stdcall ThreadFun1(PVOID pM)  ; //线程函数1，传入一个int类型的指针[取值范围：1 – 250，测试用例保证]，用于初始化输出A次数，资源需要线程释放
unsignedint__stdcall ThreadFun2(PVOID pM)  ;//线程函数2，无参数传入
unsignedint__stdcall ThreadFun3(PVOID pM)  ;//线程函数3，无参数传入
Unsigned int __stdcall ThreadFunc4(PVOID pM);//线程函数4，无参数传入
char  g_write[1032]; //线程1,2,3,4按顺序向该数组赋值。不用考虑数组是否越界，测试用例保证
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