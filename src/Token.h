#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QDebug>

class Token
{

public:
    Token();
    Token(int startline, int startcolumn, int endline, int endcolumn, QString text, int type);
	Token(const Token &other);
	Token& operator=(const Token &other);
	~Token();

    bool operator==(const Token& rhs);
    bool operator!=(const Token& rhs);

    void setStartLine(int sl);
    void setEndLine(int el);
    void setStartColumn(int sc);
    void setEndColumn(int ec);
    void setText(const QString &text);
    void setType(int type);

    int startLine() const;
    int endLine() const;
    int startColumn() const;
    int endColumn() const;
    QString text() const;
    int type() const;

private:
	class TokenPrivate *d;
	friend class TokenPrivate;

};

QDebug & operator<<(QDebug &dbg, const Token &t);
QDebug & operator<<(QDebug &dbg, Token *t);



#endif /* TOKEN_H */
