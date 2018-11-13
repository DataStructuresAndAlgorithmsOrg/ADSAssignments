#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Edge
{
	public:
		int source;
		int destination;
		int weight;
};

bool compare (Edge edge1, Edge edge2)
{
	return (edge1.weight < edge2.weight);
}

int findParent (int vertex, int *parent)
{
	if (vertex == parent[vertex])
	{
		return vertex;
	}
	else
	{
		return findParent(parent[vertex], parent);
	}
}

void kruskalsAlgorithm(Edge* input, int numberOfVertices, int numberOfEdges)
{
	sort(input, input+numberOfEdges, compare);

	Edge *output = new Edge[numberOfVertices-1];

	int *parent = new int[numberOfVertices];
	for (int i=0; i<numberOfVertices; i++)
	{
		parent[i]=i;
	}

	int count = 0;
	int i = 0;
	while (count != numberOfVertices-1)
	{
		Edge currentEdge = input[i];
		//Check whether we can add the current edge in MST or not
		int sourceParent = findParent(currentEdge.source, parent);
		int destinationParent = findParent(currentEdge.destination, parent);

		if (sourceParent != destinationParent)
		{
			output[count]=currentEdge;
			count++;
			parent[sourceParent]=destinationParent;
		}
		i++;
	}

	cout << "Minimum Spanning Tree is: \n";
	for (int i=0;i<numberOfVertices-1;i++)
	{
		if (output[i].source < output[i].destination)
			cout << output[i].source << " " <<output[i].destination << " " << output[i].weight << "\n";
		else
			cout << output[i].destination << " " <<output[i].source << " " << output[i].weight << "\n";
	}

};

int main ()
{
	cout << "This is an implementation of Kruskals algorithm for finding the minimum spanning tree\n";

	int numberOfEdges;
	int numberOfVertices;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of edges: ";
	cin >> numberOfEdges;

	Edge* input = new Edge[numberOfEdges];
	cout << "Enter details of the " << numberOfEdges << " edges, in the format as mentioned below\n";
	cout << "Source vertex" << " : " << "Destination vertex" << " : " << "Weight of the edge\n";
	for (int i=0;i<numberOfEdges;i++)
	{
		cin >> input[i].source >> input[i].destination >> input[i].weight;
	}

	kruskalsAlgorithm(input, numberOfVertices, numberOfEdges);

	return 0;
}