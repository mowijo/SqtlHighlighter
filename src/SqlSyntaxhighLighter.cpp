#include "SqlSyntaxhighLighter.h"
#include <Token.h>
#include <Tokenizer.h>

#include <QDebug>
#include <QMap>

class SqlSyntaxhighLighterPrivate
{
public:

    QMap<Token::TYPE, QTextCharFormat*> formats;

    QTextCharFormat noformat;
    SqlSyntaxhighLighterPrivate()
    {
        QTextCharFormat *format;

        format = new QTextCharFormat;
        format->setForeground(QColor(0,128,0));
        format->setFontItalic(false);
        format->setFontWeight(QFont::Bold);
        formats[Token::KEYWORD] = format;

        format = new QTextCharFormat;
        format->setForeground(Qt::blue);
        format->setFontItalic(false);
        format->setFontWeight(QFont::Normal);
        formats[Token::SPECIAL] = format;

        format = new QTextCharFormat;
        format->setUnderlineColor(QColor(127,0,0));
        format->setUnderlineStyle(QTextCharFormat::WaveUnderline);
        formats[Token::FAILURE] = format;
        formats[Token::UNKNOWN] = format;


    }

};

SqlSyntaxhighLighter::SqlSyntaxhighLighter(QObject *parent) :
    QSyntaxHighlighter(parent)
{
    d = new SqlSyntaxhighLighterPrivate();
}

SqlSyntaxhighLighter::~SqlSyntaxhighLighter()
{
    delete d;
}

void SqlSyntaxhighLighter::highlightBlock(const QString &text)
{
    Tokenizer tzr;
    QList<Token*> tokens = tzr.tokenize(text);
    foreach(Token *t, tokens)
    {
        //QTextCharFormat *format = d->formats.value(t->type(), &d->noformat);
        //setFormat(t->startColumn(), t->text().length(), *format);

        qDebug() << t;
    }

}
