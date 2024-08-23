#include "template.h"


void quick_sort(int q[], int l, int r)
{
	if (l >= r)
		return;

	int i = l - 1;
	int j = r + 1;
	int x = q[l];
	while (i < j)
	{
		do i++;
		while (q[i] < x);
		do j--;
		while (q[j] > x);
		if (i < j)
			swap(q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}


void merge_sort(int q[], int l, int r, int temp[])
{
	if (l >= r)
		return;

	int mid = l + r >> 1;
	merge_sort(q, l, mid, temp);
	merge_sort(q, mid + 1, r, temp);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] < q[j])
			temp[k++] = q[i];
		else
			temp[k++] = q[j];
	}

	while (i <= mid)
		temp[k++] = q[i++];
	while (j <= r)
		temp[k++] = q[j++];
}


int binary_search_1(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}


int binary_search_2(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}


bool check(int mid)
{
	return false;
}


vector<int> high_accuracy_add(vector<int>& A, vector<int>& B)			
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size())
			t += A[i];
		if (i < B.size())
			t += B[i];
		C.push_back(t % 10);
		t = t / 10;
	}
	if (t)
		C.push_back(1);
	return C;
}


vector<int> high_accuracy_sub(vector<int>& A, vector<int>& B)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		t = A[i] - t;
		if (i < B.size())
			t = t - B[i];
		C.push_back((t + 10) % 10);
		if (t < 0)
			t = 1;
		else
			t = 0;
	}

	while (C.size() > 1 && C.back() == 0)				//如003，要去掉前面的0
		C.pop_back();
	return C;
}


vector<int> high_accuracy_mul(vector<int>& A, int b)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size())
			t = t + A[i] * b;
		C.push_back(t % 10);
		t = t / 10;
	}
	return C;
}


void two_high_accuracy_mul()
{
	int answer[MAX_NUM];
	int a[MAX_NUM], b[MAX_NUM];
	int length = 0;
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++)
	{
		a[i] = str1[str1.size() - i - 1] - '0';
	}
	for (int i = 0; i < str2.size(); i++)
	{
		b[i] = str2[str2.size() - i - 1] - '0';
	}

	int pos;
	for (int i = 0; i < str2.size(); i++)
	{
		pos = i;
		int cnt = 0;
		for (int j = 0; j < str1.size(); j++)
		{
			cnt = a[j] * b[i] + cnt + answer[pos];
			answer[pos] = cnt % 10;
			cnt = cnt / 10;
			pos++;
		}
		if (cnt != 0)
		{
			answer[pos] = cnt;
			pos++;
		}
	}

	//0*10会有00
	for (int i = pos - 1; i > 0; i--)
	{
		if (answer[i] == 0)
			pos--;
		else
			break;
	}

	for (int i = pos - 1; i >= 0; i--)
	{
		cout << answer[i];
	}
}


vector<int> high_accuracy_div(vector<int>& A, int b, int& r)
{
	vector<int> C;
	int r;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r = r % b;
	}

	reverse(C.begin(), C.end());
	while (C.size() > 0 && C.back() == 0)
		C.pop_back();
	return C;
}


void two_dim_pre_sum(int p[][MAX_NUM], int n, int m, int sum[][MAX_NUM])
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + p[i][j];
}


int calculate_submatrix(int sum[][MAX_NUM], int x1, int x2, int y1, int y2)
{
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}


void one_dim_diff(int p[], int n, int diff[])
{
	for (int i = 1; i <= n; i++)
	{
		diff[i] = p[i] - p[i - 1];
	}
}


void one_dim_diff_plus(int diff[], int n, int l, int r, int c)
{
	diff[l] += c;
	diff[r + 1] -= c;
}


void two_dim_diff_plus(int diff[][MAX_NUM], int x1, int x2, int y1, int y2, int c)
{
	diff[x1][y1] += c;
	diff[x2 + 1][y1] -= c;
	diff[x1][y2 + 1] -= c;
	diff[x2 + 1][y2 + 1] += c;
}


int discretization(vector<int> a, int x)
{
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	int l = 0, r = a.size() - 1;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (x < a[mid])
			r = mid + 1;
		else
			l = mid; 
	}
	return l;
}


