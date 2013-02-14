#ifndef TOKENIZERTEST_H
#define TOKENIZERTEST_H

#include <QObject>

class TokenizerTest : public QObject
{
    Q_OBJECT

private slots:

    void testSimpleKeywords();
    void testSimpleSelect();
    
};

#endif // TOKENIZERTEST_H
