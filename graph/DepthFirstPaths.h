/*
 * DepthFirstPaths.h
 *
 * The DepthFirstPaths class represents a data type for finding
 * paths from a source vertex s to every other vertex in an
 * undirected graph
 *
 * This implementation uses dfs. The constructor takes time
 * O(V + E) and uses extra space O(V).
 *
 *  Created on: Jul 4, 2015
 *      Author: hiepnm
 */

#ifndef DEPTHFIRSTPATHS_H_
#define DEPTHFIRSTPATHS_H_

#include "Graph.h"
#include <vector>
class DepthFirstPath {
public:
	DepthFirstPath(Graph const& G, int s);	// Computes a path between s and every other vertex in graph
	bool hasPathTo(int v);					// Is there a path between the source s and vertex v
	std::vector<int> pathTo(int v);			// Returns a path between s and v

private:
	bool *marked;	// marked[v] = is there an s-v path?
	int *edgeTo;	// edgeTo[v] = last edge on s-v path
	int s;			// source vertex

	void dfs(Graph const& G, int v);		// depth first search from v
};

#endif /* DEPTHFIRSTPATHS_H_ */
