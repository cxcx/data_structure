#include "heap.h"
int main(int argc, char *argv[])
{
	//测试创建最大堆
    int array[8] = {53, 17, 78, 9, 45, 65, 87, 23};
    MaxHeap<int> maxHeap(array, 8);
	cout<<maxHeap<<endl;
 	//测试取出最大
	int max = maxHeap.removeMax();
	cout<<max<<endl;
	cout<<maxHeap<<endl;
	//测试插入
	MaxHeap<int> maxHeap2;
	while(1)
	{
		int value;
		cin>>value;
		maxHeap2.insert(value);
		cout<<maxHeap2<<endl;
}
}
