//
// Created by Марат Гасанов on 20.06.2022.
//

#ifndef EDUCAD_TWODPLANE_H
#define EDUCAD_TWODPLANE_H
#include "Entity.h"

class TwoDPlane: public TwoDEntity{
private:
public:
    const PTR<TwoDLine> &getLine1() const;

private:
    PTR<TwoDLine> line1;
    PTR<TwoDLine> line2;
    PTR<TwoDPoint> point1;
    PTR<TwoDPoint> point2;
    PTR<TwoDPoint> point3;
public:
    TwoDPlane(PTR<TwoDLine> line1_, PTR<TwoDLine> line2_): line1(line1_), line2(line2_){};
    TwoDPlane(PTR<TwoDLine> line, PTR<TwoDPoint> point_) : line1(line), point1(point_){};
    TwoDPlane(PTR<TwoDPoint> point1_, PTR<TwoDPoint> point2_ , PTR<TwoDPoint> point3_): point1(point1_), point2(point2_), point3(point3_){};
    void render(std::string) override;
    void setProjected(PTR<Entity> entity);
//    void setProjectionPlane(PTR<ProjectionPlane> projectionPlane_){}
    void deleteFromRender() override;

    PTR<Entity> entityByTwoDEntity(PTR<TwoDEntity> secondProjection) override;;
};

#endif //EDUCAD_TWODPLANE_H
