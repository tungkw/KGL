// #ifndef __KGL_POINT_CLOUD_SURFEL_H
// #define __KGL_POINT_CLOUD_SURFEL_H

// #include <iostream>
// #include <string>
// #include <fstream>
// #include <queue>
// #include <map>
// #include <vector>

// #include "Object.h"
// #include "Vertice.h"


// namespace kgl
// {


// class PointCloudSurfel
//     : public Object<kgl::NormalVertice>
// {

// public:
//     PointCloudSurfel(std::string file_name)
//     {
//         num_vertex = 0;
//         num_primitives = 0;
        
//         std::ifstream file;
//         file.open(file_name);
        
//         std::stringstream line_stream;
//         std::string line, word;
//         std::vector<std::pair<std::string, int>> elements;
//         std::vector<int> num_elements_properties;
//         std::vector<std::pair<std::string, std::string>> properties;
//         while (std::getline(file, line))
//         {
//             std::stringstream line_stream(line);
//             line_stream >> word;
//             if (word == "end_header") break;
//             else if (word == "element") 
//             {
//                 std::string element;
//                 int num;
//                 line_stream >> element;
//                 line_stream >> num;
//                 elements.push_back(std::make_pair(element, num));
//                 num_elements_properties.push_back(0);
//             }
//             else if (word == "property")
//             {
//                 std::string property, data_type;
//                 line_stream >> property;
//                 if (IsDataType(property))
//                 {
//                     data_type = property;
//                     if (data_type == "list")
//                     {
//                         line_stream >> data_type >> data_type;
//                         data_type = "list_"+data_type;
//                     }
//                     line_stream >> property;
//                 }
//                 else
//                 {
//                     line_stream >> data_type;
//                 }
//                 properties.push_back(std::make_pair(property, data_type));
//                 num_elements_properties[elements.size()-1] += 1;
//             }
//         }

//         int k = 0;
//         for (int i = 0; i < elements.size(); i++)
//         {
//             std::cout << elements[i].first << " " << elements[i].second << std::endl;
//             for (int j = 0 ; j < num_elements_properties[i]; j++, k++)
//             {
//                 std::cout << "  " << properties[k].first << " " << properties[k].second << std::endl;
//             }
//         }
//     }
// };


// }

// #endif