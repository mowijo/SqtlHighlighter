#include "Tokenizer.h"

#include <QPair>
#include "Token.h"


typedef QPair<QString, int> Rule ;

class TokenizerPrivate
{

private:
	Tokenizer *p;

public:

    bool success;
    QString errormessage;
    QList<Rule> rules;

    QString stack;
    int currentline;
    int currentcolumn;

    int startedline;
    int startedcolumn;

	TokenizerPrivate(Tokenizer *parent)
	{
		p = parent;
	}


    void addRule(QString rule, int type)
    {
        rules << Rule(rule, type);
    }


    void flushStack()
    {
        stack = "";
        startedline = currentline;
        startedcolumn = currentcolumn;
    }

    Token* matchRules()
    {
        Token *t = 0;
        if(stack == " " || stack == "\t" || stack == "\n")
        {
            if(stack.count("\n") > 0)
            {
                currentline += stack.count("\n");
                currentcolumn = 0;
            }
            flushStack();
        }

        foreach(Rule r, rules)
        {
            if(stack == r.first)
            {
                t = new Token();
                t->setStartLine(startedline);
                t->setEndLine(currentline);
                t->setStartColumn(startedcolumn);
                t->setEndColumn(currentcolumn);
                t->setText(stack);
                t->setType(r.second);
                flushStack();
                break;
            }
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

QList<Token *> Tokenizer::tokenize(const QString &text)
{
    QList<Token*> tokens;
    d->stack = "";
    d->currentline = 0;
    d->currentcolumn = 0;

    for(int i = 0; i < text.length(); i++)
    {
        d->stack += text[i];
        d->currentcolumn++;
        Token *t = d->matchRules();
        if(t)
        {
            tokens << t;
        }
    }
    if(d->stack != "")
    {
        Token *t = new Token();
        t->setText(d->stack);
        tokens << t;
    }
    return tokens;
}

bool Tokenizer::wasSuccessFull() const
{
    return d->success;
}

QString Tokenizer::lastErrormessage() const
{
    return d->errormessage;
}

void Tokenizer::addRule(QString expression, int type)
{
    d->addRule(expression, type);
}


