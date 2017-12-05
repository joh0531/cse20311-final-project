#ifndef FOOD_H
#define FOOD_H

class food{
  public:
      food();
      food(int, int);
      ~food();
      void setX(int);
      void setY(int);
      void setLocation(int, int);
      int getX();
      int getY();
      void draw();

  private:
      int x;
      int y;
};

#endif
