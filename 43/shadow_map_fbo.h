#ifndef SHADOWMAPFBO_H
#define	SHADOWMAPFBO_H

#include <GL/glew.h>

class ShadowMapFBO
{
public:
    ShadowMapFBO();

    ~ShadowMapFBO();

    bool Init(unsigned int WindowWidth, unsigned int WindowHeight);

    void BindForWriting(GLenum CubeFace);//принимает enum для сторон куба
    //Поскольку мы осуществляем несколько проходов рендера в кубическую текстуру, 
    //это поможет сообщить GL в какую из граней куба будет происходить рендер
    void BindForReading(GLenum TextureUnit);
    
private:
    GLuint m_fbo;
    GLuint m_shadowMap;
    GLuint m_depth;//буфер глубины
};

#endif	/* SHADOWMAPFBO_H */

