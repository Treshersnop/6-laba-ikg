#ifndef OGLDEV_BASIC_MESH_H
#define	OGLDEV_BASIC_MESH_H

#include <map>
#include <vector>
#include <GL/glew.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags

#include "util.h"
#include "math_3d.h"
#include "texture.h"
#include "pipeline.h"

struct Vertex
{
    Vector3f m_pos;
    Vector2f m_tex;
    Vector3f m_normal;

    Vertex() {}

    Vertex(const Vector3f& pos, const Vector2f& tex, const Vector3f& normal)
    {
        m_pos    = pos;
        m_tex    = tex;
        m_normal = normal;
    }
};


class BasicMesh
{
public:
    BasicMesh();

    ~BasicMesh();

    bool LoadMesh(const std::string& Filename);

    void Render();
	
    void Render(unsigned int NumInstances, const Matrix4f* WVPMats, const Matrix4f* WorldMats);
    
    Orientation& GetOrientation() { return m_orientation; }

private:
    bool InitFromScene(const aiScene* pScene, const std::string& Filename);
    void InitMesh(const aiMesh* paiMesh,
                  std::vector<Vector3f>& Positions,
                  std::vector<Vector3f>& Normals,
                  std::vector<Vector2f>& TexCoords,
                  std::vector<unsigned int>& Indices);

    bool InitMaterials(const aiScene* pScene, const std::string& Filename);
    void Clear();

#define INVALID_MATERIAL 0xFFFFFFFF
   
#define INDEX_BUFFER 0    
#define POS_VB       1
#define NORMAL_VB    2
#define TEXCOORD_VB  3    
#define WVP_MAT_VB   4
#define WORLD_MAT_VB 5

    GLuint m_VAO;
    GLuint m_Buffers[6];

    struct BasicMeshEntry {
        BasicMeshEntry()
        {
            NumIndices = 0;
            BaseVertex = 0;
            BaseIndex = 0;
            MaterialIndex = INVALID_MATERIAL;
        }
        
        unsigned int NumIndices;
	unsigned int BaseVertex;
        unsigned int BaseIndex;
        unsigned int MaterialIndex;
    };
    
    std::vector<BasicMeshEntry> m_Entries;
    std::vector<Texture*> m_Textures;
    Orientation m_orientation;
};


#endif	/* OGLDEV_BASIC_MESH_H */

