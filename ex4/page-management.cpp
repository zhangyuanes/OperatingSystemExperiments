/**
 * @file page-management.cpp
 * @author zhaokangming (952917537@qq.com)
 * @author zhangyuanes (zhangyuanes@gmail.com)
 * @brief 存储管理框架代码
 * @version 0.2
 * @date 2021-05-17
 * 
 * @copyright Copyright (c) 2021
 * @note 
 1、 请勿修改本框架代码的函数定义
 2、 允许添加合适的C++头文件来进行编码
 3、 编程版本选择C或者C++其中一种即可，对应框架代码逻辑没有变化。

实验手册在线地址： https://www.zybuluo.com/yanbo01haomiao/note/1794341

 */
#include <iostream>
#include <time.h>
using namespace std;

#define DATA_NUM 30 // 页地址长度

/**
 * @brief 创建一个大小为N的页地址流数组
 * @param data 用于存储页地址流的数组
 * @param N 页地址流长度
 * @param seed 随机种子，相同种子产生的数组相同
 * @note 请勿修改本函数定义，如需改变不同页地址流请修改种子输入
 */
void create_data(int data[], int N, int seed) {
	srand(seed);
	for (int i = 0; i < N; i++) {
		data[i] = rand() % 5;
	}
}
/**
 * @brief 重置页地址流数据为-1
 * @param data 用于存储页地址流的数组
 * @param N 页地址流长度
 */
void reset_data(int data[], int N) {
	for (int i = 0; i < N; i++) {
		data[i] = -1;
	}
}
/**
 * @brief 输出页地址流数据
 * @param data 用于存储页地址流的数组
 * @param N 页地址流长度
 */
void output_data(int data[], int N) {
	for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
	}
	cout << endl;
}
/**
 * @brief 创建一个大小为N的页地址流数据
 * @param output 用于存储页面置换的过程数组
 * @param size 过程数组长度
 */
void show_output(int output[], const int size) {
	for (int i = 0; i < size; ++i) {
        cout << output[i] << " ";
	}
	cout << endl;
}

/**
 * @brief FIFO具体算法实现
 * @param data 页地址流数组
 * @param N 页地址流长度
 * @param memory_Size cache长度
 * @param output 记录页面置换的过程数组
 * @return 页面命中率，范围[0,1]
 * @note 需要自行补充完成,完成对应逻辑和输出
 */
float FIFO(int data[], const int N, const int memory_Size, int output[]) {
    //todo finish the function
	return 0.0;
}

float LRU(int data[], const int N, const int memory_Size, int output[]) {
    //todo finish the function
	return 0.0;
}

float optimal(int data[], const int N, const int memory_Size, int output[]) {
    //todo finish the function
	return 0.0;
}

int main() {
	const int seed = 333;    // 随机种子，请依次测试随机种子 1， 333， 256， 512，1000
	int max_memory_size = 5; // 最大cache长度
    int data_num = DATA_NUM; // 页地址流长度
	int data[DATA_NUM];      // 页地址流数组
	int output[DATA_NUM];    // 页面置换的过程数组，-1表示首次置入cache或者命中，对应地址数值表示从cache中置换出去的页面地址
    int i, j;
    float rate; 
    // 利用随机种子产生随机页地址流，然后展示
	create_data(data, data_num, seed);
    cout << "The data input is: " << endl;
	for (i = 0; i < data_num; ++i) {
        cout << data[i] << " ";
    }
	cout << endl;

	for (j = 2; j < max_memory_size; ++j) {
        cout << "when cache size is " << j << endl;

		reset_data(output, data_num);
        rate = FIFO(data, data_num, j, output);
        cout << "The hit rate of FIFO is: " << rate << endl;
        cout << "The output in FIFO is: " << endl;
		show_output(output, data_num);

		reset_data(output, data_num);
        rate = LRU(data, data_num, j, output);
        cout << "The hit rate of LRU is: " << rate << endl;
        cout << "The output in LRU is: " << endl;
		show_output(output, data_num);

		reset_data(output, data_num);
		rate = optimal(data, data_num, j, output);
        cout << "The hit rate of optimal is: "<< rate << endl;
        cout << "The output in optimal is: " << endl;
		show_output(output, data_num);
		
        cout << endl;
	}
    return 0;
}