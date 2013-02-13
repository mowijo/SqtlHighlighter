#include "TokenizerTest.h"
#include "Token.h"
#include "Tokenizer.h"
#include <QtTest/QtTest>

#include <QDebug>

void TokenizerTest::testSimpleKeywords()
{
    Tokenizer tzr;
    tzr.addRule("FOR", 0);
    tzr.addRule("IF", 1);
    tzr.addRule("WHEN", 2);
    QList<Token *> got = tzr.tokenize("\t   FOR IF\t \t \n \n WHEN WHEN WHEN   ");
    QList<Token *> expected;
    expected << new Token(0,4,0,6,"FOR",0);
    expected << new Token(0,8,0,9,"IF",1);
    expected << new Token(2,1,2,4,"WHEN",2);
    expected << new Token(2,6,2,9,"WHEN",2);
    expected << new Token(2,11,2,14,"WHEN",2);

    QCOMPARE(tzr.wasSuccessFull(), true);
    QCOMPARE(expected.size(), got.size());
    if(expected.size() == got.size())
    {
        for(int i = 0; i < got.size(); i++)
        {
            QCOMPARE(*got[i] == *expected[i], true);
        }
    }
}

void TokenizerTest::testUnmatched()
{
    Tokenizer tzr;
    tzr.addRule("FOR", 0);
    tzr.addRule("IF", 1);
    tzr.addRule("WHEN", 2);
    tzr.tokenize("\t   FOR IF\t \t \n \n WHEN WHEN WHEN  WHEn WHEN WHEN WHEN WHEN WHEN WHEN WHEN WHEN  ");
    QCOMPARE(tzr.wasSuccessFull(), false);
    Token unmatched = tzr.unmatched();
    QCOMPARE(unmatched.text().startsWith("WHEn WHEN WHEN"), true);
    QCOMPARE(unmatched.startLine(), 2);
    QCOMPARE(unmatched.startColumn(), 17);
    QCOMPARE(unmatched.type(), -1);


}
