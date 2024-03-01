Decomposition Tree and Subgraph Searching using Keywords!

Keyword search has been widely studied to retrieve relevant substructures from graphs for a given set of keywords. 
However, existing well-studied approaches aim at finding compact trees/subgraphs containing the keywords, and ignore a critical measure, density, to represent how strongly and stably the keyword nodes are connected in the substructure.
Given a set of keywords $Q = \{w_1, w_2,\ldots, w_l\}$, we study the problem of finding a cohesive subgraph containing $Q$ with high density and compactness from a graph $G=(V,E)$. 
We model the cohesive subgraph based on a carefully chosen \emph{$k$-core} model, and formulate the problem of finding cohesive subgraphs for keyword queries as finding a maximal subgraph covering $Q$. A $k$-core of a graph $G$ is a maximal connected subgraph of $G$ with a minimum degree of at least $k$.

A $k$-core of a graph $G$ is a maximal connected subgraph of $G$ with a minimum degree of at least $k$. The coreness of a graph $k_{max}$ is the biggest integer for which $G$ has a $k_{max}$-core. Given an input graph $G$, we first construct the core decomposition tree of $G$, denoted by $T$. The leaves of $T$ correspond to the vertices of $G$, and its intermediate nodes represent the subgraphs of $G$. More specifically, the root of $T$ (at level 0) represents the graph $G$ itself. At each level $1 \leq \ell \leq  k_{max}$, the non-leaf nodes represent the $\ell$-cores of $G$.
