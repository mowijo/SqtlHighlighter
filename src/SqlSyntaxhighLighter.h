#ifndef SQLSYNTAXHIGHLIGHTER_H
#define SQLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

#include <qglobal.h>

class SqlSyntaxhighLighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit SqlSyntaxhighLighter(QObject *parent);

    ~SqlSyntaxhighLighter();

protected:
     void highlightBlock(const QString &text);
    
private:
     class SqlSyntaxhighLighterPrivate *d;
     SqlSyntaxhighLighter(const SqlSyntaxhighLighter &other );
     SqlSyntaxhighLighter& operator=(const SqlSyntaxhighLighter &other);

};

#endif // SQLSYNTAXHIGHLIGHTER_H
