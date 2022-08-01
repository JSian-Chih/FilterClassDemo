clc; clear; close all;

a = load("dataFile.txt");

plot(a(1:10000,1));
hold on;
plot(a(1:10000,2));