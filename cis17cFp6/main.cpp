/* 
Problem 6 - Weighted Graph
In the vertex and edge structure defined below
Vertex	    Edge	Vertex
SFO	    2702	BOS
SFO	    1846	ORD
ORD	     867	BOS
ORD	     742	JFK
JFK	     189	BOS
SFO	    1464	DFW
DFW	     802	ORD
DFW	    1123	MIA
MIA	    1092	JFK
MIA	    1258	BOS
SFO	     339	LAX
LAX	    1235	DFW
LAX	    2342	MIA



a)  Find the shortest distance between
ORD and LAX.
use dijkstra

b)  Find the shortest distance between
JFK and SFO.
use dijkstra

c)  Find the minimum spanning tree.
use kruskal
Show by hand analysis, then code to determine and compare results.
 
Let us create the example graph discussed above 
SFO = 0  4 connections  
ORD = 1  4
JFK = 2  3
DFW = 3  4
MIA = 4  4
LAX = 5  3
BOS = 6  4
     
SFO	    2702	BOS
SFO	    1846	ORD
ORD	     867	BOS
ORD	     742	JFK
JFK	     189	BOS
SFO	    1464	DFW
DFW	     802	ORD
DFW	    1123	MIA
MIA	    1092	JFK
MIA	    1258	BOS
SFO	     339	LAX
LAX	    1235	DFW
LAX	    2342	MIA
 */

// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

const int vert = 7;

map<int, string> cities{
    {0, "SFO"},
    {1, "ORD"},
    {2, "JFK"},
    {3, "DFW"},
    {4, "MIA"},
    {5, "LAX"},
    {6, "BOS"}};

int minDistance(int dist[], bool sptSet[]);
void dijkstra(int graph[vert][vert], int src, int dist[vert]);
void primMinSpanTree(int graph[vert][vert]);
void printMinSpanTree(int parent[], int graph[vert][vert]);
int minKey(int key[], bool mstSet[]);

int main(int argc, char** argv) {

    int graph[vert][vert] = {
        { 0, 1846, 0, 1464, 0, 339, 2702},
        { 1846, 0, 742, 802, 0, 0, 867},
        { 0, 742, 0, 0, 1092, 0, 189},
        { 1464, 802, 0, 0, 1123, 1235, 0},
        { 0, 0, 1092, 1123, 0, 2342, 1258},
        { 339, 0, 0, 1235, 2342, 0, 0},
        { 2702, 867, 189, 0, 1258, 0, 0},
    };
    int dist[vert];

    cout << "The shortest distance from ORD to LAX is: ";
    dijkstra(graph, 1, dist);
    cout << dist[5] << endl;

    cout << "The shortest distance from JFK to SFO is: ";
    dijkstra(graph, 2, dist);
    cout << dist[0] << endl << endl;

    //the minimum spanning tree
    cout << "The minimum spanning tree: " << endl;
    primMinSpanTree(graph);

    return 0;
}

void dijkstra(int graph[vert][vert], int src, int dist[vert]) {
    bool sptSet[vert];

    for (int i = 0; i < vert; i++) {
        dist[i] = 1e9, sptSet[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < vert - 1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int j = 0; j < vert; j++) {
            if (!sptSet[j] && graph[u][j] && dist[u] != 1e9 && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
}

int minDistance(int dist[], bool sptSet[]) {
    int min = 1e9, min_index;

    for (int i = 0; i < vert; i++) {
        if (sptSet[i] == false && dist[i] <= min) {
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

int minKey(int key[], bool mstSet[]) {
    int min = 1e9, min_index;

    for (int i = 0; i < vert; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}

void printMinSpanTree(int parent[], int graph[vert][vert]) {
    cout << "Edge\t\tWeight\n";
    for (int i = 1; i < vert; i++) {
        cout << cities[parent[i]] << " - " << cities[i] << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMinSpanTree(int graph[vert][vert]) {
    int parent[vert];
    int key[vert];
    bool mstSet[vert];

    for (int i = 0; i < vert; i++)
        key[i] = 1e9, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < vert - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int j = 0; j < vert; j++)

            if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j]) {
                parent[j] = u, key[j] = graph[u][j];
            }
    }
    printMinSpanTree(parent, graph);
}
