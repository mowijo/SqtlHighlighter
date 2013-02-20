#include "SqlSyntaxhighLighter.h"
#include <Token.h>
#include <Tokenizer.h>

#include <QDebug>
#include <QMap>

class SqlSyntaxhighLighterPrivate
{
public:

    Tokenizer tzr;
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

        format = new QTextCharFormat;
        format->setForeground(Qt::lightGray);
        formats[Token::COMMENT] = format;
        formats[Token::GREEDYCOMMENT] = format;


        format = new QTextCharFormat;
        format->setForeground(QColor(128,64,0));
        formats[Token::STRING] = format;
        formats[Token::NUMBER] = format;


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
    QList<Token*> tokens = d->tzr.tokenize(text+"\n");
    foreach(Token *t, tokens)
    {
        QTextCharFormat *format = d->formats.value(t->type(), &d->noformat);
        setFormat(t->startColumn(), t->text().length(), *format);
    }

}
