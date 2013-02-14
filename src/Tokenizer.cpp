#include "Tokenizer.h"

#include <QPair>
#include "Token.h"

#include <sqllexer>

typedef QPair<QString, int> Rule ;

class TokenizerPrivate
{

private:
    Tokenizer *p;

public:

    bool success;
    QString errormessage;

    TokenizerPrivate(Tokenizer *parent)
    {
        p = parent;
    }

    Token * createToken(quex::Token *st)
    {
        Token *t  =  new Token();
        t->setText(QString::fromUtf8((const char*)st->get_text().c_str()));
        t->setStartColumn(st->column_number()-1);
        t->setStartLine(st->line_number()-1);
        t->setEndColumn(st->column_number()-1+t->text().length());
        t->setEndLine(st->line_number()-1);
        switch(st->type_id())
        {
        case QUEX_TKN_FAILURE: t->setType(Token::FAILURE); break;
        case QUEX_TKN_IDENTIFIER: t->setType(Token::IDENTIFIER); break;
        case QUEX_TKN_NUMBER: t->setType(Token::NUMBER); break;
        default: t->setType(Token::UNKNOWN); break;
        }

        QString tokentype = QString::fromStdString(st->type_id_name());

        if(tokentype.startsWith("KEYWORD_"))
        {
            t->setType(Token::KEYWORD);
        }
        if(tokentype.startsWith("SPECIAL_"))
        {
            t->setType(Token::SPECIAL);
        }


        return t;
    }

};

Tokenizer::Tokenizer()
{
    d = new TokenizerPrivate(this);
}

Tokenizer::~Tokenizer()
{
    delete d;
}

QList<Token *> Tokenizer::tokenize(const QString &source)
{
    QList<Token*> tokens;
    QString s(source);

    quex::Token*       token_p = 0x0;
    d->success = false;
    try {

        QUEX_TYPE_CHARACTER *text = (QUEX_TYPE_CHARACTER*)malloc(s.toUtf8().length());
        quex::sqllexer   qlex(text, s.toUtf8().length(), text);
        qlex.buffer_fill_region_prepare();

        int WIERDCONSTANT = 1; //This plus 1 is strange but needed to remedy a friggin offset.

        memcpy(text+WIERDCONSTANT, s.toUtf8().data(), sizeof(QUEX_TYPE_CHARACTER)*s.size()+WIERDCONSTANT);
        int receive_n = sizeof(QUEX_TYPE_CHARACTER)*s.size()+WIERDCONSTANT;
        qlex.buffer_fill_region_finish(receive_n);

        do {
            qlex.receive(&token_p);       // --token-policy queue

            if(token_p->type_id() != QUEX_TKN_TERMINATION )
            {
                tokens << d->createToken(token_p);
            }

        } while( token_p->type_id() != QUEX_TKN_TERMINATION );
        delete text;
    }
    catch(std::runtime_error e)
    {
        d->success = false;
        d->errormessage = QString::fromStdString(e.what());
    }

    d->success = true;
    return tokens;
}

bool Tokenizer::wasSuccessFull() const
{
    return d->success;
}

QString Tokenizer::errormessage() const
{
    return d->errormessage;
}



