#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& graph, int start)
{
  int i = start;
  queue<int> q;
  q.push(i);
  vector<bool> visited(graph.size());
  while(!q.empty())
  {
    int u = q.front();q.pop();
    if(!visited[u])
    {
      visited[u] = true;
      cout << u << " ";
    }
    for(auto it = graph[u].begin(); it != graph[u].end(); it++)
    {
      if(!visited[*it])
      {
        q.push(*it);
        visited[*it] = true;
        cout << *it << " ";
      }
    }
  }
  return;
}

int main()
{
  ifstream fin("graph.txt");
  int n, m;
  fin >> n >> m;

  vector<vector<int>> graph(n); // AdjList
  while (m--)
  {
    int x, y;
    fin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  int A = 0;
  BFS(graph, A);

  return 0;
}