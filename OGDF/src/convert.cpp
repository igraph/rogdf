// -*- mode: C++ -*-
 
// OGDF R package
// Copyright (C) 2014  Gabor Csardi <csardi.gabor@gmail.com>
// 334 Harvard street, Cambridge, MA 02139 USA

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 
// 02110-1301 USA

#include "convert.h"

#define USE_RINTERNALS
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#undef AS_INTEGER
#define AS_INTEGER(x) Rf_coerceVector(x, INTSXP)
#undef PROTECT
#define PROTECT(x) Rf_protect(x)

namespace Rcpp {
  template <> ogdf::GraphAttributes as(SEXP igraph) {
    SEXP from, to;
    ogdf::Graph *G=new ogdf::Graph();
    ogdf::GraphAttributes GA(*G, ogdf::GraphAttributes::nodeGraphics | 
			     ogdf::GraphAttributes::edgeGraphics);
    int no_nodes=INTEGER(AS_INTEGER(VECTOR_ELT(igraph, 0)))[0];
    ogdf::Array<ogdf::node> nodemap(no_nodes);

    // TODO: check argument!

    PROTECT(from=AS_INTEGER(VECTOR_ELT(igraph, 2)));
    PROTECT(to=AS_INTEGER(VECTOR_ELT(igraph, 3)));

    int *ifrom=INTEGER(from);
    int *ito=INTEGER(to);
    int no_edges=Rf_length(from);
    
    for (int i=0; i<no_nodes; i++) { nodemap[i] = G->newNode(i); }
    for (int e=0; e<no_edges; e++) { 
      ogdf::node u=nodemap[ ifrom[e] ];
      ogdf::node v=nodemap[ ito[e] ];
      G->newEdge(u, v); 
    }
    
    UNPROTECT(2);
    return GA;
  }

} // namespace Rcpp
