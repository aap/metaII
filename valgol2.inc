enum {
	ARRAYPART,
	A01,
	A02,
	CALLPART,
	A05,
	A06,
	A07,
	A04,
	A09,
	A08,
	A03,
	A10,
	VARIABLE,
	A12,
	A14,
	A13,
	A11,
	A15,
	PRIMARY,
	A16,
	A19,
	A21,
	A22,
	A20,
	A18,
	A23,
	A24,
	A25,
	A26,
	A27,
	A28,
	A17,
	TERM,
	A30,
	A31,
	A33,
	A34,
	A32,
	A29,
	A35,
	EXP2,
	A36,
	A38,
	A39,
	A37,
	EXP1,
	A41,
	A42,
	A44,
	A43,
	A40,
	A45,
	RELATION,
	A47,
	A49,
	A50,
	A51,
	A52,
	A53,
	A54,
	A48,
	A46,
	A55,
	BPRIMARY,
	A56,
	A58,
	A57,
	BTERM,
	A60,
	A61,
	A62,
	A59,
	A63,
	BEXP1,
	A65,
	A66,
	A67,
	A64,
	A68,
	IMPLICATION1,
	A69,
	A70,
	IMPLICATION,
	A72,
	A71,
	A73,
	EQUIV,
	A75,
	A76,
	A77,
	A74,
	A78,
	EXP,
	A79,
	A81,
	A80,
	ASSIGNPART,
	A83,
	A85,
	A84,
	A82,
	A86,
	ASSIGNCALLST,
	A88,
	A90,
	A91,
	A93,
	A92,
	A94,
	A89,
	A87,
	A95,
	UNTILST,
	A96,
	A97,
	WHILECLAUSE,
	A98,
	B00,
	A99,
	FORCLAUSE,
	B01,
	B02,
	FORST,
	B03,
	B04,
	IOCALL,
	B05,
	B07,
	B08,
	B09,
	B10,
	B06,
	IDSEQ1,
	B11,
	B12,
	IDSEQ,
	B14,
	B15,
	B16,
	B13,
	B17,
	TYPEDEC,
	B18,
	B19,
	ARRAY1,
	B20,
	B21,
	ARRAYDEC,
	B23,
	B24,
	B25,
	B22,
	B26,
	PROCEDURE,
	B28,
	B30,
	B29,
	B27,
	B31,
	DEC,
	B32,
	B34,
	B35,
	B33,
	BLOCK,
	B37,
	B38,
	B39,
	B40,
	B41,
	B42,
	B43,
	B45,
	B44,
	B36,
	B46,
	UNCONDITIONALST,
	B47,
	B49,
	B50,
	B48,
	CONDST,
	B53,
	B55,
	B54,
	B52,
	B57,
	B59,
	B58,
	B60,
	B56,
	B51,
	B61,
	ST,
	B62,
	B64,
	B65,
	B66,
	B67,
	B63,
	PROGRAM,
	B68,
	B69,
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
	RET012,
	RET013,
	RET014,
	RET015,
	RET016,
	RET017,
	RET018,
	RET019,
	RET020,
	RET021,
	RET022,
	RET023,
	RET024,
	RET025,
	RET026,
	RET027,
	RET028,
	RET029,
	RET030,
	RET031,
	RET032,
	RET033,
	RET034,
	RET035,
	RET036,
	RET037,
	RET038,
	RET039,
	RET040,
	RET041,
	RET042,
	RET043,
	RET044,
	RET045,
	RET046,
	RET047,
	RET048,
	RET049,
	RET050,
	RET051,
	RET052,
	RET053,
	RET054,
	RET055,
	RET056,
	RET057,
	RET058,
	RET059,
	RET060,
	RET061,
	RET062,
	RET063,
	RET064,
	RET065,
	RET066,
	RET067,
	RET068,
	RET069,
	RET070,
	RET071,
	RET072,
	RET073,
	RET074,
	RET075,
	RET076,
	RET077,
	RET078,
	RET079,
	RET080,
	RET081,
	RET082,
	RET083,
	RET084,
	RET085,
};
void run(State *s) {
	s->pc = PROGRAM;
b:
	switch(s->pc) {
	case ARRAYPART:
		TST("(.")
		BF(A01)
		CLL(EXP, RET000)
		BE
		TST(".)")
		BE
		CL("AIA")
		OUT
	case A01:
	case A02:
		R
	case CALLPART:
		TST("(")
		BF(A03)
		CL("LDF")
		OUT
		CLL(EXP, RET001)
		BF(A04)
	case A05:
		TST(",")
		BF(A06)
		CLL(EXP, RET002)
		BE
	case A06:
	case A07:
		BT(A05)
		SET
		BE
	case A04:
		BT(A08)
		SET
		BF(A09)
	case A09:
	case A08:
		BE
		TST(")")
		BE
		CL("CLL")
		OUT
	case A03:
	case A10:
		R
	case VARIABLE:
		ID
		BF(A11)
		CL("LD ")
		CI
		OUT
		CLL(ARRAYPART, RET003)
		BF(A12)
	case A12:
		BT(A13)
		SET
		BF(A14)
	case A14:
	case A13:
		BE
	case A11:
	case A15:
		R
	case PRIMARY:
		TST("WHOLE")
		BF(A16)
		TST("(")
		BE
		CLL(EXP, RET004)
		BE
		TST(")")
		BE
		CL("WHL")
		OUT
	case A16:
		BT(A17)
		ID
		BF(A18)
		CL("LD ")
		CI
		OUT
		CLL(ARRAYPART, RET005)
		BF(A19)
	case A19:
		BT(A20)
		CLL(CALLPART, RET006)
		BF(A21)
	case A21:
		BT(A20)
		SET
		BF(A22)
	case A22:
	case A20:
		BE
	case A18:
		BT(A17)
		TST(".TRUE")
		BF(A23)
		CL("SET")
		OUT
	case A23:
		BT(A17)
		TST(".FALSE")
		BF(A24)
		CL("RST")
		OUT
	case A24:
		BT(A17)
		TST("0 ")
		BF(A25)
		CL("RST")
		OUT
	case A25:
		BT(A17)
		TST("1 ")
		BF(A26)
		CL("SET")
		OUT
	case A26:
		BT(A17)
		NUM
		BF(A27)
		CL("LDL")
		CI
		OUT
	case A27:
		BT(A17)
		TST("(")
		BF(A28)
		CLL(EXP, RET007)
		BE
		TST(")")
		BE
	case A28:
	case A17:
		R
	case TERM:
		CLL(PRIMARY, RET008)
		BF(A29)
	case A30:
		TST("*")
		BF(A31)
		CLL(PRIMARY, RET009)
		BE
		CL("HLT")
		OUT
	case A31:
		BT(A32)
		TST("/")
		BF(A33)
		CLL(PRIMARY, RET010)
		BE
		CL("DIV")
		OUT
	case A33:
		BT(A32)
		TST(".,.")
		BF(A34)
		CLL(PRIMARY, RET011)
		BE
		CL("DIV")
		OUT
		CL("WHL")
		OUT
	case A34:
	case A32:
		BT(A30)
		SET
		BE
	case A29:
	case A35:
		R
	case EXP2:
		TST("-")
		BF(A36)
		CLL(TERM, RET012)
		BE
		CL("NEG")
		OUT
	case A36:
		BT(A37)
		TST("+")
		BF(A38)
		CLL(TERM, RET013)
		BE
	case A38:
		BT(A37)
		CLL(TERM, RET014)
		BF(A39)
	case A39:
	case A37:
		R
	case EXP1:
		CLL(EXP2, RET015)
		BF(A40)
	case A41:
		TST("+")
		BF(A42)
		CLL(TERM, RET016)
		BE
		CL("ADD")
		OUT
	case A42:
		BT(A43)
		TST("-")
		BF(A44)
		CLL(TERM, RET017)
		BE
		CL("SUB")
		OUT
	case A44:
	case A43:
		BT(A41)
		SET
		BE
	case A40:
	case A45:
		R
	case RELATION:
		CLL(EXP1, RET018)
		BF(A46)
		TST(".L=")
		BF(A47)
		CLL(EXP1, RET019)
		BE
		CL("LEQ")
		OUT
	case A47:
		BT(A48)
		TST(".L")
		BF(A49)
		CLL(EXP1, RET020)
		BE
		CL("LES")
		OUT
	case A49:
		BT(A48)
		TST(".=")
		BF(A50)
		CLL(EXP1, RET021)
		BE
		CL("EQU")
		OUT
	case A50:
		BT(A48)
		TST(".-=")
		BF(A51)
		CLL(EXP1, RET022)
		BE
		CL("EQU")
		OUT
		CL("NOT")
		OUT
	case A51:
		BT(A48)
		TST(".G=")
		BF(A52)
		CLL(EXP1, RET023)
		BE
		CL("LES")
		OUT
		CL("NOT")
		OUT
	case A52:
		BT(A48)
		TST(".G")
		BF(A53)
		CLL(EXP1, RET024)
		BE
		CL("LEQ")
		OUT
		CL("NOT")
		OUT
	case A53:
		BT(A48)
		SET
		BF(A54)
	case A54:
	case A48:
		BE
	case A46:
	case A55:
		R
	case BPRIMARY:
		TST(".-")
		BF(A56)
		CLL(RELATION, RET025)
		BE
		CL("NOT")
		OUT
	case A56:
		BT(A57)
		CLL(RELATION, RET026)
		BF(A58)
	case A58:
	case A57:
		R
	case BTERM:
		CLL(BPRIMARY, RET027)
		BF(A59)
	case A60:
		TST(".A")
		BF(A61)
		CL("BF ")
		GN1
		OUT
		CL("POP")
		OUT
		CLL(BPRIMARY, RET028)
		BE
	case A61:
	case A62:
		BT(A60)
		SET
		BE
		LB
		GN1
		OUT
	case A59:
	case A63:
		R
	case BEXP1:
		CLL(BTERM, RET029)
		BF(A64)
	case A65:
		TST(".V")
		BF(A66)
		CL("BT ")
		GN1
		OUT
		CL("POP")
		OUT
		CLL(BTERM, RET030)
		BE
	case A66:
	case A67:
		BT(A65)
		SET
		BE
		LB
		GN1
		OUT
	case A64:
	case A68:
		R
	case IMPLICATION1:
		TST(".IMP")
		BF(A69)
		CL("NOT")
		OUT
		CL("BT ")
		GN1
		OUT
		CL("POP")
		OUT
		CLL(BEXP1, RET031)
		BE
		LB
		GN1
		OUT
	case A69:
	case A70:
		R
	case IMPLICATION:
		CLL(BEXP1, RET032)
		BF(A71)
	case A72:
		CLL(IMPLICATION1, RET033)
		BT(A72)
		SET
		BE
	case A71:
	case A73:
		R
	case EQUIV:
		CLL(IMPLICATION, RET034)
		BF(A74)
	case A75:
		TST(".EQ")
		BF(A76)
		CL("EQU")
		OUT
	case A76:
	case A77:
		BT(A75)
		SET
		BE
	case A74:
	case A78:
		R
	case EXP:
		TST(".IF")
		BF(A79)
		CLL(EXP, RET035)
		BE
		TST(".THEN")
		BE
		CL("BFP")
		GN1
		OUT
		CLL(EXP, RET036)
		BE
		CL("B  ")
		GN2
		OUT
		LB
		GN1
		OUT
		TST(".ELSE")
		BE
		CLL(EXP, RET037)
		BE
		LB
		GN2
		OUT
	case A79:
		BT(A80)
		CLL(EQUIV, RET038)
		BF(A81)
	case A81:
	case A80:
		R
	case ASSIGNPART:
		TST("=")
		BF(A82)
		CLL(EXP, RET039)
		BE
		CLL(ASSIGNPART, RET040)
		BF(A83)
		CL("ST")
		OUT
	case A83:
		BT(A84)
		SET
		BF(A85)
		CL("SST")
		OUT
	case A85:
	case A84:
		BE
	case A82:
	case A86:
		R
	case ASSIGNCALLST:
		ID
		BF(A87)
		CL("LD ")
		CI
		OUT
		CLL(ARRAYPART, RET041)
		BF(A88)
		CLL(ASSIGNPART, RET042)
		BE
	case A88:
		BT(A89)
		CLL(ASSIGNPART, RET043)
		BF(A90)
	case A90:
		BT(A89)
		CLL(CALLPART, RET044)
		BF(A91)
	case A91:
		BT(A92)
		SET
		BF(A93)
		CL("LDF")
		OUT
		CL("CLL")
		OUT
	case A93:
	case A92:
		BF(A94)
		CL("POP")
		OUT
	case A94:
	case A89:
		BE
	case A87:
	case A95:
		R
	case UNTILST:
		TST(".UNTIL")
		BF(A96)
		LB
		GN1
		OUT
		CLL(EXP, RET045)
		BE
		TST(".DO")
		BE
		CL("BTP")
		GN2
		OUT
		CLL(ST, RET046)
		BE
		CL("B  ")
		GN1
		OUT
		LB
		GN2
		OUT
	case A96:
	case A97:
		R
	case WHILECLAUSE:
		TST(".WHILE")
		BF(A98)
		CL("BF ")
		GN1
		OUT
		CL("POP")
		OUT
		CLL(EXP, RET047)
		BE
		LB
		GN1
		OUT
	case A98:
		BT(A99)
		SET
		BF(B00)
	case B00:
	case A99:
		R
	case FORCLAUSE:
		CLL(VARIABLE, RET048)
		BF(B01)
		TST("=")
		BE
		CL("FLP")
		OUT
		CL("BFP")
		GN1
		OUT
		CLL(EXP, RET049)
		BE
		TST(".STEP")
		BE
		CL("SST")
		OUT
		CL("B  ")
		GN2
		OUT
		LB
		GN1
		OUT
		CLL(EXP, RET050)
		BE
		TST(".UNTIL")
		BE
		CL("ADS")
		OUT
		LB
		GN2
		OUT
		CL("RSR")
		OUT
		CLL(EXP, RET051)
		BE
		CL("LEQ")
		OUT
		CLL(WHILECLAUSE, RET052)
		BE
		TST(".DO")
		BE
	case B01:
	case B02:
		R
	case FORST:
		TST(".FOR")
		BF(B03)
		CL("SET")
		OUT
		LB
		GN1
		OUT
		CLL(FORCLAUSE, RET053)
		BE
		CL("BFP")
		GN2
		OUT
		CLL(ST, RET054)
		BE
		CL("RST")
		OUT
		CL("B  ")
		GN1
		OUT
		LB
		GN2
		OUT
	case B03:
	case B04:
		R
	case IOCALL:
		TST("READ")
		BF(B05)
		TST("(")
		BE
		CLL(VARIABLE, RET055)
		BE
		TST(",")
		BE
		CLL(EXP, RET056)
		BE
		TST(")")
		BE
		CL("RED")
		OUT
	case B05:
		BT(B06)
		TST("WRITE")
		BF(B07)
		TST("(")
		BE
		CLL(VARIABLE, RET057)
		BE
		TST(",")
		BE
		CLL(EXP, RET058)
		BE
		TST(")")
		BE
		CL("WRT")
		OUT
	case B07:
		BT(B06)
		TST("EDIT")
		BF(B08)
		TST("(")
		BE
		CLL(EXP, RET059)
		BE
		TST(",")
		BE
		SR
		BE
		CL("EDT")
		CI
		OUT
		TST(")")
		BE
	case B08:
		BT(B06)
		TST("PRINT")
		BF(B09)
		CL("PNT")
		OUT
	case B09:
		BT(B06)
		TST("EJECT")
		BF(B10)
		CL("EJT")
		OUT
	case B10:
	case B06:
		R
	case IDSEQ1:
		ID
		BF(B11)
		LB
		CI
		OUT
		CL("BLK 1")
		OUT
	case B11:
	case B12:
		R
	case IDSEQ:
		CLL(IDSEQ1, RET060)
		BF(B13)
	case B14:
		TST(",")
		BF(B15)
		CLL(IDSEQ1, RET061)
		BE
	case B15:
	case B16:
		BT(B14)
		SET
		BE
	case B13:
	case B17:
		R
	case TYPEDEC:
		TST(".REAL")
		BF(B18)
		CLL(IDSEQ, RET062)
		BE
	case B18:
	case B19:
		R
	case ARRAY1:
		ID
		BF(B20)
		LB
		CI
		OUT
		TST("(.")
		BE
		TST("0")
		BE
		TST("..")
		BE
		NUM
		BE
		CL("BLK 1")
		OUT
		CL("BLK")
		CI
		OUT
		TST(".)")
		BE
	case B20:
	case B21:
		R
	case ARRAYDEC:
		TST(".ARRAY")
		BF(B22)
		CLL(ARRAY1, RET063)
		BE
	case B23:
		TST(",")
		BF(B24)
		CLL(ARRAY1, RET064)
		BE
	case B24:
	case B25:
		BT(B23)
		SET
		BE
	case B22:
	case B26:
		R
	case PROCEDURE:
		TST(".PROCEDURE")
		BF(B27)
		ID
		BE
		LB
		CI
		OUT
		LB
		GN1
		OUT
		CL("BLK 1")
		OUT
		TST("(")
		BE
		CLL(IDSEQ, RET065)
		BF(B28)
	case B28:
		BT(B29)
		SET
		BF(B30)
	case B30:
	case B29:
		BE
		TST(")")
		BE
		CL("SP  1")
		OUT
		TST(".,")
		BE
		CLL(ST, RET066)
		BE
		CL("R  ")
		GN1
		OUT
	case B27:
	case B31:
		R
	case DEC:
		CLL(TYPEDEC, RET067)
		BF(B32)
	case B32:
		BT(B33)
		CLL(ARRAYDEC, RET068)
		BF(B34)
	case B34:
		BT(B33)
		CLL(PROCEDURE, RET069)
		BF(B35)
	case B35:
	case B33:
		R
	case BLOCK:
		TST(".BEGIN")
		BF(B36)
		CL("B  ")
		GN1
		OUT
	case B37:
		CLL(DEC, RET070)
		BF(B38)
		TST(".,")
		BE
	case B38:
	case B39:
		BT(B37)
		SET
		BE
		LB
		GN1
		OUT
		CLL(ST, RET071)
		BE
	case B40:
		TST(".,")
		BF(B41)
		CLL(ST, RET072)
		BE
	case B41:
	case B42:
		BT(B40)
		SET
		BE
		TST(".END")
		BE
		ID
		BF(B43)
	case B43:
		BT(B44)
		SET
		BF(B45)
	case B45:
	case B44:
		BE
	case B36:
	case B46:
		R
	case UNCONDITIONALST:
		CLL(IOCALL, RET073)
		BF(B47)
	case B47:
		BT(B48)
		CLL(ASSIGNCALLST, RET074)
		BF(B49)
	case B49:
		BT(B48)
		CLL(BLOCK, RET075)
		BF(B50)
	case B50:
	case B48:
		R
	case CONDST:
		TST(".IF")
		BF(B51)
		CLL(EXP, RET076)
		BE
		TST(".THEN")
		BE
		CL("BFP")
		GN1
		OUT
		CLL(UNCONDITIONALST, RET077)
		BF(B52)
		TST(".ELSE")
		BF(B53)
		CL("B  ")
		GN2
		OUT
		LB
		GN1
		OUT
		CLL(ST, RET078)
		BE
		LB
		GN2
		OUT
	case B53:
		BT(B54)
		SET
		BF(B55)
		LB
		GN1
		OUT
	case B55:
	case B54:
		BE
	case B52:
		BT(B56)
		CLL(FORST, RET079)
		BF(B57)
	case B57:
		BT(B58)
		CLL(UNTILST, RET080)
		BF(B59)
	case B59:
	case B58:
		BF(B60)
		LB
		GN1
		OUT
	case B60:
	case B56:
		BE
	case B51:
	case B61:
		R
	case ST:
		CLL(CONDST, RET081)
		BF(B62)
	case B62:
		BT(B63)
		CLL(UNCONDITIONALST, RET082)
		BF(B64)
	case B64:
		BT(B63)
		CLL(FORST, RET083)
		BF(B65)
	case B65:
		BT(B63)
		CLL(UNTILST, RET084)
		BF(B66)
	case B66:
		BT(B63)
		SET
		BF(B67)
	case B67:
	case B63:
		R
	case PROGRAM:
		CLL(BLOCK, RET085)
		BF(B68)
		CL("HLT")
		OUT
		CL("SP  1")
		OUT
		CL("END")
		OUT
	case B68:
	case B69:
		R
	}
}
