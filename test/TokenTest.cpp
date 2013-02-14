#include <QtTest/QtTest>
#include <QString>
#include "TokenTest.h"
#include "Token.h"
#include "Tokenizer.h"

void TokenTest::testConstructors()
{

    Token t;
    QCOMPARE(t.startLine(), 0);
    QCOMPARE(t.startColumn(), 0);
    QCOMPARE(t.endLine(), 0);
    QCOMPARE(t.endColumn(), 0);
    QCOMPARE(t.type() == Token::UNKNOWN, true);
    QCOMPARE(t.text(), QString(""));

    Token t2(10, 20, 30, 40, "Hola", Token::KEYWORD);
    QCOMPARE(t2.startLine(), 10);
    QCOMPARE(t2.startColumn(), 20);
    QCOMPARE(t2.endLine(), 30);
    QCOMPARE(t2.endColumn(), 40);
    QCOMPARE(t2.type() == Token::KEYWORD, true);
    QCOMPARE(t2.text(), QString("Hola"));
}

void TokenTest::testComparison()
{
    Token t, t2;
    QCOMPARE(t == t2, true);

    t = Token(10, 20, 30, 40, "Hola", Token::KEYWORD);
    t2 = Token(11, 20, 30, 40, "Hola", Token::KEYWORD);


    //Test operator==
    QCOMPARE(t == t2, false);
    t2.setStartLine(10);
    QCOMPARE(t == t2, true);

    t2.setStartColumn(21);
    QCOMPARE(t == t2, false);
    t2.setStartColumn(20);
    QCOMPARE(t == t2, true);

    t2.setEndLine(31);
    QCOMPARE(t == t2, false);
    t2.setEndLine(30);
    QCOMPARE(t == t2, true);

    t2.setEndColumn(41);
    QCOMPARE(t == t2, false);
    t2.setEndColumn(40);
    QCOMPARE(t == t2, true);

    t2.setType(Token::SPECIAL);
    QCOMPARE(t == t2, false);
    t2.setType(Token::KEYWORD);
    QCOMPARE(t == t2, true);

    t2.setText("Hi");
    QCOMPARE(t == t2, false);
    t2.setText("Hola");
    QCOMPARE(t == t2, true);




    //Test operator!=
    QCOMPARE(t != t2, false);
    t2.setStartLine(10);
    QCOMPARE(t != t2, false);

    t2.setStartColumn(21);
    QCOMPARE(t != t2, true);
    t2.setStartColumn(20);
    QCOMPARE(t != t2, false);

    t2.setEndLine(31);
    QCOMPARE(t != t2, true);
    t2.setEndLine(30);
    QCOMPARE(t != t2, false);

    t2.setEndColumn(41);
    QCOMPARE(t != t2, true);
    t2.setEndColumn(40);
    QCOMPARE(t != t2, false);

    t2.setType(Token::STRING);
    QCOMPARE(t != t2, true);
    t2.setType(Token::KEYWORD);
    QCOMPARE(t != t2, false);

    t2.setText("Hi");
    QCOMPARE(t != t2, true);
    t2.setText("Hola");
    QCOMPARE(t != t2, false);

}
