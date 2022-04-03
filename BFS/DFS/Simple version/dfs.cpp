#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void DFS(vector<vector<int>>& graph, int& start);
void DFS_visit(vector<vector<int>>& graph, vector<int>& visited, int& vertex);

void DFS(vector<vector<int>>& graph, int& start)
{
  vector<int> visited(graph.size());
  DFS_visit(graph, visited, start);
  return;
}

void DFS_visit(vector<vector<int>>& graph, vector<int>& visited, int& vertex)
{
  visited[vertex] = true;
  cout << vertex << " ";
  for(auto it = graph[vertex].begin(); it != graph[vertex].end(); it++)
  {
    if(!visited[*it])
    {
      DFS_visit(graph, visited, *it);
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
  DFS(graph, A);

  return 0;
}