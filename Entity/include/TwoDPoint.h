//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_TWODPOINT_H
#define EDUCAD_TWODPOINT_H
#include "Entity.h"

class TwoDPoint : public TwoDEntity{
public:
    double X;
    double Y;
    TwoDPoint(double x, double y, PTR<ProjectionPlane> plane);
    void render(std::string);
    void deleteFromRender();

    PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) override;
};

#endif //EDUCAD_TWODPOINT_H
