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

    enum STATES
    {
        INSIDECOMMENT = 1,
        OUTSIDECOMMENT

    };

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

    //First we apply the styles for everything as if there was no issue with multi block
    //comments. We do, however, remember if we encounter a start or end of a comment.
    foreach(Token *t, tokens)
    {
        qDebug() << t->toString();
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

    if(commentstart.x() > -1)
    {
        qDebug() << "A comment starts on " << commentstart.y();
        setFormat(commentstart.y(), text.length()-commentstart.y(), *d->formats[Token::COMMENT]);
        setCurrentBlockState(SqlSyntaxhighLighterPrivate::INSIDECOMMENT);
    }
    if(commentend.x() > -1)
    {
        qDebug() << "A comment ends on " << commentstart.y();
        if(previousBlockState() == SqlSyntaxhighLighterPrivate::INSIDECOMMENT)
        {
            setFormat(0, commentend.y()+2, *d->formats[Token::COMMENT]);
        }
        else
        {
            setFormat(0, commentend.y()+2, *d->formats[Token::FAILURE]);
        }
        setCurrentBlockState(SqlSyntaxhighLighterPrivate::OUTSIDECOMMENT);
    }
    else if(previousBlockState() == SqlSyntaxhighLighterPrivate::INSIDECOMMENT)
    {
        setFormat(0, text.length(), *d->formats[Token::COMMENT]);
        setCurrentBlockState(SqlSyntaxhighLighterPrivate::INSIDECOMMENT);
    }
    else
    {
        setCurrentBlockState(SqlSyntaxhighLighterPrivate::OUTSIDECOMMENT);
        //Do nothing.
    }

}
