import networkx as nx
import pygraphviz as pgv
from nxpd import draw, nxpdParams
nxpdParams['show'] = 'ipynb'
G = nx.DiGraph()
G.add_edges_from([(72, +37), (72, -37), (+37, +13), (+37, -13), (-37, +13),(-37,-13),(+13,+40),(+13,-40),(-13,+40),(-13,-40),(+40,+26),(+40,-26),(-40,+26),(-40,-26)])
def find_all_paths(graph, start, path=[]):
    path = path + [start]
    mulsix=[path]
    paths = [path]
    if len(graph[start]) == 0:   # No neighbors
        if sum(path)%6==0:
            print(path)
    for node in graph[start]:
        newpaths = find_all_paths(graph, node, path)
        for newpath in newpaths:
            paths.append(newpath)
    return mulsix
find_all_paths(G,72)


