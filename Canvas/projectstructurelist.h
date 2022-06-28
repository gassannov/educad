#ifndef PROJECTSTRUCTURELIST_H
#define PROJECTSTRUCTURELIST_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <vector>
#include "contextedit.h"

using namespace std;

class ProjectStructureList : public QTreeWidget
{
private:
    QTreeWidgetItem* kingItem;
    QTreeWidget* treeWidget;
    QTreeWidgetItem* planeXYStruct;
    QTreeWidgetItem* planeXZStruct;
    QTreeWidgetItem* objectsStruct;
    vector <QTreeWidgetItem*> userPlanesStruct;
    vector <QTreeWidgetItem*> objects;
    QFont font;
private:
    PointContextEdit pointRMB;
    LineContextEdit lineRMB;
public:
    QFrame* structureWidget;
    void clear ();
    ProjectStructureList();
    int addNewPlaneToStructure();
    void addObjectToStructure (QString objName, std::string objType);
    void addPointCoords (QString pointName, int x, int y, int z);
    void addLineCoords (QString lineName, int x1, int y1, int z1, int x2, int y2, int z2);
    void addObjectDependency (std::string objType,QString objName, QString dependency);
    int addPointToXYPlaneStructure (QString pointName);
    int addPointToXZPlaneStructure (QString pointName);
    int addPlaneToXYPlaneStructure (QString planeName);
    int addPlaneToXZPlaneStructure (QString planeName);
    int addPointToUserPlaneStructure ();
    int addLineToXYPlaneStructure (QString lineName);
    int addLineToXZPlaneStructure (QString lineName);
    int addLineToUserPlaneStructure ();
    int removePointFromXYPlaneStructure (QString pointName);
    int removePointFromXZPlaneStructure (QString pointName);
    int removePointFromUserPlaneStructure ();
    int removeLineFromXYPlaneStructure (QString lineName);
    int removeLineFromXZPlaneStructure (QString lineName);
    int removeLineFromUserPlaneStructure ();
    int removePlaneFromStructure ();
private slots:
    void onItemSelected(QTreeWidgetItem *item, int );
};

#endif // PROJECTSTRUCTURELIST_H

