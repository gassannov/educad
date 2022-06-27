#ifndef EDUCAD_COORDINATEINPUTDIALOG_H
#define EDUCAD_COORDINATEINPUTDIALOG_H

#include "QDialog"
#include "QObject"
#include "QLineEdit"
#include "QBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "QInputMethodEvent"
#include "QInputEvent"
#include "QIntValidator"

class CoordinateInputDialog : public QDialog {
Q_OBJECT
public:
    CoordinateInputDialog( QWidget* parent = nullptr);
    ~CoordinateInputDialog() {}
    std::tuple<int,int,int,std::string> getInput() const;
signals:
    void applied();
private:
    QPushButton* okBtn;
    QLineEdit *xEdit;
    QLineEdit *yEdit;
    QLineEdit *zEdit;
    QLineEdit* text;
private slots:
    void checkInput();
};


#endif //EDUCAD_COORDINATEINPUTDIALOG_H
