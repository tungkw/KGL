#ifndef __KI_CAMERA_H
#define __KI_CAMERA_H


class KiCamera
{
private:
    float pos[3];
    float eye[3];
    float up[3];

public:
    KiCamera(int mode);
    ~KiCamera();
};



#endif
