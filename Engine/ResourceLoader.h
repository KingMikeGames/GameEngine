#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Util.h"
#include "Mesh.h"
#include <iterator>

class ResourceLoader
{
public:
	static std::string loadShader(const std::string& fileName)
	{
		std::ifstream file;
		file.open("./res/shaders/" + fileName);

		std::string output;
		std::string line;

		if (file.is_open())
		{
			while (file.good())
			{
				getline(file, line);
				output.append(line + "\n");
			}
		}
		else
		{
			std::cerr << "Unable to load shader: " << fileName << std::endl;
		}

		return output;
	}

	static Mesh loadMesh(const std::string& fileName, Mesh& mesh)
	{
		/*Vertex data[] =
		{ Vertex(physx::PxVec3(-0.75, -1, -0.75)),
		Vertex(physx::PxVec3(0, 1, 0)),
		Vertex(physx::PxVec3(-0.75, -1, .75)),
		Vertex(physx::PxVec3(.75, -1, -.75)),
		Vertex(physx::PxVec3(.75, -1, .75)) };
		int indicess[] =
		{ 0, 1, 3,
		3, 1, 4,
		4, 1, 2,
		2, 1, 0 };
		mesh.addVertices(data, ARRAY_SIZE(data), indicess, ARRAY_SIZE(indicess));
		return Mesh();*/

		if (fileName.find(".obj") == std::string::npos)
			return Mesh();

		std::vector<Vertex> vertices;
		std::vector<int> indices;

		std::ifstream file;
		file.open("./res/models/" + fileName);

		std::string output;
		std::string line;

		if (file.is_open())
		{
			while (file.good())
			{
				getline(file, line);
				if (line.length() < 2) continue;

				std::istringstream buffer(line);
				std::vector<std::string> tokens((std::istream_iterator<std::string>(buffer)),
												std::istream_iterator<std::string>());

				switch (line.c_str()[0])
				{
				case 'v':
					vertices.push_back(Vertex(glm::vec3(
						std::atof(tokens[1].c_str()),
						std::atof(tokens[2].c_str()),
						std::atof(tokens[3].c_str()))));
					break;
				case 'f':
					indices.push_back(std::atof(tokens[1].c_str()) - 1);
					indices.push_back(std::atof(tokens[2].c_str()) - 1);
					indices.push_back(std::atof(tokens[3].c_str()) - 1);
					break;
				default:
					break;
				}
			}

			mesh.addVertices(&vertices.front(), vertices.size(), &indices.front(), indices.size());
			return Mesh();
		}
		else
		{
			std::cerr << "Unable to load shader: " << fileName << std::endl;
			return Mesh();
		}
	}
};