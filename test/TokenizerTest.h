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

    void testMultiLineComments();
    void testMultiLineComments_data();

    void testPartialMultiLineComments_data();
    void testPartialMultiLineComments();

    void testGreedyComments();
    void testGreedyComments_data();

    
};

#endif // TOKENIZERTEST_H
