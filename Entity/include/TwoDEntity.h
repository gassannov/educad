//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_TWODENTITY_H
#define EDUCAD_TWODENTITY_H
#include "Entity.h"

class TwoDEntity{
public:
    PTR<Renderable> renderable;
    PTR<ProjectionPlane> projectionPlane;
    PTR<Entity> projectedEntity;
    virtual void render(std::string) = 0;
    virtual void deleteFromRender() = 0;
    void setRenderable(PTR<Renderable> renderable_);
    virtual void setProjected(PTR<Entity> projected){projectedEntity = projected;}
    virtual void setProjectionPlane(PTR<ProjectionPlane> projectionPlane_){projectionPlane = projectionPlane_;}
    virtual PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) = 0;
};

#endif //EDUCAD_TWODENTITY_H
