all: m2 v2

m2: m2.c m2.inc
	cc -o m2 m2.c
m2.inc: meta2.code
	./asm2c.awk <meta2.code >m2.inc

v2: v2.c valgol2.inc
	cc -o v2 v2.c
valgol2.inc: valgol2.m2
	./m2 <valgol2.m2 | ./asm2c.awk >valgol2.inc
