#ifndef TOKENIZERTEST_H
#define TOKENIZERTEST_H

#include <QObject>

class TokenizerTest : public QObject
{
    Q_OBJECT

private slots:

    void testSimpleKeywords();
    void testSimpleSelect();
    void testNumbers();
    void testValidIdentifiers();
    void testInvalidIdentifiers();

    
};

#endif // TOKENIZERTEST_H
