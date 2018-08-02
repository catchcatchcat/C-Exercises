#include <iostream>

using namespace std;

bool rectangle(int x, int y, int w, int h) { //三角形
    return (x < w && y < h);
}

bool rightTriangle(int x, int y, int base, int height) { //直角三角形
    return (height * (x - base) + base * y < 0);
}

bool circle(int x, int y, int radius) { //圆形
    return (x - 10) * (x - 10) +  (y - 10) * (y - 10)  <= radius * radius;
}

int main(){
    int w, h;
    w = 8; // 目标绘制形状的宽
    h = 8;  // 目标绘制形状的高
    for(int i = 0; i < 20; i++) { // 50是画布的高
        for(int j = 0; j < 30; j++){ // 40是画布的宽
            //rectangle(j, i, w, h) ? cout<<"*" : cout<<" ";
            //rightTriangle(j, i, w, h) ? cout<<"*" : cout<<" ";
            circle(j, i, w) ? cout<<"*" : cout<<" ";
        }
        cout<<endl;
    }
}
