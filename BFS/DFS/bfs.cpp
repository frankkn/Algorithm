#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
  private:
    int num_vertex;
    vector<list<int>> AdjList;
    vector<int>color, // 0:white, 1:gray, 2:black
              distance, // 0:start, INT_MAX:can't reach from start point
              predecessor; // -1: No pred means it is start point
  public:
    Graph():num_vertex(0){};
    Graph(int n):num_vertex(n)
    {
      AdjList.resize(num_vertex);
      color.resize(n,0);
      distance.resize(n,num_vertex+1);
      predecessor.resize(n,-1);
    };
    Graph(string const& filename);
    void AddEdgeList(int from, int to);
    void BFS(int start);
};

Graph::Graph (string const& filename)
{
  ifstream fin(filename);
  int n, m;
  fin >> n >> m;

  num_vertex = n;
  AdjList.resize(n);
  color.resize(n,0);
  distance.resize(n,num_vertex+1);
  predecessor.resize(n,-1);

  for (int i = 0, from, to; i != m; ++i)
  {
    fin >> from >> to;
    AddEdgeList(from, to);
    //AddEdgeList(to, from);
  }
}

void Graph::AddEdgeList(int from, int to)
{
  AdjList[from].push_back(to);
}

void Graph::BFS(int start)
{
  queue<int> q;
  int i = start;

  for (int j = 0; j < num_vertex; j++)
  {
    if(color[i] == 0)
    {
      color[i] = 1;
      cout << i << " ";
      distance[i] = 0;
      predecessor[i] = -1;
      q.push(i);
      while(!q.empty())
      {
        int u = q.front();
        for(auto it = AdjList[u].begin(); it!= AdjList[u].end(); it++)
        {
          if(color[*it] == 0)
          {
            color[*it] = 1;
            cout << *it << " ";
            distance[*it] = distance[u] +1;
            predecessor[*it] = u;
            q.push(*it);
          }
        }
        q.pop();
        color[u] = 2;
      }
    }
    i = j; // If one loop can't traverse all vertices, it means several components in this graph.
  }
}

int main()
{
  Graph graph("graph.txt");
  graph.BFS(0);
  return 0;
}