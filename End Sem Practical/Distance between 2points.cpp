class Solution {
  public:
  
    int distance(int x1, int y1, int x2, int y2) {
    double dist = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    return (int)round(dist);
}
};
