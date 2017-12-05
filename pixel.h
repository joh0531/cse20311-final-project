#ifndef PIXEL_H
#define PIXEL_H

class pixel{

public:
  pixel();
  pixel(int, int);
  ~pixel();
  void setX(int);
  void setY(int);
  void setLocation(int, int);
  int getX();
  int getY();
  void draw();
  pixel& operator= (&pixel);

private:
    int x;
    int y;
};

#endif
