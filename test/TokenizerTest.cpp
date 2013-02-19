#include "TokenizerTest.h"
#include "Token.h"
#include "Tokenizer.h"
#include <QtTest/QtTest>

#include <QDebug>

void TokenizerTest::testSimpleKeywords()
{
    Tokenizer tzr;
    QList<Token *> got = tzr.tokenize("\t   FOR IF\t \t \n \n WHEN WHEN WHEN   ");
    QList<Token *> expected;
    expected << new Token(0,4,0,7,"FOR", Token::IDENTIFIER);
    expected << new Token(0,8,0,10,"IF", Token::IDENTIFIER);
    expected << new Token(2,1,2,5,"WHEN", Token::IDENTIFIER);
    expected << new Token(2,6,2,10,"WHEN", Token::IDENTIFIER);
    expected << new Token(2,11,2,15,"WHEN", Token::IDENTIFIER);

    QCOMPARE(tzr.wasSuccessFull(), true);
    QCOMPARE(expected.size(), got.size());
    if(expected.size() == got.size())
    {
        for(int i = 0; i < got.size(); i++)
        {
            //qDebug() << got[i] << "?=" << expected[i];
            QCOMPARE(*got[i] == *expected[i], true);
        }
    }
}

void TokenizerTest::testSimpleSelect()
{
    Tokenizer tzr;
    QList<Token *> got = tzr.tokenize("SeLecT*FROM TableName WHERE id>5");
    QList<Token *> expected;
    expected << new Token(0,0,0,6,"SeLecT", Token::KEYWORD);
    expected << new Token(0,6,0,7,"*", Token::SPECIAL);
    expected << new Token(0,7,0,11,"FROM", Token::KEYWORD);
    expected << new Token(0,12,0,21,"TableName", Token::IDENTIFIER);
    expected << new Token(0,22,0,27,"WHERE", Token::KEYWORD);
    expected << new Token(0,28,0,30,"id", Token::IDENTIFIER);
    expected << new Token(0,30,0,31,">", Token::SPECIAL);
    expected << new Token(0,31,0,32,"5", Token::NUMBER);


    QCOMPARE(tzr.wasSuccessFull(), true);
    QCOMPARE(expected.size(), got.size());
    if(expected.size() == got.size())
    {
        for(int i = 0; i < got.size(); i++)
        {

            QCOMPARE( *got[i] == *expected[i], true);
        }
    }
}



void TokenizerTest::testNumbers()
{
    QList<QString> numbers;
    QList<Token *> expected;
    numbers
            << "1"
            << "2"
            << "3"
            << "0"
            << "0.5"
            << "0.0"
            << "-0"
            << "-0.0"
            << "-1.54486"
            << "-3.115E-5"
            << "-3.115E5"
            << "-3.115E+5"
            << "-3.115e-5"
            << "-3.115e5"
            << "-3.115e+5"
            << "-117.6"
            << "5161565161.651"
            << "4654654654E5464";


    Tokenizer tzr;
    QString code;
    foreach(QString n, numbers)
    {
        expected << new Token(0,0,0,0,n, Token::NUMBER);
        code += " " + n + " ";
    }

    QList<Token *> got = tzr.tokenize(code);

    QCOMPARE(tzr.wasSuccessFull(), true);
    QCOMPARE(expected.size(), got.size());
    if(expected.size() == got.size())
    {
        for(int i = 0; i < got.size(); i++)
        {
            QCOMPARE(got[i]->text(), expected[i]->text());
            QCOMPARE(got[i]->type(), expected[i]->type());
        }
    }
}

void TokenizerTest::testValidIdentifiers()
{
    QList<QString> identifiers;
    QList<Token *> expected;
    identifiers
            << "id"
            << "@a_@$#_@$#_@$#Coltype"
            << "#a_@$#_@$#_@$#Coltype"
            << "_a_@$#_@$#_@$#Coltype123456789"
               ;


    Tokenizer tzr;
    QString code;
    foreach(QString i, identifiers)
    {
        expected << new Token(0,0,0,0,i, Token::IDENTIFIER);
        code += " " + i + " ";
    }

    QList<Token *> got = tzr.tokenize(code);

    QCOMPARE(tzr.wasSuccessFull(), true);
    QCOMPARE(expected.size(), got.size());
    if(expected.size() == got.size())
    {
        for(int i = 0; i < got.size(); i++)
        {
            QCOMPARE(got[i]->text(), expected[i]->text());
            QCOMPARE(got[i]->type(), expected[i]->type());
        }
    }
}




void TokenizerTest::testInvalidIdentifiers()
{
    QList<QString> identifiers;
    QList<Token *> expected;
    identifiers
            << "0id"
               ;
    Tokenizer tzr;
    QString code;
    foreach(QString i, identifiers)
    {
        expected << new Token(0,0,0,0,i, Token::FAILURE);
        code += " " + i + " ";
    }

    QList<Token *> got = tzr.tokenize(code);

    //    QCOMPARE(tzr.wasSuccessFull(), true);

    for(int i = 0; i < got.size(); i++)
    {
        //qDebug() << got[i]->text() << got[i]->type() ;

    }
}


