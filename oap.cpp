//
// Created by Марат Гасанов on 06.06.2022.
//
#include "Entity.hpp"
#define Z 0
#include "iostream"
#include "vector"
#include "assert.h"
using namespace std;

class Polygon{
private:
    vector<PTR<Line>> lines;
    vector<PTR<Point>> points;
    PTR<Plane> polygonPlane;
public:
    Polygon(vector<PTR<Point>> realPoints){
        for (int i = 0; i < realPoints.size(); ++i) {
            if (i > 2){
                if (!AngemUtils::isPointOnPlane(*polygonPlane, *realPoints[i])){
                    exit(1);
                }
            }
            if (i >= 1){
                PTR<Line> line(new LineByTwoPoints(realPoints[i], realPoints[i-1]));
                lines.push_back(line);
            }
            if (i == 2){
                polygonPlane = MAKEPTR<PlaneByThreePoints>(realPoints[i], realPoints[i-1], realPoints[i-2]);
            }
            points.push_back(realPoints[i]);
        }
        PTR<Line> line(new LineByTwoPoints(realPoints[realPoints.size()-1], realPoints[0]));
        lines.push_back(line);
    };

    bool isPointInRectangle(PTR<Point> point){
        if (!AngemUtils::isPointOnPlane(*polygonPlane, *point)) return false;
        PTR<Line> currLine;
        bool isXBigger;
        bool isYBigger;
        bool isZBigger;
        int intersectionNumber = 0;
        for (int i = 1; i < points.size(); ++i) {
            bool isFind = true;
            double currX = (points[i]->x + points[i-1]->x)/2;
            double currY = (points[i]->y + points[i-1]->y)/2;
            double currZ = (points[i]->z + points[i-1]->z)/2;
            PTR<Point> currPoint(new PointByCoords(currX, currY, currZ));
            currLine = MAKEPTR<LineByTwoPoints>(point, currPoint);
            for (int j = 0; j < points.size(); ++j) {
                if (AngemUtils::isPointOnLine(*currLine, *currPoint)){
                    isFind = false;
                }
            }
            if (isFind) {
                isXBigger = (currX > point->x);
                isYBigger = (currY > point->y);
                isZBigger = (currZ > point->z);
                break;
            }
        }

        for (int i = 0; i < lines.size(); ++i) {
            AngemPoint pointIntersection = AngemUtils::linesIntersection(*currLine, *lines[i]);
            double maxX = std::max(lines[i]->point1->x, lines[i]->point2->x);
            double minX = std::min(lines[i]->point1->x, lines[i]->point2->x);

            double maxY = std::max(lines[i]->point1->y, lines[i]->point2->y);
            double minY = std::min(lines[i]->point1->y, lines[i]->point2->y);

            double maxZ = std::max(lines[i]->point1->z, lines[i]->point2->z);
            double minZ = std::min(lines[i]->point1->z, lines[i]->point2->z);

            if (pointIntersection.x >= minX && pointIntersection.x <= maxX && (pointIntersection.x > currLine->point1->x == isXBigger)){
                if (pointIntersection.y >= minY && pointIntersection.y <= maxY && (pointIntersection.y > currLine->point1->y == isYBigger) ){
                    if (pointIntersection.z >= minZ && pointIntersection.z <= maxZ && (pointIntersection.z > currLine->point1->z == isZBigger) ){
                        intersectionNumber++;
                    }
                }
            }
        }
        return (intersectionNumber%2 != 0);
    }
};

void test(){
    //Точки многоугольника
    vector<double> x = {1, 2, 1, 3, 5, 4, 3};
    vector<double> y = {1, 3, 4, 5, 3, 2, 3};

    //Тестовые точки
    vector<double> testX = {3, 1, 4, 3, 4, 2, 10};
    vector<double> testY = {1, 5, 3, 4, 6, 4, 10};

    //Тестовые результаты
    vector<bool> testResult = {false, false, true, true, false, true, false};
    vector<bool> expResult;

    vector<PTR<Point>> points;
    for (int i = 0; i < x.size(); ++i) {
        points.push_back(MAKEPTR<PointByCoords>(x[i], y[i], Z));
    }

    Polygon polygon(points);

    points = {};

    for (int i = 0; i < testX.size(); ++i) {
        points.push_back(MAKEPTR<PointByCoords>(testX[i], testY[i], Z));
        assert(polygon.isPointInRectangle(points[i]) == testResult[i]);
    }
}

int main(){
    test();
}
