/*
 * DepthFirstPath.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: hiepnm
 */


#include <cstddef>
#include "DepthFirstPaths.h"

DepthFirstPath::DepthFirstPath(Graph const& G, int s) {
	this->s = s;
	edgeTo = new int[G.V()];
	marked = new bool[G.V()];
	dfs(G, s);
}

void DepthFirstPath::dfs(Graph const& G, int v) {
	marked[v] = true;
	for (std::vector<int>::iterator it; it != G.Adj(v).end(); it++) {
		int w = *it;
		if (!marked[w]) {
			edgeTo[w] = v;
			dfs(G, w);
		}
	}
}

bool DepthFirstPath::hasPathTo(int v) {
	return marked[v];
}

std::vector<int> DepthFirstPath::pathTo(int v) {
	if (!hasPathTo(v)) {
		return NULL;
	}
	std::vector<int> vertices;
	for (int x = v; x != s; x = edgeTo[x]) {
		vertices.push_back(x);
	}
	vertices.push_back(s);
	return vertices;
}
