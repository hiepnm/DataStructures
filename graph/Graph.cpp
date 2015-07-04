/*
 * Graph.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: hiepnm
 */


#include <exception>
#include <cstdio>
Graph::Graph(int numVertices) {
	if (numVertices < 0) {
		throw new std::exception("Number of vertices must be nonnegative");
	}
	this->v = numVertices;
	this->e = 0;
	this->adj = new std::vector<int>[numVertices];
	for (int vt = 0; vt < numVertices; vt++) {
		adj[vt] = new std::vector<int>;
	}
}
Graph::Graph(const Graph& G):v(G.V()), e(G.E()) {
	this->adj = new std::vector<int>[G.V()];
	for (int vt = 0; vt < G.V(); vt++) {
		this->adj[vt] = new std::vector<int>;
		for (std::vector<int>::iterator it = G.Adj(vt).begin(); it != G.Adj(vt).end(); it++) {
			int w = *it;
			this->adj[vt].push_back(w);
		}
	}
}

void Graph::validateVertex(int v) {
	if (v < 0 || v > this->v) {
		char err[100];
		sprintf(err, "vertex %d is not between 0 and %d", v, this->v - 1);
		throw new std::exception(err);
	}
}
int Graph::V() {
	return this->v;
}

int Graph::E() {
	return this->e;
}

std::vector<int> Graph::Adj(int v) {
	validateVertex(v);
	return adj[v];
}