void interval_merge(vector<PII>& segs)
{
	vector<PII> regs;
	sort(segs.begin(), segs.end());
	int start = -2e9, end = -2e9;
	for (auto seg : segs)
	{
		if (seg.first <= end)
			end = max(seg.second, end);
		else
		{
			if (start != -2e9)
				regs.push_back({ start,end });
			start = seg.first;
			end = seg.second;
		}
	}
	if (start != -2e9)
		regs.push_back({ start,end });

	segs = regs;
}


void link_list_add(int k, int x, int& head, int e[], int ne[], int& idx)
{
	ne[idx] = ne[k];
	e[idx] = x;
	ne[k] = idx;
	idx++;
}


void link_list_remove(int k, int& head, int e[], int ne[], int& idx)
{
	ne[k] = ne[ne[k]];
}


void monotonic_stack()
{
	int stk[MAX_NUM];
	int tt = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		while (tt && stk[tt] >= x)
			tt--;
		if (tt)
			cout << stk[tt] << " ";
		stk[++tt] = x;
	}
}


void monotonic_queue()
{
	int n, k;
	int a[MAX_NUM];
	int q[MAX_NUM];					//存的是队列中元素的下标
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int hh = -1, tt = 0;
	for (int i = 0; i < n; i++)
	{
		if (tt >= hh && i - k + 1 >= hh)
			hh++;
		while (tt >= hh && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		cout << a[q[hh]] << " ";
	}
}


void KMP(int p[], int s[], int n, int m)
{
	//求next数组
	int next[MAX_NUM];
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && p[j + 1] != p[i])
			j = next[j];
		if (p[j + 1] == p[i])
			j++;
		next[i] = j;
	}

	//匹配过程
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (s[i] != p[j + 1])
			j = next[j];
		if (s[i] == next[j])
			j++;
		if (j == n)
		{
			cout << i - n + 1;
			j = next[j];
		}
	}
}


void Tries_tree_insert(int son[][26], int cnt[], int idx, char str[])
{
	int p = 0;			//从根节点出发
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
			son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;   
}


int query(int son[][26], int cnt[], char str[])
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
			return;
		p = son[p][u];
	}
	return cnt[p];
}


void init_DSU(int p[], int n)
{
	for (int i = 0; i < n; i++)
		p[i] = i;
}


int find_DSU(int p[], int n, int x)
{
	if (x != p[x])
		p[x] = find_DSU(p, n, x);
	else
		return p[x];
}


void merge_DSU(int p[], int n, int a, int b)
{
	p[find_DSU(p, n, a)] = find_DSU(p, n, b);
}


void create_heap(int p[], int n)
{
	for (int i = n / 2; i; i--)						//从最后一个非叶子节点开始down
	{
		down_heap(p, i, n);
	}
}


void down_heap(int p[], int u, int size)
{
	int t = u;
	if (u * 2 <= size && p[u] >= p[u * 2])
		t = u * 2;
	if (u * 2 + 1 <= size && p[u] >= p[u * 2 + 1])
		t = u * 2 + 1;
	if (u != t)
	{
		swap(p[u], p[t]);
		down_heap(p, t, size);
	}
}


void up_heap(int p[], int u, int size)
{
	while (u && p[u / 2] > p[u])
	{
		swap(p[u / 2], p[u]);
		u /= 2;
	}
}


void insert_hash(int x, int head[], int e[], int next[], int& idx)
{
	int k = (x % MAX_NUM + MAX_NUM) % MAX_NUM;
	e[idx] = x;
	next[idx] = head[k];
	head[k] = idx;
	idx++;
}


bool find_hash(int x, int head[], int e[], int next[])
{
	int k = (x % MAX_NUM + MAX_NUM) % MAX_NUM;
	for (int i = head[k]; i != -1; i = next[i])
	{
		if (e[i] == x)
			return true;
	}
	return false;
}


void dfs(int path[], bool visited[], int n, int u)
{
	if (u == n)
		path[u] = n;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			path[u] = i;
			visited[i] = true;
			dfs(path, visited, n, u + 1);
			//回溯
			u--;
			visited[i] = false;
		}
	}
}


