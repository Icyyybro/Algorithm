#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define MAX_NUM 1001
#define INFINITY 0x3f
typedef pair<int, int> PII;

/// 基础算法
//------------------------------------------------------------------------------
// 快速排序
void quick_sort(int q[], int l, int r);

// 归并排序
void merge_sort(int q[], int l, int r, int temp[]);

// 二分排序1
int binary_search_1(int l, int r);

// 二分排序2
int binary_search_2(int l, int r);
bool check(int mid);

// 高精度加法
vector<int> high_accuracy_add(vector<int> &A, vector<int> &B); // 数组从零开始依次是个位，十位，百位......

// 高精度减法
vector<int> high_accuracy_sub(vector<int> &A, vector<int> &B); // 默认A>=B

// 高精度乘法
vector<int> high_accuracy_mul(vector<int> &A, int b);

// 两个高维数进行高精度乘法
void two_high_accuracy_mul();

// 高精度除法
vector<int> high_accuracy_div(vector<int> &A, int b, int &r);

// 二维前缀和
void two_dim_pre_sum(int p[][MAX_NUM], int n, int m, int sum[][MAX_NUM]);
int calculate_submatrix(int sum[][MAX_NUM], int x1, int x2, int y1, int y2); // 计算子矩阵

// 一维差分
void one_dim_diff(int p[], int n, int diff[]);
void one_dim_diff_plus(int diff[], int n, int l, int r, int c); // 将数组从l到r区间上的数加c

// 二维差分
void two_dim_diff_plus(int diff[][MAX_NUM], int x1, int x2, int y1, int y2, int c); // 二维差分仅需要考虑子矩阵所有元素加c的方法就行，构造可以想象成多次加c就可以

// 离散化
int discretization(vector<int> a, int x); // 离散化，并找出x对应离散化的位置

// 区间合并
void interval_merge(vector<PII> &segs);

/// 基础算法
//------------------------------------------------------------------------------
// 数组实现链表
// head表示头节点的下标
// e[i]表示节点i的值
// ne[i]表示节点i的next指针
// idx记录已经用到了哪个节点
void link_list_add(int k, int x, int &head, int e[], int ne[], int &idx); // 在k节点后插入节点
void link_list_remove(int k, int &head, int e[], int ne[], int &idx);

// 单调栈
// 给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 - 1。
void monotonic_stack();

// 单调队列
// 滑动窗口
// 输入包含两行。
// 第一行包含两个整数n和k，分别代表数组长度和滑动窗口的长度。
// 第二行有n个整数，代表数组的具体数值。
// 同行数据之间用空格隔开。
void monotonic_queue();

// KMP算法
void KMP(int p[], int s[], int n, int m); // 数组都从下标1开始

// Tries树
// son[i][26]表示第i个节点的26个孩子的序号
// cnt[]以当前节点结尾的单词有几个
// idx当前分配的下标
void Tries_tree_insert(int son[][26], int cnt[], int idx, char str[]);
int query(int son[][26], int cnt[], char str[]);

// 并查集
void init_DSU(int p[], int n);				  // 初始化并查集
int find_DSU(int p[], int n, int x);		  // 查找x的祖先节点
void merge_DSU(int p[], int n, int a, int b); // 将a集合和b集合合并

// 小顶堆
void create_heap(int p[], int n);
void down_heap(int p[], int u, int size); // u位置上的数大了，要向下调整
void up_heap(int p[], int u, int size);

// hash
// 拉链法
void insert_hash(int x, int head[], int e[], int next[], int &idx); // 将x放入哈希表里,采用头插法
bool find_hash(int x, int head[], int e[], int next[]);				// 查找x是否在hash中

/// 搜索与图论
//------------------------------------------------------------------------------
// 深度优先搜索
void dfs(int path[], bool visited[], int n, int u);

// 宽度优先搜索
void bfs(int n, int next[]);

// 迪杰斯特拉算法寻找最短路径
// 邻接矩阵版本(朴素dijkstra算法)
int dijkstra_graph(int graph[][MAX_NUM], int n);
// 邻接矩阵版本(堆优化)
int dijkstra_graph_queue_priority(int graph[][MAX_NUM], int n);
// 邻接表版本(插入边)
void dijkstra_list_add(int e[], int next[], int head[], int weight[], int x, int y, int length, int &idx);
// 邻接表版本(堆优化)
int dijkstra_list_priority_queue(int e[], int next[], int head[], int weight[], int n);

// Bellman-Ford算法
int bellman_ford(int k); // 通过k条边可以到达终点的最短路径

// SPFA算法
// 插入边
void spfa_add(int e[], int next[], int head[], int weight[], int x, int y, int length, int &idx);
// 寻找最短路径
int spfa(int e[], int next[], int head[], int weight[], int n);
// 判断负环
bool spfa_judge(int e[], int next[], int head[], int weight[], int n);

// Floyd算法
void floyd(int graph[][MAX_NUM], int n);

// prim算法
int prim(int graph[][MAX_NUM], int n);

// kruskal算法
// 定义边
struct Edge
{
	int a;
	int b;
	int w;
};
// 并查集查找祖宗节点，判断是否联通
int kruskal_find(int x, int p[]);
// 算法
int kruskal(Edge edges[], int m, int n);
// 比较边权大小
int edges_cmp(Edge e1, Edge e2);

// 染色法判断二分图
// 深度优先搜索给图染色
bool stain_dfs(int c, int u, int color[], int e[], int next[], int head[]);
// 染色法
bool stain(int e[], int next[], int head[], int n);

// 匈牙利算法
int hungary();
// 判断是否有对象
bool hungary_find(int x, bool visited[], int head[], int e[], int next[], bool match[]);

/// 数论
//------------------------------------------------------------------------------
// 质数
// 试除法判断质数
bool is_prime(int x);
// 分解质因数
void divide(int x);
// 埃及筛法找出所有比n小的质数
void get_primes_egypt(int x, vector<int> primes);
// 线性筛法找出所有比n小的质数
vector<int> get_primes_linear(int x);

// 约数
// 求所有约数
vector<int> get_divisor(int x);
// 求约数个数
int get_divisor_num(int x);

// 欧拉函数
void ola(int x);
// 线性筛法求n个数的欧拉函数之和
long long ola_sum(int x);

// 快速幂
int quick_power(int a, int k, int p);
// 快速幂求逆元
int inverse_element(int a, int p);

// 扩展欧几里得算法
int exgcd(int a, int b, int &x, int &y);

// 高斯消元
int gauss(double a[][MAX_NUM], int n);

// 求组合数1
void combination(int N);