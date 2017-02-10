#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct node{
    string what;
    node* next;
    node(string s) {
        what = s;
        next = NULL;
    }
};

struct adjList{
    struct node* head; 
    struct node* tail;
};
struct graph{
    struct adjList* adj;
    int V;
    int now_on;
};

struct graph* makeGraph(int V){
    struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
    graph->V = V;
    graph->now_on = 0;
    graph->adj = (struct adjList*) malloc(V * sizeof(struct adjList));
 
    int i;
    for (i = 0; i < V; ++i)
        graph->adj[i].head = NULL;
        graph->adj[i].tail = NULL;
    return graph;
}
void addNode(graph* graph, node* x){
    graph->adj[graph->now_on].head = x;
    graph->adj[graph->now_on].tail = x;
    graph->now_on++;
}

void addNode(graph* graph, string s){
    node* x = new node(s);
    graph->adj[graph->now_on].head = x;
    graph->adj[graph->now_on].tail = x;
    graph->now_on++;
}

void addEdge(struct graph* graph, node* x, node* child){
    
    for(int i = 0; i < graph->V;i++)
    if(graph->adj[i].head->what == x->what){
        graph->adj[i].tail->next = child;
        graph->adj[i].tail = child;
        break;
    }else{
        //cout << graph->adj[i].head->what << endl;
    }
}

