/*
 * Graph.h
 *
 *  Created on: Jul 4, 2015
 *      Author: hiepnm
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include <exception>
class Graph {
public:
	Graph(int V);				// initializes an empty graph with V vertices and 0 edges
	Graph(const Graph&);		// Initializes a new graph that is deep copy of G
	const int V() const;					// return number of vertices
	const int E() const;					// return number of edges
	void addEdge(int v, int w);	// add the undirected edge v-w
	const std::vector<int> Adj(int v) const;// return the vertices adjacent to vertex v
	int degree(int v);			// return the degree of vertex

private:
	int v;
	int e;
	std::vector<int>* adj;

	void validateVertex(int v);	//throw an IndexOutOfBoundException unless 0 <= v < V

};

#endif /* GRAPH_H_ */
