#include "rogdf.h"

// [[Rcpp::export]]
IntegerVector rogdf_version() {
  return IntegerVector::create(_["major"] = 2012,
			       _["minor"] = 7,
			       _["patch"] = 0);
}

// [[Rcpp::export("L_circular")]]  
NumericMatrix rogdf_circular_layout(GraphAttributes graph, 
	 double minDistCircle=20, double minDistLevel=20, 
	 double minDistSibling=10, double minDistCC=20, double pageRatio=1) {
  
  CircularLayout layout;
  layout.minDistCircle(minDistCircle);
  layout.minDistLevel(minDistLevel);
  layout.minDistSibling(minDistSibling);
  layout.minDistCC(minDistCC);
  layout.pageRatio(pageRatio);
  layout.call(graph);

  Graph ugraph=graph.constGraph();
  int no_nodes=ugraph.numberOfNodes();
  NumericMatrix coords(no_nodes, 2);
  List<node> nodes;
  ListIterator<node> it;
  int i;
  ugraph.allNodes(nodes);
  for (i=0, it=nodes.begin(); i < no_nodes; i++, it++) {
    coords(i, 0) = graph.x(*it);
    coords(i, 1) = graph.y(*it);
  }
  return coords;
}

// [[Rcpp::export("L_tree")]]
NumericMatrix rogdf_tree_layout(GraphAttributes graph,
	 double siblingDistance=20, double subtreeDistance=20,
	 double levelDistance=50, double treeDistance=50,
	 bool orthogonalLayout=false,
	 Orientation orientation=topToBottom,
	 TreeLayout::RootSelectionType selectRoot=TreeLayout::rootIsSource) {

  TreeLayout layout;
  layout.siblingDistance(siblingDistance);
  layout.subtreeDistance(subtreeDistance);
  layout.levelDistance(levelDistance);
  layout.treeDistance(treeDistance);
  layout.orthogonalLayout(orthogonalLayout);
  layout.orientation(orientation);
  layout.rootSelection(selectRoot);
  layout.call(graph);

  Graph ugraph=graph.constGraph();
  int no_nodes=ugraph.numberOfNodes();
  NumericMatrix coords(no_nodes, 2);
  List<node> nodes;
  ListIterator<node> it;
  int i;
  ugraph.allNodes(nodes);
  for (i=0, it=nodes.begin(); i < no_nodes; i++, it++) {
    coords(i, 0) = graph.x(*it);
    coords(i, 1) = graph.y(*it);
  }
  return coords;
}
