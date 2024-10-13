BEGIN     { print "digraph map {"; }
/^- /     { outputEdges(); delete a; }
/^[ \t]/  { a[$1] = $2; }
END       { outputEdges(); print "}"; }
function outputEdges()
{
   outputEdge(a["local"], a["destino"], "");
   outputEdge(a["local"], a["aparente"], " [style=dashed]");
}
function outputEdge(from, to)
{
   if (from && to) print "\t" from " -> " to;
}
