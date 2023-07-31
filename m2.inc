enum {
	OUT1,
	A01,
	A03,
	A04,
	A05,
	A02,
	OUTPUT,
	A07,
	A06,
	A09,
	A08,
	A10,
	A11,
	EX3,
	A12,
	A14,
	A15,
	A16,
	A17,
	A18,
	A19,
	A20,
	A13,
	EX2,
	A21,
	A23,
	A22,
	A25,
	A26,
	A28,
	A27,
	A24,
	A29,
	EX1,
	A31,
	A32,
	A33,
	A30,
	A34,
	ST,
	A35,
	A36,
	PROGRAM,
	A38,
	A37,
	A39,
	RET000,
	RET001,
	RET002,
	RET003,
	RET004,
	RET005,
	RET006,
	RET007,
	RET008,
	RET009,
	RET010,
	RET011,
};
void run(State *s) {
	s->pc = PROGRAM;
b:
	switch(s->pc) {
	case OUT1:
		TST("*1")
		BF(A01)
		CL("GN1")
		OUT
	case A01:
		BT(A02)
		TST("*2")
		BF(A03)
		CL("GN2")
		OUT
	case A03:
		BT(A02)
		TST("*")
		BF(A04)
		CL("CI")
		OUT
	case A04:
		BT(A02)
		SR
		BF(A05)
		CL("CL ")
		CI
		OUT
	case A05:
	case A02:
		R
	case OUTPUT:
		TST(".OUT")
		BF(A06)
		TST("(")
		BE
	case A07:
		CLL(OUT1, RET000)
		BT(A07)
		SET
		BE
		TST(")")
		BE
	case A06:
		BT(A08)
		TST(".LABEL")
		BF(A09)
		CL("LB")
		OUT
		CLL(OUT1, RET001)
		BE
	case A09:
	case A08:
		BF(A10)
		CL("OUT")
		OUT
	case A10:
	case A11:
		R
	case EX3:
		ID
		BF(A12)
		CL("CLL")
		CI
		OUT
	case A12:
		BT(A13)
		SR
		BF(A14)
		CL("TST")
		CI
		OUT
	case A14:
		BT(A13)
		TST(".ID")
		BF(A15)
		CL("ID")
		OUT
	case A15:
		BT(A13)
		TST(".NUMBER")
		BF(A16)
		CL("NUM")
		OUT
	case A16:
		BT(A13)
		TST(".STRING")
		BF(A17)
		CL("SR")
		OUT
	case A17:
		BT(A13)
		TST("(")
		BF(A18)
		CLL(EX1, RET002)
		BE
		TST(")")
		BE
	case A18:
		BT(A13)
		TST(".EMPTY")
		BF(A19)
		CL("SET")
		OUT
	case A19:
		BT(A13)
		TST("$")
		BF(A20)
		LB
		GN1
		OUT
		CLL(EX3, RET003)
		BE
		CL("BT ")
		GN1
		OUT
		CL("SET")
		OUT
	case A20:
	case A13:
		R
	case EX2:
		CLL(EX3, RET004)
		BF(A21)
		CL("BF ")
		GN1
		OUT
	case A21:
		BT(A22)
		CLL(OUTPUT, RET005)
		BF(A23)
	case A23:
	case A22:
		BF(A24)
	case A25:
		CLL(EX3, RET006)
		BF(A26)
		CL("BE")
		OUT
	case A26:
		BT(A27)
		CLL(OUTPUT, RET007)
		BF(A28)
	case A28:
	case A27:
		BT(A25)
		SET
		BE
		LB
		GN1
		OUT
	case A24:
	case A29:
		R
	case EX1:
		CLL(EX2, RET008)
		BF(A30)
	case A31:
		TST("/")
		BF(A32)
		CL("BT ")
		GN1
		OUT
		CLL(EX2, RET009)
		BE
	case A32:
	case A33:
		BT(A31)
		SET
		BE
		LB
		GN1
		OUT
	case A30:
	case A34:
		R
	case ST:
		ID
		BF(A35)
		LB
		CI
		OUT
		TST("=")
		BE
		CLL(EX1, RET010)
		BE
		TST(".,")
		BE
		CL("R")
		OUT
	case A35:
	case A36:
		R
	case PROGRAM:
		TST(".SYNTAX")
		BF(A37)
		ID
		BE
		CL("ADR")
		CI
		OUT
	case A38:
		CLL(ST, RET011)
		BT(A38)
		SET
		BE
		TST(".END")
		BE
		CL("END")
		OUT
	case A37:
	case A39:
		R
	}
}
