#pragma once
#include <vector>
#include "Point3D.h"
struct Point {
	float x, y, z;
};


class AssimpLoader
{
public:
	float** meshesArray = new float*[4];
	std::vector<Point3D*> meshVertexs;
	bool LoadModelFromFile(char* sFilePath);
	///bool LoadModelFromFileBumpMap(char* sFilePath, char* sColorMap, char* sNormalMap);

	//static void FinalizeVBO();
	//static void BindModelsVAO();

	void RenderModel();
	//void RenderModelBumpMap(CShaderProgram* spProgram);

private:
	bool bLoaded;
	//static CVertexBufferObject vboModelData;
	///static UINT uiVAO;
	//static std::vector<CTexture> tTextures;
	std::vector<int> iMeshStartIndices;
	std::vector<int> iMeshSizes;
	std::vector<int> iMaterialIndices;
	std::vector<std::vector<Point3D*>> meshes;
	int iNumMaterials;
};
/*

using namespace std;
class CAssimpModel
{
public:
	bool LoadModelFromFile(char* sFilePath);
	bool LoadModelFromFileBumpMap(char* sFilePath, char* sColorMap, char* sNormalMap);

	static void FinalizeVBO();
	static void BindModelsVAO();

	void RenderModel();
	void RenderModelBumpMap(CShaderProgram* spProgram);

	CAssimpModel();
private:
	bool bLoaded;
	static CVertexBufferObject vboModelData;
	static UINT uiVAO;
	static vector<CTexture> tTextures;
	vector<int> iMeshStartIndices;
	vector<int> iMeshSizes;
	vector<int> iMaterialIndices;
	int iNumMaterials;
};*/