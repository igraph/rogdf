
## R interface to the Open Graph Drawing Framework

### OGDF

[OGDF](http://www.ogdf.net) is a self-contained C++ class library for
the automatic layout of diagrams. OGDF offers sophisticated algorithms
and data structures to use within your own applications or scientific
projects. The library is available under the GNU General Public
License.

OGDF is developed and supported by TU Dortmund, Osnabrück University,
University of Cologne, University of Sydney and oreas GmbH.

### Installation

Until the OGDF R package makes it into
[CRAN](http://cran.r-project.org), you can install it directly
from github, using the `devtools` package:

```
install.packages("devtools")  # if you don't have devtools yet
library(devtools)
install_github("igraph/rogdf/OGDF")
```

### Try it out

```
library(OGDF)
library(igraph)

g <- graph.star(10)
plot(g, layout=L_circular(g))

g <- erdos.renyi.game(100, 1/100)
l <- L_circular(g)
plot(g, layout=l, vertex.size=3, vertex.label=NA)

######

g <- graph.tree(20, 3)
plot(g, layout=L_tree(g))
```
