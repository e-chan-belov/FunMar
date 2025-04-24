grammar FunMar;

prog: func+ EOF;

func: ID '{' expStmt* '}';

expStmt: stmt ';' | schm;

stmt: funMarRule | terminalRule;

funMarRule: sbwordi '->' sbwordo;

terminalRule: sbwordi '=>' sbwordo;

schm: 'scheme' '{' expStmt* '}';

sbwordi: LET? (ID LET)* ID?;

sbwordo: funcAbst+;

abst: LET | ID;

funcAbst: LET | ID | ID'('abst+')';

LET: '"' .*? '"';
ID: [a-zA-Z_][a-zA-Z_0-9]*;
WS: [ \t\r\n]+ -> skip;
