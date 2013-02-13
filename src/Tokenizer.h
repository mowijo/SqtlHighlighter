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
    bool wasSuccessFull() const;
    QString lastErrormessage() const;

    void addRule(QString expression, int type);


private:
	class TokenizerPrivate *d;
	friend class TokenizerPrivate;
    Tokenizer(const Tokenizer &other);
    Tokenizer& operator=(const Tokenizer &other);

};

#endif /* TOKENIZER_H */
