%require "3.7"
%language "C++"
%locations
%defines "parser.h"
%output "parser.cpp"

%define api.parser.class {Parser}
%define api.namespace {gvl::lang}
%define api.value.type variant
%param {yyscan_t scanner}

%code top {
#include <iostream>
#include <string>
#include <cmath>

#include "scanner.h"
}
 
%code provides {
#define YY_DECL \
    int yylex(gvl::lang::Parser::semantic_type *yylval, gvl::lang::Parser::location_type* yylloc, yyscan_t yyscanner)
YY_DECL;
}

%token NUM
%token STRING
%token IDENT
%token AND
%token OR
%token NOT
%token IF
%token THEN
%token ELSE
%token WHILE
%token UNTIL
%token DO
%token PRINT
%token READINT
%token READSTR
%token BEG
%token END
%token EXIT
%token SUBSTRING
%token LENGTH
%token POSITION
%token CONCATENATE
%token BOOL_TRUE
%token BOOL_FALSE
%token ASSIGN
%token PLUS
%token MINUS
%token MUL
%token DIV
%token MOD
%token EQ
%token LT
%token GT
%token LE
%token GE
%token NE
%token STR_EQ
%token STR_NE
%token LPAREN
%token RPAREN
%token SEMICOLON
%token COMMA

%start program
 
%%
 
/* Wyrażenie numeryczne, którego wartością jest liczba */
num_expr        : num_expr PLUS t_num_expr
                | num_expr MINUS t_num_expr
                | t_num_expr
                ;

t_num_expr      : t_num_expr MUL f_num_expr
                | t_num_expr DIV f_num_expr
                | t_num_expr MOD f_num_expr
                | f_num_expr
                ;

f_num_expr      : NUM
                | IDENT
                | READINT
                | MINUS num_expr
                | LPAREN num_expr RPAREN
                | LENGTH LPAREN str_expr RPAREN
                | POSITION LPAREN str_expr COMMA str_expr RPAREN
                ;

/* Wyrażenie, którego wartością jest łańcuch */
str_expr        : STRING
                | IDENT
                | READSTR
                | CONCATENATE LPAREN str_expr COMMA str_expr RPAREN
                | SUBSTRING LPAREN str_expr COMMA num_expr COMMA num_expr RPAREN
                ;

/* Relacje logiczne */
num_rel         : EQ
                | LT
                | LE
                | GT
                | GE
                | NE
                ;

str_rel         : STR_EQ
                | STR_NE
                ;

bool_expr       : bool_expr OR t_bool_expr
                | t_bool_expr
                ;

t_bool_expr     : t_bool_expr AND f_bool_expr
                | f_bool_expr
                ;

f_bool_expr     : BOOL_TRUE
                | BOOL_FALSE
                | LPAREN bool_expr RPAREN
                | NOT bool_expr
                | num_expr num_rel num_expr
                | str_expr str_rel str_expr
                ;

/* Podstawowe konstrukcje */
simple_instr    : assign_stat
                | if_stat
                | while_stat
                | until_stat
                | BEG instr END
                | output_stat
                | EXIT
                ;

/* Ciąg instrukcji */
instr           : instr SEMICOLON simple_instr
                | simple_instr /* Without this rule the program has to start with a semicolon */
                | %empty
                ;

/* Przypisanie */
assign_stat     : IDENT ASSIGN num_expr
                | IDENT ASSIGN str_expr
                ;

/* Konstrukcja warunkowa */
if_stat         : IF bool_expr THEN simple_instr
                | IF bool_expr THEN simple_instr ELSE simple_instr
                ;

/* Petla "while" */
while_stat      : WHILE bool_expr DO simple_instr
                ;

/* Petla "until" */
until_stat      : DO simple_instr UNTIL bool_expr
                ;

/* Wypisanie informacji na ekran */
output_stat     : PRINT LPAREN num_expr RPAREN
                | PRINT LPAREN str_expr RPAREN
                ;

/* Program jako taki */
program         : instr
                ;
%%
 
void gvl::lang::Parser::error(const location_type& loc, const std::string& msg) {
    std::cerr << "[" << loc.begin.line << "] Error: " << msg << std::endl;
}
