#!/bin/awk -f

/^	ADR/ {
	start = $2
	next
}
/^	END/ {
	printf("enum {\n");
	for(i = 0; i < l; i++)
		printf("\t%s,\n", labels[i])
	for(i = 0; i < nret; i++)
		printf("\tRET%03d,\n", i);
	printf("};\n");

	printf("void run(State *s) {\n");
	printf("	s->pc = %s;\n", start);
	printf("b:\n");
	printf("	switch(s->pc) {\n");
	for(i = 0; i < n; i++)
		print code[i]
	printf("	}\n");
	printf("}\n");
	exit
}
/^	/ {
	q = index($0, "'")
	strarg = substr($0, q)
	gsub("'", "\"", strarg)
	if($1 == "CLL")
		s = sprintf("\t\t%s(%s, RET%03d)", $1, $2, nret++)
	else if(q)
		s = sprintf("\t\t%s(%s)", $1, strarg)
	else if(NF == 2)
		s = sprintf("\t\t%s(%s)", $1, $2)
	else
		s = sprintf("\t\t%s", $1)
	code[n++] = s
	next
}
/^[A-Z]/ {
	s = sprintf("\tcase %s:", $1)
	labels[l++] = $1
	code[n++] = s
	next
}
