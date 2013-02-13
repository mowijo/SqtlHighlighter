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
    Token unmatched();

    void addRule(QString expression, int type);
    void deleteRules();


private:
	class TokenizerPrivate *d;
	friend class TokenizerPrivate;
    Tokenizer(const Tokenizer &other);
    Tokenizer& operator=(const Tokenizer &other);

};

#endif /* TOKENIZER_H */
