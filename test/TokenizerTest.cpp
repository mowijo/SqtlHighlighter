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
    expected << new Token(0,4,0,7,"FOR",0);
    expected << new Token(0,8,0,10,"IF",0);
    expected << new Token(2,1,2,5,"WHEN",0);
    expected << new Token(2,6,2,10,"WHEN",0);
    expected << new Token(2,11,2,15,"WHEN",0);

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
