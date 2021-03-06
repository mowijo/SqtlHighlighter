#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QList>

class Token;

class Tokenizer
{

public:
	Tokenizer();
	~Tokenizer();

    QList<Token*> tokenize(const QString &text);
    QList<Token*> m_tokenize(const QString &text);

    bool wasSuccessFull() const;
    QString errormessage() const;

private:
	class TokenizerPrivate *d;
	friend class TokenizerPrivate;
    Tokenizer(const Tokenizer &other);
    Tokenizer& operator=(const Tokenizer &other);

};

#endif /* TOKENIZER_H */
