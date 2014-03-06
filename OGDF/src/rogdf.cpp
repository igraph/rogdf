#include "rogdf.h"

// [[Rcpp::export]]
IntegerVector rogdf_version() {
  return IntegerVector::create(_["major"] = 2012,
			       _["minor"] = 7,
			       _["patch"] = 0);
}

NumericMatrix rogdf_get_layout(GraphAttributes &GA) {
  Graph G=GA.constGraph();
  NumericMatrix coords(G.numberOfNodes(), 2);
  int i; node v;
  for(i=0, v=G.firstNode(); v; i++, v=v->succ())  {
    coords(i, 0) = GA.x(v);
    coords(i, 1) = GA.y(v);
  }
  return coords;
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
  return rogdf_get_layout(graph);
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
  return rogdf_get_layout(graph);
}
