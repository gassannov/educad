#include "CoordinateInputDialog.h"

CoordinateInputDialog::CoordinateInputDialog(QWidget *parent) {
    QBoxLayout *layout = new QHBoxLayout;
    auto intValidator = new QIntValidator (0, 100, this);
    xEdit = new QLineEdit;
    xEdit->setPlaceholderText("X");
    xEdit->setValidator(intValidator);
    yEdit = new QLineEdit;
    yEdit->setPlaceholderText("Y");
    yEdit->setValidator(intValidator);
    zEdit = new QLineEdit;
    zEdit->setPlaceholderText("Z");
    zEdit->setValidator(intValidator);
    text = new QLineEdit;
    text->setPlaceholderText("name");
    auto message = new QLabel("Координаты точки: ");
    layout->addWidget(text);
    layout->addWidget(message);
    layout->addWidget(xEdit);
    layout->addWidget(yEdit);
    layout->addWidget(zEdit);
    okBtn = new QPushButton("OK");
    okBtn->setDisabled(true);
    connect(okBtn, SIGNAL(clicked()), SLOT(accept()));
    connect(xEdit, SIGNAL(textChanged(const QString &)), SLOT (checkInput()));
    connect(yEdit, SIGNAL(textChanged(const QString &)), SLOT (checkInput()));
    connect(zEdit, SIGNAL(textChanged(const QString &)), SLOT (checkInput()));
    layout->addWidget(okBtn);
    setLayout(layout);
}

std::tuple<int, int, int, std::string> CoordinateInputDialog::getInput() const {
    return std::tuple<int, int, int, std::string>(xEdit->text().toInt(), yEdit->text().toInt(), zEdit->text().toInt(), text->text().toStdString());
}

void CoordinateInputDialog::checkInput() {
    if (!xEdit->text().isEmpty()) {
        if ((!yEdit->text().isEmpty()) || (!zEdit->text().isEmpty()))
            okBtn->setEnabled(true);
        else
            okBtn->setDisabled(true);
    } else
        okBtn->setDisabled(true);

    }
