%option reentrant interactive noyywrap outfile="scanner.cpp" header="scanner.hpp"

%{
#include <cstdlib>
#include <iostream>

#include "parser.hpp"

using Parser = lang::Parser;
%}

NUM         -?[0-9]+
STRING      \"([^\\\"]|\\.)*\"
IDENT       [A-Za-z][A-Za-z0-9]*
WS          [\t ]+

%%

and         { return Parser::token::AND; }
or          { return Parser::token::OR; }
not         { return Parser::token::NOT; }
if          { return Parser::token::IF; }
then        { return Parser::token::THEN; }
else        { return Parser::token::ELSE; }
while       { return Parser::token::WHILE; }
until       { return Parser::token::UNTIL; }
do          { return Parser::token::DO; }
print       { return Parser::token::PRINT; }
readint     { return Parser::token::READINT; }
readstr     { return Parser::token::READSTR; }
begin       { return Parser::token::BEG; }
end         { return Parser::token::END; }
exit        { return Parser::token::EXIT; }
substring   { return Parser::token::SUBSTRING; }
length      { return Parser::token::LENGTH; }
position    { return Parser::token::POSITION; }
concatenate { return Parser::token::CONCATENATE; }
true        { return Parser::token::BOOL_TRUE; }
false       { return Parser::token::BOOL_FALSE; }
":="        { return Parser::token::ASSIGN; }
"+"         { return Parser::token::PLUS; }
"-"         { return Parser::token::MINUS; }
"*"         { return Parser::token::MUL; }
"/"         { return Parser::token::DIV; }
"%"         { return Parser::token::MOD; }
"("         { return Parser::token::LPAREN; }
")"         { return Parser::token::RPAREN; }
"="         { return Parser::token::EQ; }
"<"         { return Parser::token::LT; }
"<="        { return Parser::token::LE; }
">"         { return Parser::token::GT; }
">="        { return Parser::token::GE; }
"<>"        { return Parser::token::NE; }
"=="        { return Parser::token::STR_EQ; }
"!="        { return Parser::token::STR_NE; }
";"         { return Parser::token::SEMICOLON; }
","         { return Parser::token::COMMA; }
{NUM}       { return Parser::token::NUM; }
{STRING}    { return Parser::token::STRING; }
{IDENT}     { return Parser::token::IDENT; }
{WS}        /* Ignore whitespace */
.           { std::cerr << "Unexpected input: " << yytext << std::endl; exit(1); }

%%
 
int main() {
    yyscan_t scanner;
    yylex_init(&scanner);
    lang::Parser parser{ scanner };
    std::cout.precision(10);
    parser.parse();
    yylex_destroy(scanner);
}