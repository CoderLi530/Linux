#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


//插入排序
//将一个元素插入到一个已排好序的序列中，直到所有记录插入完为止，得到一个新的有序序列
//时间复杂度：最好情况O(N) 最坏情况O(N^2) 空间复杂度：O(1)
//稳定性：稳定
void InsertSort(vector<int> &v)
{
    assert(!v.empty());
    // 一个一个插入数据
    for (int i = 1; i < v.size(); ++i)
    {
        int key = v[i];
        int prev = i - 1;

        while (prev >= 0 && v[prev] > key)
        {
            v[prev + 1] = v[prev];
            --prev;
        }
        v[prev + 1] = key;
    }
}

//希尔排序
//缩小增量法，是对直接插入排序的优化，不用一个一个插入数据
//时间复杂度：最好情况O(N^1.3) 最坏情况O(N^2) 空间复杂度：O(1)
//稳定性：不稳定
void ShellSort(vector<int>& v)
{
    //使用Knuth序列计算初始间隔(比直接除2更加高效)
    int gap = 1;
    while (gap < v.size() / 3) gap = gap * 3 + 1; 
    //比较相隔一定距离的元素来排序
    for(; gap > 0; gap /= 3)
    {
        //子数组进行排序
        for (int i = gap; i < v.size(); ++i)
        {
            //和插入排序一样
            int key = v[i];
            int prev = i - gap;
            while (prev >= 0 && key < v[prev])
            {
                v[prev + gap] = v[prev];
                prev -= gap;
            }
            v[prev + gap] = key;
        }
    }
}

//选择排序
//遍历待排序的数据元素选出最大或最小的一个元素，存放到序列的起始位置，直到全部排完
//时间复杂度：最好情况O(N^2) 最好情况O(N^2) 空间复杂度：O(1)
//稳定性：不稳定
void SelectSort(vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        //先找到数组的最小值的下标
        int index = i;
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[j] < v[index])
            {
                index = j;
            }
        }
        //不管是否相等，直接交换
        swap(v[index], v[i]);
    }
}

//向下调整建大堆
void AdjustDown(vector<int>& v, int n, int parent)
{
    int child = 2 * parent + 1; //左孩子的位置
    while (child < n)
    {
        //获取左右孩子中较大的孩子，注意右孩子有可能为空
        if (child + 1 < n && v[child + 1] > v[child])
        {
            ++child;
        }
        //孩子比父亲大，交换
        if (v[child] > v[parent])
        {
            swap(v[child], v[parent]);
            //交换完之后进行向下走
            parent = child;
            child = 2 * parent + 1;
        }
        else
        {
            break;
        }
    }

}

//堆排序
//堆本质上是一个二叉树，排升序建大堆，排降序建小堆
//时间复杂度：最好情况O(NlogN) 最坏情况O(NlogN) 空间复杂度：O(1)
//稳定性：不稳定
void HeapSort(vector<int>& v)
{
    //通过向下调整建大堆
    for (int parent = (v.size() - 2) / 2; parent >= 0; --parent)
    {
        AdjustDown(v, v.size(), parent);
    }
    //利用堆顶和最后一个位置进行交换，之后移除最后一个位置进行建大堆，这样就堆顶又是最大的元素了，以此类推，直到排好序
    int end = v.size() - 1;
    while (end > 0) //等于0时已经排好序了
    {
        swap(v[0], v[end]);
        AdjustDown(v, end, 0);
        --end;
    }
}

//冒泡排序
//根据序列中两个记录键值的比较结果来交换两个记录所在序列中的位置，键值较大在序列尾部，键值较低在序列首部
//时间复杂度：最好情况O(N) 最坏情况O(N^2) 空间复杂度O(1)
//稳定性：稳定
void BubbleSort(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        bool swapped = false; 
        for (int j = 1; j < v.size(); ++j)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j - 1]);
                swapped = true;
            }
        }
        //没有进行交换，说明有序
        if (!swapped) break;
    }
}

//三数取中避免时间复杂度退化成O(N^2)
int GetMidi(vector<int>& v, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (v[left] > v[mid]) swap(v[left], v[mid]);
    if (v[left] > v[right]) swap(v[left], v[right]);
    if (v[mid] > v[right]) swap(v[mid], v[right]);

    swap(v[left], v[mid]);
    return left;
}

//递归版本
void _QuickSort(vector<int>& v, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int keyi = GetMidi(v, left, right);
    int begin = left;
    int end = right;
    while (left < right)
    {
        while (left < right && v[right] >= v[keyi])
            --right;
        while (left < right && v[left] <= v[keyi])
            ++left;
        swap(v[right], v[left]); 
        
    }
    swap(v[keyi], v[left]);
    _QuickSort(v, begin, left - 1);
    _QuickSort(v, left + 1, end);
}

//快速排序
//取待排序元素序列中的某元素作为基准值，将序列分割成两部分，左半部分均小于基准值，右半部分均大于基准值，然后左半部分和右半部分重复该过程，直到排好序列
//时间复杂度：
void QuickSort(vector<int>& v)
{
    _QuickSort(v, 0, v.size() - 1);
}

int main()
{
    vector<int> v = {2, 6, 4, 1, 5, 3, 7, 3, 9, 0};
    //InsertSort(v);
    //ShellSort(v);
    // SelectSort(v);
    // HeapSort(v);
    // BubbleSort(v);
    QuickSort(v);
    for (auto num : v)
        cout << num << " ";
    cout << endl;
    return 0;
}