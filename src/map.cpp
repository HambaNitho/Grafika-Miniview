#include <iostream>
#include "gl.hpp"
using namespace std;

int main() {

 polygon p1,p2,p3, p4, p5, p6;
 int coef = 30;

  p1.add_point(2*coef, -11*coef);
  p1.add_point(4*coef, -9*coef);
  p1.add_point(4*coef, -7*coef);
  p1.add_point(7*coef, -4*coef);
  p1.add_point(6*coef, -3*coef);
  p1.add_point(5*coef, -3*coef);
  p1.add_point(2*coef, -6*coef);
  p1.add_point(2*coef, -11*coef);

  p1.draw_stroke(0,600);

  p2.add_point(10*coef, -5*coef);
  p2.add_point(10*coef, -6*coef);
  p2.add_point(9*coef, -7*coef);
  p2.add_point(9*coef, -9*coef);
  p2.add_point(11*coef, -11*coef);
  p2.add_point(12*coef, -11*coef);
  p2.add_point(13*coef, -12*coef);
  p2.add_point(17*coef, -12*coef);
  p2.add_point(17*coef, -11*coef);
  p2.add_point(15*coef, -9*coef);
  p2.add_point(17*coef, -7*coef);
  p2.add_point(15*coef, -5*coef);
  p2.add_point(10*coef, -5*coef);

  p2.draw_stroke(0,600);

  p3.add_point(10*coef, -2*coef);  
  p3.add_point(16*coef, -2*coef);  
  p3.add_point(18*coef, -0*coef);  
  p3.add_point(11*coef, -0*coef);  
  p3.add_point(10*coef, -1*coef);  
  p3.add_point(10*coef, -2*coef);  

  p3.draw_stroke(0,600);

  p4.add_point(20*coef, -4*coef);
  p4.add_point(20*coef, -10*coef);
  p4.add_point(22*coef, -12*coef);
  p4.add_point(26*coef, -12*coef);
  p4.add_point(26*coef, -11*coef);
  p4.add_point(25*coef, -10*coef);
  p4.add_point(24*coef, -10*coef);
  p4.add_point(23*coef, -9*coef);
  p4.add_point(25*coef, -7*coef);
  p4.add_point(25*coef, -6*coef);
  p4.add_point(26*coef, -5*coef);
  p4.add_point(26*coef, -4*coef);
  p4.add_point(24*coef, -4*coef);
  p4.add_point(22*coef, -6*coef);
  p4.add_point(20*coef, -4*coef);

  p4.draw_stroke(0,600);

  p5.add_point(29*coef, -1*coef);
  p5.add_point(28*coef, -2*coef);
  p5.add_point(28*coef, -3*coef);
  p5.add_point(29*coef, -4*coef);
  p5.add_point(31*coef, -4*coef);
  p5.add_point(32*coef, -3*coef);
  p5.add_point(31*coef, -2*coef);
  p5.add_point(30*coef, -1*coef);
  p5.add_point(29*coef, -1*coef);

  p5.draw_stroke(0,600);

  p6.add_point(38*coef, -4*coef);
  p6.add_point(37*coef, -5*coef);
  p6.add_point(36*coef, -5*coef);
  p6.add_point(33*coef, -8*coef);
  p6.add_point(32*coef, -8*coef);
  p6.add_point(31*coef, -9*coef);
  p6.add_point(29*coef, -11*coef);
  p6.add_point(29*coef, -12*coef);
  p6.add_point(32*coef, -12*coef);
  p6.add_point(34*coef, -10*coef);
  p6.add_point(37*coef, -13*coef);
  p6.add_point(41*coef, -13*coef);
  p6.add_point(41*coef, -4*coef);
  p6.add_point(38*coef, -4*coef);

  p6.draw_stroke(0,600);


  canvas::get_instance()->render();
  canvas::get_instance()->clear();  

}