void bfs(int n, int next[])
{
	queue<int> q;
	int visited[MAX_NUM];
	visited[1] = 0;

	while (q.size())
	{
		int t = q.front();
		q.pop();

		for (int i = t; i != -1; i = next[i])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}


int dijkstra_graph(int graph[][MAX_NUM], int n)
{
	int distance[MAX_NUM];
	int visited[MAX_NUM];
	memset(distance, INFINITY, sizeof distance);
	memset(visited, false, sizeof visited);
	distance[1] = 0;

	for (int i = 0; i < n; i++)
	{
		//找最短长度
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (visited[j] == false && (t == -1 || distance[t] > distance[j]))
				t = j;
		}
		visited[t] = true;
		//更新长度
		for (int j = 1; j <= n; j++)
			distance[j] = distance[t] + graph[t][j];
	}

	//如果不连通
	if (distance[n] == 0x3f3f3f3f)
		return -1;
	else
		return distance[n];
}


int dijkstra_graph_queue_priority(int graph[][MAX_NUM], int n)
{
	int distance[MAX_NUM];
	int visited[MAX_NUM];
	memset(distance, INFINITY, sizeof distance);
	memset(visited, false, sizeof visited);
	distance[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;				//第一个元素是路径长度，第二个元素是下标
	heap.push({ 0, 1 });

	while (heap.size())
	{
		//找最短长度
		auto now_node = heap.top();
		int ver = now_node.second;
		int dist = now_node.first;
		heap.pop();
		if (visited[ver] == true)
			continue;
		
		visited[ver] = true;
		for (int i = 1; i <= n; i++)
		{
			if (distance[i] > dist + graph[ver][i])
			{
				distance[i] = dist + graph[ver][i];
				heap.push({ distance[i], i });
			}
		}
	}

	if (distance[n] == 0x3f3f3f3f)
		return -1;
	else
		return distance[n];
}


void dijkstra_list_add(int e[], int next[], int head[], int weight[], int x, int y, int length, int& idx)
{
	e[idx] = y;
	weight[idx] = length;
	next[idx] = head[x];
	head[x] = idx;
	idx++;
}


int dijkstra_list_priority_queue(int e[], int next[], int head[], int weight[], int n)
{
	int distance[MAX_NUM];
	int visited[MAX_NUM];
	memset(distance, INFINITY, sizeof distance);
	memset(visited, false, sizeof visited);
	distance[1] = 0;
	priority_queue < PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0, 1 });

	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();
		int ver = t.second;
		int dist = t.first;
		if (visited[ver] == true)
			continue;

		visited[ver] = true;
		for (int i = head[ver]; i != -1; i = next[i])
		{
			if (distance[e[i]] > dist + weight[i])
			{
				distance[e[i]] = dist + weight[i];
				heap.push({ distance[e[i]], e[i] });
			}	
		}
	}

	if (distance[n] == 0x3f3f3f3f)
		return -1;
	else
		return distance[n];
}


int bellman_ford(int k)
{
	struct Edge
	{
		int a, b, w;
	}edges[MAX_NUM];

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
	}
	int distance[MAX_NUM], backup[MAX_NUM];
	memset(distance, INFINITY, sizeof distance);
	memset(backup, INFINITY, sizeof backup);

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			if (distance[b] >= backup[a] + w)
				distance[b] = backup[a] + w;
		}
	}

	if (distance[n] >= 0x3f3f3f3f / 2)
		return -1;
	else
		return distance[n];
}


void spfa_add(int e[], int next[], int head[], int weight[], int x, int y, int length, int& idx)
{
	e[idx] = y;
	weight[idx] = length;
	next[idx] = head[x];
	head[x] = idx;
	idx++;
}


int spfa(int e[], int next[], int head[], int weight[], int n)
{
	int distance[MAX_NUM];
	memset(distance, INFINITY, sizeof distance);
	distance[1] = 0;
	bool visited[MAX_NUM];
	memset(visited, false, sizeof visited);
	visited[1] = true;
	queue<int> heap;
	heap.push(1);

	while (heap.size())
	{
		int t = heap.front();
		heap.pop();
		visited[t] = false;
		for (int i = head[t]; i != -1; i = next[i])
		{
			if (distance[e[i]] > distance[t] + weight[i])
				distance[e[i]] = distance[t] + weight[i];
			if (visited[e[i]] == false)
			{
				heap.push(e[i]);
				visited[e[i]] = true;
			}
		}
	}

	if (distance[n] == 0x3f3f3f3f)
		return -1;
	else
		return distance[n];
}


