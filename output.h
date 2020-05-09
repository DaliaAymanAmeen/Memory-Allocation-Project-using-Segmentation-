#ifndef OUTPUT_H
#define OUTPUT_H

#include <QDialog>

namespace Ui {
class output;
}

class output : public QDialog
{
    Q_OBJECT

public:
    explicit output(QWidget *parent = nullptr);
    ~output();

private:
    Ui::output *ui;
};

#endif // OUTPUT_H
