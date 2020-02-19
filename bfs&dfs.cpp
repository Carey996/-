#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<int> bfs_search(int head, vector<int> graph1, int m, int n) {
	queue<int> index;
	vector<int> searched;
	index.push(head);
	while (!index.empty()) {
		int front = index.front();
		searched.push_back(front);
		index.pop();
		if (front + 1 < graph1.size() && graph1[front + 1] == 1) {
			index.push(front + 1);
		}
		if (front + m < graph1.size() && graph1[front + m] == 1) {
			index.push(front + m);
		}
	}
	while (!searched.empty()) {
		int i = searched.back();
		graph1[i] = 0;
		searched.pop_back();
	}
	return graph1;
}

void dfs(int head,vector<int>graph1,int m,int n,vector<int>& searched) {
	stack<int> index;
	index.push(head);
	while (!index.empty()) {
		if (head + 1 < graph1.size() && graph1[head + 1] == 1)dfs(head + 1, graph1, m, n, searched);
		if (head + m < graph1.size() && graph1[head + m] == 1)dfs(head + m, graph1, m, n, searched);
		searched.push_back(index.top());
		index.pop();
	}
}
vector<int> dfs_search(int head, vector<int> graph1, int m, int n) {
	vector<int> searched = {};
	dfs(head, graph1, m, n, searched);
	while (!searched.empty()) {
		int i = searched.back();
		graph1[i] = 0;
		searched.pop_back();
	}
	return graph1;
}


int main() {
	vector<vector<int>> graph = {
		{0,1,0,1,1},
		{0,1,1,0,0},
		{1,0,0,1,0},
		{1,1,1,0,0},
		{1,0,1,0,0}
	};
	int m = 5, n = 5;
	vector<int> graph1 = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			graph1.push_back(graph[i][j]);
		}
	}
	vector<int> graph2 = graph1;
	int count_bfs = 0;
	int ans_bfs = 0;
	while (count_bfs < m * n) {
		if (graph1[count_bfs] == 0) {
			count_bfs++;
		}
		else if (graph1[count_bfs] == 1) {
			graph1 = bfs_search(count_bfs, graph1, m, n);
			count_bfs = 0;
			ans_bfs++;
		}
	}
	cout << "bfs:" << ans_bfs << endl;
	int count_dfs = 0;
	int ans_dfs = 0;
	while (count_dfs < m * n) {
		if (graph2[count_dfs] == 1) {
			graph2 = dfs_search(count_dfs, graph2, m, n);
			count_dfs = 0;
			ans_dfs++;
		}
		count_dfs++;
	}
	cout << "dfs:" << ans_dfs << endl;
	return 0;
}
