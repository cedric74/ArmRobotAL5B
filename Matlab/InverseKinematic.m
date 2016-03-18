clc
clear all

%Define symbolic variables
syms nx ny nz ox oy oz ax ay az px py pz

nx = 1;
ny = 0;
nz = 0;
ox = 0;
oy = -1;
oz = 0;
ax = 0;
ay = 0;
az =-1;
px = 105;
py = 0;
pz = 150;


%Define transformations:
theta1 = atan2(py,px);
theta5 = atan2(nx*sin(theta1)-ny*cos(theta1), ox*sin(theta1)- oy*cos(theta1));
theta3 = acos(((px-40*ax)^2+(py-40*ay)^2+(pz-70-40*az)^2 - 25425)/ 25200)
%theta3 = 0;

r1 =  -40*ax*cos(theta1) -40*ay*sin(theta1) +px*cos(theta1)+py*sin(theta1)
r2 =  70+40*az-pz
theta2 = atan2 (105*r2*sin(theta3) + 105*r1*cos(theta3) + 120*r1, -105*r2*cos(theta3) + 105*r1*sin(theta3)-120*r2)

theta234 = atan2(ax*cos(theta1)+ay*sin(theta1),az);
theta4 = theta234-theta2-theta3;

%convert angle from radian to degree
theta1degree = (theta1*180)/pi 

%convert angle from radian to degree
theta2degree = (theta2*180)/pi

%convert angle from radian to degree
theta3degree = (theta3*180)/pi

%convert angle from radian to degree
theta4degree = (theta4*180)/pi

%convert angle from radian to degree
theta5degree = (theta5*180)/pi


