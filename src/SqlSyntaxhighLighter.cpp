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
        //format->setForeground(QColor(128,64,0));
        format->setForeground(QColor(255,0,0));
        format->setBackground(Qt::black);
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

    //Now. Since we are allowed to highlight one chunk at a time and that chunk may contain
    // Mulitline-comment-start or -end without the matchins end/start we need to keep track
    //of how far we have gotten in a multiline comment and wether it is being started or ended
    //in the current block.
    QPoint commentend(-1,-1);   //We use x for line and y for column
    QPoint commentstart(-1,-1); //We use x for line and y for column
    foreach(Token *t, tokens)
    {
        QTextCharFormat *format = d->formats.value(t->type(), &d->noformat);
        if(t->type() == Token::COMMENTSTART)
        {
            commentstart.setX(t->startLine());
            commentstart.setY(t->startColumn());
        }
        if(t->type() == Token::COMMENTEND)
        {
            commentend.setX(t->endLine());
            commentend.setY(t->endColumn());
        }
        setFormat(t->startColumn(), t->text().length(), *format);
    }
}
