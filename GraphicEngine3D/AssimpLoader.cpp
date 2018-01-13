#include "AssimpLoader.h"
#include "Engine3D.h"
bool AssimpLoader::LoadModelFromFile(char* sFilePath)
{
	//	i//f (vboModelData.GetBufferID() == 0)
		//{
		//	vboModelData.CreateVBO();
		//	tTextures.reserve(50);
		//}
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(sFilePath,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	if (!scene)
	{
		//MessageBox(appMain.hWnd, "Couldn't load model ", "Error Importing Asset", MB_ICONERROR);
		std::cout << "Loading error" << std::endl;
		false;
	}

	const int iVertexTotalSize = sizeof(aiVector3D) * 2 + sizeof(aiVector2D);

	int iTotalVertices = 0;
	float scale = 0.01;
	for (int i = 0; i < scene->mNumMeshes; ++i)
	{
		aiMesh* mesh = scene->mMeshes[i];
		int iMeshFaces = mesh->mNumFaces;

		std::vector<Point3D*> meshVertexs;
		for (int j = 0; j < mesh->mNumVertices; ++j) {
			aiVector3D vect= mesh->mVertices[j];
			meshVertexs.push_back(new Point3D(vect.x * scale, vect.y * scale, vect.z * scale));
			
		}

		meshes.push_back(meshVertexs);
	
		iNumMaterials = scene->mNumMaterials;

		return bLoaded = true; // TODO			
	}
/*	
	meshVertexs.push_back(new Point3D(0, 0, 2));
	meshVertexs.push_back(new Point3D(2, 0, 0));
	meshVertexs.push_back(new Point3D(2, 0, 2));
	meshVertexs.push_back(new Point3D(0, 0, 2));
	meshes.push_back(meshVertexs);
	*/


	
	/*
	float* tmp = new float[3];
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	meshesArray[0] = tmp;

	float tmp2[] = { 2,0,0 };
	meshesArray[1] = tmp2;

	float tmp3[] = { 2,0,2 };
	meshesArray[2] = tmp3;

	float tmp4[] = { 0,0,2 };
	meshesArray[3] = tmp4;

	float meshesArray[][3] = {
		{ 0,0,0 },
		{ 2,0,0 },
		{ 2,0,2 },
		{ 0,0,2 }
	};

	*/
	return true;
}

void AssimpLoader::RenderModel()
{
	//if (!bLoaded)return;
	/*int iNumMeshes = iMeshSizes.size();
	for(int i = 0; i <iNumMeshes; ++i)
	{
		int iMatIndex = iMaterialIndices[i];
		//tTextures[iMatIndex].BindTexture();
		glDrawArrays(GL_TRIANGLES, iMeshStartIndices[i], iMeshSizes[i]);

	}*/
	

	for (int i = 0; i < meshes.size(); ++i) {
		std::vector<Point3D*> tmp = meshes[i];

		//std::cout << "==============" << std::endl;
		for (int j = 0; j < tmp.size(); ++j) {
			glVertex3fv(tmp[j]->toVector());
			//std::cout << tmp[j]->toString() << std::endl;
		}

	}
	/*	//for (int j = 0; j < 3; ++j) {
			glVertex3fv(meshVertexs[i]->toVector());
			std::cout << "==============" << std::endl;
			std::cout << meshVertexs[i]->toString() << std::endl;
			
			std::cout << "=============="<< std::endl;
			for (int j = 0; j < 3; ++j) {
				std::cout << meshesArray[i][j] << std::endl;
			}*/
		//}
	

}
void loadObject(const aiScene* sc) {
	// For each mesh in the aiScene object
	for (unsigned int n = 0; n < sc->mNumMeshes; ++n)
	{
		// Get the current aiMesh object. 
		const aiMesh* mesh = sc->mMeshes[n];

		// Create a one dimensional array to store face indices
		unsigned int *faceArray;
		faceArray = (unsigned int *)malloc(sizeof(unsigned int) * mesh->mNumFaces * 3);
		unsigned int faceIndex = 0;

		// Copy face indices from aiMesh to faceArray. 
		// In an aiMesh object, face indices are stored in two layers. There is an array of aiFace, and then each aiFace stores 3 indices. 
		// Must copy face indices to a one dimensional array so that it can be used in OpenGL functions. 
		for (unsigned int t = 0; t < mesh->mNumFaces; ++t) {
			const aiFace* face = &mesh->mFaces[t];  // Go through the list of aiFace

													// For each aiFace, copy its indices to faceArray. 
			memcpy(&faceArray[faceIndex], face->mIndices, 3 * sizeof(unsigned int));
			faceIndex += 3;
		}
		//			aMesh.numFaces = sc->mMeshes[n]->mNumFaces; // Record the number of faces. 

																// Generate and bind a vertex buffer object for face indices (also called elements)
					//glGenBuffers(1, &buffer);
					//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
					// Transfer the faceArray to the vertex buffer object. 
					//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh->mNumFaces * 3, faceArray, GL_STATIC_DRAW);
	}
}