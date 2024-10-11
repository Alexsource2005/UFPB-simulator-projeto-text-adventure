
BEGIN {
   count = 0;
   obj = "";
   if (pass == "c2") {
      print "\ntObjetos lista_objetos[] = {";
   }
}

/^- / {
   outputRecord(",");
   obj = $2;
   prop["descricao"] = "NULL";
   prop["rotulos"]        = "";
   prop["local"]    = "NULL";
   prop["destino"] = "NULL";
   prop["aparente"] = "";
   prop["detalhes"] = "\"Voce nao ve nada de especial.\"";
   prop["conteudo"] = "\". Voce ve\"";
   prop["texto_GO"] = "\"Voce nao pode se aproximar mais que isso.\"";
   prop["peso"] = "99";
   prop["capacidade"] = "0";
   prop["vida"] = "0";	
   prop["abrir"]        = "nao_pode_ser_aberto";
   prop["fechar"]       = "nao_pode_ser_fechado";
}

obj && /^[ \t]+[a-z]/ {
   name = $1;
   $1 = "";
   if (name in prop) {
      prop[name] = $0;
   }
   else if (pass == "c2") {
      print "#error \"" FILENAME " line " NR ": unknown attribute '" name "'\"";
   }
}

!obj && pass == (/^#include/ ? "c1" : "h") {
   print;
}

END {
   outputRecord("\n};");
   if (pass == "h") {
      print "\n#define fim_lista\t(lista_objetos + " count ")";
   }
}

function outputRecord(separator)
{
   if (obj) {
      if (pass == "h") {
         print "#define " obj "\t(lista_objetos + " count ")";
      }
      else if (pass == "c1") {
         print "static const char *tags" count "[] = {" prop["rotulos"] ", NULL};";
      }
      else if (pass == "c2") {
         print "\t{\t/* " count " = " obj " */";
         print "\t\t" prop["descricao"] ",";
         print "\t\ttags" count ",";
         print "\t\t" prop["local"] ",";
         print "\t\t" prop["destino"] ",";
	 print "\t\t" prop[prop["aparente"] ? "aparente" : "destino"] ",";
         print "\t\t" prop["detalhes"] ",";
	 print "\t\t" prop["conteudo"] ",";
	 print "\t\t" prop["texto_GO"] ",";
	 print "\t\t" prop["peso"] ",";
	 print "\t\t" prop["capacidade"] ",";
	 print "\t\t" prop["vida"] ",";
	 print "\t\t" prop["abrir"] ",";
         print "\t\t" prop["fechar"];
	 print "\t}" separator;
         delete prop;
      }
      count++;
   }
}
