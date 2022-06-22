//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_LINE_H
#define EDUCAD_LINE_H
#include "Angem.hpp"
#include "string"
#include "Entity.h"

class Point;
class Plane;

class Line : public Entity, public AngemLine {
public:
    std::string type() const {return "line";};
    PTR<Point> point1;
    PTR<Point> point2;
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    PTR<TwoDLine> getProjectionLine(PTR<ProjectionPlane> projectionPlane);
};

class LineByTwoPoints : public Line {
private:
    PTR<Point> first;
    PTR<Point> second;
public:
    void update() ;
    LineByTwoPoints();
    LineByTwoPoints(PTR<Point> first, PTR<Point> second);
    std::vector<PTR<Entity> > getParents() const;
};

class LineByParallel : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
    void setPoints(AngemPoint point1, AngemPoint point2);
public:
    void update() ;
    LineByParallel();
    std::vector<PTR<Entity> > getParents() const;
    LineByParallel(const PTR<Point>& first, const PTR<Line>& second);
};

class LineByPerpendicular : public Line {
private:
    PTR<Point> point;
    PTR<Line> line;
public:
    void update() ;
    LineByPerpendicular();
    std::vector<PTR<Entity> > getParents() const;
    LineByPerpendicular(const PTR<Point>& point, const PTR<Line>& line);
};

class LineByPlanesIntersection : public Line {
private:
    PTR<Plane> first;
    PTR<Plane> second;
public:
    void update() ;
    LineByPlanesIntersection();
    LineByPlanesIntersection(PTR<Plane> first, PTR<Plane> second);
    std::vector<PTR<Entity> > getParents() const;
};

class LineByParametres: public Line{
public:
    LineByParametres(double i, double j, double k, double x0, double y0, double z0);
    void update(){};
    std::vector<PTR<Entity> > getParents() const;
};

#include "Point.h"
#include "Plane.h"

#endif //EDUCAD_LINE_H
