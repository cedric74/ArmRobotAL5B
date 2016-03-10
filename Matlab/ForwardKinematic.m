
clc
clear all

%Define symbolic variables
syms t1 t2 t3 t4 t5 d1 a2 a3 d5 

% create a numerical or symbolic DH parameter
%      alpha              d       a       t
DH=[  0               0       0          t1;     %frame1
      -90*pi/180      0       0          t2;     %frame2
      0               5       0          t3;     %frame3
      -90*pi/180      0       4          t4;     %frame4
      90*pi/180       0       1          t5;     %frame5
];



%define Distance
d1 = 70;
a2 = 120;
a3 = 105;
d5 = 40;

%define Angle in Radian
t1 = 0  *pi/180;
t2 = 0  *pi/180;
t3 = 90  *pi/180;
t4 = 90 *pi/180;
t5 = 0  *pi/180;

%Define transformations:
T1_0 = [
    cos(t1),  0, -sin(t1), 0;
    sin(t1),  0,  cos(t1), 0;
          0, -1,        0, d1;
          0,  0,        0, 1];

T2_1 = [
    sin(t2) , cos(t2), 0, a2*sin(t2) ;
    -cos(t2), sin(t2), 0, -a2*cos(t2);
           0,       0, 1,           0;
           0,       0, 0,            1
    ];

T3_2 = [
    cos(t3) , -sin(t3), 0,  a3*cos(t3);
    sin(t3),   cos(t3), 0,  a3*sin(t3);
           0,       0,  1,           0;
           0,       0,  0,           1
    ];


T4_3 = [
    sin(t4),     0,  cos(t4),  0;
    -cos(t4),    0,  sin(t4),  0;
           0,   -1,        0,  0; 
           0,    0,        0,  1
    ];


T5_4 = [
    cos(t5) , -sin(t5), 0,  0;
    sin(t5),   cos(t5), 0,  0;
           0,       0,  1,  d5;
           0,       0,  0,  1
    ];

%Determine transformation
T2_0 = T1_0 * T2_1;
T3_0 = T2_0*T3_2;
T4_0 = T3_0*T4_3;
T5_0 = T4_0*T5_4





