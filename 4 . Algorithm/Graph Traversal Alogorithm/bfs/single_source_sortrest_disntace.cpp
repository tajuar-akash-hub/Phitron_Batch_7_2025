#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

/* problem description
find single souce shotest distance
tricks : just check the visited_array, if false ,then no connection
input :
0 1
1 3
3 2
4 6
3 5

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
1) decleare an array called level to keep all the track of levels
2) initially though memset, set -1 to defualt value
3) level of source is 0 - set it manually
4) level of children, is level[child] = level[par] +1


*/

bool visited[1001];
int level[1001];

void bfs(int src)
{
    memset(visited, false, sizeof(visited));

    // set level
    memset(level, -1, sizeof(level));

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
        cout << par << " ";

        // children gula push
        for (auto child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);

                visited[child] = true;

                // for tracking level
                level[child] = level[par] + 1;
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


    cout <<endl;

    // printing level of every node
    for (int i = 0; i < 7; i++)
    {
        cout << "I" << "  " << i << " : "<< level[i] << " "<< endl;
    }

    // find out distance src to dist 

    cout <<" printint destination src to des : " << level[dest] ;
}