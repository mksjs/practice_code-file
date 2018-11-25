#include <stdio.h> 
#include <limits.h> 
#include<stdbool.h> 
// Number of vertices in the graph 
int V;
  
// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++) 
    		if (mstSet[v] == false && key[v] < min) 
        		min = key[v], min_index = v;
	return min_index; 
} 
  
// A utility function to print the constructed MST stored in parent[] 
int printMST(int parent[], int n, int graph[V][V]) 
{ 
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < V; i++) 
    		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  
// Function to construct and print MST for a graph represented using adjacency matrix representation 
void primMST(int graph[V][V]) 
{ 
	int parent[V];  //array to store constructed MST
    	int key[V];  // Key values used to pick minimum weight edge in cut 
    	bool mstSet[V];  //to remove set of vertices not yet included in MST
  	// Initialize all keys as INFINITE 
    	for (int i = 0; i < V; i++) 
        	key[i] = INT_MAX, mstSet[i] = false; 
  
    	// Always include first 1st vertex in MST. 
    	// Make key 0 so that this vertex is picked as first vertex. 
    	key[0] = 0;      
    	parent[0] = -1; // First node is always root of MST  
  
    	// The MST will have V vertices 
    	for (int count = 0; count < V-1; count++) 
    	{ 
        // Pick the minimum key vertex from the set of vertices not yet included in MST 
        	int u = minKey(key, mstSet);
		mstSet[u] = true; 
        	for (int v = 0; v < V; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
		    		parent[v] = u, key[v] = graph[u][v]; 
	} 
    	printMST(parent, V, graph); 
} 
  
  
// driver program to test above function 
int main() 
{ 
	int i,j;
	printf("\nEnter number of Vertises : ");
	scanf("%d", &V);
	int graph[V][V];
  	printf("\nEnter the weight : \n");
	for(i=0;i<V;i++)
	  for(j=0;j<V;j++)
	  	scanf("%d", &graph[i][j]);	  
   	primMST(graph); 
  
    return 0; 
}
