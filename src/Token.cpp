#include "Token.h"

class TokenPrivate
{

private:
	Token *p;

public:

    int startline;
    int endline;
    int startcolumn;
    int endcolumn;
    QString text;
    int type;


    TokenPrivate(Token *parent)
	{
		p = parent;
        startline = 0;
        startcolumn = 0;
        endline = 0;
        endcolumn = 0;
        type = 0;
	}

    void copy(TokenPrivate *other)
    {
        this->startline = other->startline;
        this->endline = other->endline;
        this->startcolumn = other->startcolumn;
        this->endcolumn = other->endcolumn;
        this->text = other->text;
        this->type = other->type;
    }

    bool equals(TokenPrivate *other)
    {
        if(this->startline != other->startline)return false;
        if(this->endline != other->endline)return false;
        if(this->startcolumn != other->startcolumn)return false;
        if(this->endcolumn != other->endcolumn)return false;
        if(this->text != other->text)return false;
        if(this->type != other->type)return false;
        return true;
    }

};

Token::Token()
{
    d = new TokenPrivate(this);
}

Token::Token(int startline, int startcolumn, int endline, int endcolumn, QString text, int type)
{
    d = new TokenPrivate(this);
    d->startline = startline;
    d->startcolumn = startcolumn;
    d->endline = endline;
    d->endcolumn = endcolumn;
    d->text = text;
    d->type = type;
}

Token::Token(const Token&other)
{
    d = new TokenPrivate(this);
    d->copy(other.d);
}

Token& Token::operator=(const Token &other)
{
    if(this == &other) return *this;
    d->copy(other.d);
    return *this;
}

Token::~Token()
{
    delete d;
}

void Token::setStartLine(int sl)
{
    d->startline = sl;
}

int Token::type() const
{
    return d->type;
}

QString Token::text() const
{
    return d->text;
}

int Token::endColumn() const
{
    return d->endcolumn;
}

int Token::startColumn() const
{
    return d->startcolumn;
}

int Token::endLine() const
{
    return d->endline;
}

int Token::startLine() const
{
    return d->startline;
}

void Token::setType(int type)
{
    d->type = type;
}

void Token::setText(const QString &text)
{
    d->text = text;
}

void Token::setEndColumn(int ec)
{
    d->endcolumn = ec;
}

void Token::setStartColumn(int sc)
{
    d->startcolumn = sc;
}

void Token::setEndLine(int el)
{
    d->endline = el;
}



bool Token::operator==(const Token& rhs)
{
    return this->d->equals(rhs.d);
}

bool Token::operator !=(const Token &rhs)
{
    return !this->d->equals(rhs.d);
}
