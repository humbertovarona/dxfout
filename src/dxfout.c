#include <stdio.h>
#include <string.h>
#include "dxfout.h"

FILE *beginDXF(const char *FileNameOutDXF) {

  objectattr.color = OBJWHITE;
  objectattr.thickness = 1.0;
  strcpy(objectattr.linetype,"CONTINUOUS");
  objectattr.height =  1.0;
  objectattr.rotation = 0.0;
  objectattr.obliquing = 0.0;
  objectattr.closed =  1;

  FILE *outDXF = fopen(FileNameOutDXF, "wt");
  fprintf(outDXF, "  0\nSECTION\n  2\nENTITIES\n");
  return outDXF;
}

void endDXF(FILE *out) {
  fprintf(out, "  0\nENDSEC\n  0\nEOF\n");
  fclose(out);
}

void beginPOLYLINE(FILE *out, const char *layer) {
  fprintf(out, "  0\nPOLYLINE\n  8\n%s\n  6\n%s\n", layer, objectattr.linetype);
  fprintf(out, " 62\n     %d\n", objectattr.color);
  fprintf(out, " 39\n%2.3f\n 66\n     1\n", objectattr.thickness);
  fprintf(out, " 10\n0.0\n 20\n0.0\n 30\n0.0\n");
  if (objectattr.closed)
    fprintf(out," 70\n     1\n");
}

void endPOLYLINE(FILE *out, const char *layer) {
  fprintf(out, "  0\nSEQEND\n  8\n%s\n", layer);
}

void writeVERTEX(FILE *out, const char *layer, float coordX, float coordY) {
  fprintf(out, "  0\nVERTEX\n  8\n%s\n", layer);
  fprintf(out, " 62\n     %d\n", objectattr.color);
  fprintf(out," 10\n%6.3f\n 20\n%6.3f\n 30\n0.0\n", coordX, coordY);
}

void writeTEXT(FILE *out, const char *layer, float coordX, float coordY,
               const char *texto) {
  fprintf(out, "  0\nTEXT\n  8\n%s\n  6\n%s\n", layer, objectattr.linetype);
  fprintf(out, " 62\n%d\n 39\n%2.3f\n 10\n%6.3f\n 20\n%6.3f\n 30\n0.0\n",
          objectattr.color, objectattr.thickness, coordX, coordY);
  fprintf(out, " 40\n%2.3f\n  1\n%s\n 50\n%2.3f\n 51\n%2.3f\n%2.3f\n",
          objectattr.height, texto, objectattr.rotation,
          objectattr.obliquing);
  fprintf(out, " 72\n     1\n 11\n%6.3f\n 21\n%6.3f\n 31\n0.0\n",
          coordX, coordY);
}

void writeCIRCLE(FILE *out, const char *layer, float coordX, float coordY,
                 float radio) {
  fprintf(out, "  0\nCIRCLE\n  8\n%s\n  6\n%s\n", layer, objectattr.linetype);
  fprintf(out, " 62\n%d\n 39\n%2.3f\n 10\n%6.3f\n 20\n%6.3f\n 30\n0.0\n 40\n%f",
          objectattr.color, objectattr.thickness, coordX, coordY, radio);
}

void writeLINE(FILE *out, const char *layer, float coordXStart,
               float coordYStart, float coordXEnd, float coordYEnd) {
  fprintf(out, "  0\nCIRCLE\n  8\n%s\n  6\n%s\n", layer, objectattr.linetype);
  fprintf(out, " 62\n%d\n 39\n%2.3f\n 10\n%6.3f\n 20\n%6.3f\n 30\n0.0\n",
          objectattr.color, objectattr.thickness, coordXStart, coordYStart);
  fprintf(out, " 11\n%6.3f\n 21\n%6.3f\n 31\n0.0\n", coordXEnd, coordYEnd);
}

void writePOINT(FILE *out, const char *layer, float coordX, float coordY) {
  fprintf(out, "  0\nPOINT\n  8\n%s\n", layer);
  fprintf(out, " 62\n     %d\n", objectattr.color);
  fprintf(out," 10\n%6.3f\n 20\n%6.3f\n 30\n0.0\n", coordX, coordY);
}
