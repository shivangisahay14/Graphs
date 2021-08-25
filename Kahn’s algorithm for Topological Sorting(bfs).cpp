Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then. 
 

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighbouring nodes.
If in-degree of a neighbouring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty.
Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
How to find in-degree of each node? 
There are 2 ways to calculate in-degree of every vertex: 
 
i.)Take an in-degree array which will keep track of 
Traverse the array of edges and simply increase the counter of the destination node by 1. 
  for each node in Nodes
    indegree[node] = 0;
for each edge(src, dest) in Edges
    indegree[dest]++
Time Complexity: O(V+E)
ii.)Traverse the list for every node and then increment the in-degree of all the nodes connected to it by 1. 
 
    for each node in Nodes
        If (list[node].size()!=0) then
        for each dest in list
            indegree[dest]++;


#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   int x, y, e,v;
   cin >> v >> e; // Number of vertices and edges
   vector <int> AdjList[v]; // Step 1: Initializing AdjList
   vector<int> indegree(v, 0); // Step 1: Initializing indegrees to 0
   queue <int> q;
 
   int visited_nodes = 0; // Step 1: Visited nodes initialized to 0
 
   for(int i=0; i < e; i++)
   {
       cin >> x >> y;
       indegree[y]++; // Incrementing indegree
       AdjList[x].push_back(y); // Add the edge x -> y to adjacency list
   }
 
   for(int i = 0; i < v; i++)
       if(indegree[i]==0) q.push(i); // Step 2: Add all indegree 0 nodes to queue
 
   while(!q.empty()) // Step 3: Remove vertex from queue
   {
       visited_nodes++; // Step 3.1 Incrementing count of visited nodes
       for(auto x: AdjList[q.front()])
       {
           indegree[x]--; // Step 3.2 Reduce indegree of adjacent node
           if(indegree[x]==0) q.push(x); // Step 3.3 Push adjacent node with indegree 0
       }
 
       cout << q.front()<<" ";
       q.pop();
      
   } // Step 4: Repeat until queue is empty
 
   if(visited_nodes != v) // Step 5: if visited nodes are not equal to number of vertices, cycle exists
       cout<<"\nCycle exists, cannot do further topological sort"; 
}

