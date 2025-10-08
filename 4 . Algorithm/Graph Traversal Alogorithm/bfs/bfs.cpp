#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// matrix declration a[node][edge]

  // then connection

  /*input exaple
    5 5  // node number, edge number
    0 1
    0 2
    3 0
    1 3
    3 4
  */

  

void print_matrix(int a[5][5], int node, int edge)
{
  for (int i = 0; i < node; i++)
  {
    for (int j = 0; j < node; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

void graph_input_adjaceny_matrix_undirected()
{

  int node_number;
  int edge_number;
  cin >> node_number >> edge_number;

  
  int adj_matrix[5][5];
  // vector< vector<int> > adj_matrix;
  // initally all value are zero
  memset(adj_matrix, 0, sizeof(adj_matrix));

  // diagonal value also need to be same 2,2 , 3,3 bcz 2 to 2 psbl
  while (edge_number--)
  {
    int a, b;
    cin >> a >> b;
    adj_matrix[a][b] = 1;
    adj_matrix[b][a] = 1;
  }

  // make the corner value 1 as well
  for (int i = 0; i < node_number; i++)
  {
    for (int j = 0; j < node_number; j++)
    {
      if (i == j)
        adj_matrix[i][j] = 1;
    }
  }
}

// using adjaceny list

vector<vector<int>> graph_input_adjaceny_list_undirected()
{

  int node_number;
  int edge_number;
  cin >> node_number >> edge_number;

  // vector<int> adj_list[5]; // array of vector 

  vector< vector<int> > adj_list(node_number); // or vector of vector 

  // initally all value are zero
  // memset(adj_list, 0, sizeof(adj_list));

  // diagonal value also need to be same 2,2 , 3,3 bcz 2 to 2 psbl
  while (edge_number--)
  {
    int a, b;
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  // print list

  // for (int i = 0; i < node_number; i++)
  // {
  //   for (int x : adj_list[i])
  //   {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }

  return adj_list;
}

// edge list - simple list

void graph_input_edge_list_undirected()
{
  int node_number;
  int edge_number;
  cin >> node_number >> edge_number;

  vector<pair<int, int>> edge_list; // array of vector

  // initally all value are zero
  // memset(adj_list, 0, sizeof(adj_list));

  // diagonal value also need to be same 2,2 , 3,3 bcz 2 to 2 psbl
  while (edge_number--)
  {
    int a, b;
    cin >> a >> b;
    edge_list.push_back({a, b});
  }

  // print list

  for (auto p : edge_list)
  {
    cout << p.first << " " << p.second << " " << endl;
  }
}

void bfs(int src)
{
  // visited tracking array
  
  bool visited[1001];
  memset(visited,false,sizeof(visited));

  vector<vector<int>> adj_list = graph_input_adjaceny_list_undirected();

  // bfs apply

  queue<int> q;
  q.push(src);
  visited[src] = true;
 
  while (!q.empty())
  {

    // ber kore ana
    int par = q.front();
    q.pop();

    // oi node ke niye kaj
    cout << par << " ";

    // children gula push
    for (auto child : adj_list[par])
    {
      if (!visited[child])
      {
        q.push(child);
        visited[child] = true;
      }
    }
  }

  // // print list
  // for (int i = 0; i < adj_list.size(); i++)
  // {
  //   cout << i << " : ";
  //   for (int x : adj_list[i])
  //   {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }
}

int main()
{
  // graph_input_adjaceny_matrix_undirected();
  // graph_input_adjaceny_list_undirected();
  // graph_input_edge_list_undirected();
  bfs(0);
}