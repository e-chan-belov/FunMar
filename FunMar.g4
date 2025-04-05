grammar FunMar;

prog: func+ EOF;

func: ID '{' expStmt* '}';

expStmt: stmt ';' | schm;

stmt: rule | terminalRule;

rule: sbwordi '->' sbwordo;

terminalRule: sbwordi '=>' sbwordo;

schm: 'scheme' '{' expStmt* '}';

sbwordi: LET? (ID LET)* ID?;

sbwordo: LET? (funCall LET)* funCall?;

funCall: ID'('sbwordi')' | ID;

LET: '"' .*? '"';
ID: [a-zA-Z_][a-zA-Z_0-9]*;
WS: [ \t\r\n]+ -> skip;
