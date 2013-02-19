#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QList>
#include <QDebug>

class Token
{

public:


    enum TYPE
    {
        KEYWORD,
        SPECIAL,
        GREEDYCOMMENT,
        COMMENT,
        COMMENTSTART,
        COMMENTEND,
        NUMBER,
        STRING,
        IDENTIFIER,
        FAILURE,
        UNKNOWN
    };

    Token();
    Token(int startline, int startcolumn, int endline, int endcolumn, QString text, TYPE type = Token::UNKNOWN);
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
    void setType(TYPE type);

    int startLine() const;
    int endLine() const;
    int startColumn() const;
    int endColumn() const;
    QString text() const;
    TYPE type() const;

    QString toString() const;

private:
	class TokenPrivate *d;
	friend class TokenPrivate;

};

QDebug & operator<<(QDebug &dbg, const Token &t);
QDebug & operator<<(QDebug &dbg, Token *t);

typedef QList<Token*> TokenPList;

Q_DECLARE_METATYPE(Token)
Q_DECLARE_METATYPE(TokenPList)



#endif /* TOKEN_H */
