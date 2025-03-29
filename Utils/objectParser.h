//
// Created by barti on 28.03.2025.
//

#ifndef RAYTRACER_OBJECTPARSER_H
#define RAYTRACER_OBJECTPARSER_H

#pragma once

#include "vec3.h"

#include "triangle.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace math;

class objectParser {
public:
  vector <vec3> vertices;
  vector <triangle> triangles;

  bool loadObj (const string& path){
      ifstream objFile(path);

      if(!objFile.is_open()) {
          cout << "Could not open file" << endl;
      }

      string line;
      while (getline (objFile, line)) {
          stringstream ss(line);
          string type;
          ss >> type;
          if(type == "v"){
              vec3 v;
              ss >> v.x >> v.y >> v.z;
              vertices.push_back(v);
          }
          else if(type=="f"){
              int v1, v2, v3;
              ss >> v1 >> v2 >> v3;
              triangle t(vertices[v1-1], vertices[v2-1], vertices[v3-1]);
              triangles.push_back(t);


          }
          
      }
      objFile.close();
      return true;
  }

};


#endif //RAYTRACER_OBJECTPARSER_H
