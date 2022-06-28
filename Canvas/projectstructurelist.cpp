#include "projectstructurelist.h"
#include "QString"
#include "string.h"
#include "iostream"
#include "QApplication"
#include "QScreen"
#include "iostream"
//#include "QDesktopWidget"
#include "QFont"
using namespace std;

ProjectStructureList::ProjectStructureList() {
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int height = rec.height()*9/10;
    int width = rec.width();
    structureWidget = new QFrame ();
    font = QFont("Times", 16);
    treeWidget = new QTreeWidget (structureWidget);
    treeWidget->setFont(font);
    treeWidget->setHeaderLabel("Структура проекта");
    setColumnCount(1);
    kingItem = new QTreeWidgetItem();
    kingItem->setFont(0, font);
    planeXYStruct = new QTreeWidgetItem();
    planeXZStruct = new QTreeWidgetItem();
    objectsStruct = new QTreeWidgetItem();
    planeXYStruct->setFont(0,font);
    planeXZStruct->setFont(0, font);
    objectsStruct->setFont(0, font);
    planeXYStruct->setText(0, "Плоскость XY");
    planeXZStruct->setText(0, "Плоскость XZ");
    objectsStruct->setText(0, "Объекты");
    kingItem->setText(0, "Мой проект");
    treeWidget->addTopLevelItem(kingItem);
    kingItem->addChild(planeXYStruct);
    kingItem->addChild(planeXZStruct);
    kingItem->addChild(objectsStruct);
    structureWidget->setGeometry(QRect(0,height*556/10000,width/4,height));
    treeWidget->setGeometry(0,0,width/4-2,height);
    treeWidget->setFrameShape(QFrame::NoFrame);
    structureWidget->setFrameShape(QFrame::Box);
    structureWidget->setLineWidth(2);
    structureWidget->setMidLineWidth(1);
    connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)),
            SLOT(onItemSelected(QTreeWidgetItem*, int)));
}

void ProjectStructureList::clear () {
    for (int i=0; i<planeXYStruct->childCount(); i++) {
          planeXYStruct->removeChild(planeXYStruct->child(i));
    }
    for (int i=0; i<planeXZStruct->childCount(); i++) {
          planeXZStruct->removeChild(planeXZStruct->child(i));
    }
}

int ProjectStructureList::addNewPlaneToStructure() {
    QTreeWidgetItem* newPlaneStruct = new QTreeWidgetItem ();
  //  newPlaneStruct->setText(0, QString::fromStdString(plane.getPlaneName()));
    kingItem->addChild(newPlaneStruct);
    return 0;
}

int ifExistsOnPlane ( QTreeWidgetItem* planeStruct, QString objName, QString objType) {
    for (int i=0; i<planeStruct->childCount(); i++) {
        if (planeStruct->child(i)->text(0).contains(objType + objName)) return i;
    }
    return -1;
}

