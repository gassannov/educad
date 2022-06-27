//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_ENTITY_H
#define EDUCAD_ENTITY_H
#include "string"
#include "set"
#include "utils.h"
#include "polyset.h"

class ProjectionPlane;
class Plane;
class Line;
class Point;
class TwoDEntity;
class TwoDPoint;
class TwoDLine;
class Renderable;

class Entity {
public:
//private:
    std::set<PTR<ProjectionPlane> > projections;
    std::set<PTR<TwoDEntity>> twoDProjections;
    std::vector<PTR<Entity> > childrends;
//public:
    virtual void update() = 0;
    virtual PTR<TwoDEntity> getProjection(PTR<ProjectionPlane> projectionPlane) = 0;
    void addProjectionPlane(const PTR<ProjectionPlane>& plane){projections.insert(plane);}
    void deleteProjectionPlane(PTR<ProjectionPlane> plane){projections.erase(plane);}
    virtual std::string type() const = 0;
    virtual std::vector<PTR<Entity> > getParents() const = 0;
    std::vector<PTR<Entity> > getChildren() const{return childrends;}
    void addChildren(PTR<Entity> children){ childrends.push_back(children);};
};

#include "Point.h"
#include "Line.h"
#include "Plane.h"
#include "ProjectionPlane.h"
#include "TwoDEntity.h"
#include "TwoDPoint.h"
#include "TwoDLine.h"
#include "TwoDPlane.h"
#include "Renderable.h"

#endif //EDUCAD_ENTITY_H
