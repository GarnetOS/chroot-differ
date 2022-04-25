#include <QCoreApplication>
#include <QDirIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> ql;

    QDirIterator it(".", QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())

        ql.append(it.next());

    QList<QString> ql2;

    QDirIterator it2(".", QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);
    while (it2.hasNext())

        ql2.append(it2.next());
    QList<QString> values;

    foreach (QString s1, ql)
    {
       qDebug() << s1;
       foreach (QString s2, ql2)
       {
           qDebug()<< s2;
           if (s1==s2)
           {
               values.append(s1);
               continue;
           }
       }
    }

    return a.exec();
}
