//
// Created by Muhammed Ahad on 2018-10-27.
//


#include <iostream>
#include "GeometricPrimitive.hpp"

GeometricPrimitive::GeometricPrimitive(const Shape *shape) : shape(shape){
}

bool GeometricPrimitive::intersect(const Ray &ray, SurfaceInteraction *isect) const {
    float tHit;
    if(!shape->intersect(ray, &tHit, isect)){
        return false;
    }
    ray.tMax = tHit;
    isect->primitive = this;

    return true;
}

bool GeometricPrimitive::intersect(const Ray &ray, float *t, SurfaceInteraction *isect) const {
    float tHit;
    if(!shape->intersect(ray, &tHit, isect)){
        return false;
    }
    ray.tMax = tHit;
    isect->primitive = this;

    *t = ray.tMax;

    return true;
}

bool GeometricPrimitive::intersectP(const Ray &ray) const {
    std::cout << "GeometricPrimitive::intersectP(const Ray &ray) const, has not implemented yet..." << std::endl;

    return false;
}