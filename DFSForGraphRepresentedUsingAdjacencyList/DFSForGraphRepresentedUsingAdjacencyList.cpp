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

    cout << "This is Depth first search traversal of a graph represented in adjacency list form\n";
    cout << "Enter number of vertices in the graph\n";
    int numberOfVertices;
    cin >> numberOfVertices;
	Graph graph(numberOfVertices);

    cout << "Enter number of edges\n";
    int numberOfEdges;
    cin >> numberOfEdges;
    
    cout <<"Enter nodes between which there are edges\n";
    int node1, node2;
    for(int i=0; i<numberOfEdges; i++)
    {
        cin >>node1>>node2;
        graph.addEdge(node1,node2);
    }

    cout << "Enter the vertex for which DFS has to be perfomed\n";
    int vertexForDFS;
    cin >> vertexForDFS;
	graph.DFS(vertexForDFS);

	return 0;
}