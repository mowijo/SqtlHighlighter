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
    QList<Rule> rules;

    Token unmatched;
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
                t->setEndColumn(currentcolumn-1);
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
    d->startedcolumn = 0;
    d->startedline = 0;
    d->success = true;

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
        d->success = false;
        d->unmatched.setText(d->stack);
        d->unmatched.setStartColumn(d->startedcolumn);
        d->unmatched.setStartLine(d->startedline);
        d->unmatched.setEndColumn(d->currentcolumn-1);
        d->unmatched.setEndLine(d->currentline);
        d->unmatched.setType(-1);
    }
    return tokens;
}

bool Tokenizer::wasSuccessFull() const
{
    return d->success;
}

Token Tokenizer::unmatched()
{
    return d->unmatched;
}

void Tokenizer::addRule(QString expression, int type)
{
    d->addRule(expression, type);
}

void Tokenizer::deleteRules()
{
    d->rules.clear();
}