bool spfa_judge(int e[], int next[], int head[], int weight[], int n)
{
	int distance[MAX_NUM];
	bool visited[MAX_NUM];
	int cnt[MAX_NUM];
	memset(cnt, 0, sizeof cnt);
	memset(distance, INFINITY, sizeof distance);
	memset(visited, false, sizeof visited);
	distance[1] = 0;
	
	queue<int> que;
	for (int i = 0; i < n; i++)
	{
		que.push(i);
		visited[i] = true;
	}

	while (que.size())
	{
		int t = que.front();
		que.pop();
		for (int i = head[t]; i != -1; i = next[i])
		{
			if (distance[e[i]] > distance[t] + weight[i])
			{
				distance[e[i]] = distance[t] + weight[i];
				cnt[e[i]] = cnt[t] + 1;
			}
			if (visited[e[i]] == false)
			{
				que.push(e[i]);
				visited[e[i]] = true;
			}
			if (cnt[e[i]] >= n + 1)
				return true;
		}
	}

	return false;
}


void floyd(int graph[][MAX_NUM], int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
}


int prim(int graph[][MAX_NUM], int n)
{
	int distance[MAX_NUM];
	bool state[MAX_NUM];
	memset(distance, INFINITY, sizeof distance);
	memset(state, false, sizeof state);
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 0; j < n; j++)
		{
			if (state[j] == false && (t == -1 || distance[t] > distance[j]))
				t = j;
		}
		if (i && distance[t] == 0x3f3f3f3f)
			return -1;
		if (i)
			res += distance[t];
		state[t] == true;
		for (int j = 0; j < n; j++)
			distance[j] = min(distance[j], graph[t][j]);
	}
	return res;
}


int kruskal_find(int x, int p[])
{
	if (p[x] != x)
		p[x] = kruskal_find(p[x], p);
	return p[x];
}


int kruskal(Edge edges[], int m, int n)
{
	int p[MAX_NUM];

	sort(edges, edges + m, edges_cmp);
	
	//初始化并查集
	for (int i = 0; i < m; i++)
		p[i] = i;
	
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;
		//判断是否连通
		if (kruskal_find(a, p) != kruskal_find(b, p))
		{
			p[a] = b;
			res += w;
			cnt++;
		}
	}

	if (cnt < n - 1)
		return -1;
	else
		return res;
}


int edges_cmp(Edge e1, Edge e2)
{
	return e1.w < e2.w;
}


bool stain_dfs(int c, int u, int color[], int e[], int next[], int head[])
{
	color[u] = c;

	for (int i = head[u]; i != -1; i = next[i])
	{
		if (color[e[i]] == c)
			return false;
		else
		{
			if (stain_dfs(3 - c, e[i], color, e, next, head) == false)
				return false;
		}
	}

	return true;
}


bool stain(int e[], int next[], int head[], int n)
{
	bool flag = true;
	int color[MAX_NUM];
	memset(color, 0, sizeof color);
	for (int i = 0; i < n; i++)
	{
		if (!color[i])
		{
			if (stain_dfs(1, i, color, e, next, head) == false)
			{
				flag = false;
				break;
			}
		}
	}

	return flag;
}


int hungary()
{
	int res = 0;
	int n1, n2;					//存储两个集合的大小
	bool match[MAX_NUM];		//存储右边集合和左边集合的匹配
	bool visited[MAX_NUM];		//存储第二个集合的点是否已经遍历
	int head[MAX_NUM], e[MAX_NUM], next[MAX_NUM];			//存储左边集合中的点与右边集合的点相连的边


	//初始化。。。。。。


	for (int i = 1; i <= n1; i++)
	{
		memset(visited, false, sizeof visited);
		if (hungary_find(i, visited, head, e, next, match) == true)
			res++;
	}
}


bool hungary_find(int x, bool visited[], int head[], int e[], int next[], bool match[])
{
	for (int i = head[x]; i != -1; i = next[i])
	{
		if (visited[e[i]] == false)
		{
			visited[e[i]] = true;
			if (match[e[i]] == 0 || hungary_find(match[e[i]], visited, head, e, next, match) == true)		//没匹配或者对象有其他女朋友
			{
				match[e[i]] = x;
				return true;
			}
				
		}
	}
	return false;
}


bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}


