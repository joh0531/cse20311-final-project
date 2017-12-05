

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

private:
    int x;
    int y;
}
