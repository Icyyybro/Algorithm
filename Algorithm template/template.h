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

/// �����㷨
//------------------------------------------------------------------------------
// ��������
void quick_sort(int q[], int l, int r);

// �鲢����
void merge_sort(int q[], int l, int r, int temp[]);

// ��������1
int binary_search_1(int l, int r);

// ��������2
int binary_search_2(int l, int r);
bool check(int mid);

// �߾��ȼӷ�
vector<int> high_accuracy_add(vector<int> &A, vector<int> &B); // ������㿪ʼ�����Ǹ�λ��ʮλ����λ......

// �߾��ȼ���
vector<int> high_accuracy_sub(vector<int> &A, vector<int> &B); // Ĭ��A>=B

// �߾��ȳ˷�
vector<int> high_accuracy_mul(vector<int> &A, int b);

// ������ά�����и߾��ȳ˷�
void two_high_accuracy_mul();

// �߾��ȳ���
vector<int> high_accuracy_div(vector<int> &A, int b, int &r);

// ��άǰ׺��
void two_dim_pre_sum(int p[][MAX_NUM], int n, int m, int sum[][MAX_NUM]);
int calculate_submatrix(int sum[][MAX_NUM], int x1, int x2, int y1, int y2); // �����Ӿ���

// һά���
void one_dim_diff(int p[], int n, int diff[]);
void one_dim_diff_plus(int diff[], int n, int l, int r, int c); // �������l��r�����ϵ�����c

// ��ά���
void two_dim_diff_plus(int diff[][MAX_NUM], int x1, int x2, int y1, int y2, int c); // ��ά��ֽ���Ҫ�����Ӿ�������Ԫ�ؼ�c�ķ������У������������ɶ�μ�c�Ϳ���

// ��ɢ��
int discretization(vector<int> a, int x); // ��ɢ�������ҳ�x��Ӧ��ɢ����λ��

// ����ϲ�
void interval_merge(vector<PII> &segs);

/// �����㷨
//------------------------------------------------------------------------------
// ����ʵ������
// head��ʾͷ�ڵ���±�
// e[i]��ʾ�ڵ�i��ֵ
// ne[i]��ʾ�ڵ�i��nextָ��
// idx��¼�Ѿ��õ����ĸ��ڵ�
void link_list_add(int k, int x, int &head, int e[], int ne[], int &idx); // ��k�ڵ�����ڵ�
void link_list_remove(int k, int &head, int e[], int ne[], int &idx);

// ����ջ
// ����һ������ΪN���������У����ÿ������ߵ�һ������С�������������������� - 1��
void monotonic_stack();

// ��������
// ��������
// ����������С�
// ��һ�а�����������n��k���ֱ�������鳤�Ⱥͻ������ڵĳ��ȡ�
// �ڶ�����n����������������ľ�����ֵ��
// ͬ������֮���ÿո������
void monotonic_queue();

// KMP�㷨
void KMP(int p[], int s[], int n, int m); // ���鶼���±�1��ʼ

// Tries��
// son[i][26]��ʾ��i���ڵ��26�����ӵ����
// cnt[]�Ե�ǰ�ڵ��β�ĵ����м���
// idx��ǰ������±�
void Tries_tree_insert(int son[][26], int cnt[], int idx, char str[]);
int query(int son[][26], int cnt[], char str[]);

// ���鼯
void init_DSU(int p[], int n);				  // ��ʼ�����鼯
int find_DSU(int p[], int n, int x);		  // ����x�����Ƚڵ�
void merge_DSU(int p[], int n, int a, int b); // ��a���Ϻ�b���Ϻϲ�

// С����
void create_heap(int p[], int n);
void down_heap(int p[], int u, int size); // uλ���ϵ������ˣ�Ҫ���µ���
void up_heap(int p[], int u, int size);

// hash
// ������
void insert_hash(int x, int head[], int e[], int next[], int &idx); // ��x�����ϣ����,����ͷ�巨
bool find_hash(int x, int head[], int e[], int next[]);				// ����x�Ƿ���hash��

/// ������ͼ��
//------------------------------------------------------------------------------
// �����������
void dfs(int path[], bool visited[], int n, int u);

// �����������
void bfs(int n, int next[]);

// �Ͻ�˹�����㷨Ѱ�����·��
// �ڽӾ���汾(����dijkstra�㷨)
int dijkstra_graph(int graph[][MAX_NUM], int n);
// �ڽӾ���汾(���Ż�)
int dijkstra_graph_queue_priority(int graph[][MAX_NUM], int n);
// �ڽӱ�汾(�����)
void dijkstra_list_add(int e[], int next[], int head[], int weight[], int x, int y, int length, int &idx);
// �ڽӱ�汾(���Ż�)
int dijkstra_list_priority_queue(int e[], int next[], int head[], int weight[], int n);

// Bellman-Ford�㷨
int bellman_ford(int k); // ͨ��k���߿��Ե����յ�����·��

// SPFA�㷨
// �����
void spfa_add(int e[], int next[], int head[], int weight[], int x, int y, int length, int &idx);
// Ѱ�����·��
int spfa(int e[], int next[], int head[], int weight[], int n);
// �жϸ���
bool spfa_judge(int e[], int next[], int head[], int weight[], int n);

// Floyd�㷨
void floyd(int graph[][MAX_NUM], int n);

// prim�㷨
int prim(int graph[][MAX_NUM], int n);

// kruskal�㷨
// �����
struct Edge
{
	int a;
	int b;
	int w;
};
// ���鼯�������ڽڵ㣬�ж��Ƿ���ͨ
int kruskal_find(int x, int p[]);
// �㷨
int kruskal(Edge edges[], int m, int n);
// �Ƚϱ�Ȩ��С
int edges_cmp(Edge e1, Edge e2);

// Ⱦɫ���ж϶���ͼ
// �������������ͼȾɫ
bool stain_dfs(int c, int u, int color[], int e[], int next[], int head[]);
// Ⱦɫ��
bool stain(int e[], int next[], int head[], int n);

// �������㷨
int hungary();
// �ж��Ƿ��ж���
bool hungary_find(int x, bool visited[], int head[], int e[], int next[], bool match[]);

/// ����
//------------------------------------------------------------------------------
// ����
// �Գ����ж�����
bool is_prime(int x);
// �ֽ�������
void divide(int x);
// ����ɸ���ҳ����б�nС������
void get_primes_egypt(int x, vector<int> primes);
// ����ɸ���ҳ����б�nС������
vector<int> get_primes_linear(int x);

// Լ��
// ������Լ��
vector<int> get_divisor(int x);
// ��Լ������
int get_divisor_num(int x);

// ŷ������
void ola(int x);
// ����ɸ����n������ŷ������֮��
long long ola_sum(int x);

// ������
int quick_power(int a, int k, int p);
// ����������Ԫ
int inverse_element(int a, int p);

// ��չŷ������㷨
int exgcd(int a, int b, int &x, int &y);

// ��˹��Ԫ
int gauss(double a[][MAX_NUM], int n);

// �������1
void combination(int N);