void divide(int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			int s = 0;
			while (x % i == 0)
			{
				x /= i;
				s++;
			}
			cout << i << " " << s << endl;
		}
	}

	if (x > 1)
		cout << x << " " << 1 << endl;
}


void get_primes_egypt(int x, vector<int> primes)
{
	bool deleted[MAX_NUM];
	for (int i = 2; i <= x; i++)
	{
		if (deleted[i] == false)
		{
			primes.push_back(i);
			for (int j = i + i; j <= x; j += i)
				deleted[j] = true;
		}
	}
}


vector<int> get_primes_linear(int x)
{
	vector<int> primes;
	bool visited[MAX_NUM];
	for (int i = 2; i <= x; i++)
	{
		if (visited[i] == false)
			primes.push_back(i);
		for (int j = 0; primes[j] <= x / i; j++)
		{
			visited[primes[j] * i] == true;
			if (i % primes[j] == 0)
				break;
		}
	}
	return primes;
}


vector<int> get_divisor(int x)
{
	vector<int> ans;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			ans.push_back(i);
			if (i != x / i)
				ans.push_back(x / i);
		}
	}
	return ans;
}


int get_divisor_num(int x)
{
	int ans = 1;
	unordered_map<int, int> primes;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			while (x % i == 0)
			{
				primes[i]++;
				x /= i;
			}
		}
	}
	if (x > 1)
		primes[x]++;

	for (auto prime : primes)
		ans = ans * (prime.second + 1);
	return ans;
}


long long get_divisor_sum(int x)
{
	long long sum = 1;
	for (int i = 2; i <= x / i; i++)
	{
		int cnt = 0;
		int t = 0;
		while (x % i == 0)
		{
			x /= i;
			cnt++;
		}
		for (int j = 0; j <= cnt; j++)
			t += pow(i, j);
		sum *= t;
	}
	return sum;
}


int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


void ola(int x)
{
	long long ans = x;
	vector<int> primes;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			while (x % i == 0)
				x /= i;
			primes.push_back(i);
		}
	}
	if (x > 1)
		primes.push_back(x);

	for (int i = 0; i < primes.size(); i++)
		ans *= (1 - 1.0 / primes[i]);
	cout << ans << endl;
}


long long ola_sum(int x)
{
	bool visited[MAX_NUM];
	long long phi[MAX_NUM];
	vector<int> primes;
	phi[1] = 1;
	for (int i = 2; i <= x; i++)
	{
		if (visited[i] == false)
		{
			phi[i] = i - 1;
			primes.push_back(i);
		}
		for (int j = 0; primes[j] <= x / i; j++)
		{
			visited[primes[j] * i] = true;
			if (i % primes[j] == 0)
			{
				phi[primes[j] * i] = phi[i] * primes[j];
				break;
			}
			phi[primes[j] * i] = phi[i] * (primes[j] - 1);
		}
	}

	long long ans = 0;
	for (int i = 1; i <= x; i++)
		ans += phi[i];
	return ans;
}


int quick_power(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1)
			res = res * a % p;
		k = k >> 1;
		a = a * a % p;
	}
	return res;
}


int inverse_element(int a, int p)
{
	if (a % p == 0)
		return -1;
	else
		return quick_power(a, p - 2, p);
}


int exgcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y = y - a / b * x;
	return d;
}


int gauss(double a[][MAX_NUM], int n)
{
	double eps = 1e-6;
	int c, r;
	for (c = 0, r = 0; c < n; c++)
	{
		int t = r;
		for (int i = r; i < n; i++)
			if (fabs(a[i][c]) > fabs(a[t][c]))
				t = i;
		if (fabs(a[t][c]) < eps)
			continue;
		for (int i = c; i <= n; i++)
			swap(a[t][i], a[r][i]);

		for (int i = n; i >= c; i--)
			a[r][i] /= a[r][c];

		for (int i = r + 1; i < n; i++)
		{
			if (fabs(a[i][c]) > eps)
				for (int j = n; j >= c; j--)
					a[i][j] -= a[i][c] * a[r][j];
		}

		r++;
	}

	if (r < n)
	{
		for (int i = r; i < n; i++)
			if (fabs(a[i][n]) > eps)
				return -1;
		return 0;
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
			a[i][n] -= a[i][j] * a[j][n];
	}
	return 1;
}


void combination(int N)
{
	int c[MAX_NUM][MAX_NUM];
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
		}
}
