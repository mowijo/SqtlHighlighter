 #ifndef TOKENTEST_H
 #define TOKENTEST_H
 
 
 #include <QObject>
 
 class TokenTest : public QObject
 {
 
 Q_OBJECT

 private slots:
     void testConstructors();
     void testComparison();

 };
 
#endif /* TOKENTEST_H */
 
