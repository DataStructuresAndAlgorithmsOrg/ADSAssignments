#include<iostream>
#include<list>
using namespace std;

class Graph 
{
	int numberOfVertices; 

	// Pointer to an array containing adjacency lists
	list<int> *adjacencyList;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);

	public:
		Graph (int numberOfVertices);

		// Function to add an edge to the graph between vertices v and w
		void addEdge (int v, int w);

		// DFS traversal of the vertices reachable from vertix v
		void DFS(int v);
};

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from vertix v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

Graph::Graph(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    this->adjacencyList = new list<int>[numberOfVertices];
}

void Graph::addEdge(int v, int w)
{
	// Add vertix w to vertex v’s list.
	adjacencyList[v].push_back(w);
}

int main ()
{
	Graph graph(4);


	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(1,2);
	graph.addEdge(2,0);
	graph.addEdge(2,3);
	graph.addEdge(3,3);

	graph.DFS(2);

	return 0;
}