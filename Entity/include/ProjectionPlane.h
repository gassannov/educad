//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_PROJECTIONPLANE_H
#define EDUCAD_PROJECTIONPLANE_H
#include "Entity.h"

//ProjectionPlane
class ProjectionPlane : public Plane {
//private:
public:
    std::set<PTR<TwoDEntity> > projected;
    PTR<Point> originPoint;
    PTR<Line> absciss;
    PTR<Line> ordinat;

//public:
    ProjectionPlane(const PTR<Plane>& plane);
    ProjectionPlane(double A, double B, double C, double D);
    std::string planeType() const {return "projectionPlane";}
    void add(PTR<TwoDEntity> object) {projected.insert(object);}
    void erase(PTR<TwoDEntity> object){projected.erase(object);}
    void update() override{};
    std::vector<PTR<Entity> > getParents() const {return {};}
    PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane){};
};

#endif //EDUCAD_PROJECTIONPLANE_H
