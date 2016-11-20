#include <iostream>
#include <algorithm>
#define MAXR 20000 // Max rectangles
#define MAXE 20000 // Max event
using namespace std;
struct point {
  int x,y;
  point(){}
  point(int x, int y):x(x),y(y){}
};
struct event { // index of rectangle and left or right type
  int ind,t;   // t:type 0 for left coordinate, 1 for right coordinates
  event(){}
  event(int ind, int t):ind(ind),t(t){}
};
int n,e; // number of rectangles, number of events;
int area;
point rect[MAXR][2]; // rect[i][0] and rect[i][1] is bottom-left and top-right respectively
event event_h[MAXE];
event event_v[MAXE];
bool cmpx (event &a, event &b){ return rect[a.ind][a.t].x < rect[b.ind][b.t].x;}
bool cmpy (event &a, event &b){ return rect[a.ind][a.t].y < rect[b.ind][b.t].y;}
bool in_set[MAXR];

int main(){ // each rectangle in form of bottom left and top right coordinates
  cin>>n;
  for (int i = 0; i < n; ++i){
    cin>>rect[i][0].x
       >>rect[i][0].y
       >>rect[i][1].x
       >>rect[i][1].y;
    event_h[e]   = event(i,0);
    event_v[e++] = event(i,0);
    event_h[e]   = event(i,1);
    event_v[e++] = event(i,1);
  }
  sort(event_h,event_h+e,cmpx);
  sort(event_v,event_v+e,cmpy);
  in_set[event_h[0].ind] = 1;
  for (int i = 1; i < e; ++i){
    int delta_x = rect[event_h[i].ind][event_h[i].t].x - rect[event_h[i-1].ind][event_h[i-1].t].x;
    if (delta_x == 0) continue;
    int cnt = 0;
    int last_y;
    for (int j = 0; j < e; ++j){
      if (in_set[event_v[j].ind]){
        if (event_v[j].t == 0){
          if (cnt == 0) last_y = rect[event_v[j].ind][0].y;
          cnt++;
        }
        else {
          cnt--;
          if (cnt == 0){
            int delta_y = rect[event_v[j].ind][1].y - last_y;
            cout << delta_x*delta_y << endl;
            area+=delta_x*delta_y;
          }
        }
      }
    }
    in_set[event_h[i].ind] = (event_h[i].t == 0);
  }
  cout << "Area: " << area << endl;
}
