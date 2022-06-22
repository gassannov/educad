//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_POINT_H
#define EDUCAD_POINT_H
#include "Entity.h"
#include "Angem.hpp"

class Point : public Entity, public AngemPoint {
public:
    std::string type() const {return "point";};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane) override;
    PTR<Point> getProjectionOnLine(const PTR<Line>& line);
    PTR<Point> getProjectionOnPlane(const PTR<Plane>& plane);
    PTR<TwoDPoint> getProjectionPoint(const PTR<ProjectionPlane>& projectionPlane);
    double getDistance(PTR<Point> point);
};

class PointByCoords : public Point {
public:
    void update() {};
    PointByCoords(double x, double y, double z);
    std::vector<PTR<Entity> > getParents() const {return {};} ;
};

class PointOnLine : public Point{
public:
    void update() ;
    PointOnLine(PTR<Line> line, double* x, double* y, double* z);
    std::vector<PTR<Entity> > getParents() const;
    PTR<Line> line;
};

class PointOnPlane : public Point{
public:
    PointOnPlane(PTR<Plane> plane, double* x, double* y, double* z);
    std::vector<PTR<Entity> > getParents() const;
    PTR<Plane> plane;
    void update() ;
};

class PointByLinesIntersection : public Point {
private:
    PTR<Line> first;
    PTR<Line> second;
public:
    void update() ;
    PointByLinesIntersection(const PTR<Line>& first, const PTR<Line>& second);
    std::vector<PTR<Entity> > getParents() const;
};

#endif //EDUCAD_POINT_H