void TokenizerTest::testMultiLineComments_data()
{
    QTest::addColumn<QString>("code");
    QTest::addColumn<TokenPList>("expected");

    QTest::newRow("/* */ in a single line")
            << "this is /* a comment */ we ignore"
            << (
                TokenPList()
                << new Token(0,0,0,4,"this", Token::IDENTIFIER)
                << new Token(0,5,0,7,"is", Token::IDENTIFIER)
                << new Token(0,8,0,23,"/* a comment */", Token::COMMENT)
                << new Token(0,24,0,26,"we", Token::IDENTIFIER)
                << new Token(0,27,0,33,"ignore", Token::IDENTIFIER)
               );


    QTest::newRow("/* */ with a newlines within")
            << "this is \n/* \na\n comment\n */\n we ignore"
            << (
                TokenPList()
                << new Token(0,0,0,4,"this", Token::IDENTIFIER)
                << new Token(0,5,0,7,"is", Token::IDENTIFIER)
                << new Token(1,0,4,18,"/* \na\n comment\n */", Token::COMMENT)
                << new Token(5,1,5,3,"we", Token::IDENTIFIER)
                << new Token(5,4,5,10,"ignore", Token::IDENTIFIER)
               );

    QTest::newRow("/* A lot of stuff within the comment...*/")
            << "/* A lot of stuff within the comment...*/"
            << (
                TokenPList()
                << new Token(0,0,0,41,"/* A lot of stuff within the comment...*/", Token::COMMENT)
               );



}

void TokenizerTest::testMultiLineComments()
{
    Tokenizer tzr;
    QFETCH(QString, code);
    QFETCH(TokenPList, expected);

    TokenPList got = tzr.tokenize(code);
    QCOMPARE(expected.size(), got.size());
    for(int i = 0; i < got.size(); i++)
    {
        QCOMPARE(got[i]->type(), expected[i]->type());
        QCOMPARE(got[i]->text(), expected[i]->text());
        QCOMPARE(got[i]->startLine(), expected[i]->startLine());
        QCOMPARE(got[i]->endLine(), expected[i]->endLine());
        QCOMPARE(got[i]->startColumn(), expected[i]->startColumn());
        QCOMPARE(got[i]->endColumn(), expected[i]->endColumn());

    }

}




void TokenizerTest::testPartialMultiLineComments_data()
{
    QTest::addColumn<QString>("code");
    QTest::addColumn<TokenPList>("expected");

    QTest::newRow("this is a /* partial comment ")
            << "this is a /* partial comment "
            << (
                TokenPList()
               << new Token(0,  0, 0, 4,"this", Token::IDENTIFIER)
               << new Token(0,  5, 0, 7,"is", Token::IDENTIFIER)
               << new Token(0,  8, 0, 9,"a", Token::IDENTIFIER)
               << new Token(0, 10, 0, 10,"", Token::COMMENTSTART)
               << new Token(0, 13, 0, 20,"partial", Token::IDENTIFIER)
               << new Token(0, 21, 0, 28,"comment", Token::IDENTIFIER)
               );

    QTest::newRow("this is a */ partial comment ")
            << "this is a */ partial comment "
            << (
                TokenPList()
               << new Token(0,  0, 0,  4,"this", Token::IDENTIFIER)
               << new Token(0,  5, 0,  7,"is", Token::IDENTIFIER)
               << new Token(0,  8, 0,  9,"a", Token::IDENTIFIER)
               << new Token(0, 10, 0, 10,"", Token::COMMENTEND)
               << new Token(0, 13, 0, 20,"partial", Token::IDENTIFIER)
               << new Token(0, 21, 0, 28,"comment", Token::IDENTIFIER)
               );


    QTest::newRow("this is a /* */ partial /* comment ")
            << "this is a /* */ partial /* comment "
            << (
                TokenPList()
               << new Token(0, 0, 0, 4,"this", Token::IDENTIFIER)
               << new Token(0, 5, 0, 7,"is", Token::IDENTIFIER)
               << new Token(0, 8, 0, 9,"a", Token::IDENTIFIER)
               << new Token(0, 10, 0, 15,"/* */", Token::COMMENT)
               << new Token(0, 16, 0, 23,"partial", Token::IDENTIFIER)
               << new Token(0, 24, 0, 24,"", Token::COMMENTSTART)
               << new Token(0, 27, 0, 34,"comment", Token::IDENTIFIER)
               );




}

void TokenizerTest::testPartialMultiLineComments()
{
    Tokenizer tzr;
    QFETCH(QString, code);
    QFETCH(TokenPList, expected);

    TokenPList got = tzr.tokenize(code);
    QCOMPARE(expected.size(), got.size());
    for(int i = 0; i < got.size(); i++)
    {
        qDebug() << got[i]->toString();
        QCOMPARE(got[i]->type(), expected[i]->type());
        QCOMPARE(got[i]->text(), expected[i]->text());
        QCOMPARE(got[i]->startLine(), expected[i]->startLine());
        QCOMPARE(got[i]->endLine(), expected[i]->endLine());
        QCOMPARE(got[i]->startColumn(), expected[i]->startColumn());
        QCOMPARE(got[i]->endColumn(), expected[i]->endColumn());

    }

}
