#ifndef TOOLBAR_H
#define TOOLBAR_H


#include "QMessageBox"
#include "QDialogButtonBox"
#include <QWidget>
#include <QPushButton>
#include "QStylePainter"
#include "QMainWindow"
#include "canvas.h"
#include "QObject"
#include "QComboBox"
#include "CoordinateInputDialog.h"

class LineComboBox : public QComboBox {
public:
    void showPopup (int x, int y);
};

class PointComboBox : public QComboBox {
public:
    void showPopup (int x, int y);
};

class ToolBar : public QObject
{
   QMessageBox* clearAll;
    QPushButton* newProjectButton;
    QPushButton* saveProjectButton;
    QPushButton* openProjectButton;
    QPushButton* createPointButton;
    QPushButton* createLineButton;
    QPushButton* createProjectionPlaneButton;
    QPushButton* resizeButton;
    QPushButton* eraseButton;
    QPushButton* cursorButton;
    LineComboBox* lineMethod;
    PointComboBox* pointMethod;
    QWidget *parentWidget;
    Canvas* canvas;
public:
    ToolBar(QWidget *parent, Canvas* _canvas);
    QFrame* toolBarWidget;
private slots:
    void newProjectButtonHandler();
    void saveProjectButtonHandler();
    void openProjectButtonHander ();
    void createPointButtonHandler ();
    void createLineButtonHandler ();
    void cursorButtonHandler ();
    void createProjectionPlaneButtonHandler ();
    void resizeButtonHandler();
    void eraseButtonHandler();
    void onPointIndexChanged(int index);
};



#endif // TOOLBAR_H
