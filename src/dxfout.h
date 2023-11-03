#ifndef __DXFOUT_H
#define __DXFOUT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum COLOR {
  OBJRED = 1, OBJYELLOW, OBJGREEN, OBJCYAN, OBJBLUE, OBJMAGENTA, OBJWHITE
};

typedef struct OBJECTATTR {
  COLOR color;
  float thickness;
  char linetype[15];
  float height;
  float rotation;
  float obliquing;
  int closed;
};

OBJECTATTR objectattr;

FILE * _cdecl beginDXF(const char *FileNameOutDXF);
void _cdecl endDXF(FILE *out);
void _cdecl beginPOLYLINE(FILE *out, const char *layer);
void _cdecl endPOLYLINE(FILE *out, const char *layer);
void _cdecl writeVERTEX(FILE *out, const char *layer, float coordX,
                        float coordY);
void _cdecl writeTEXT(FILE *out, const char *layer, float coordX,
                      float coordY, const char *texto);
void _cdecl writeCIRCLE(FILE *out, const char *layer, float coordX,
                        float coordY, float radio);
void _cdecl writeLINE(FILE *out, const char *layer, float coordXStart,
               float coordYStart, float coordXEnd, float coordYEnd);
void _cdecl writePOINT(FILE *out, const char *layer, float coordX,
                       float coordY);

#ifdef __cplusplus
}
#endif

#endif
