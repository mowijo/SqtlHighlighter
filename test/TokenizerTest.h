#ifndef TOKENIZERTEST_H
#define TOKENIZERTEST_H

#include <QObject>

class TokenizerTest : public QObject
{
    Q_OBJECT

private slots:

    void testUnmatched();
    void testSimpleKeywords();
    
};

#endif // TOKENIZERTEST_H
