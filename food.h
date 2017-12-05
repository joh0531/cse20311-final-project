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

  private:
      int x;
      int y;
}