int ProjectStructureList::addPointToXYPlaneStructure (QString pointName) {
    if (ifExistsOnPlane(planeXYStruct, pointName, "Point ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0,"Point " + pointName + "\'");
        planeXYStruct->addChild(newPoint);
        planeXYStruct->child(planeXYStruct->childCount()-1)->setFont(0, font);
    }
    return 0;
}

int ProjectStructureList::addPointToXZPlaneStructure (QString pointName) {
     if (ifExistsOnPlane(planeXZStruct, pointName, "Point ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0, "Point " + pointName + "\'\'");
        planeXZStruct->addChild(newPoint);
        planeXZStruct->child(planeXZStruct->childCount()-1)->setFont(0, font);
     }
    return 0;
}

int ProjectStructureList::addLineToXYPlaneStructure (QString lineName) {
    if (ifExistsOnPlane(planeXYStruct, lineName, "Line ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0,"Line " + lineName + "\'");
        planeXYStruct->addChild(newPoint);
        planeXYStruct->child(planeXYStruct->childCount()-1)->setFont(0, font);
    }
    return 0;
}

int ProjectStructureList::addLineToXZPlaneStructure (QString lineName) {
     if (ifExistsOnPlane(planeXZStruct, lineName, "Line ")==-1) {
        QTreeWidgetItem* newPoint = new QTreeWidgetItem();
        newPoint->setText(0, "Line " + lineName + "\'\'");
        planeXZStruct->addChild(newPoint);
        planeXZStruct->child(planeXZStruct->childCount()-1)->setFont(0, font);
     }
    return 0;
}

int ProjectStructureList::removeLineFromXYPlaneStructure(QString lineName) {
    int index = ifExistsOnPlane(planeXYStruct, lineName, "Line ");
    if (index>=0) {
        QTreeWidgetItem* removableChild = planeXYStruct->child(index);
        planeXYStruct->removeChild(removableChild);
        delete removableChild;
    }
    return 0;
}

int ProjectStructureList::removeLineFromXZPlaneStructure(QString lineName) {
    int index = ifExistsOnPlane(planeXZStruct, lineName, "Line ");
    if (index>=0) {
        QTreeWidgetItem* removableChild = planeXZStruct->child(index);
        planeXZStruct->removeChild(removableChild);
        delete removableChild;
    }
    return 0;
}


int ProjectStructureList::removePointFromXYPlaneStructure(QString pointName) {
    int index = ifExistsOnPlane(planeXYStruct, pointName, "Point ");
    if (index>=0) {
        printf ("point found on XY index=%d\n", index);
        QTreeWidgetItem* removableChild = planeXYStruct->child(index);
        planeXYStruct->removeChild(removableChild);
        delete removableChild;
    }
    return 0;
}

int ProjectStructureList::removePointFromXZPlaneStructure(QString pointName) {
     printf ("\nenterted removing point\n");
    int index = ifExistsOnPlane(planeXZStruct, pointName, "Point ");
    if (index>=0) {
        printf ("point found on XZ index=%d\n", index);
        QTreeWidgetItem* removableChild = planeXZStruct->child(index);
        planeXZStruct->removeChild(removableChild);
        delete removableChild;
    }
    printf ("Finished XZ removing\n");
    return 0;
}

int ProjectStructureList::addPlaneToXYPlaneStructure(QString planeName) {
    if (ifExistsOnPlane(planeXYStruct, planeName, "Plane ")==-1) {
        QTreeWidgetItem* planePoint = new QTreeWidgetItem();
        planePoint->setText(0,"Plane " + planeName + "\'");
        planeXYStruct->addChild(planePoint);
        planeXYStruct->child(planeXYStruct->childCount()-1)->setFont(0, font);
    }
    return 0;
}

int ProjectStructureList::addPlaneToXZPlaneStructure(QString planeName) {
    if (ifExistsOnPlane(planeXZStruct, planeName, "Plane ")==-1) {
        QTreeWidgetItem* planePoint = new QTreeWidgetItem();
        planePoint->setText(0,"Plane " + planeName + "\'");
        planeXZStruct->addChild(planePoint);
        planeXZStruct->child(planeXZStruct->childCount()-1)->setFont(0, font);
    }
    return 0;
}

void ProjectStructureList::onItemSelected(QTreeWidgetItem *item, int) {
    std::string  text = item->text(0).toStdString();
    cout << text << endl;
}

void ProjectStructureList::addObjectToStructure(QString objName, std::string objType) {
    QTreeWidgetItem* objectItem = new QTreeWidgetItem();
    objectItem->setText(0,QString::fromStdString(objType) + " " + objName);
    objectsStruct->addChild(objectItem);
    objects.push_back(objectItem);
    objectsStruct->child(objectsStruct->childCount()-1)->setFont(0, font);
}

void ProjectStructureList::addPointCoords(QString pointName, int x, int y, int z) {
    QTreeWidgetItem* curr;
    for (auto obj: objects) {
        if (obj->text(0)=="Точка " + pointName) {
            curr=obj;
            break;
        }
    }
    std::string xCoord = to_string(x);
    std::string yCoord;
    std::string zCoord;
    if (y==-1) {
        yCoord = "-";
    } else yCoord = to_string(y);
    if (z==-1) {
        zCoord = "-";
    } else zCoord = to_string(z);
    QTreeWidgetItem* coordsItem = new QTreeWidgetItem();
    coordsItem->setText(0, "X: " + QString::fromStdString(xCoord) + " Y: " + QString::fromStdString(yCoord) + " Z: " + QString::fromStdString(zCoord));
    curr->addChild(coordsItem);
}

void ProjectStructureList::addLineCoords(QString lineName, int x1, int y1, int z1, int x2, int y2, int z2) {
    QTreeWidgetItem* curr;
    for (auto obj: objects) {
        if (obj->text(0)=="Линия " + lineName) {
            curr=obj;
            break;
        }
    }
    std::string x1Coord = to_string(x1); std::string x2Coord = to_string(x2);
    std::string y1Coord = to_string(y1); std::string y2Coord = to_string(y2);
    std::string z1Coord = to_string(z2); std::string z2Coord = to_string(z2);
    QTreeWidgetItem* coordsItem = new QTreeWidgetItem();
    coordsItem->setText(0, "X1: " + QString::fromStdString(x1Coord) + " Y1: " + QString::fromStdString(y1Coord) + " Z1: " + QString::fromStdString(z1Coord) + "\nX2: " + QString::fromStdString(x2Coord) + " Y2: " + QString::fromStdString(y2Coord) + " Z2: " + QString::fromStdString(z2Coord));
    curr->addChild(coordsItem);
}

void ProjectStructureList::addObjectDependency(std::string objType, QString lineName, QString dependency) {
    QTreeWidgetItem* curr;
    for (auto obj: objects) {
        if (obj->text(0)==(QString::fromStdString(objType) + lineName)) {
            curr=obj;
            break;
        }
    }
    QTreeWidgetItem* dependencyItem = new QTreeWidgetItem();
    dependencyItem->setText(0, dependency);
    curr->addChild(dependencyItem);
}





