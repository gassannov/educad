//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_PLANE_H
#define EDUCAD_PLANE_H
#include "Entity.h"
#include "Angem.hpp"

// Planes
class Plane : public Entity, public AngemPlane {
public:
    std::string type() const {return "plane";};
    virtual std::string planeType() const = 0;
    double getA(){return A;}
    double getB(){return B;}
    double getC(){return C;}
    double getD(){return D;}
};

class PlaneByThreePoints : public Plane {
public:
    PTR<Point> first;
    PTR<Point> second;
    PTR<Point> third;
    std::string planeType() const {return "planeByThreePoints";};
    PlaneByThreePoints(PTR<Point> p1, PTR<Point> p2, PTR<Point> p3);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

class PlaneByPointAndLine : public Plane {
public:
    PTR<Point> point;
    PTR<Line> line;
    std::string planeType() const {return "planeByPointAndLine";};
    PlaneByPointAndLine(PTR<Point> p, PTR<Line> l);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

class PlaneByIntersectingLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    std::string planeType() const {return "planeByIntersectinLines";};
    void update(){};
    PlaneByIntersectingLines(PTR<Line> l, PTR<Line> l1);
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

class PlaneByParallelLines : public Plane {
public:
    PTR<Line> first;
    PTR<Line> second;
    std::string planeType() const {return "planeByParallelLines";};
    PlaneByParallelLines(PTR<Line> l, PTR<Line> l1);
    void update(){};
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane);
    std::vector<PTR<Entity> > getParents() const;
};

#endif //EDUCAD_PLANE_H
