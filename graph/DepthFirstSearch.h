/*
 * DepthFirstSearch.h
 *
 * The DepthFirstSearch class represents a data type for determining
 * the vertices connected to a given source vertex s in an undirected
 * graph.
 * For versions that find the paths, see DepthFirstPath and BreadFirstPaths
 * The contruction take time O(V+E) and space O(V)
 *
 *  Created on: Jul 4, 2015
 *      Author: hiepnm
 */

#ifndef DEPTHFIRSTSEARCH_H_
#define DEPTHFIRSTSEARCH_H_
class DepthFirstSearch {
public:
	DepthFirstSearch(Graph const&, int );	//find vertices connected to a source vertex s
	bool marked(int v);						// is v connected to s?
	int count();							// how many vertices are connected to s?
private:
	bool *marked;	// marked[v] = is there an s-v path?
	int count;		// number of vertices connected to s

	void dfs(Graph const&, int);

};

#endif /* DEPTHFIRSTSEARCH_H_ */
