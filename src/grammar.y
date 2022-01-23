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

#include "operations.h"
#include "scanner.h"
#include "symbol_table.h"

using Operations = gvl::lang::Operations;

gvl::lang::SymbolTable table;
}
 
%code provides {
#define YY_DECL \
    int yylex(gvl::lang::Parser::semantic_type *yylval, gvl::lang::Parser::location_type* yylloc, yyscan_t yyscanner)
YY_DECL;
}

%code requires {
#include "operations.h"
}

%token <std::int32_t> NUM
%token <std::string> STRING
%token <std::string> IDENT
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

%type <std::int32_t> num_expr t_num_expr f_num_expr
%type <std::string> str_expr
%type <gvl::lang::Operations> num_rel str_rel
%type <bool> bool_expr t_bool_expr f_bool_expr

%%
 
/* Wyrażenie numeryczne, którego wartością jest liczba */
num_expr        : num_expr PLUS t_num_expr {
                    $$ = $1 + $3;
                }
                | num_expr MINUS t_num_expr {
                    $$ = $1 - $3;
                }
                | t_num_expr {
                    $$ = $1;
                }
                ;

t_num_expr      : t_num_expr MUL f_num_expr {
                    $$ = $1 * $3;
                }
                | t_num_expr DIV f_num_expr {
                    $$ = $1 / $3;
                }
                | t_num_expr MOD f_num_expr {
                    $$ = $1 % $3;
                }
                | f_num_expr {
                    $$ = $1;
                }
                ;

f_num_expr      : NUM {
                    $$ = $1;
                }
                | IDENT {
                    $$ = table.LookupInteger($1, {@1.begin.line, @1.begin.column});
                }
                | READINT {
                    std::int32_t input;
                    std::cout << "Enter integer: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    $$ = input;
                }
                | MINUS num_expr {
                    $$ = -$2;
                }
                | LPAREN num_expr RPAREN {
                    $$ = ($2);
                }
                | LENGTH LPAREN str_expr RPAREN {
                    std::string str = $3;
                    $$ = str.length();
                }
                | POSITION LPAREN str_expr COMMA str_expr RPAREN {
                    std::int32_t pos = $3.find($5);
                    return pos != std::string::npos ? pos : 0;
                }
                ;

/* Wyrażenie, którego wartością jest łańcuch */
str_expr        : STRING {
                    $$ = $1;
                }
                | IDENT {
                    $$ = table.LookupString($1, {@1.begin.line, @1.begin.column});
                }
                | READSTR {
                    std::string input;
                    std::cout << "Enter integer: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    $$ = input;
                }
                | CONCATENATE LPAREN str_expr COMMA str_expr RPAREN {
                    $$ = $3 + $5;
                }
                | SUBSTRING LPAREN str_expr COMMA num_expr COMMA num_expr RPAREN {
                    $$ = $3.substr($5, $7);
                }
                ;

/* Relacje logiczne */
num_rel         : EQ {
                    $$ = Operations::kEq;
                }
                | LT {
                    $$ = Operations::kLt;
                }
                | LE {
                    $$ = Operations::kLe;
                }
                | GT {
                    $$ = Operations::kGt;
                }
                | GE {
                    $$ = Operations::kGe;
                }
                | NE {
                    $$ = Operations::kNe;
                }
                ;

str_rel         : STR_EQ {
                    $$ = Operations::kEq;
                }
                | STR_NE {
                    $$ = Operations::kNe;
                }
                ;

bool_expr       : bool_expr OR t_bool_expr {
                    $$ = $1 || $3;
                }
                | t_bool_expr {
                    $$ = $1;
                }
                ;

t_bool_expr     : t_bool_expr AND f_bool_expr {
                    $$ = $1 && $3;
                }
                | f_bool_expr {
                    $$ = $1;
                }
                ;

f_bool_expr     : BOOL_TRUE {
                    $$ = true;
                }
                | BOOL_FALSE {
                    $$ = false;
                }
                | LPAREN bool_expr RPAREN {
                    $$ = ($2);
                }
                | NOT bool_expr {
                    $$ = !$2;
                }
                | num_expr num_rel num_expr {
                    bool result;
                    switch($2) {
                        case Operations::kEq:
                            result = ($1 == $3);
                            break;
                        case Operations::kLt:
                            result = ($1 < $3);
                            break;
                        case Operations::kLe:
                            result = ($1 <= $3);
                            break;
                        case Operations::kGt:
                            result = ($1 > $3);
                            break;
                        case Operations::kGe:
                            result = ($1 >= $3);
                            break;
                        case Operations::kNe:
                            result = ($1 != $3);
                            break;
                        default:
                            break;
                    }
                    $$ = result;
                }
                | str_expr str_rel str_expr {
                    bool result;
                    switch($2) {
                        case Operations::kStrEq:
                            result = ($1 == $3);
                            break;
                        case Operations::kStrNe:
                            result = ($1 != $3);
                            break;
                        default:
                            break;
                    }
                    $$ = result;
                }
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
assign_stat     : IDENT ASSIGN num_expr {
                    table.AssignInteger($1, {@1.begin.line, @1.begin.column}, $3);
                }
                | IDENT ASSIGN str_expr {
                    table.AssignString($1, {@1.begin.line, @1.begin.column}, $3);
                }
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
output_stat     : PRINT LPAREN num_expr RPAREN {
                    std::cout << $3 << std::endl;
                }
                | PRINT LPAREN str_expr RPAREN {
                    std::cout << $3 << std::endl;
                }
                ;

/* Program jako taki */
program         : instr
                ;
%%
 
void gvl::lang::Parser::error(const location_type& loc, const std::string& msg) {
    std::cerr << "[" << loc.begin.line << "] Error: " << msg << std::endl;
}
