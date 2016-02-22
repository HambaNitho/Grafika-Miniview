#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "gl.hpp"
//#include <ncurses.h>
using namespace std;

int main() {

	polygon sulawesi, sumatera, kalimantan_id, kalimantan_my, papua, jawa;
	polygon bangka, belitung;
	polygon madura, bali, ntt_1, ntt_2, ntt_timor, ntb_4, ntb_3, ntb_2, ntb_1;
	polygon malut, maluku_2, maluku_1;
	int coef = 5;

	sumatera.add_point(3*coef, 5*coef);
sumatera.add_point(5*coef, 7*coef);
sumatera.add_point(9*coef, 7*coef);
sumatera.add_point(18*coef, 16*coef);
sumatera.add_point(19*coef, 16*coef);
sumatera.add_point(23*coef, 20*coef);
sumatera.add_point(25*coef, 20*coef);
sumatera.add_point(27*coef, 22*coef);
sumatera.add_point(27*coef, 23*coef);
sumatera.add_point(26*coef, 23*coef);
sumatera.add_point(26*coef, 25*coef);
sumatera.add_point(29*coef, 25*coef);
sumatera.add_point(29*coef, 29*coef);
sumatera.add_point(30*coef, 30*coef);
sumatera.add_point(30*coef, 32*coef);
sumatera.add_point(31*coef, 33*coef);
sumatera.add_point(33*coef, 39*coef);
sumatera.add_point(32*coef, 40*coef);
sumatera.add_point(31*coef, 39*coef);
sumatera.add_point(30*coef, 39*coef);
sumatera.add_point(29*coef, 40*coef);
sumatera.add_point(18*coef, 29*coef);
sumatera.add_point(18*coef, 28*coef);
sumatera.add_point(17*coef, 27*coef);
sumatera.add_point(17*coef, 25*coef);
sumatera.add_point(13*coef, 21*coef);
sumatera.add_point(13*coef, 19*coef);
sumatera.add_point(10*coef, 16*coef);
sumatera.add_point(9*coef, 16*coef);
sumatera.add_point(9*coef, 14*coef);
sumatera.add_point(7*coef, 12*coef);
sumatera.add_point(6*coef, 12*coef);
sumatera.add_point(2*coef, 8*coef);
sumatera.add_point(2*coef, 6*coef);
sumatera.add_point(3*coef, 5*coef);

bangka.add_point(32*coef, 27*coef);
bangka.add_point(33*coef, 27*coef);
bangka.add_point(34*coef, 28*coef);
bangka.add_point(34*coef, 29*coef);
bangka.add_point(36*coef, 31*coef);
bangka.add_point(36*coef, 32*coef);
bangka.add_point(35*coef, 32*coef);
bangka.add_point(34*coef, 31*coef);
bangka.add_point(34*coef, 30*coef);
bangka.add_point(33*coef, 29*coef);
bangka.add_point(32*coef, 29*coef);
bangka.add_point(31*coef, 28*coef);
bangka.add_point(32*coef, 27*coef);

belitung.add_point(39*coef, 30*coef);
belitung.add_point(40*coef, 31*coef);
belitung.add_point(40*coef, 32*coef);
belitung.add_point(38*coef, 32*coef);
belitung.add_point(38*coef, 31*coef);
belitung.add_point(39*coef, 30*coef);

jawa.add_point(34*coef, 40*coef);
jawa.add_point(37*coef, 40*coef);
jawa.add_point(38*coef, 41*coef);
jawa.add_point(40*coef, 41*coef);
jawa.add_point(41*coef, 42*coef);
jawa.add_point(41*coef, 43*coef);
jawa.add_point(46*coef, 43*coef);
jawa.add_point(48*coef, 41*coef);
jawa.add_point(50*coef, 43*coef);
jawa.add_point(52*coef, 43*coef);
jawa.add_point(53*coef, 44*coef);
jawa.add_point(53*coef, 45*coef);
jawa.add_point(57*coef, 45*coef);
jawa.add_point(58*coef, 46*coef);
jawa.add_point(58*coef, 49*coef);
jawa.add_point(57*coef, 48*coef);
jawa.add_point(56*coef, 48*coef);
jawa.add_point(55*coef, 47*coef);
jawa.add_point(47*coef, 47*coef);
jawa.add_point(46*coef, 46*coef);
jawa.add_point(39*coef, 46*coef);
jawa.add_point(38*coef, 45*coef);
jawa.add_point(35*coef, 45*coef);
jawa.add_point(35*coef, 44*coef);
jawa.add_point(34*coef, 43*coef);
jawa.add_point(31*coef, 43*coef);
jawa.add_point(34*coef, 40*coef);

madura.add_point(54*coef, 43*coef);
madura.add_point(57*coef, 43*coef);
madura.add_point(56*coef, 44*coef);
madura.add_point(54*coef, 44*coef);
madura.add_point(54*coef, 43*coef);

bali.add_point(59*coef, 47*coef);
bali.add_point(61*coef, 47*coef);
bali.add_point(61*coef, 48*coef);
bali.add_point(60*coef, 48*coef);
bali.add_point(59*coef, 47*coef);

ntb_1.add_point(63*coef, 47*coef);
ntb_1.add_point(64*coef, 47*coef);
ntb_1.add_point(64*coef, 49*coef);
ntb_1.add_point(62*coef, 49*coef);
ntb_1.add_point(63*coef, 48*coef);
ntb_1.add_point(63*coef, 47*coef);

ntb_2.add_point(65*coef, 48*coef);
ntb_2.add_point(68*coef, 48*coef);
ntb_2.add_point(69*coef, 49*coef);
ntb_2.add_point(67*coef, 49*coef);
ntb_2.add_point(66*coef, 50*coef);
ntb_2.add_point(65*coef, 50*coef);
ntb_2.add_point(65*coef, 48*coef);

ntb_3.add_point(68*coef, 47*coef);
ntb_3.add_point(71*coef, 47*coef);
ntb_3.add_point(71*coef, 49*coef);
ntb_3.add_point(70*coef, 49*coef);
ntb_3.add_point(68*coef, 47*coef);

ntb_4.add_point(71*coef, 51*coef);
ntb_4.add_point(75*coef, 51*coef);
ntb_4.add_point(76*coef, 52*coef);
ntb_4.add_point(76*coef, 53*coef);
ntb_4.add_point(74*coef, 53*coef);
ntb_4.add_point(73*coef, 52*coef);
ntb_4.add_point(72*coef, 52*coef);
ntb_4.add_point(71*coef, 51*coef);

ntt_1.add_point(75*coef, 47*coef);
ntt_1.add_point(77*coef, 47*coef);
ntt_1.add_point(78*coef, 48*coef);
ntt_1.add_point(81*coef, 48*coef);
ntt_1.add_point(82*coef, 47*coef);
ntt_1.add_point(89*coef, 47*coef);
ntt_1.add_point(88*coef, 48*coef);
ntt_1.add_point(82*coef, 48*coef);
ntt_1.add_point(81*coef, 49*coef);
ntt_1.add_point(74*coef, 49*coef);
ntt_1.add_point(74*coef, 48*coef);
ntt_1.add_point(75*coef, 47*coef);

ntt_2.add_point(90*coef, 48*coef);
ntt_2.add_point(92*coef, 48*coef);
ntt_2.add_point(92*coef, 49*coef);
ntt_2.add_point(91*coef, 50*coef);
ntt_2.add_point(90*coef, 50*coef);
ntt_2.add_point(87*coef, 53*coef);
ntt_2.add_point(86*coef, 53*coef);
ntt_2.add_point(85*coef, 54*coef);
ntt_2.add_point(84*coef, 53*coef);
ntt_2.add_point(84*coef, 52*coef);
ntt_2.add_point(86*coef, 50*coef);
ntt_2.add_point(88*coef, 50*coef);
ntt_2.add_point(90*coef, 48*coef);

ntt_timor.add_point(92*coef, 48*coef);
ntt_timor.add_point(93*coef, 47*coef);
ntt_timor.add_point(95*coef, 47*coef);
ntt_timor.add_point(95*coef, 48*coef);
ntt_timor.add_point(94*coef, 49*coef);
ntt_timor.add_point(92*coef, 49*coef);
ntt_timor.add_point(92*coef, 48*coef);

kalimantan_id.add_point(44*coef, 17*coef);
kalimantan_id.add_point(47*coef, 20*coef);
kalimantan_id.add_point(50*coef, 20*coef);
kalimantan_id.add_point(52*coef, 18*coef);
kalimantan_id.add_point(54*coef, 18*coef);
kalimantan_id.add_point(55*coef, 19*coef);
kalimantan_id.add_point(56*coef, 19*coef);
kalimantan_id.add_point(57*coef, 18*coef);
kalimantan_id.add_point(58*coef, 18*coef);
kalimantan_id.add_point(59*coef, 17*coef);
kalimantan_id.add_point(59*coef, 16*coef);
kalimantan_id.add_point(60*coef, 15*coef);
kalimantan_id.add_point(60*coef, 14*coef);
kalimantan_id.add_point(61*coef, 13*coef);
kalimantan_id.add_point(61*coef, 11*coef);
kalimantan_id.add_point(62*coef, 10*coef);
kalimantan_id.add_point(66*coef, 10*coef);
kalimantan_id.add_point(68*coef, 12*coef);
kalimantan_id.add_point(66*coef, 12*coef);
kalimantan_id.add_point(66*coef, 13*coef);
kalimantan_id.add_point(68*coef, 15*coef);
kalimantan_id.add_point(68*coef, 16*coef);
kalimantan_id.add_point(71*coef, 19*coef);
kalimantan_id.add_point(71*coef, 20*coef);
kalimantan_id.add_point(68*coef, 20*coef);
kalimantan_id.add_point(67*coef, 21*coef);
kalimantan_id.add_point(67*coef, 24*coef);
kalimantan_id.add_point(64*coef, 27*coef);
kalimantan_id.add_point(64*coef, 31*coef);
kalimantan_id.add_point(63*coef, 32*coef);
kalimantan_id.add_point(63*coef, 33*coef);
kalimantan_id.add_point(62*coef, 34*coef);
kalimantan_id.add_point(60*coef, 34*coef);
kalimantan_id.add_point(59*coef, 35*coef);
kalimantan_id.add_point(58*coef, 35*coef);
kalimantan_id.add_point(58*coef, 33*coef);
kalimantan_id.add_point(57*coef, 33*coef);
kalimantan_id.add_point(56*coef, 32*coef);
kalimantan_id.add_point(53*coef, 32*coef);
kalimantan_id.add_point(52*coef, 33*coef);
kalimantan_id.add_point(50*coef, 33*coef);
kalimantan_id.add_point(50*coef, 32*coef);
kalimantan_id.add_point(46*coef, 32*coef);
kalimantan_id.add_point(45*coef, 31*coef);
kalimantan_id.add_point(45*coef, 26*coef);
kalimantan_id.add_point(44*coef, 26*coef);
kalimantan_id.add_point(43*coef, 25*coef);
kalimantan_id.add_point(43*coef, 22*coef);
kalimantan_id.add_point(42*coef, 21*coef);
kalimantan_id.add_point(42*coef, 18*coef);
kalimantan_id.add_point(43*coef, 17*coef);
kalimantan_id.add_point(44*coef, 17*coef);


kalimantan_my.add_point(44*coef, 17*coef);
kalimantan_my.add_point(47*coef, 20*coef);
kalimantan_my.add_point(50*coef, 20*coef);
kalimantan_my.add_point(52*coef, 18*coef);
kalimantan_my.add_point(54*coef, 18*coef);
kalimantan_my.add_point(55*coef, 19*coef);
kalimantan_my.add_point(56*coef, 19*coef);
kalimantan_my.add_point(57*coef, 18*coef);
kalimantan_my.add_point(58*coef, 18*coef);
kalimantan_my.add_point(59*coef, 17*coef);
kalimantan_my.add_point(59*coef, 16*coef);
kalimantan_my.add_point(60*coef, 15*coef);
kalimantan_my.add_point(60*coef, 14*coef);
kalimantan_my.add_point(61*coef, 13*coef);
kalimantan_my.add_point(61*coef, 11*coef);
kalimantan_my.add_point(62*coef, 10*coef);
kalimantan_my.add_point(66*coef, 10*coef);
kalimantan_my.add_point(69*coef, 10*coef);
kalimantan_my.add_point(70*coef, 9*coef);
kalimantan_my.add_point(69*coef, 8*coef);
kalimantan_my.add_point(71*coef, 8*coef);
kalimantan_my.add_point(72*coef, 7*coef);
kalimantan_my.add_point(70*coef, 5*coef);
kalimantan_my.add_point(68*coef, 5*coef);
kalimantan_my.add_point(68*coef, 4*coef);
kalimantan_my.add_point(66*coef, 2*coef);
kalimantan_my.add_point(65*coef, 2*coef);
kalimantan_my.add_point(63*coef, 4*coef);
kalimantan_my.add_point(63*coef, 5*coef);
kalimantan_my.add_point(62*coef, 6*coef);
kalimantan_my.add_point(61*coef, 6*coef);
kalimantan_my.add_point(61*coef, 8*coef);
kalimantan_my.add_point(59*coef, 8*coef);
kalimantan_my.add_point(58*coef, 9*coef);
kalimantan_my.add_point(57*coef, 9*coef);
kalimantan_my.add_point(57*coef, 10*coef);
kalimantan_my.add_point(53*coef, 14*coef);
kalimantan_my.add_point(50*coef, 14*coef);
kalimantan_my.add_point(49*coef, 15*coef);
kalimantan_my.add_point(49*coef, 17*coef);
kalimantan_my.add_point(48*coef, 18*coef);
kalimantan_my.add_point(47*coef, 18*coef);
kalimantan_my.add_point(46*coef, 17*coef);
kalimantan_my.add_point(44*coef, 17*coef);


sulawesi.add_point(77*coef, 18*coef);
sulawesi.add_point(78*coef, 19*coef);
sulawesi.add_point(83*coef, 19*coef);
sulawesi.add_point(84*coef, 20*coef);
sulawesi.add_point(86*coef, 20*coef);
sulawesi.add_point(89*coef, 17*coef);
sulawesi.add_point(89*coef, 19*coef);
sulawesi.add_point(87*coef, 21*coef);
sulawesi.add_point(76*coef, 21*coef);
sulawesi.add_point(75*coef, 22*coef);
sulawesi.add_point(75*coef, 25*coef);
sulawesi.add_point(76*coef, 26*coef);
sulawesi.add_point(77*coef, 26*coef);
sulawesi.add_point(78*coef, 25*coef);
sulawesi.add_point(81*coef, 25*coef);
sulawesi.add_point(82*coef, 24*coef);
sulawesi.add_point(84*coef, 24*coef);
sulawesi.add_point(80*coef, 28*coef);
sulawesi.add_point(78*coef, 28*coef);
sulawesi.add_point(81*coef, 31*coef);
sulawesi.add_point(81*coef, 33*coef);
sulawesi.add_point(82*coef, 34*coef);
sulawesi.add_point(82*coef, 35*coef);
sulawesi.add_point(81*coef, 36*coef);
sulawesi.add_point(80*coef, 36*coef);
sulawesi.add_point(80*coef, 37*coef);
sulawesi.add_point(79*coef, 37*coef);
sulawesi.add_point(78*coef, 36*coef);
sulawesi.add_point(78*coef, 34*coef);
sulawesi.add_point(77*coef, 33*coef);
sulawesi.add_point(77*coef, 31*coef);
sulawesi.add_point(76*coef, 30*coef);
sulawesi.add_point(75*coef, 31*coef);
sulawesi.add_point(75*coef, 39*coef);
sulawesi.add_point(73*coef, 39*coef);
sulawesi.add_point(72*coef, 38*coef);
sulawesi.add_point(72*coef, 37*coef);
sulawesi.add_point(73*coef, 36*coef);
sulawesi.add_point(73*coef, 34*coef);
sulawesi.add_point(72*coef, 33*coef);
sulawesi.add_point(71*coef, 33*coef);
sulawesi.add_point(70*coef, 32*coef);
sulawesi.add_point(70*coef, 31*coef);
sulawesi.add_point(71*coef, 30*coef);
sulawesi.add_point(71*coef, 29*coef);
sulawesi.add_point(72*coef, 28*coef);
sulawesi.add_point(72*coef, 26*coef);
sulawesi.add_point(73*coef, 25*coef);
sulawesi.add_point(73*coef, 22*coef);
sulawesi.add_point(77*coef, 18*coef);

papua.add_point(110*coef, 23*coef);
papua.add_point(111*coef, 24*coef);
papua.add_point(112*coef, 24*coef);
papua.add_point(113*coef, 25*coef);
papua.add_point(115*coef, 25*coef);
papua.add_point(115*coef, 30*coef);
papua.add_point(117*coef, 32*coef);
papua.add_point(119*coef, 32*coef);
papua.add_point(122*coef, 29*coef);
papua.add_point(123*coef, 29*coef);
papua.add_point(124*coef, 28*coef);
papua.add_point(124*coef, 27*coef);
papua.add_point(127*coef, 27*coef);
papua.add_point(128*coef, 28*coef);
papua.add_point(129*coef, 28*coef);
papua.add_point(131*coef, 30*coef);
papua.add_point(135*coef, 30*coef);
papua.add_point(135*coef, 41*coef);
papua.add_point(134*coef, 42*coef);
papua.add_point(135*coef, 43*coef);
papua.add_point(135*coef, 50*coef);
papua.add_point(132*coef, 47*coef);
papua.add_point(129*coef, 47*coef);
papua.add_point(128*coef, 48*coef);
papua.add_point(125*coef, 48*coef);
papua.add_point(125*coef, 46*coef);
papua.add_point(126*coef, 45*coef);
papua.add_point(127*coef, 45*coef);
papua.add_point(128*coef, 44*coef);
papua.add_point(128*coef, 42*coef);
papua.add_point(127*coef, 41*coef);
papua.add_point(127*coef, 40*coef);
papua.add_point(125*coef, 38*coef);
papua.add_point(124*coef, 38*coef);
papua.add_point(123*coef, 37*coef);
papua.add_point(122*coef, 37*coef);
papua.add_point(121*coef, 36*coef);
papua.add_point(118*coef, 36*coef);
papua.add_point(117*coef, 35*coef);
papua.add_point(116*coef, 35*coef);
papua.add_point(115*coef, 34*coef);
papua.add_point(114*coef, 34*coef);
papua.add_point(113*coef, 33*coef);
papua.add_point(113*coef, 34*coef);
papua.add_point(112*coef, 35*coef);
papua.add_point(111*coef, 35*coef);
papua.add_point(111*coef, 33*coef);
papua.add_point(109*coef, 31*coef);
papua.add_point(111*coef, 31*coef);
papua.add_point(112*coef, 30*coef);
papua.add_point(113*coef, 30*coef);
papua.add_point(114*coef, 29*coef);
papua.add_point(109*coef, 29*coef);
papua.add_point(109*coef, 28*coef);
papua.add_point(108*coef, 27*coef);
papua.add_point(107*coef, 27*coef);
papua.add_point(106*coef, 26*coef);
papua.add_point(108*coef, 24*coef);
papua.add_point(109*coef, 24*coef);
papua.add_point(110*coef, 23*coef);

malut.add_point(97*coef, 16*coef);
malut.add_point(95*coef, 18*coef);
malut.add_point(95*coef, 20*coef);
malut.add_point(96*coef, 21*coef);
malut.add_point(96*coef, 25*coef);
malut.add_point(98*coef, 25*coef);
malut.add_point(98*coef, 24*coef);
malut.add_point(97*coef, 23*coef);
malut.add_point(97*coef, 21*coef);
malut.add_point(98*coef, 21*coef);
malut.add_point(99*coef, 22*coef);
malut.add_point(99*coef, 21*coef);
malut.add_point(98*coef, 20*coef);
malut.add_point(99*coef, 19*coef);
malut.add_point(99*coef, 18*coef);
malut.add_point(98*coef, 18*coef);
malut.add_point(98*coef, 19*coef);
malut.add_point(97*coef, 20*coef);
malut.add_point(96*coef, 19*coef);
malut.add_point(97*coef, 19*coef);
malut.add_point(97*coef, 16*coef);

maluku_1.add_point(91*coef, 31*coef);
maluku_1.add_point(94*coef, 31*coef);
maluku_1.add_point(95*coef, 32*coef);
maluku_1.add_point(95*coef, 33*coef);
maluku_1.add_point(94*coef, 34*coef);
maluku_1.add_point(93*coef, 34*coef);
maluku_1.add_point(91*coef, 32*coef);
maluku_1.add_point(91*coef, 31*coef);

maluku_2.add_point(98*coef, 31*coef);
maluku_2.add_point(104*coef, 31*coef);
maluku_2.add_point(106*coef, 33*coef);
maluku_2.add_point(106*coef, 34*coef);
maluku_2.add_point(105*coef, 34*coef);
maluku_2.add_point(104*coef, 33*coef);
maluku_2.add_point(99*coef, 33*coef);
maluku_2.add_point(98*coef, 34*coef);
maluku_2.add_point(97*coef, 34*coef);
maluku_2.add_point(97*coef, 32*coef);
maluku_2.add_point(98*coef, 31*coef);
	

	int width = 480;
	int height = 270;

	int xPos = canvas::get_instance()->get_var_info().xres - width - 10;
	int yPos = canvas::get_instance()->get_var_info().yres - height - 10;
	point view_pos(xPos,yPos);

	point clipping_pos(0,0);
	view v(height, width, view_pos, clipping_pos, 0.5);
	
	initscr();
    noecho();
    timeout(-1);
    int c;

	while (true) {
        v.draw(sumatera);
        v.draw(jawa);
        v.draw(kalimantan_my);
        v.draw(kalimantan_id);
        v.draw(papua);
        v.draw(sulawesi);
        v.draw(bangka);
        v.draw(belitung);
        v.draw(madura);
        v.draw(bali);
        v.draw(ntb_1);
        v.draw(ntb_2);
        v.draw(ntb_3);
        v.draw(ntb_4);
        v.draw(ntt_1);
        v.draw(ntt_2);
        v.draw(ntt_timor);
        v.draw(malut);
        v.draw(maluku_2);
        v.draw(maluku_1);

		sumatera.draw_stroke(0, 0);
		jawa.draw_stroke(0, 0);
		kalimantan_id.draw_stroke(0, 0);
		kalimantan_my.draw_stroke(0, 0);
		sulawesi.draw_stroke(0, 0);
		papua.draw_stroke(0, 0);
		bangka.draw_stroke(0, 0);
		belitung.draw_stroke(0, 0);
		madura.draw_stroke(0, 0);
		bali.draw_stroke(0, 0);
		ntb_4.draw_stroke(0, 0);
		ntb_3.draw_stroke(0, 0);
		ntb_2.draw_stroke(0, 0);
		ntb_1.draw_stroke(0, 0);
		ntt_2.draw_stroke(0, 0);
		ntt_1.draw_stroke(0, 0);
		ntt_timor.draw_stroke(0, 0);
		malut.draw_stroke(0, 0);
		maluku_2.draw_stroke(0, 0);
		maluku_1.draw_stroke(0, 0);

		canvas::get_instance()->render();
        c = getch();   
        switch(c) {
            case 122:       // key z
                v.zoom(-1);
                break;
            case 120:       // key x
                v.zoom(1);
                break;
            case 65:       // key up
                v.move_clip(0, -4);
                break;
            case 66:       // key down
                v.move_clip(0, 4);     
                break;
            case 67:       // key right
                v.move_clip(4, 0);
                break;
            case 68:       // key left
                v.move_clip(-4, 0);
                break;
            default:
                v.move_clip(0, 0);
                break;
        }
		canvas::get_instance()->clear();
		//v.move_clip(1, 0);
		//v.draw(p1);	

		//usleep(100000);
	}

    return 0;
}