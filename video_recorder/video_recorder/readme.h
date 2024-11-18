//
//  readme.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/18.
//

/*
 Camera采集图像，然后上传到显卡形成YUV纹理对象，最后将YUV格式的纹理重新渲染到RGBA的纹理上
 接着将RGBA格式的纹理对象传递到Filter节点，这个节点会使用OpenGLES来处理纹理对象
 GLImageView或者VideoEncoder拿到Filter节点输出之后，进行屏幕渲染或者编码操作
 
 ImageProgram
 每个节点的处理都是一个OpenGL的渲染过程，所以每个节点都要建立一个GLPrograme
 
 TextureFrame
 每个节点的输入都是一个纹理对象，其实是一个纹理ID，使用GLProgram将这个纹理对象渲染到目标纹理对象的时候，还需要建立一个帧缓存对象FBO，并且将这个纹理对象attach到这个帧缓存对象上
 
 要想使用OpenGLES ，必须要有上下文以及关联的线程，后面写编码器组件也需要一个单独的线程，也需要OpenGL上下文，并且需要和渲染线程共享OpenGL上下文，这样才能在编码线程中访问到渲染线程中的纹理对象 帧缓存对象
 
 */
