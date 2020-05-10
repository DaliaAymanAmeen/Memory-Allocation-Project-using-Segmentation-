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

private slots:
    void on_add_seg_clicked();

    void on_first_fit_clicked();

    void on_add_process_clicked();

    void on_Best_Fit_clicked();

private:
    Ui::output *ui;
};

#endif // OUTPUT_H
