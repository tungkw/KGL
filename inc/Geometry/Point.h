#ifndef __KGL_POINT_CLOUD_SURFEL_H
#define __KGL_POINT_CLOUD_SURFEL_H

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <map>
#include <vector>

#include "Object.h"
#include "Vertice.h"


namespace kgl
{


class PointCloudSurfel
    : public Object<kgl::NormalVertice>
{

public:
    PointCloudSurfel(std::string file_name)
    {
        num_vertex = 0;
        num_primitives = 0;
        
        std::ifstream file;
        file.open(file_name);

        std::string word;
        file >> word >> num_vertex;
        this->num_primitives = this->num_vertex;

        kgl::NormalVertice vertice;
        for (int i = 0 ; i < this->num_vertex; i++)
        {
            file >> word >> vertice.pos.x() >> vertice.pos.y() >> vertice.pos.z();
            this->vertex.push_back(vertice);
            this->primitives.push_back(i);
        }
        for (int i = 0 ; i < this->num_vertex; i++)
        {
            file >> word >> this->vertex[i].normal.x() >> this->vertex[i].normal.y() >> this->vertex[i].normal.z();
        }
        for (int i = 0 ; i < this->num_vertex; i++)
        {
            file >> word >> this->vertex[i].color.x() >> this->vertex[i].color.y() >> this->vertex[i].color.z();
            this->vertex[i].color.w() = 1;
        }


        // for (int i = 0 ; i < this->num_vertex; i++)
        // {
        //     std::cout << "======" << std::endl;
        //     std::cout << this->vertex[i].pos.transpose() << std::endl;
        //     std::cout << this->vertex[i].normal.transpose() << " " << this->vertex[i].normal.norm() << std::endl;
        //     std::cout << this->vertex[i].color.transpose() << std::endl;
        // }
    }
};


}

#endif