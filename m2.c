#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef struct State State;
struct State {
	int pc;
	int sp;
	int stack[10000];
	int sw;

	char line[1000];
	int lp;

	int symcnt;

	char *input;
	char val[1000];
};

void skip(State *s) {
	while(isspace(*s->input)) s->input++;
}

void resetbuf(State *s) {
	memset(s->line, '\t', sizeof(s->line));
	s->lp = 1;
	s->line[s->lp] = '\0';
}

#define trace(...)

void tst(State *s, char *str) {
trace("\t\t\tTST %s\n", str);
	int len = strlen(str);
	skip(s);
	if(strncmp(s->input, str, len) == 0) {
		s->sw = 1;
		s->input += len;
	} else {
		s->sw = 0;
	}
}
void id(State *s) {
trace("\t\t\tID\n");
	char *p;

	skip(s);
	if(isalpha(*s->input)) {
		p = s->val;
		*p++ = *s->input++;
		while(isalnum(*s->input))
			*p++ = *s->input++;
		*p++ = '\0';
trace("\t\t\tID: <%s>\n", s->val);
		s->sw = 1;
	} else
		s->sw = 0;
}
void num(State *s) {
trace("num\n");
exit(1);
}
void sr(State *s) {
trace("\t\t\tSR\n");
	char *p;

	skip(s);
	if(*s->input == '\'') {
		p = s->val;
		*p++ = *s->input++;
		while(*s->input != '\'')
			*p++ = *s->input++;
		*p++ = *s->input++;
		*p++ = '\0';
trace("\t\t\tSR: <%s>\n", s->val);
		s->sw = 1;
	} else
		s->sw = 0;
}
void cll(State *s, int loc, int ret) {
trace("\t\t\tCLL\n");
	s->stack[s->sp] = ret;
	s->sp += 3;
	s->pc = loc;
	s->stack[s->sp+1] = 0;
	s->stack[s->sp+2] = 0;
}
void r(State *s) {
trace("\t\t\tR\n");
	s->sp -= 3;
	s->pc = s->stack[s->sp];
}
void set(State *s) {
trace("\t\t\tSET\n");
	s->sw = 1;
}
void b(State *s, int loc) {
trace("\t\t\tB\n");
	s->pc = loc;
}
int bt(State *s, int loc) {
trace("\t\t\tBT\n");
	if(s->sw)
		s->pc = loc;
	return s->sw;
}
int bf(State *s, int loc) {
trace("\t\t\tBF\n");
	if(!s->sw)
		s->pc = loc;
	return !s->sw;
}
void be(State *s) {
trace("\t\t\tBE\n");
	if(!s->sw) {
		printf("ERROR\n");
		exit(0);
	}
}
void copy(State *s, char *p) {
	while(*p) s->line[s->lp++] = *p++;
	s->line[s->lp++] = ' ';
	s->line[s->lp] = '\0';
}
void cl(State *s, char *str) {
trace("\t\t\tCL\n");
	copy(s, str);
}
void ci(State *s) {
trace("\t\t\tCI\n");
	copy(s, s->val);
}
void gensym(State *s, int n) {
	char str[4];
	str[0] = 'A' + n/100;
	sprintf(str+1, "%02d", n%100);
	copy(s, str);
}
void gn1(State *s) {
trace("\t\t\tGN1\n");
	if(s->stack[s->sp+1] == 0)
		s->stack[s->sp+1] = s->symcnt++;
	gensym(s, s->stack[s->sp+1]);
}
void gn2(State *s) {
trace("\t\t\tGN2\n");
	if(s->stack[s->sp+2] == 0)
		s->stack[s->sp+2] = s->symcnt++;
	gensym(s, s->stack[s->sp+2]);
}
void lb(State *s) {
trace("\t\t\tLB\n");
	s->lp = 0;
}
void out(State *s) {
trace("\t\t\tOUT\n");
	if(s->line[s->lp-1] == ' ')
		s->line[s->lp-1] = '\0';
	printf("%s\n", s->line);
	resetbuf(s);
}

void init(State *s) {
	s->sp = 0;
	s->sw = 0;
	s->symcnt = 1;
	resetbuf(s);
}

#define TST(str) tst(s, str);
#define ID id(s);
#define NUM num(s);
#define SR sr(s);
#define CLL(lb, ret) cll(s, lb, ret); goto b; case ret:
#define R r(s); goto b;
#define SET set(s);
#define B(lb) b(s, lb); goto b;
#define BT(lb) if(bt(s, lb)) goto b;
#define BF(lb) if(bf(s, lb)) goto b;
#define BE be(s);
#define CL(str) cl(s, str);
#define CI ci(s);
#define GN1 gn1(s);
#define GN2 gn2(s);
#define LB lb(s);
#define OUT out(s);

#include "m2.inc"

char buf[10000];
int main() {
	State s;
	int n;

	n = fread(buf, 1, sizeof(buf), stdin);
	buf[n] = '\0';
	s.input = buf;
	init(&s);
	run(&s);
}
