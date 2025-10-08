#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* problem description
find single souce shotest distance and their path 


*/
/*
  Explanaation :
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

// using adjaceny list
vector<vector<int>> graph_input_adjaceny_list_undirected()
{
    int node_number;
    int edge_number;
    cin >> node_number >> edge_number;

    // vector<int> adj_list[5]; // array of vector

    vector<vector<int>> adj_list(node_number); // or vector of vector

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

    return adj_list;
}

// edge list - simple list
/*
set levels
1) decleare an array called parent to track parents
2) set initial value -1 for every parent 


*/

bool visited[1001];
int level[1001];
int parents[1001];

void bfs(int src)
{
    memset(visited, false, sizeof(visited));

    // set level
    memset(level, -1, sizeof(level));

    // set parent -1 for all first

    memset(parents,-1,sizeof(parents));

    vector<vector<int>> adj_list = graph_input_adjaceny_list_undirected();

    // bfs apply
    queue<int> q;

    q.push(src);

    level[src] = 0;

    visited[src] = true;

    while (!q.empty())
    {
        // ber kore ana
        int par = q.front();
        q.pop();

        // oi node ke niye kaj
        // cout << par << " ";

        // children gula push
        for (auto child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);

                visited[child] = true;

                // for tracking level
                level[child] = level[par] + 1;

                //for tracking parents 

                parents[child] = par;
            }
        }
    }
}
// problem 1 :

int main()
{
    // graph_input_adjaceny_matrix_undirected();
    // graph_input_adjaceny_list_undirected();
    // graph_input_edge_list_undirected();

    int src, dest;

    cin >> src >> dest;

    bfs(src);


    

    // printing level of every node
    // for (int i = 0; i < 7; i++)
    // {
    //     cout << "I" << "  " << i << " : "<< level[i] << " "<< endl;
    // }

    // printing parents of node

    // for(int i=0; i<7;i++){
    //     cout << " i = " << i <<" = ";
    //     cout << parents[i] <<" " <<endl;
    // }


    // printing parents 
    vector<int> path;
    int node = dest;

    while(node != -1){
        // cout << node <<" ";
        path.push_back(node);
        node = parents[node];
    }

    // print 
    reverse(path.begin(),path.end());

    for(auto val : path){
        cout << val<<" ";
    }
}