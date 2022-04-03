#include <fstream>
#include <iostream>
#include <list>
#include <iomanip>
#include <vector>
using namespace std;

class Graph
{
  private:
    int num_vertex;
    vector<list<int>> AdjList;
    vector<int>color, // 0:white, 1:gray, 2:black
              predecessor, // -1: No pred means it is start point
              discover,
              finish;
  public:
    Graph():num_vertex(0){};
    Graph(int n):num_vertex(n)
    {
      AdjList.resize(num_vertex);
      color.resize(n,0);
      predecessor.resize(n,-1);
      discover.resize(n,0);
      finish.resize(n,0);
    };
    Graph(string const& filename);
    void AddEdgeList(int from, int to);
    void DFS(int start);
    void DFS_Visit(int vertex, int &time);
};

Graph::Graph (string const& filename)
{
  ifstream fin(filename);
  int n, m;
  fin >> n >> m;
  num_vertex = n;
  AdjList.resize(n);
  color.resize(n,0);
  predecessor.resize(n,-1);
  discover.resize(n,0);
  finish.resize(n,0);

  for (int i = 0, from, to; i != m; ++i)
  {
    fin >> from >> to;
    AddEdgeList(from, to); // directed
    //AddEdgeList(to, from);
  }
}

void Graph::AddEdgeList(int from, int to)
{
  AdjList[from].push_back(to);
}

void Graph::DFS(int start)
{
  int time = 0;
  int i = start;
  for(int j = 0; j < num_vertex; ++j)
  {
    if(color[i] == 0)
    {
      DFS_Visit(i, time);
    }
    i = j; // if one loop can't traverse all vertices, it means many components in this graph.
  }
  cout << endl;
  cout << "predecessor:" << endl;         // 印出 A(0) ~ H(7)的predecessor
  for (int i = 0; i < num_vertex; i++){
    cout << setw(4) << i;
  }
  cout << endl;
  for (int i = 0; i < num_vertex; i++){
    cout << setw(4) << predecessor[i];
  }
  cout << "\ndiscover time:" << endl;  // 印出 A(0) ~ H(7)的discover time
  for (int i = 0; i < num_vertex; i++){
    cout << setw(4) << i;
  }
  cout << endl;
  for (int i = 0; i < num_vertex; i++){
    cout << setw(4) << discover[i];
  }
  cout << "\nfinish time:" << endl;    // 印出 A(0) ~ H(7)的finish time
  for (int i = 0; i < num_vertex; i++){
    cout << setw(4) << i;
  }
  cout << endl;
  for (int i = 0; i < num_vertex; i++){
    cout << setw(4) << finish[i];
  }

}

void Graph::DFS_Visit(int vertex, int& time)
{
  color[vertex] = 1;
  cout << vertex << " ";
  discover[vertex] = ++time;
  for(auto it = AdjList[vertex].begin(); it != AdjList[vertex].end(); it++)
  {
    if(color[*it] == 0)
    {
      predecessor[*it] = vertex;
      DFS_Visit(*it, time);
    }
  }
  color[vertex] = 2;
  finish[vertex] = ++time;
}

int main()
{
  Graph graph("graph.txt");
  graph.DFS(0);
  return 0;
}