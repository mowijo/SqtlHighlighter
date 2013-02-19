#include <QtGui>
#include <SqlSyntaxhighLighter.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPlainTextEdit qte;
    qte.setFont(QFont("courier"));
    SqlSyntaxhighLighter shl;
    shl.setDocument(qte.document());
    qte.show();

    return a.exec();

}
