#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> nodes;
set<int> visited;
vector<vector<int>> result;

void findAllPaths(vector<vector<int>>& adj, int Origin, int Destination)
{

    nodes.push_back(Origin);
    visited.insert(Origin);
    
    if(Origin == Destination)
    {
        result.push_back(nodes);
        return;
    }

    else
    {
        for(int v = 0; v < adj[0].size(); v++)
        {
            if(adj[Origin][v] > 0 && visited.find(v) == visited.end())
            {
                findAllPaths(adj, v, Destination);
                nodes.pop_back();
                visited.erase(v);
            }
        }
    }
}

vector<vector<int>> createMatrix(vector<vector<int>>& graph){
    vector<vector<int>> matrix;
    for (int i = 0; i < graph.size(); i++){
        vector<int> temp;
        for (int j = 0; j < graph.size(); j++){
            temp.push_back(0);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i < graph.size(); i++){
        for (int j = 0; j < graph[i].size(); j++){
            int value = graph[i][j];
            matrix[i][value] = 1;
        }
    }
    return matrix;
}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> matrix = createMatrix(graph);
        findAllPaths(matrix,0,graph.size()-1);
        return result;
    }

int main(){

    vector<vector<int>> graph = {{1,2,3},{2},{3},{}};
    vector<vector<int>> matrix = createMatrix(graph);
    findAllPaths(matrix,0,graph.size()-1);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
