#ifndef LINEEDITNUMBER_H
#define LINEEDITNUMBER_H

#include <QLineEdit>
#include <string>

using namespace std;

class LineEditNumber : public QLineEdit
{
public:
    explicit LineEditNumber(QLineEdit *parent = nullptr);

    bool in_type; // 0 for int, 1 for double
    bool isSpan; // Input is a span

    void checkInput();


};

#endif // LINEEDITNUMBER_H
